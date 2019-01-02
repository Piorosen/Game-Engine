#pragma once

#define PI 3.14159265358979323846264338327950288 

class Vector2D {
public:
	double x, y;

public:
	Vector2D(double mx, double my) : x(mx), y(my) {}
	Vector2D() : x(0.0), y(0.0) {}
	Vector2D(const Vector2D& vec) : x(vec.x), y(vec.y) {}

	void Rotate(const double& radian)
	{
		double newX = x * cos(radian) - y * sin(radian);
		double newY = x * sin(radian) + y * cos(radian);

		x = newX;
		y = newY;

	}
	void operator+=(const Vector2D& other) {
		this->x += other.x;
		this->y += other.y;
	}
	Vector2D operator+(const Vector2D& other) const {
		return Vector2D(this->x + other.x, this->y + other.y);
	}

	void operator*=(const Vector2D& other) {
		this->x *= other.x;
		this->y *= other.y;
	}
	Vector2D operator*(const Vector2D& other) {
		return Vector2D(this->x * other.x, this->y * other.y);
	}

	void operator-=(const Vector2D& other) {
		this->x -= other.x;
		this->y -= other.y;
	}
	Vector2D operator-(const Vector2D& other) {
		return Vector2D(this->x - other.x, this->y - other.y);
	}

	static Vector2D Nomalize(Vector2D vec) {
		auto magnitude = Magnitude(vec);
		return Vector2D(vec.x / magnitude, vec.y / magnitude);
	}
	static double Distance(Vector2D x, Vector2D y) {
		return Magnitude(x - y);
	}
	static double Magnitude(Vector2D vec) {
		return sqrt(vec.x * vec.x + vec.y * vec.y);
	}
};