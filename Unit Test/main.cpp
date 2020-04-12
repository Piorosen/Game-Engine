#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#define OUTPUT_CONSOLE
#include "TestModule.hpp"
#include "GraphicsTest.h"
#include "Graphics.h"

using namespace Graphics::Library;
using namespace Graphics::Output;

int color = 0;

void test(Graphics::Output::Pixel* p, Graphics::Library::Size s){
    color++;
    for (int y = 0; y < s.Y; y++){
        for (int x = 0; x < s.X; x++){
            if (y == 0 || x == 0 || y == s.Y - 1 || x == s.X - 1){
                if (color % 2 == 0){
                     p[y * s.X + x].SetPixel(Color(ColorForground::White, ColorBackground::White), ' ');
                }else {
                    p[y * s.X + x].SetPixel(Color(ColorForground::Green, ColorBackground::Green), ' ');
                }
            }else {
                if (color % 2 == 0){
                     p[y * s.X + x].SetPixel(Color(ColorForground::Red, ColorBackground::Red), ' ');
                }else {
                    p[y * s.X + x].SetPixel(Color(ColorForground::Blue, ColorBackground::Blue), ' ');
                }
            }
        }
    }
}

int main()
{
    Config();
    GrahpicsTest();
    srand((unsigned int)time(0));

    

	Terminal t = Terminal(Graphics::Library::Size(80, 30));
    t.Display.EventDraw += test;
    t.Display.Cursor.EraseCursor(true);
    t.Display.Hz = 10;
    long long s = clock() / (CLOCKS_PER_SEC / 1000);
    long long e = clock() / (CLOCKS_PER_SEC / 1000);
    
    while (true) {
        while (e - s < 1000 / t.Display.Hz) {
            e = clock() / (CLOCKS_PER_SEC / 1000);
        }
        t.Display.ReDraw();
        s = e;
    }
    
    return 0;


}
//

