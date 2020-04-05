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
			void FontColor(const Graphics::Library::Color color) {
#if OS_MAC || OS_LINUX
				std::cout << "\033[" << color.GetForground() << "m";
				std::cout << "\033[" << color.GetBackground() << "m";
#elif OS_WINDOWS
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((int)color.GetBackground() & 0xf << 4) | (int)color.GetForground() & 0xf);
#endif
			}

			void GotoXY(const Graphics::Library::Point pt) {
#if OS_MAC || OS_LINUX
				std::cout << "\033[" << pt.X & 0xffff << ';' << pt.Y & 0xffff;
#elif OS_WINDOWS
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { pt.X & 0xffff, pt.Y & 0xffff });
#endif
			}

		protected:


		};
	}
}