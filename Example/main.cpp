#include <iostream>

#include "Window.h"

#include "UnitTest/TestModule.h"

using namespace std;
using namespace Graphics;

Window* window = Window::Instance();

int main() {
    Graphics::Rectangle r(Point(20, 20), Size(10, 10));

    while (true) {
        window->Clear();
        r.Rotate(Point(15, 15), 5);
        window->Draw(r);
        Sleep(100);
    }
}