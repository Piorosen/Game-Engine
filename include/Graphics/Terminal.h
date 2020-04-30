#pragma once

#include "Func.h"
#include "EventHandler.h"

#include "Point.h"
#include "IDevice.h"

#include "Display.h"
#include "Mouse.h"
#include "Keyboard.h"

#include "Enviroment.h"

namespace Graphics {
    namespace Output {
        class Terminal {
        private:
			bool hasInput();
#if OS_WINDOWS
			HANDLE CIN;
#endif

        public:
			Graphics::Output::Display Display;

			Graphics::Input::Keyboard Keyboard;
			Graphics::Input::Mouse Mouse;

			Terminal(const Graphics::Library::Size size);
			void RefreshInputDevice();
        };
    }
}
