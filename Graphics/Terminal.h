#pragma once

#include "Point.h"
#include "IDevice.h"

#include "Display.h"
#include "Mouse.h"
#include "Keyboard.h"

namespace Graphics {
    namespace Output {
        class Terminal {
        private:
#if OS_WINDOWS
			HANDLE CIN;
			bool beInput() {
				INPUT_RECORD input_record;
				DWORD input_count;
				PeekConsoleInput(CIN, &input_record, 1, &input_count);
				return !(!input_count);
			}

			INPUT_RECORD selectInput()
			{
				INPUT_RECORD input_record;
				DWORD input_count;
				ReadConsoleInput(CIN, &input_record, 1, &input_count);
				return input_record;
			}
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
