#pragma once

#include "Display.h"
#include "Point.h"

#include "IDevice.h"
#include "Keyboard.h"
#include "Mouse.h"

namespace Graphics {
    namespace Output {
        class Terminal {
        private:
            Graphics::Input::Keyboard keyboard;
            Graphics::Input::Mouse mouse;
            
        public:
            Display Display;
            
			Terminal(const Graphics::Library::Size size) : Display(size){
                
            }
            
            
        };
    }
}
