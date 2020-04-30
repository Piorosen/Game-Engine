#include "Color.h"

Graphics::Color::Color() {
	this->Background = Graphics::ColorBackground::Black;
	this->Forground = Graphics::ColorForground::White;
}

Graphics::Color::Color(Graphics::ColorForground forground, Graphics::ColorBackground background) {
	this->Background = background;
	this->Forground = forground;
}

bool Graphics::Color::operator==(const Graphics::Color& c) const {
	if (Background == c.Background && Forground == c.Forground) {
		return true;
	}
	return false;
}

bool Graphics::Color::operator!=(const Graphics::Color& c) const {
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

