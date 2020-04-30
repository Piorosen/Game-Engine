#include "Display.h"

int Graphics::Display::EraseCursor(bool isShowCursor, char *result, int index)
{
    int base = index;
    if (result == nullptr)
    {
        std::cout << (isShowCursor ? "\e[?25l" : "\e[?25h");
    }
    else
    {
        result[index++] = '\e';
        result[index++] = '[';
        result[index++] = '?';
        result[index++] = '2';
        result[index++] = '5';
        result[index++] = isShowCursor ? 'l' : 'h';
    }
    return index - base;
}

int Graphics::Display::FontColor(const Graphics::Color color, char *result, int index)
{
    int base = index;
    if (result == nullptr)
    {
        std::cout << "\033[" << (int)color.GetForground() << ";" << (int)color.GetBackground() << 'm';
    }
    else
    {
        int forg = (int)color.GetForground();
        int back = (int)color.GetBackground();

        result[index++] = '\033';
        result[index++] = '[';

        if (forg / 10 == 0)
        {
            result[index++] = forg + '0';
        }
        else
        {
            result[index++] = (forg / 10) + '0';
            result[index++] = (forg % 10) + '0';
        }
        result[index++] = ';';

        if (back / 10 == 0)
        {
            result[index++] = back + '0';
        }
        else
        {
            result[index++] = (back / 10) + '0';
            result[index++] = (back % 10) + '0';
        }
        result[index++] = 'm';
        result[index++] = '\0';
    }
    return index - base;
}

int Graphics::Display::GotoXY(Graphics::Point pt, char *result, int index)
{
    int base = index;

    pt.X += 1;
    pt.Y += 1;

    if (result == nullptr)
    {
        std::cout << "\033[" << ((pt.Y) & 0xffff) << ';' << ((pt.X) & 0xffff) << 'f';
    }
    else
    {
        result[index++] = '\033';
        result[index++] = '[';

        if (pt.Y / 10 == 0)
        {
            result[index++] = pt.Y + '0';
        }
        else
        {
            result[index++] = (pt.Y / 10) + '0';
            result[index++] = (pt.Y % 10) + '0';
        }

        result[index++] = ';';

        if (pt.X / 10 == 0)
        {
            result[index++] = pt.X + '0';
        }
        else
        {
            result[index++] = (pt.X / 10) + '0';
            result[index++] = (pt.X % 10) + '0';
        }

        result[index++] = 'f';
        result[index++] = '\0';
    }

    return index - base;
}

int Graphics::Display::ChangeTitle(const char *name, char *result, int index)
{
    int base = 0;
    if (result == nullptr)
    {
        std::cout << "\033]0;" << name << "\007";
    }
    else
    {
        char save[256] = {
            0,
        };

        sprintf(save, "\033]0;%s\007", name);
        strcat(result, save);
        index = (int)strlen(save);
    }
    return index - base;
}

int Graphics::Display::ResizeTerminal(Graphics::Size size, char *result, int index)
{
    this->Size = size;
    if (DisplayPixel != nullptr)
    {
        delete[] DisplayPixel;
        DisplayPixel = nullptr;
    }

    if (NewPixel != nullptr)
    {
        delete[] NewPixel;
        NewPixel = nullptr;
    }

    if (buffer != nullptr)
    {
        delete[] buffer;
        buffer = nullptr;
    }

    DisplayPixel = new Graphics::Pixel[size.X * size.Y];
    NewPixel = new Graphics::Pixel[size.X * size.Y];
    buffer = new char[size.X * size.Y * 30];

    for (int i = 0; i < Size.X * Size.Y; i++)
    {
        DisplayPixel[i] = Graphics::Pixel();
        NewPixel[i] = Graphics::Pixel();
    }
    int base = 0;
    if (result == nullptr)
    {
        std::cout << "\e[8;" << size.Y + 1 << ";" << size.X + 0 << "t";
        fflush(stdout);
    }
    else
    {
        char save[100] = {
            0,
        };

        sprintf(save, "\e[8;%d;%dt", size.Y, size.X);
        strcat(result, save);
        index = (int)strlen(save);
    }
    return index - base;
}

Graphics::Display::Display(Graphics::Size displaySize)
{
    EraseCursor(true);

    DisplayPixel = nullptr;
    NewPixel = nullptr;
    buffer = nullptr;

    Size = displaySize;
    ResizeTerminal(displaySize);
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

    for (int i = 0; i < size; i++)
    {
        buffer[i] = '\0';
    }
    int index = 0;
    for (int y = 0; y < Size.Y; y++)
    {
        index += GotoXY(Graphics::Point(0, y), buffer, index) - 1;

        for (int x = 0; x < Size.X; x++)
        {
            index += FontColor(NewPixel[y * Size.X + x].Color, buffer, index) - 1;
            buffer[index++] = NewPixel[y * Size.X + x].Ascii;
        }
    }
    buffer[index++] = '\0';
    puts(buffer);
    fflush(stdout);
    fflush(stderr);
}

void Graphics::Display::ReDraw()
{
    EventDraw.Invoke(NewPixel, Size);
    Draw();
}