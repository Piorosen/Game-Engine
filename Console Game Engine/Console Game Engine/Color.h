#pragma once

namespace Engine {
	namespace Draw {
		class ColorList {
		public:
			const char Black = 0x0;
			const char Blue = 0x1;
			const char Green = 0x2;
			const char BluGreen = 0x3;
			const char Red = 0x4;
			const char YellRed = 0x5;
			const char Yellow = 0x6;
			const char White = 0x7;
			const char Gray = 0x8;
			const char WhiteBlue = 0x9;
			const char WhiteGreen = 0xA;
			const char WhiteBluGreen = 0xB;
			const char WhiteRed = 0xC;
			const char WhiteYellRed = 0xD;
			const char WhiteYellow = 0xE;
			const char WhiteWhite = 0xF;
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
				BackColor = _X;
				TextColor = _Y;
			}

			bool operator==(const Color& c) const {
				if (BackColor == c.BackColor && TextColor == c.TextColor) {
					return true;
				}return false;
			}
		};

	}
}

