#include "Point.h"

Engine::Draw::Point::Point()
{
	X = 0;
	Y = 0;
}

Engine::Draw::Point::Point(int _X, int _Y)
{
	X = _X;
	Y = _Y;
}

Engine::Draw::Point::Point(COORD & pt)
{
	X = pt.X;
	Y = pt.Y;
}

bool Engine::Draw::Point::operator==(const Point & pt) const
{
	if (X == pt.X && Y == pt.Y) {
		return true;
	}return false;
}

bool Engine::Draw::Point::operator!=(const Point & pt) const
{
	if (X == pt.X && Y == pt.Y) {
		return false;
	}return true;
}

