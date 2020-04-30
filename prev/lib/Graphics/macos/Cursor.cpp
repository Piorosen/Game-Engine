#include "Cursor.h"

int Graphics::Output::Cursor::EraseCursor(bool isShowCursor, char* result, int index)
{
	int base = index;
	if (result == nullptr) {
		std::cout << (isShowCursor ? "\e[?25l" : "\e[?25h");
	}
	else {
		result[index++] = '\e';
		result[index++] = '[';
		result[index++] = '?';
		result[index++] = '2';
		result[index++] = '5';
		result[index++] = isShowCursor ? 'l' : 'h';
	}
	return index - base;
}

int Graphics::Output::Cursor::FontColor(const Graphics::Library::Color color, char* result, int index)
{
	int base = index;
	if (result == nullptr) {
		std::cout << "\033[" << (int)color.GetForground() << ";" << (int)color.GetBackground() << 'm';
	}
	else {
		int forg = (int)color.GetForground();
		int back = (int)color.GetBackground();

		result[index++] = '\033';
		result[index++] = '[';

		if (forg / 10 == 0) {
			result[index++] = forg + '0';
		}
		else {
			result[index++] = (forg / 10) + '0';
			result[index++] = (forg % 10) + '0';
		}
		result[index++] = ';';

		if (back / 10 == 0) {
			result[index++] = back + '0';
		}
		else {
			result[index++] = (back / 10) + '0';
			result[index++] = (back % 10) + '0';
		}
		result[index++] = 'm';
		result[index++] = '\0';
	}
	return index - base;
}


int Graphics::Output::Cursor::GotoXY(Graphics::Library::Point pt, char* result, int index)
{
	int base = index;

	pt.X += 1;
	pt.Y += 1;

	if (result == nullptr) {
		std::cout << "\033[" << ((pt.Y) & 0xffff) << ';' << ((pt.X) & 0xffff) << 'f';
	}
	else {
		result[index++] = '\033';
		result[index++] = '[';

		if (pt.Y / 10 == 0) {
			result[index++] = pt.Y + '0';
		}
		else {
			result[index++] = (pt.Y / 10) + '0';
			result[index++] = (pt.Y % 10) + '0';
		}

		result[index++] = ';';

		if (pt.X / 10 == 0) {
			result[index++] = pt.X + '0';
		}
		else {
			result[index++] = (pt.X / 10) + '0';
			result[index++] = (pt.X % 10) + '0';
		}

		result[index++] = 'f';
		result[index++] = '\0';
	}

	return index - base;
}
