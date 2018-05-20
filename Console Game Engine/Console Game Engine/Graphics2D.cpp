#include "Graphics2D.h"

Engine::_2D::_2DGraphics::_2DGraphics()
{
}

void Engine::_2D::_2DGraphics::Initialize(int Width, int Height)
{
	size.X = Width;
	size.Y = Height;
	*pixel = new Draw::Graphic_Pixel[size.Y];
	for (int i = 0; i < size.Y; i++) {
		pixel[i] = new Draw::Graphic_Pixel[size.X];
	}

}

void Engine::_2D::_2DGraphics::Shutdown()
{
	for (int i = 0; i < size.Y; i++) {
		delete[] pixel[i];
	}
	delete[] pixel;
}

void Engine::_2D::_2DGraphics::gotoxy(int x, int y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x & 0xffff, y & 0xffff });
}

void Engine::_2D::_2DGraphics::gotoxy(Draw::Point pt)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pt.X & 0xffff, pt.Y & 0xffff });
}

void Engine::_2D::_2DGraphics::SetColor(char textColor, char backColor)
{
	textColor &= 0xf;
	backColor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (backColor << 4) | textColor);
}

void Engine::_2D::_2DGraphics::SetColor(Draw::Color color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (color.BackColor << 4) | color.TextColor);
}

void Engine::_2D::_2DGraphics::Render()
{
}
