#include "Display.h"

int Graphics::Output::Display::ChangeTitle(const char *name, char *result, int index)
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

int Graphics::Output::Display::ResizeTerminal(Graphics::Library::Size size, char *result, int index)
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

    DisplayPixel = new Graphics::Output::Pixel[size.X * size.Y];
    NewPixel = new Graphics::Output::Pixel[size.X * size.Y];
    buffer = new char[size.X * size.Y * 30];

    for (int i = 0; i < Size.X * Size.Y; i++)
    {
        DisplayPixel[i] = Graphics::Output::Pixel();
        NewPixel[i] = Graphics::Output::Pixel();
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

Graphics::Output::Display::Display(Graphics::Library::Size displaySize)
{
    Cursor.EraseCursor(true);

    DisplayPixel = nullptr;
    NewPixel = nullptr;
    buffer = nullptr;

    Size = displaySize;
    this->Cursor = Graphics::Output::Cursor();
    ResizeTerminal(displaySize);
}

Graphics::Output::Display::~Display()
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

void Graphics::Output::Display::Clear()
{
    system("clear");
}

void Graphics::Output::Display::Draw()
{
    int size = Size.X * Size.Y * 30;

    for (int i = 0; i < size; i++)
    {
        buffer[i] = '\0';
    }
    int index = 0;
    for (int y = 0; y < Size.Y; y++)
    {
        index += Cursor.GotoXY(Graphics::Library::Point(0, y), buffer, index) - 1;

        for (int x = 0; x < Size.X; x++)
        {
            index += Cursor.FontColor(NewPixel[y * Size.X + x].Color, buffer, index) - 1;
            buffer[index++] = NewPixel[y * Size.X + x].Ascii;
        }
    }
    buffer[index++] = '\0';
    puts(buffer);
    fflush(stdout);
    fflush(stderr);
}

void Graphics::Output::Display::ReDraw()
{
    EventDraw.Invoke(NewPixel, Size);
    Draw();
}
