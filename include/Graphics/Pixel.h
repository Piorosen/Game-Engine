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
		char Ascii;

		Pixel();
		Pixel(Graphics::Color color, char ch);
		Pixel(char ch);
		Pixel(Graphics::Color color);

		void SetPixel(Graphics::Color color, char ch);
		void SetPixel(char ch);
		void SetPixel(Graphics::Color color);

		bool operator==(const Pixel &g) const;
		bool operator!=(const Pixel &g) const;

	protected:
	};
} // namespace Graphics
