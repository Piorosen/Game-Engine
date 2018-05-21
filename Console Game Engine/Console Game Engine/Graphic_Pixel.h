#pragma once
#include "Color.h"
#include <string>

namespace Engine {
	namespace Draw {
		class Graphic_Pixel {
		private:

			Draw::Color color;
			char text;

		public:
			bool Draw = false;
			inline void SetPixel(Color c, char ch) {
				if (c.BackColor == -1 && c.TextColor == -1) {
					text = ch;
					color = c;
					Draw = false;
				}
				else {
					text = ch;
					color = c;
					Draw = true;
				}
			}

			inline Color GetColor() const { return color; }
			inline char GetText() const { return text; }

			bool operator==(const Graphic_Pixel& g) const;
			bool operator!=(const Graphic_Pixel& g) const;

		protected:


		};
	}
}