#pragma once
namespace Engine {
	namespace Input {
		class Keyboard {
		private:
			bool Key[256] = { 0, };

		public:
			void Initialize() {
				for (int i = 0; i < sizeof(Key) / sizeof(bool); i++) {
					Key[i] = false;
				}
			}
			void KeyUp(unsigned short ch) {
				Key[ch] = false;
			}

			void KeyDown(unsigned short ch) {
				Key[ch] = true;
			}

			bool IsKeyDown(unsigned short ch) {
				return Key[ch];
			}
		};
	}
}