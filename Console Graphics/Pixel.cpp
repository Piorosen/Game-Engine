#pragma once

#include "Pixel.h"

void Graphics::Output::Pixel::SetPixel(Graphics::Library::Color color, char ch) {
	this->Color = color;
	this->Ascii = ch;
}

bool Graphics::Output::Pixel::operator==(const Pixel& g) const
{
	if (this->Ascii == g.Ascii && this->Color == g.Color) {
		return true;
	}
	return false;
}

bool Graphics::Output::Pixel::operator!=(const Pixel& g) const
{
	if (this->Ascii == g.Ascii && this->Color == g.Color) {
		return false;
	}
	return true;
}

