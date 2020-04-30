#include "Display.h"

void Graphics::Display::EraseCursor(bool isShowCursor)
{
	CONSOLE_CURSOR_INFO cursorinfo = { 0, };
	cursorinfo.dwSize = 1;
	cursorinfo.bVisible = !isShowCursor;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorinfo);
}

void Graphics::Display::FontColor(const Graphics::Color color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (((int)color.GetBackground() & 0xf) << 4) | ((int)color.GetForground() & 0xf));
}


void Graphics::Display::GotoXY(Graphics::Point pt)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)pt.X, (short)pt.Y });
}


void Graphics::Display::ChangeTitle(const char* name)
{
    SetConsoleTitle(name);
}

void Graphics::Display::ResizeTerminal(Graphics::Size size)
{
    // Enviroment::TerminalSize = size;
    
    this->Size = size;
    if (DisplayPixel != nullptr) {
        delete[] DisplayPixel;
        DisplayPixel = nullptr;
    }

    if (NewPixel != nullptr) {
        delete[] NewPixel;
        NewPixel = nullptr;
    }

    DisplayPixel = new Graphics::Pixel[size.X * size.Y];
    NewPixel = new Graphics::Pixel[size.X * size.Y];
    
    for (int i = 0; i < Size.X * Size.Y; i++) {
        DisplayPixel[i] = Graphics::Pixel();
        NewPixel[i] = Graphics::Pixel();
    }
    char text[256];
    sprintf(text, "mode con:lines=%d cols=%d", Size.Y, Size.X);
    system(text);
}


Graphics::Display::Display(Graphics::Size displaySize) {
    EraseCursor(true);
    
    DisplayPixel = nullptr;
    NewPixel = nullptr;
    
    Size = displaySize;
    ResizeTerminal(displaySize);
}

Graphics::Display::~Display() {
    
    if (DisplayPixel == nullptr){
        delete[] DisplayPixel;
        DisplayPixel = nullptr;
    }

    if (NewPixel == nullptr){
        delete[] NewPixel;
        NewPixel = nullptr;
    }
    
}


void Graphics::Display::Clear()
{
    system("cls");
}

void Graphics::Display::Draw() {
    Graphics::Point prev(0, 0);

    for (int y = 0; y < Size.Y; y++) {
        for (int x = 0; x < Size.X; x++) {
            if (DisplayPixel[y * Size.X + x] != NewPixel[y * Size.X + x]) {
                if (Graphics::Point(x - 1, y) != prev) {
                    GotoXY(Graphics::Point(x, y));
                }

                FontColor(NewPixel[y * Size.X + x].Color);
                putchar(NewPixel[y * Size.X + x].Ascii);
                prev = Graphics::Point(x, y);
            }
        }
    }
}

void Graphics::Display::ReDraw()
{
    EventDraw.Invoke(NewPixel, Size);
    Draw();
}
