#pragma once

#include "Color.h"

namespace Graphics
{
	class Pixel
	{
	private:
	public:
		Graphics::Color Color;
		//Graphics::Library::Font Font;
		//Graphics::Library::Point Position;
		char Ascii = 0;

		void SetPixel(Graphics::Color color, char ch);
		void SetPixel(char ch);
		void SetPixel(Graphics::Color color);

		bool operator==(const Pixel &g) const;
		bool operator!=(const Pixel &g) const;

	protected:
	};
} // namespace Graphics
