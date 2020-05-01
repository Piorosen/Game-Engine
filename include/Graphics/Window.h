#pragma once
#include "Enviroment.h"
#include "Vector.h"
#include "Color.h"
#include "Display.h"
#include "Pixel.h"
#include "Point.h"
#include "Vector.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "EventHandler.h"


namespace Graphics {
    class Window {
    private:
        Window(){}


    public:
        static Window* Create() {
            static Window* instance = new Window();
            return instance;
        }
        
        void SessionStart() {}
        void SessionClose() {}
    

    };

}