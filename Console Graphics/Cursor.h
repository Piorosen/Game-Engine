#pragma once
#include <iostream>
#include <string>

#include "Point.h"
#include "Enviroment.h"
#include "Color.h"

namespace Graphics {
	namespace Output {
		class Cursor {
		private:


		public:
			static void EraseCursor(bool isShowCursor) {
#if OS_MAC || OS_LINUX 
				isShowCursor ? system("setterm -cursor on") : system("setterm -cursor off");
#elif OS_WINDOWS
				CONSOLE_CURSOR_INFO cursorinfo = { 0, };
				cursorinfo.dwSize = 1;
				cursorinfo.bVisible = isShowCursor;
				SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorinfo);
#endif
				
			}

			static void FontColor(const Graphics::Library::Color color) {
#if OS_MAC || OS_LINUX
				std::cout << "\033[" << (int)color.GetForground() << ";" << (int)color.GetBackground() << 'm';
#elif OS_WINDOWS
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (((int)color.GetBackground() & 0xf) << 4) | ((int)color.GetForground() & 0xf));
#endif
			}

			static void GotoXY(const Graphics::Library::Point pt) {
#if OS_MAC || OS_LINUX
				std::cout << "\033[" << ((pt.X + 1) & 0xffff) << ';' << ((pt.Y + 1) & 0xffff) << 'f';
#elif OS_WINDOWS
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pt.X & 0xffff, pt.Y & 0xffff });
#endif
			}

		protected:


		};
	}
}