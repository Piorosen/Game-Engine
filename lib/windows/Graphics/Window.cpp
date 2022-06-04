#include "Window.h"

void Graphics::Window::Clear()
{
    Display::Instance()->Clear();
}

void Graphics::Window::Draw(const Shape object)
{
    int size = object.GetIndics() / 3;
    Vector* vertex = object.GetVertex();

    for (int i = 0; i < size; i++)
    {
        drawTriangle(Point(vertex[i * 3].X, vertex[i * 3].Y), Point(vertex[i * 3 + 1].X, vertex[i * 3 + 1].Y), Point(vertex[i * 3 + 2].X, vertex[i * 3 + 2].Y));
    }
    Display::Instance()->ReDraw();
}
