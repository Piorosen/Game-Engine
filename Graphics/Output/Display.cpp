#include "Display.h"

#if OS_MAC || OS_LINUX
int Graphics::Output::Display::ResizeTerminal(Graphics::Library::Size size, char* result, int index)
#elif OS_WINDOWS
void Graphics::Output::Display::ResizeTerminal(Graphics::Library::Size size)
#endif
{
    this->Size = size;
    if (DisplayPixel != nullptr) {
        delete[] DisplayPixel;
        DisplayPixel = nullptr;
    }

    if (NewPixel != nullptr) {
        delete[] NewPixel;
        NewPixel = nullptr;
    }
    
    if (buffer != nullptr) {
        delete[] buffer;
        buffer = nullptr;
    }

    DisplayPixel = new Graphics::Output::Pixel[size.X * size.Y];
    NewPixel = new Graphics::Output::Pixel[size.X * size.Y];
    buffer = new char[size.X * size.Y * 30];
    
    for (int i = 0; i < Size.X * Size.Y; i++) {
        DisplayPixel[i] = Graphics::Output::Pixel();
        NewPixel[i] = Graphics::Output::Pixel();
    }
#if OS_MAC || OS_LINUX
    if (result == nullptr) {
        std::cout << "\e[8;" << size.Y + 1 << ";" << size.X << "t";
    }
    else {
        char save[100] = { 0, };

        sprintf(save, "\e[8;%d;%dt", size.Y, size.X);
        strcat(result, save);
        index = (int)strlen(save);
    }
    return index;
#elif OS_WINDOWS
    char text[256];
    sprintf(text, "mode con:lines=%d cols=%d", Size.Y, Size.X);
    system(text);
#endif
}


Graphics::Output::Display::Display(Graphics::Library::Size displaySize) {
    Cursor.EraseCursor(true);
    
    DisplayPixel = nullptr;
    NewPixel = nullptr;
    buffer = nullptr;
    
    Size = displaySize;
    this->Cursor = Graphics::Output::Cursor();
    ResizeTerminal(displaySize);
}


void Graphics::Output::Display::Clear()
{
#if OS_MAC || OS_LINUX
    system("clear");
#elif OS_WINDOWS
    system("cls");
#endif
}

void Graphics::Output::Display::Draw() {
#if OS_MAC || OS_LINUX
    int size = Size.X * Size.Y * 30;
    

    for (int i = 0; i < size; i++) {
        buffer[i] = '\0';
    }

    int index = 0;
    for (int y = 0; y < Size.Y; y++) {
        index += Cursor.GotoXY(Graphics::Library::Point(0, y), buffer, index);
        index--;
        for (int x = 0; x < Size.X; x++) {
            index += Cursor.FontColor(NewPixel[y * Size.X + x].Color, buffer, index);
            index--;
            buffer[index++] = NewPixel[y * Size.X + x].Ascii;
        }
    }
    buffer[index++] = '\0';
    puts(buffer);
    fflush(stdout);
    fflush(stderr);
    
#elif OS_WINDOWS
    Graphics::Library::Point prev(0, 0);

    for (int y = 0; y < Size.Y; y++) {
        for (int x = 0; x < Size.X; x++) {
            if (DisplayPixel[y * Size.X + x] != NewPixel[y * Size.X + x]) {
                if (Graphics::Library::Point(x - 1, y) != prev) {
                    Cursor.GotoXY(Graphics::Library::Point(x, y));
                }

                Cursor.FontColor(NewPixel[y * Size.X + x].Color);
                putchar(NewPixel[y * Size.X + x].Ascii);
                prev = Graphics::Library::Point(x, y);
            }
        }
    }
#endif
}

void Graphics::Output::Display::ReDraw()
{
    EventDraw.Invoke(NewPixel, Size);
    Draw();
}
