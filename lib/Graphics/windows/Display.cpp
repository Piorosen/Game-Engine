#include "Display.h"

void Graphics::Output::Display::ChangeTitle(const char* name)
{
    SetConsoleTitle(name);
}

void Graphics::Output::Display::ResizeTerminal(Graphics::Library::Size size)
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
    char text[256];
    sprintf(text, "mode con:lines=%d cols=%d", Size.Y, Size.X);
    system(text);
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

Graphics::Output::Display::~Display() {
    
    if (DisplayPixel == nullptr){
        delete[] DisplayPixel;
        DisplayPixel = nullptr;
    }

    if (NewPixel == nullptr){
        delete[] NewPixel;
        NewPixel = nullptr;
    }
    
    if (buffer == nullptr){
        delete[] buffer;
        buffer = nullptr;
    }
}


void Graphics::Output::Display::Clear()
{
    system("cls");
}

void Graphics::Output::Display::Draw() {
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
}

void Graphics::Output::Display::ReDraw()
{
    EventDraw.Invoke(NewPixel, Size);
    Draw();
}
