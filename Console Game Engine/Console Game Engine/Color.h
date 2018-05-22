#pragma once

namespace Engine {
	namespace Draw {
		class ColorList {
		public:
			static const char Black = 0x0;
			static const char Blue = 0x1;
			static const char Green = 0x2;
			static const char BluGreen = 0x3;
			static const char Red = 0x4;
			static const char YellRed = 0x5;
			static const char Yellow = 0x6;
			static const char White = 0x7;
			static const char Gray = 0x8;
			static const char WhiteBlue = 0x9;
			static const char WhiteGreen = 0xA;
			static const char WhiteBluGreen = 0xB;
			static const char WhiteRed = 0xC;
			static const char WhiteYellRed = 0xD;
			static const char WhiteYellow = 0xE;
			static const char WhiteWhite = 0xF;
		};

		class Color {
		public:
			char BackColor = 0;
			char TextColor = 0;
			Color() {
				BackColor = 0;
				TextColor = 0;
			}
			Color(int _X, int _Y) {
				BackColor = _X & 0xf;
				TextColor = _Y & 0xf;
			}

			bool operator==(const Color& c) const {
				if (BackColor == c.BackColor && TextColor == c.TextColor) {
					return true;
				}return false;
			}
			bool operator!=(const Color& c) const {
				if (BackColor == c.BackColor && TextColor == c.TextColor) {
					return false;
				}return true;
			}

		};

	}
}

