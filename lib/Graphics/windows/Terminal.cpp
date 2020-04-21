#include "Terminal.h"

Graphics::Output::Terminal::Terminal(const Graphics::Library::Size size) : Display(size)
{
	DWORD mode;
	CIN = GetStdHandle(STD_INPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
}

void Graphics::Output::Terminal::RefreshInputDevice()
{
	if (beInput())
	{
		auto input = selectInput();

		if (input.EventType == KEY_EVENT)
		{
			Keyboard.Refresh((void *)&input.Event);
		}
		else if (input.EventType == MOUSE_EVENT)
		{
			Mouse.Refresh((void *)&input.Event.MouseEvent);
		}
	}
}