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
				for (size_t i = 0; i < ch.length(); i++) {
					pixel[pt.Y][pt.X + i].SetPixel(c, ch[i]);
				}
			}
			inline void SetPixel(int X, int Y, Draw::Color c, std::string ch) {
				for (size_t i = 0; i < ch.length(); i++) {
					pixel[Y][X + i].SetPixel(c, ch[i]);
				}
			}
			Graphics2D();

			void Initialize(int, int);
			void Shutdown();

			void gotoxy(int x, int y);
			void gotoxy(Draw::Point pt);

			void SetColor(char textColor, char backColor);
			void SetColor(Draw::Color color);

			void ScreenClear() {
				auto chk = Draw::Color(Draw::ColorList::Black, Draw::ColorList::Black);
				SetColor(0, 0);
				for (int y = 0; y < size.Y; y++) {
					for (int x = 0; x < size.X; x++) {
						if (pixel[y][x].GetColor() != chk)
							pixel[y][x].SetPixel(Draw::Color(Draw::ColorList::Black, Draw::ColorList::Black), ' ');
					}
				}
			}

			bool Render();

		};
	}
}