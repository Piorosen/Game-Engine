#pragma once

#include "Display.h"
#include "Point.h"

#include "IDevice.h"
#include "Keyboard.h"
#include "Mouse.h"

namespace Graphics {
    namespace Output {
        class Renderer {
        private:
            Display display;
            
        public:
            Renderer(const Graphics::Library::Size size) : display(size){
                
            }
            
            
            
            
        };
    }
}
