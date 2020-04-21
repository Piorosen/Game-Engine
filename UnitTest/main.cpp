#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define OUTPUT_CONSOLE

#include "Terminal.h"

#include "TestModule.hpp"
#include "GraphicsTest.h"


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

    

    return 0;


}
//

