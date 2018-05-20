#pragma once
#include <Windows.h>

#include "Draw.h"
#include "Color.h"



namespace Engine {
	namespace _2D{
		class _2DGraphics
		{
			 


		private:
			Draw::Size size;
			Draw::Graphic_Pixel** pixel;



			void Frame();

			

		public:
			_2DGraphics();

			void Initialize(int, int);
			void Shutdown();

			void gotoxy(int x, int y);
			void gotoxy(Draw::Point pt);
			void SetColor(char textColor, char backColor);
			void SetColor(Draw::Color color);



			void Render();

		};
	}
}