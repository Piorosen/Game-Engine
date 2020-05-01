#include <iostream>

#include "Window.h"
#include "UnitTest/TestModule.h"

using namespace std;
using namespace Graphics;

int main() {
    std::cout << "TEST";
    runTest();
    
    auto window = Window::Instance();
    Rectangle r = Rectangle(Point(0,0), Size(30, 30));
    window->Draw(r);

}