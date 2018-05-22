#pragma once
#include "Color.h"
#include <string>

namespace Engine {
	namespace Draw {
		class Graphic_Pixel {
		private:

		public:
			bool Draw = false;
			inline void SetPixel(Color c, char ch) {
				if (c.BackColor == -1 && c.TextColor == -1) {
					Text = ch;
					Color = c;
					Draw = false;
				}
				else{
					Text = ch;
					Color = c;
					Draw = true;
				}
			}

			Draw::Color Color;
			char Text;

			bool operator==(const Graphic_Pixel& g) const;
			bool operator!=(const Graphic_Pixel& g) const;

		protected:


		};
	}
}