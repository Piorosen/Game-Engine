#include "Color.h"

Graphics::Color::Color() {
	this->Background = ColorBackground::Black;
	this->Forground = ColorForground::White;
}

Graphics::Color::Color(ColorForground forground, ColorBackground background) {
	this->Background = background;
	this->Forground = forground;
}

bool Graphics::Color::operator==(const Color& c) const {
	if (Background == c.Background && Forground == c.Forground) {
		return true;
	}
	return false;
}

bool Graphics::Color::operator!=(const Color& c) const {
	if (Background == c.Background && Forground == c.Forground) {
		return false;
	}
	return true;
}

Graphics::ColorForground Graphics::Color::GetForground() const {
	return this->Forground;
}

Graphics::ColorBackground Graphics::Color::GetBackground() const {
	return this->Background;
}

