#pragma once
#include "../Point.h"


namespace Graphics {
    class Shape {
    protected:
        Vector* vertex;
        int indics;

    public:
        Graphics::Size Scale;
        Graphics::Point Location;

        Shape() {
            vertex = nullptr;
            indics = 0;
        }

        virtual ~Shape() {
            
        }

        int GetIndics() const {
            return indics;
        }
        
        Vector* GetVertex() const {
            return vertex;
        }
    };
}