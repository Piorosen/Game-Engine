#include "Cursor.h"

#if OS_MAC || OS_LINUX
int Graphics::Output::Cursor::EraseCursor(bool isShowCursor, char* result, int index)
#elif OS_WINDOWS
void Graphics::Output::Cursor::EraseCursor(bool isShowCursor)
#endif
{
#if OS_MAC || OS_LINUX
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
#elif OS_WINDOWS
	CONSOLE_CURSOR_INFO cursorinfo = { 0, };
	cursorinfo.dwSize = 1;
	cursorinfo.bVisible = isShowCursor;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorinfo);
#endif	
}

#if OS_MAC || OS_LINUX
int Graphics::Output::Cursor::FontColor(const Graphics::Library::Color color, char* result, int index)
#elif OS_WINDOWS
void Graphics::Output::Cursor::FontColor(const Graphics::Library::Color color)
#endif
{
#if OS_MAC || OS_LINUX
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
#elif OS_WINDOWS
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (((int)color.GetBackground() & 0xf) << 4) | ((int)color.GetForground() & 0xf));
#endif
}


#if OS_MAC || OS_LINUX
int Graphics::Output::Cursor::GotoXY(Graphics::Library::Point pt, char* result, int index)
#elif OS_WINDOWS
void Graphics::Output::Cursor::GotoXY(Graphics::Library::Point pt)
#endif
{
#if OS_MAC || OS_LINUX
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
#elif OS_WINDOWS
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pt.X & 0xffff, pt.Y & 0xffff });
#endif
}
