#pragma once
#include "EventHandler.h"

namespace Graphics {
	namespace Input {
		class Keyboard {
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

			void Initialize() {
				for (int i = 0; i < sizeof(Key) / sizeof(bool); i++) {
					Key[i] = false;
				}
			}

			bool IsKeyDown(unsigned short ch) {
				return Key[ch];
			}
		};
	}
}