#include "Window.h"

void Graphics::Window::Refresh()
{
    while (!suspend)
    {
        keyboard.Refresh(nullptr);
        mouse.Refresh(nullptr);
    }
}

void Graphics::Window::SessionStart()
{
    if (suspend == true)
    {
        input = std::thread(&Window::Refresh, this);
        suspend = false;
        input.join();
    }
}

void Graphics::Window::SessionClose()
{
    suspend = true;
    input.detach();
}

void Graphics::Window::Draw(const Shape object)
{
    int size = object.GetIndics() / 3;
    Vector *vertex = object.GetVertex();

    for (int i = 0; i < size; i++)
    {
        drawTriangle(Point(vertex[i * 3].X, vertex[i * 3].Y), Point(vertex[i * 3 + 1].X, vertex[i * 3 + 1].Y), Point(vertex[i * 3 + 2].X, vertex[i * 3 + 2].Y));
    }
    Display::Instance()->ReDraw();
}