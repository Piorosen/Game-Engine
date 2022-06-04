#pragma once
#define PI 3.1415926535

#include "Shape.h"


namespace Graphics {
    class Rectangle : public Shape {
        
    public:
        Rectangle(Graphics::Point location, Graphics::Size size) {
            Location = location;
            Scale = size;

            vertex = new Vector[4];
            indics = 6;

            vertex[0] = Vector(location.X, location.Y, 0);
            vertex[1] = Vector(location.X + size.X, location.Y, 0);
            vertex[2] = Vector(location.X + size.X, location.Y + size.Y, 0);

            vertex[3] = Vector(location.X + size.X, location.Y + size.Y, 0);
            vertex[4] = Vector(location.X, location.Y, 0);
            vertex[5] = Vector(location.X, location.Y + size.Y, 0);
        }

        void Rotate(Point center, double degree) {
            double rad = degree / 180.0 * PI;

            for (int i = 0; i < indics; i++) {
                double x = cos(rad) * (center.X - vertex[i].X) - sin(rad) * (center.Y - vertex[i].Y);
                double y = sin(rad) * (center.X - vertex[i].X) + cos(rad) * (center.Y - vertex[i].Y);
                vertex[i] = Vector(x + center.X, y + center.Y, 0);
            }
        }

        virtual ~Rectangle(){
            if (vertex != nullptr) {
                delete[] vertex;
                vertex = nullptr;
            }
        }
    };
}