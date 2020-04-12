#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <time.h>
#include <cstring>

#include "Point.h"
#include "Pixel.h"
#include "Cursor.h"
#include "EventHandler.h"

namespace Graphics {
	namespace Output {
		class Display {
		private:
			Graphics::Library::Size Size;
			Graphics::Output::Pixel* DisplayPixel;
			Graphics::Output::Pixel* NewPixel;
			Graphics::Output::Cursor Cursor;


			short Hz = 60;

		public:
			Graphics::Library::EventHandler<Graphics::Output::Pixel*, Graphics::Library::Size> EventDraw;

			Display(Graphics::Library::Size displaySize);
			void Clear();
			void ReDraw();

#if OS_MAC || OS_LINUX
			int ResizeTerminal(Graphics::Library::Size size, char* result = nullptr, int index = 0);
#elif OS_WINDOWS
			void ResizeTerminal(Graphics::Library::Size size);
#endif
		protected:
			void Draw();

		protected:

		};
	}
}
