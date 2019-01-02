#pragma once

namespace Engine {
	namespace Draw {
		enum ColorList {
			Black = 0x0,
			Blue = 0x1,
			Green = 0x2,
			BluGreen = 0x3,
			Red = 0x4,
			YellRed = 0x5,
			Yellow = 0x6,
			White = 0x7,
			Gray = 0x8,
			WhiteBlue = 0x9,
			WhiteGreen = 0xA,
			WhiteBluGreen = 0xB,
			WhiteRed = 0xC,
			WhiteYellRed = 0xD,
			WhiteYellow = 0xE,
			WhiteWhite = 0xF
		};

		class Color {
		public:
			char BackColor = 0;
			char TextColor = 0;
			Color() {
				BackColor = 0;
				TextColor = 0;
			}
			Color(int _BackColor, int _TextColor) {
				BackColor = _BackColor & 0xf;
				TextColor = _TextColor & 0xf;
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

