#pragma once

#include "Shape.h"

namespace Graphics {
    class Rectangle : public Shape {
        
    public:
        Rectangle(Graphics::Point location, Graphics::Size size) {
            Location = location;
            Scale = size;

            vertex = new Vector[6];
            indics = 6;

            vertex[0] = Vector(location.X, location.Y, 0);
            vertex[1] = Vector(location.X + size.X, location.Y, 0);
            vertex[2] = Vector(location.X + size.X, location.Y + size.Y, 0);

            vertex[3] = Vector(location.X, location.Y, 0);
            vertex[4] = Vector(location.X + size.X, location.Y + size.Y, 0);
            vertex[5] = Vector(location.X, location.Y + size.Y, 0);
        }

        virtual ~Rectangle(){
            if (vertex != nullptr) {
                delete[] vertex;
                vertex = nullptr;
            }
        }
    };
}