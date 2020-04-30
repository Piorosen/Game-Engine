#pragma once

#include "Color.h"

namespace Graphics {
	namespace Output {
		class Pixel {
		private:
			

		public:
            Graphics::Library::Color Color;
            //Graphics::Library::Font Font;
            //Graphics::Library::Point Position;
            char Ascii = 0;
            
			void SetPixel(Graphics::Library::Color color, char ch);

			bool operator==(const Pixel& g) const;
			bool operator!=(const Pixel& g) const;

		protected:


		};
	}
}
