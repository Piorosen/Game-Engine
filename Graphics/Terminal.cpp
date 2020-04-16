

#include "Terminal.h"

Graphics::Output::Terminal::Terminal(const Graphics::Library::Size size) : display(size)
{
#if OS_WINDOWS
    DWORD mode;
    GetConsoleMode(CIN, &mode);
    CIN = GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
#endif
}

void Graphics::Output::Terminal::RefreshInputDevice() {
#if OS_WINDOWS
				if (beInput()) {
					auto input = selectInput();

					if (input.EventType == KEY_EVENT) {
						keyboard.Refresh((void*)&input.Event);
					}
					else if (input.EventType == MOUSE_EVENT) {
						mouse.Refresh((void*)&input.Event);

					}
				}
#endif
			}