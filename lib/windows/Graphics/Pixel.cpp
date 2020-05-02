#include "Pixel.h"


Graphics::Pixel::Pixel() {
	this->Ascii = 0;
	this->Color = Graphics::Color();
}
Graphics::Pixel::Pixel(char ch) {
	this->Ascii = ch;
	this->Color = Graphics::Color();
}
Graphics::Pixel::Pixel(Graphics::Color color) {
	this->Ascii = 0;
	this->Color = color;
}
Graphics::Pixel::Pixel(Graphics::Color color, char ch) {
	this->Ascii = ch;
	this->Color = color;
}

void Graphics::Pixel::SetPixel(Graphics::Color color, char ch) {
	this->Ascii = ch;
	this->Color = color;
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

