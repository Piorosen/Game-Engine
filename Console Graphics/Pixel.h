#pragma once

#include "Color.h"

namespace Graphics {
	namespace Output {
		class Pixel {
		private:

		public:
			bool Draw = false;
			inline void SetPixel(Graphics::Library::Color c, char ch) {
				if (c.BackColor == -1 && c.TextColor == -1) {
					Text = ch;
					Color = c;
					Draw = false;
				}
				else {
					Text = ch;
					Color = c;
					Draw = true;
				}
			}

			Draw::Color Color;
			char Text;

			bool operator==(const Pixel& g) const;
			bool operator!=(const Pixel& g) const;

		protected:


		};
	}
}