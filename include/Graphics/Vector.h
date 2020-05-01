#pragma once
#include <cmath>

namespace Graphics {
    class Vector {
    private:
        double X, Y, Z;

    public:
        static double epsilon;

        Vector();
        Vector(double x, double y, double z);
        Vector(const Vector& lhs);

        double Magnitude();
        Vector Normalize();
        
        Vector operator+=(const double lhs);
        Vector operator-=(const double lhs);
        // Vector operator*=(const double lhs);
        // Vector operator/=(const double lhs);

        Vector operator+=(const Vector& lhs);
        Vector operator-=(const Vector& lhs);
        // Vector operator*=(const Vector& lhs);
        // Vector operator/=(const Vector& lhs);
        
        
        Vector operator+(const double lhs);
        Vector operator-(const double lhs);
        // Vector operator*(const double lhs);
        // Vector operator/(const double lhs);

        Vector operator+(const Vector& lhs);
        Vector operator-(const Vector& lhs);
        // Vector operator*(const Vector& lhs);
        // Vector operator/(const Vector& lhs);

        bool operator==(const double lhs) const;
        bool operator!=(const double lhs) const;
        bool operator==(const Vector& lhs) const;
        bool operator!=(const Vector& lhs) const;
        
    };
}

