#include <iostream>

#include "Window.h"

#include "UnitTest/TestModule.h"

using namespace std;
using namespace Graphics;

Window* window = Window::Instance();
Rectangle r(Point(15, 15), Size(20, 20));
double degree = 0;


void test(unsigned short a){
    
    if (a == 'a'){ 
        degree = -5;
    }else if (a == 'd') {
        degree = 5;
    }else {
        degree = 0;
    }
    Display::Instance()->Clear();
    r.Rotate(Point(r.Location.X + r.Scale.X / 2, r.Location.Y + r.Scale.Y / 2), degree);
    window->Draw(r);
}

int main() {
    std::cout << "TEST";
    runTest();
    Keyboard a;
    a.EventKeyDown += test;

    for (int i = 0; ; i++){
        a.Refresh(nullptr);
    }
}