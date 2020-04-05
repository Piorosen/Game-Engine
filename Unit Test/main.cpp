#include <iostream>

#define OUTPUT_CONSOLE
// #define OUTPUT_FILE
#include "Graphics.h"

#include "TestModule.hpp"
#include "GraphicsTest.h"

using namespace Graphics::Library;
int a = 0, b = 5;
void func1(Graphics::Output::Pixel*, Size) {
	Graphics::Output::Cursor::FontColor(Color(ColorForground::Blue, ColorBackground::Red));

	Graphics::Output::Cursor::GotoXY(Point(2, 3));
	printf("%d", a++);
}


void func2(Graphics::Output::Pixel*, Graphics::Library::Size) {
	Graphics::Output::Cursor::FontColor(Color(ColorForground::Yellow, ColorBackground::Black));

	Graphics::Output::Cursor::GotoXY(Graphics::Library::Point(5, 8));
	printf("%d", b);
	b += 10;
}

int main()
{
	Graphics::Output::Dispaly d;

	d.EventDraw += func1;
	d.EventDraw += func2;

	d.MainLoop();

	Config();
	GrahpicsTest();
}