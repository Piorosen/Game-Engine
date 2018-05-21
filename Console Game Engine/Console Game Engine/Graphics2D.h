#pragma once
#include <Windows.h>

#include "DrawLibrary.h"
#include "Color.h"



namespace Engine {
	namespace _2D{
		class Graphics2D
		{
		private:
			Draw::Size size;
			Draw::Color NowColor;
			// [Y][X]
			Draw::Graphic_Pixel** pixel;
			Draw::Graphic_Pixel** Drawed_pixel;
			
		public:
			inline void SetPixel(Draw::Point pt, Draw::Color c, std::string ch) {
				pixel[pt.Y][pt.X].SetPixel(c, ch);
			}
			inline void SetPixel(int X, int Y, Draw::Color c, std::string ch) {
				pixel[Y][X].SetPixel(c, ch);
			}
			Graphics2D();

			void Initialize(int, int);
			void Shutdown();

			void gotoxy(int x, int y);
			void gotoxy(Draw::Point pt);

			void SetColor(char textColor, char backColor);
			void SetColor(Draw::Color color);

			void ScreenClear() {
				SetColor(0, 0);
				system("cls");
			}

			bool Render();

		};
	}
}