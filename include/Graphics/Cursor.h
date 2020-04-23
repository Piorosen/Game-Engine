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
            
#if OS_MAC || OS_LINUX
			int EraseCursor(bool isShowCursor, char* result = nullptr, int index = 0);
#elif OS_WINDOWS
			void EraseCursor(bool isShowCursor);
#endif
                 
#if OS_MAC || OS_LINUX
			int FontColor(const Graphics::Library::Color color, char* result = nullptr, int index = 0);
#elif OS_WINDOWS
			void FontColor(const Graphics::Library::Color color);
#endif
               

#if OS_MAC || OS_LINUX
			int GotoXY(Graphics::Library::Point pt, char* result = nullptr, int index = 0);
#elif OS_WINDOWS
			void GotoXY(Graphics::Library::Point pt);
#endif
		protected:


		};
	}
}
