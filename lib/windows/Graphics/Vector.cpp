#include "Vector.h"

double Graphics::Vector::epsilon = 0.0001;

Graphics::Vector::Vector(){
    X = 0;
    Y = 0;
    Z = 0;
}

Graphics::Vector::Vector(double x, double y, double z){
    X = x;
    Y = y;
    Z = z;
}


Graphics::Vector::Vector(const Vector& lhs){
    X = lhs.X;
    Y = lhs.Y;
    Z = lhs.Z;
}

double Graphics::Vector::Magnitude() {
    return sqrt(X * X + Y * Y + Z * Z);
}

Graphics::Vector Graphics::Vector::Normalize() {
    double magnitude = this->Magnitude();
    return Graphics::Vector(X / magnitude, Y / magnitude, Z / magnitude);
}

Graphics::Vector Graphics::Vector::operator+=(const double lhs) {
    X += lhs;
    Y += lhs;
    Z += lhs;
    return *this;
}
Graphics::Vector Graphics::Vector::operator-=(const double lhs) {
    X -= lhs;
    Y -= lhs;
    Z -= lhs;
    return *this;
}

Graphics::Vector Graphics::Vector::operator+=(const Vector& lhs) {
    X += lhs.X;
    Y += lhs.Y;
    Z += lhs.Z;
    return *this;
}
Graphics::Vector Graphics::Vector::operator-=(const Vector& lhs) {
    X -= lhs.X;
    Y -= lhs.Y;
    Z -= lhs.Z;
    return *this;
}


Graphics::Vector Graphics::Vector::operator+(const double lhs) {
    return Graphics::Vector(X + lhs, Y + lhs, Z + lhs);
}

Graphics::Vector Graphics::Vector::operator-(const double lhs) {
    return Graphics::Vector(X - lhs, Y - lhs, Z - lhs);
}

Graphics::Vector Graphics::Vector::operator+(const Vector& lhs) {
    return Graphics::Vector(X + lhs.X, Y + lhs.Y, Z + lhs.Z);
}

Graphics::Vector Graphics::Vector::operator-(const Vector& lhs) {
    return Graphics::Vector(X - lhs.X, Y - lhs.Y, Z - lhs.Z);
}

bool Graphics::Vector::operator==(const double lhs) const {
    if (fabs(X - lhs) <= epsilon && fabs(Y - lhs) <= epsilon && fabs(Z - lhs) <= epsilon) {
        return true;
    }else {
        return false;
    }
}
bool Graphics::Vector::operator==(const Vector& lhs) const {
    if (fabs(X - lhs.X) <= epsilon && fabs(Y - lhs.Y) <= epsilon && fabs(Z - lhs.Z) <= epsilon) {
        return true;
    }else {
        return false;
    }
}

bool Graphics::Vector::operator!=(const double lhs) const {
    return !this->operator==(lhs);
}

bool Graphics::Vector::operator!=(const Vector& lhs) const {
    return !this->operator==(lhs);
}