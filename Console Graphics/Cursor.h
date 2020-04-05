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
#if OS_MAC || OS_LINUX || OS_WINDOWS
			Graphics::Library::Point current_position;
#endif

		public:
			void FontColor(const Graphics::Library::Color forground, const Graphics::Library::Color background) {
#if OS_MAC || OS_LINUX
				std::cout << "\033[" << forground << "m";
				std::cout << "\033[" << background << "m";
#elif OS_WINDOWS
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((int)background & 0xf << 4) | (int)forground & 0xf);
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