#include "Graphic_Pixel.h"



bool Engine::Draw::Graphic_Pixel::operator==(const Graphic_Pixel & g) const
{
	if (Color == g.Color && Text == g.Text) {
		return true;
	}return false;
}

bool Engine::Draw::Graphic_Pixel::operator!=(const Graphic_Pixel & g) const
{
	if (Color == g.Color && Text == g.Text) {
		return false;
	}return true;
}
