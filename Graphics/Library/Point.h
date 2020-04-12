#pragma once

namespace Graphics {
	namespace Library {
		class Point {
		public:
			int X;
			int Y;
			Point();
			Point(int _X, int _Y);
			Point(const Point& pt);

			Point operator=(const Point& pt);
			bool operator==(const Point& pt) const;
			bool operator!=(const Point& pt) const;

		};

		typedef Point Size;
	}
}
