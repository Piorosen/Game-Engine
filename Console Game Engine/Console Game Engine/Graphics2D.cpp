#include "Graphics2D.h"
#include <iostream>


Engine::_2D::Graphics2D::Graphics2D()
{
}

void Engine::_2D::Graphics2D::Initialize(int Width, int Height)
{
	size.X = Width;
	size.Y = Height;
	pixel = new Draw::Graphic_Pixel*[size.Y];
	Drawed_pixel = new Draw::Graphic_Pixel*[size.Y];

	for (int i = 0; i < size.Y; i++) {
		pixel[i] = new Draw::Graphic_Pixel[size.X];
		Drawed_pixel[i] = new Draw::Graphic_Pixel[size.X];
	}

	for (int y = 0; y < Height; y++) {
		for (int x = 0; x < Width; x++) {
			pixel[y][x].SetPixel(Draw::Color(0x0, 0x0), ' ');
			Drawed_pixel[y][x].SetPixel(Draw::Color(0x0, 0x0), ' ');
		}
	}
}

void Engine::_2D::Graphics2D::Shutdown()
{
	for (int i = 0; i < size.Y; i++) {
		delete[] pixel[i];
	}
	delete[] pixel;

	for (int i = 0; i < size.Y; i++) {
		delete[] Drawed_pixel[i];
	}
	delete[] Drawed_pixel;
}

void Engine::_2D::Graphics2D::gotoxy(int x, int y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x & 0xffff, y & 0xffff });
}

void Engine::_2D::Graphics2D::gotoxy(Draw::Point pt)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pt.X & 0xffff, pt.Y & 0xffff });
}

void Engine::_2D::Graphics2D::SetColor(char textColor, char backColor)
{
	textColor &= 0xf;
	backColor &= 0xf;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (backColor << 4) | textColor);
}

void Engine::_2D::Graphics2D::SetColor(Draw::Color color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (color.BackColor << 4) | color.TextColor);
}

bool Engine::_2D::Graphics2D::Render()
{
	for (int y = 0; y < size.Y; y++) {
		for (int x = 0; x < size.X; x++) {
			if (pixel[y][x].Draw && pixel[y][x] != Drawed_pixel[y][x]) {
				gotoxy(x, y);
				SetColor(pixel[y][x].GetColor());
				putchar(pixel[y][x].GetText());
				Drawed_pixel[y][x] = pixel[y][x];
			}pixel[y][x].Draw = false;
		}
	}
	return true;
}
