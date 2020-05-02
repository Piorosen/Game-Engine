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
    curColor = color;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (((int)color.GetBackground() & 0xf) << 4) | ((int)color.GetForground() & 0xf));
}

void Graphics::Display::GotoXY(Graphics::Point pt)
{
    curPosition = pt;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { (short)pt.X, (short)pt.Y });
}

void Graphics::Display::ChangeTitle(const char* name)
{
    SetConsoleTitle(name);
}

void Graphics::Display::ResizeTerminal(Graphics::Size size)
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

    DisplayPixel = new Graphics::Pixel[size.X * size.Y];
    NewPixel = new Graphics::Pixel[size.X * size.Y];
    
    char text[256];
    sprintf(text, "mode con:lines=%d cols=%d", Size.Y, Size.X);
    system(text);
}

void Graphics::Display::Write(const char* text){
    int len = (int)strlen(text);
    for (int i = 0; i < len; i++){
         NewPixel[curPosition.Y * Size.X + curPosition.X].SetPixel(curColor, text[i]);
         curPosition.X++;
         if (curPosition.X >= Size.X){
             curPosition.X -= Size.X;
             curPosition.Y += 1;
         }
    }
}

bool Graphics::Display::SetPixel(const Graphics::Point pt, const Graphics::Pixel value){
    int range = pt.Y * Size.X + pt.X;
    if (0 <= range && range < Size.X * Size.Y) {
		NewPixel[pt.Y * Size.X + pt.X] = value;
        return true;
    }
    return false;
}

Graphics::Pixel Graphics::Display::GetPixel(const Graphics::Point pt) const{
    int range = pt.Y * Size.X + pt.X;
    if (0 <= range && range < Size.X * Size.Y) {
        return NewPixel[pt.Y * Size.X + pt.X];
    }
    return Graphics::Pixel();
}

Graphics::Display::Display() {
    DisplayPixel = nullptr;
    NewPixel = nullptr;
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
				DisplayPixel[y * Size.X + x] = NewPixel[y * Size.X + x];
				
                prev = Graphics::Point(x, y);
            }
			NewPixel[y * Size.X + x] = Pixel();
        }
    }

}

void Graphics::Display::ReDraw()
{
    Draw();
}
