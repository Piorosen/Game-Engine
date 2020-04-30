#include "Pixel.h"

void Graphics::Pixel::SetPixel(Graphics::Color color, char ch) {
	this->Ascii = ch;
}

void Graphics::Pixel::SetPixel(char ch) {
	this->Ascii = ch;
}

void Graphics::Pixel::SetPixel(Graphics::Color color) {
	this->Color = color;
}

bool Graphics::Pixel::operator==(const Pixel& g) const
{
	if (this->Ascii == g.Ascii && this->Color == g.Color) {
		return true;
	}
	return false;
}

bool Graphics::Pixel::operator!=(const Pixel& g) const
{
	if (this->Ascii == g.Ascii && this->Color == g.Color) {
		return false;
	}
	return true;
}

