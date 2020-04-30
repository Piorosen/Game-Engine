#include "Point.h"

Graphics::Library::Point::Point() {
	this->X = 0;
	this->Y = 0;
}

Graphics::Library::Point::Point(int _X, int _Y) {
	this->X = _X;
	this->Y = _Y;
}

Graphics::Library::Point::Point(const Point& pt) {
	this->X = pt.X;
	this->Y = pt.Y;
}

Graphics::Library::Point Graphics::Library::Point::operator=(const Point& pt) {
	this->X = pt.X;
	this->Y = pt.Y;
	return *this;
}

bool Graphics::Library::Point::operator==(const Point& pt) const {
	if (this->X == pt.X && this->Y == pt.Y) {
		return true;
	}
	else
	{
		return false;
	}
}
bool Graphics::Library::Point::operator!=(const Point& pt) const {
	if (this->X == pt.X && this->Y == pt.Y) {
		return false;
	}
	else
	{
		return true;
	}
}
