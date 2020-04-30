#include "Point.h"

Graphics::Point::Point() {
	this->X = 0;
	this->Y = 0;
}

Graphics::Point::Point(int _X, int _Y) {
	this->X = _X;
	this->Y = _Y;
}

Graphics::Point::Point(const Point& pt) {
	this->X = pt.X;
	this->Y = pt.Y;
}

Graphics::Point Graphics::Point::operator=(const Point& pt) {
	this->X = pt.X;
	this->Y = pt.Y;
	return *this;
}

bool Graphics::Point::operator==(const Point& pt) const {
	if (this->X == pt.X && this->Y == pt.Y) {
		return true;
	}
	else
	{
		return false;
	}
}
bool Graphics::Point::operator!=(const Point& pt) const {
	if (this->X == pt.X && this->Y == pt.Y) {
		return false;
	}
	else
	{
		return true;
	}
}
