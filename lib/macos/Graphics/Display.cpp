#include "Display.h"

void Graphics::Display::EraseCursor(bool isShowCursor)
{
    buffer[index++] = '\e';
    buffer[index++] = '[';
    buffer[index++] = '?';
    buffer[index++] = '2';
    buffer[index++] = '5';
    buffer[index++] = isShowCursor ? 'l' : 'h';
}

void Graphics::Display::FontColor(const Graphics::Color color)
{

    int forg = (int)color.GetForground();
    int back = (int)color.GetBackground();

    buffer[index++] = '\033';
    buffer[index++] = '[';

    if (forg / 10 == 0)
    {
        buffer[index++] = forg + '0';
    }
    else
    {
        buffer[index++] = (forg / 10) + '0';
        buffer[index++] = (forg % 10) + '0';
    }
    buffer[index++] = ';';

    if (back / 10 == 0)
    {
        buffer[index++] = back + '0';
    }
    else
    {
        buffer[index++] = (back / 10) + '0';
        buffer[index++] = (back % 10) + '0';
    }
    buffer[index++] = 'm';
    buffer[index++] = '\0';
}

void Graphics::Display::GotoXY(Graphics::Point pt)
{
    pt.X += 1;
    pt.Y += 1;

    buffer[index++] = '\033';
    buffer[index++] = '[';

    if (pt.Y / 10 == 0)
    {
        buffer[index++] = pt.Y + '0';
    }
    else
    {
        buffer[index++] = (pt.Y / 10) + '0';
        buffer[index++] = (pt.Y % 10) + '0';
    }

    buffer[index++] = ';';

    if (pt.X / 10 == 0)
    {
        buffer[index++] = pt.X + '0';
    }
    else
    {
        buffer[index++] = (pt.X / 10) + '0';
        buffer[index++] = (pt.X % 10) + '0';
    }

    buffer[index++] = 'f';
    buffer[index++] = '\0';
}

void Graphics::Display::ChangeTitle(const char *name)
{
    int base = 0;
    char save[256] = {
        0,
    };

    sprintf(save, "\033]0;%s\007", name);
    strcat(buffer, save);
    index += (int)strlen(save);
}

void Graphics::Display::ResizeTerminal(Graphics::Size size)
{
    this->Size = size;

    if (NewPixel != nullptr)
    {
        delete[] NewPixel;
        NewPixel = nullptr;
    }

    NewPixel = new Graphics::Pixel[size.X * size.Y];

    if (buffer != nullptr)
    {
        delete[] buffer;
        buffer = nullptr;
    }
    buffer = new char[size.X * size.Y * 30];

    for (int i = 0; i < Size.X * Size.Y; i++)
    {
        NewPixel[i] = Graphics::Pixel();
    }
    int base = 0;

    char save[100] = {
        0,
    };

    sprintf(save, "\e[8;%d;%dt", size.Y + 2, size.X);
    strcat(buffer, save);
    index += (int)strlen(save);
}

void Graphics::Display::Write(const char *text)
{
    strcat(buffer, text);
    index += (int)strlen(text);
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

Graphics::Display::Display()
{
    DisplayPixel = nullptr;
    NewPixel = nullptr;

    buffer = nullptr;
    index = 0;
}

Graphics::Display::~Display()
{

    if (DisplayPixel == nullptr)
    {
        delete[] DisplayPixel;
        DisplayPixel = nullptr;
    }

    if (NewPixel == nullptr)
    {
        delete[] NewPixel;
        NewPixel = nullptr;
    }

    if (buffer == nullptr)
    {
        delete[] buffer;
        buffer = nullptr;
    }
}

void Graphics::Display::Clear()
{
    system("clear");
}

void Graphics::Display::Draw()
{
    int size = Size.X * Size.Y * 30;

    int tty;
    int ttx;

    for (int y = 0; y < Size.Y; y++)
    {
        GotoXY(Graphics::Point(0, y));
        index -= 1;
        tty = strlen(buffer);

        for (int x = 0; x < Size.X; x++)
        {
            FontColor(NewPixel[y * Size.X + x].Color);
            index -= 1;
            ttx = strlen(buffer);
            buffer[index++] = NewPixel[y * Size.X + x].Ascii ? NewPixel[y * Size.X + x].Ascii : ' ';
        }
    }
    buffer[index++] = '\0';
    puts(buffer);
    fflush(stdout);
    fflush(stderr);

    index = 0;
    for (int i = 0; i < size; i++)
    {
        buffer[i] = '\0';
    }
}

void Graphics::Display::ReDraw()
{
    Draw();
}