#pragma once

#include <thread>

#include "Enviroment.h"
#include "Vector.h"
#include "Color.h"
#include "Display.h"
#include "Pixel.h"
#include "Point.h"
#include "Vector.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "EventHandler.h"

#include "Shape/Rectangle.h"

namespace Graphics
{
class Window
{
protected:
    Window() {}

    // Raster 쉐이더로 옮길 예정.
    void drawLine(Graphics::Point x, Graphics::Point y)
    {
        int dx, dy;
        int p_value;
        int inc_2dy;
        int inc_2dydx;
        int inc_value;
        int ndx;

        dx = abs(y.X - x.X);
        dy = abs(y.Y - x.Y);

        if (dy <= dx)
        {
            inc_2dy = 2 * dy;
            inc_2dydx = 2 * (dy - dx);

            if (y.X < x.X)
            {
                ndx = x.X;
                x.X = y.X;
                y.X = ndx;

                ndx = x.Y;
                x.Y = y.Y;
                y.Y = ndx;
            }
            if (x.Y < y.Y)
                inc_value = 1;
            else
                inc_value = -1;

            
            Display::Instance()->SetPixel(x, Pixel('*'));
            // display[x.Y][x.X] = '*';


            p_value = 2 * dy - dx;
            for (ndx = x.X; ndx < y.X; ndx++)
            {
                if (0 > p_value)
                    p_value += inc_2dy;
                else
                {
                    p_value += inc_2dydx;
                    x.Y += inc_value;
                }
                Display::Instance()->SetPixel(Point(ndx, x.Y), Pixel('*'));
                // display[x.Y][ndx] = '*';
            }
        }
        else
        {
            inc_2dy = 2 * dx;
            inc_2dydx = 2 * (dx - dy);

            if (y.Y < x.Y)
            {
                ndx = x.Y;
                x.Y = y.Y;
                y.Y = ndx;

                ndx = x.X;
                x.X = y.X;
                y.X = ndx;
            }
            if (x.X < y.X)
                inc_value = 1;
            else
                inc_value = -1;

            
            Display::Instance()->SetPixel(x, Pixel('*'));
            // display[x.Y][x.X] = '*';
            
            
            p_value = 2 * dx - dy;
            for (ndx = x.Y; ndx < y.Y; ndx++)
            {
                if (0 > p_value)
                    p_value += inc_2dy;
                else
                {
                    p_value += inc_2dydx;
                    x.X += inc_value;
                }
                Display::Instance()->SetPixel(Point(x.X, ndx), Pixel('*'));
                // display[ndx][x.X] = '*';
            }
        }
    }
    void drawTriangle(Point a, Point b, Point c)
    {
        drawLine(a, b);
        drawLine(b, c);
        drawLine(c, a);
    }

    std::thread input;

    bool suspend = true;
    void Refresh();

public: 
    Keyboard keyboard;
    Mouse mouse;

    static Window* Instance() {
        static Window* inst = new Window();
        Display::Instance()->ResizeTerminal(Size(40, 40));
        Display::Instance()->EraseCursor(true);
        Display::Instance()->ReDraw();
        return inst;
    }

    void SessionStart();
    void SessionClose();

    void Draw(const Shape object);
};

} // namespace Graphics