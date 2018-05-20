#pragma once
#include <Windows.h>

#include "Draw.h"
#include "Color.h"



namespace Engine {
	namespace _2D{
		class Graphics2D
		{
			 


		private:
			Draw::Size size;
			// [Y][X]
			static Draw::Graphic_Pixel** pixel;



			void Frame();

			

		public:
			inline void SetPixel(Draw::Point pt, Draw::Color c, TCHAR ch) {
				pixel[pt.Y][pt.X].SetPixel(c, ch);
			}



			Graphics2D();

			void Initialize(int, int);
			void Shutdown();

			void gotoxy(int x, int y);
			void gotoxy(Draw::Point pt);
			void SetColor(char textColor, char backColor);
			void SetColor(Draw::Color color);



			bool Render();

		};
	}
}