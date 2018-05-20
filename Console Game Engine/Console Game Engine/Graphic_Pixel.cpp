#include "Graphic_Pixel.h"



bool Engine::Draw::Graphic_Pixel::operator==(const Graphic_Pixel & g) const
{
	if (color == g.color && text == g.text) {
		return true;
	}return false;
}
