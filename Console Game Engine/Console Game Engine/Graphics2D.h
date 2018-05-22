#pragma once
#include <Windows.h>

#include "DrawLibrary.h"
#include "Color.h"
#include "Model2D.h"

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
			inline void SetPixel(int X, int Y, Draw::Color c, char ch) {
				pixel[Y][X].SetPixel(c, ch);
			}
			inline void SetPixel(Draw::Point pt, Draw::Color c, char ch) {
				pixel[pt.Y][pt.X].SetPixel(c, ch);
			}
			Graphics2D();

			void Initialize(int, int);
			void Shutdown();

			void gotoxy(int x, int y);
			void gotoxy(Draw::Point pt);

			void SetColor(char textColor, char backColor);
			void SetColor(Draw::Color color);

			void DrawModel(Model2D model, int xLange = 1) {
				for (int y = model.Location.Y; y < model.Size.Y + model.Location.Y; y++) {
					for (int x = model.Location.X; x < model.Size.X + model.Location.X; x++) {
						if (y == model.Location.Y || y == model.Location.Y + model.Size.Y - 1) {
							if (pixel[y][x].Color != model.Outer)
								SetPixel(x, y, model.Inner, model.Text);
						}
						else if (x / xLange == model.Location.X / xLange ||
							x / xLange == (model.Size.X + model.Location.X - 1) / xLange) {
							if (pixel[y][x].Color != model.Outer)
								SetPixel(x, y, model.Inner, model.Text);
						}
						else {
							if (pixel[y][x].Color != model.Inner)
								SetPixel(x, y, model.Outer, model.Text);
						}
					}
				}
			}

			void ScreenClear(Draw::Color color = Draw::Color(Draw::ColorList::Black, Draw::ColorList::Black)) {
				auto chk = color;
				SetColor(color);
				for (int y = 0; y < size.Y; y++)
					for (int x = 0; x < size.X; x++)
						if (pixel[y][x].Color != chk)
							pixel[y][x].SetPixel(Draw::Color(Draw::ColorList::Black, Draw::ColorList::Black), ' ');
			}

			bool Render();

		};
	}
}