#pragma once
#include "Draw.h"

namespace Engine {
	class Graphic_Pixel {
	private:
		Draw::Point pt;
		Draw::Color color;

		wchar_t text;

	public:
		virtual ~Graphic_Pixel() {}

		//	void SetPixel(Point, Color) {}
		//	bool operator==(Graphic_Pixel) const {}


	protected:


	};
}