#pragma once
#include "IDevice.h"
#include "EventHandler.h"

using namespace Graphics::Library;

namespace Graphics {
	namespace Input {
        class Keyboard : Library::Interface::IDevice {
		private:
			bool Key[256] = { 0, };

			void KeyUp(unsigned short ch) {
				Key[ch] = false;
				EventKeyUp.Invoke(ch);
				EventKeyChanged.Invoke(ch, false);
			}

			void KeyDown(unsigned short ch) {
				Key[ch] = true;
				EventKeyDown.Invoke(ch);
				EventKeyChanged.Invoke(ch, true);
			}
            
		public:
			EventHandler<unsigned short> EventKeyDown;
			EventHandler<unsigned short> EventKeyUp;
			EventHandler<unsigned short, bool> EventKeyChanged;

			Keyboard() {
				for (int i = 0; i < sizeof(Key) / sizeof(bool); i++) {
					Key[i] = false;
				}
			}

			void Refresh(void* data) {
#if OS_WINDOWS
				KEY_EVENT_RECORD input = *(KEY_EVENT_RECORD*)data;

				if (input.bKeyDown) {
					KeyDown(input.wVirtualKeyCode);
				}
				else {
					KeyUp(input.wVirtualKeyCode);
				}
#endif
			}
		};
	}
}
