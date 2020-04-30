#include "Terminal.h"

Graphics::Output::Terminal::Terminal(const Graphics::Library::Size size) : Display(size)
{
	DWORD mode;
	CIN = GetStdHandle(STD_INPUT_HANDLE);

	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
}

bool Graphics::Output::Terminal::hasInput()
{
	INPUT_RECORD input_record;
	DWORD input_count;
	PeekConsoleInput(CIN, &input_record, 1, &input_count);
	return !(!input_count);
}

void Graphics::Output::Terminal::RefreshInputDevice()
{
	if (hasInput())
	{
		INPUT_RECORD input;
		DWORD input_count;
		ReadConsoleInput(CIN, &input, 1, &input_count);

		if (input.EventType == KEY_EVENT)
		{
			Keyboard.Refresh((void *)&input.Event.KeyEvent);
		}
		else if (input.EventType == MOUSE_EVENT)
		{
			Mouse.Refresh((void *)&input.Event.MouseEvent);
		}
	}
}