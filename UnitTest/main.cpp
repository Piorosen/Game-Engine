#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define OUTPUT_CONSOLE

#include "Terminal.h"


#include "TestModule.hpp"
#include "GraphicsTest.h"


using namespace Graphics::Library;
using namespace Graphics::Output;
using namespace Graphics::Input;


int color = 0;

void test(Graphics::Output::Pixel* p, Graphics::Library::Size s){
    color++;
    for (int y = 0; y < s.Y; y++){
        for (int x = 0; x < s.X; x++){
            if (y == 0 || x == 0 || y == s.Y - 1 || x == s.X - 1){
                if (color % 2 == 0){
                     p[y * s.X + x].SetPixel(Color(ColorForground::White, ColorBackground::White), 'A');
                }else {
                    p[y * s.X + x].SetPixel(Color(ColorForground::Green, ColorBackground::Green), 'B');
                }
            }else {
                if (color % 2 == 0){
                     p[y * s.X + x].SetPixel(Color(ColorForground::Red, ColorBackground::Red), 'C');
                }else {
                    p[y * s.X + x].SetPixel(Color(ColorForground::Blue, ColorBackground::Blue), 'D');
                }
            }
        }
    }
}

void mouse(MouseEvent* event, unsigned char size){
    for (int i = 0; i < size; i++){
        std::cout << (int)event[i].GetMouseButton() << " {" << event[i].Position.X << ", " << event[i].Position.Y << "} " << event[i].Pressed << std::endl;
    }
    std::cout << std::endl;
}

void keyboard(unsigned short key, bool state) {
	std::cout << key << " " << state << std::endl;
}

int main()
{
    // Config();
    // GrahpicsTest();
    // srand((unsigned int)time(0));

    Terminal t = Terminal(Graphics::Library::Size(80, 30));
    t.Display.Cursor.EraseCursor(true);

    t.Display.Hz = 10;

	t.Display.EventDraw += test;
    t.Mouse.EventKeyChanged += mouse;
	t.Keyboard.EventKeyChanged += keyboard;

    long long s = clock() / (CLOCKS_PER_SEC / 1000);
    long long e = clock() / (CLOCKS_PER_SEC / 1000);
    
    while (true) {
        while (e - s < 1000 / t.Display.Hz) {
            
            // t.RefreshInputDevice();
            e = clock() / (CLOCKS_PER_SEC / 1000);
        }
        t.Display.ReDraw();
        s = e;
    }

    return 0;
}
//

