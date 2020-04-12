#include "Color.h"

Graphics::Library::Color::Color() {
	this->Background = ColorBackground::Black;
	this->Forground = ColorForground::White;
}

Graphics::Library::Color::Color(ColorForground forground, ColorBackground background) {
	this->Background = background;
	this->Forground = forground;
}

bool Graphics::Library::Color::operator==(const Color& c) const {
	if (Background == c.Background && Forground == c.Forground) {
		return true;
	}
	return false;
}

bool Graphics::Library::Color::operator!=(const Color& c) const {
	if (Background == c.Background && Forground == c.Forground) {
		return false;
	}
	return true;
}

Graphics::Library::ColorForground Graphics::Library::Color::GetForground() const {
	return this->Forground;
}

Graphics::Library::ColorBackground Graphics::Library::Color::GetBackground() const {
	return this->Background;
}
