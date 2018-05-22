#pragma once
#include <Windows.h>



namespace Engine {
	namespace Draw {


		class Point {
		public:
			int X;
			int Y;
			Point();
			Point(int _X, int _Y);
			Point(COORD &pt);

			bool operator==(const Point& pt) const;
			bool operator!=(const Point& pt) const;

		};

		typedef Point Size;
	}
}