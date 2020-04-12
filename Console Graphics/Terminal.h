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
			Graphics::Input::Keyboard keyboard;
			Graphics::Input::Mouse mouse;

            Display Display;
            
			Terminal(const Graphics::Library::Size size) : Display(size){
				DWORD mode;
				GetConsoleMode(CIN, &mode);
				CIN = GetStdHandle(STD_INPUT_HANDLE);
				SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
            }

			void RefreshInputDevice() {
#if OS_WINDOWS
				if (beInput()) {
					auto input = selectInput();

					if (input.EventType == KEY_EVENT) {
						keyboard.Refresh((void*)&input.Event);
					}
					else if (input.EventType == MOUSE_EVENT) {
						mouse.Refresh((void*)&input.Event);

					}
				}
#endif
			}

        };
    }
}
