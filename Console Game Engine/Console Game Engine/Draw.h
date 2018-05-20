#pragma once
#include "Draw.h"

namespace Engine{
	namespace Draw {
		class Color {
		public:
			char BackColor = 0;
			char TextColor = 0;
			Color() {
				BackColor = 0;
				TextColor = 0;
			}
			Color(int _X, int _Y) {
				BackColor = _X;
				TextColor = _Y;
			}
		};

		class Point {
		public:
			int X;
			int Y;
			Point() {
				X = 0;
				Y = 0;
			}
			Point(int _X, int _Y) {
				X = _X;
				Y = _Y;
			}
			Point(Point &pt) {
				X = pt.X;
				Y = pt.Y;
			}
			Point(COORD &pt) {
				X = pt.X;
				Y = pt.Y;
			}
			bool operator==(Point& pt) {
				if (X == pt.X && Y == pt.Y) {
					return true;
				}return false;
			}

			
		};

		class Graphic_Pixel {
		private:
			Draw::Color color;
			TCHAR text;

		public:
			virtual ~Graphic_Pixel() {}

			void SetPixel(Color c, TCHAR ch) {
				color = c;
			}
			bool operator==(Graphic_Pixel) const {}


		protected:


		};
		typedef Point Size;
	}
}