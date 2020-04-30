#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
 
#include "Keyboard.h"

static struct termios initial_settings, new_settings;
static int peek_character = -1;
 
void close_keyboard()
{
    tcsetattr(0, TCSANOW, &initial_settings);
}
 
int _kbhit()
{
    unsigned char ch;
    int nread;
 
    if (peek_character != -1) return 1;
    new_settings.c_cc[VMIN]=0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0,&ch,1);
    new_settings.c_cc[VMIN]=1;
    tcsetattr(0, TCSANOW, &new_settings);
    if(nread == 1)
    {
        peek_character = ch;
        return 1;
    }
    return 0;
}
 
int _getch()
{
    char ch;
 
    if(peek_character != -1)
    {
        ch = peek_character;
        peek_character = -1;
        return ch;
    }
    read(0,&ch,1);
    return ch;
}
 

void Graphics::Input::Keyboard::KeyUp(unsigned short ch)
{
	Key[ch] = false;
	EventKeyUp.Invoke(ch);
	EventKeyChanged.Invoke(ch, false);
}

void Graphics::Input::Keyboard::KeyDown(unsigned short ch)
{
	Key[ch] = true;
	EventKeyDown.Invoke(ch);
	EventKeyChanged.Invoke(ch, true);
}

Graphics::Input::Keyboard::Keyboard()
{
	tcgetattr(0,&initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);

	for (int i = 0; i < sizeof(Key) / sizeof(bool); i++)
	{
		Key[i] = false;
	}
}

void Graphics::Input::Keyboard::Refresh(void *data)
{
	while(_kbhit()){
		char p = _getch();
		KeyDown(p);
		KeyUp(p);
	}
}