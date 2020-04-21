#include "Cursor.h"

void Graphics::Output::Cursor::EraseCursor(bool isShowCursor)
{
	CONSOLE_CURSOR_INFO cursorinfo = { 0, };
	cursorinfo.dwSize = 1;
	cursorinfo.bVisible = isShowCursor;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorinfo);
}

void Graphics::Output::Cursor::FontColor(const Graphics::Library::Color color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (((int)color.GetBackground() & 0xf) << 4) | ((int)color.GetForground() & 0xf));
}


void Graphics::Output::Cursor::GotoXY(Graphics::Library::Point pt)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pt.X & 0xffff, pt.Y & 0xffff });
}
