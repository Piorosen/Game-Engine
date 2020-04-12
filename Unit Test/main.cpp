
#include <termios.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <ctype.h>
 
            /* Call this to change the terminal related to the stream to "raw" state.
             * (Usually you call this with stdin).
             * This means you get all keystrokes, and special keypresses like CTRL-C
             * no longer generate interrupts.
             *
             * You must restore the state before your program exits, or your user will
             * frantically have to figure out how to type 'reset' blind, to get their terminal
             * back to a sane state.
             *
             * The function returns 0 if success, errno error code otherwise.
            */
            static int stream_makeraw(FILE *const stream, struct termios *const state)
            {
                struct termios  old, raw, actual;
                int             fd;
             
                if (!stream)
                    return errno = EINVAL;
             
                /* Tell the C library not to buffer any data from/to the stream. */
                if (setvbuf(stream, NULL, _IONBF, 0))
                    return errno = EIO;
             
                /* Write/discard already buffered data in the stream. */
                fflush(stream);
             
                /* Termios functions use the file descriptor. */
                fd = fileno(stream);
                if (fd == -1)
                    return errno = EINVAL;
             
                /* Discard all unread input and untransmitted output. */
                tcflush(fd, TCIOFLUSH);
             
                /* Get current terminal settings. */
                if (tcgetattr(fd, &old))
                    return errno;
             
                /* Store state, if requested. */
                if (state)
                    *state = old; /* Structures can be assigned! */
             
                /* New terminal settings are based on current ones. */
                raw = old;
             
                /* Because the terminal needs to be restored to the original state,
                 * you want to ignore CTRL-C (break). */
                raw.c_iflag |= IGNBRK;  /* do ignore break, */
                raw.c_iflag &= ~BRKINT; /* do not generate INT signal at break. */
             
                /* Make sure we are enabled to receive data. */
                raw.c_cflag |= CREAD;
             
                /* Do not generate signals from special keypresses. */
                raw.c_lflag &= ~ISIG;
             
                /* Do not echo characters. */
                raw.c_lflag &= ~ECHO;
             
                /* Most importantly, disable "canonical" mode. */
                raw.c_lflag &= ~ICANON;
             
                /* In non-canonical mode, we can set whether getc() returns immediately
                 * when there is no data, or whether it waits until there is data.
                 * You can even set the wait timeout in tenths of a second.
                 * This sets indefinite wait mode. */
                raw.c_cc[VMIN] = 1;  /* Wait until at least one character available, */
                raw.c_cc[VTIME] = 0; /* Wait indefinitely. */
             
                /* Set the new terminal settings. */
                if (tcsetattr(fd, TCSAFLUSH, &raw))
                    return errno;
             
                /* tcsetattr() is happy even if it did not set *all* settings.
                 * We need to verify. */
                if (tcgetattr(fd, &actual)) {
                    const int saved_errno = errno;
                    /* Try restoring the old settings! */
                    tcsetattr(fd, TCSANOW, &old);
                    return errno = saved_errno;
                }
             
                if (actual.c_iflag != raw.c_iflag ||
                    actual.c_oflag != raw.c_oflag ||
                    actual.c_cflag != raw.c_cflag ||
                    actual.c_lflag != raw.c_lflag) {
                    /* Try restoring the old settings! */
                    tcsetattr(fd, TCSANOW, &old);
                    return errno = EIO;
                }
             
                /* Success! */
                return 0;
            }
             
            /* Call this to restore the saved state.
             *
             * The function returns 0 if success, errno error code otherwise.
            */
            static int stream_restore(FILE *const stream, const struct termios *const state)
            {
                int fd, result;
             
                if (!stream || !state)
                    return errno = EINVAL;
             
                /* Write/discard all buffered data in the stream. Ignores errors. */
                fflush(stream);
             
                /* Termios functions use the file descriptor. */
                fd = fileno(stream);
                if (fd == -1)
                    return errno = EINVAL;
             
                /* Discard all unread input and untransmitted output. */
                do {
                    result = tcflush(fd, TCIOFLUSH);
                } while (result == -1 && errno == EINTR);
             
                /* Restore terminal state. */
                do {
                    result = tcsetattr(fd, TCSAFLUSH, state);
                } while (result == -1 && errno == EINTR);
                if (result == -1)
                    return errno;
             
                /* Success. */
                return 0;
            }
int main(void)
{
    struct termios  saved;
    int             c;
 
    /* Make terminal at standard input unbuffered and raw. */
    if (stream_makeraw(stdin, &saved)) {
        fprintf(stderr, "Cannot make standard input raw: %s.\n", strerror(errno));
        return 1;
    }
 
    fprintf(stdout, "Press Q to quit.\n");
    fflush(stdout);
 
    do {
        c = getchar(); /* Or c = getc(stdin); */
        if (isprint(c))
            fprintf(stdout, "Received character '%c', code %d = 0%03o = 0x%02x\n", c, c, c, c);
        else
            fprintf(stdout, "Received code %d = 0%03o = 0x%02x\n", c, c, c);
        fflush(stdout);
    } while (c != 'Q');
 
    /* Restore terminal to original state. */
    if (stream_restore(stdin, &saved)) {
        fprintf(stderr, "Cannot restore standard input state: %s.\n", strerror(errno));
        return 1;
    }
 
    fprintf(stdout, "All done.\n");
    return 1;
}
