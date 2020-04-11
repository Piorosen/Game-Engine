#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#define OUTPUT_CONSOLE
// #define OUTPUT_FILE
#include "Graphics.h"
#include "TestModule.hpp"
#include "GraphicsTest.h"

using namespace Graphics::Output;

void test(Graphics::Output::Pixel* p, Graphics::Library::Size s){
    for (int y = 0; y < s.Y; y++){
        for (int x = 0; x < s.X; x++){
            
            ColorForground f = (ColorForground)(rand() % 8 + 30);
            ColorBackground b = (ColorBackground)(rand() % 8 + 40);
            
            p[y * s.X + x].SetPixel(Color(f, b), ' ');
        }
    }   
}

int main()
{
    
    Config();
    GrahpicsTest();
    
    return 0;
}
