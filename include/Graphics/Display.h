#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <time.h>
#include <cstring>

#include "Point.h"
#include "Pixel.h"
#include "Cursor.h"
#include "EventHandler.h"
#include "IDevice.h"

namespace Graphics {
	namespace Output {
		class Display {
		private:
            char* buffer;
			Graphics::Library::Size Size;
			Graphics::Output::Pixel* DisplayPixel;
			Graphics::Output::Pixel* NewPixel;
			
		public:
            short Hz = 60;
            
			Graphics::Library::EventHandler<Graphics::Output::Pixel*, Graphics::Library::Size> EventDraw;
            Graphics::Output::Cursor Cursor;
            
			Display(Graphics::Library::Size displaySize);
			~Display();
			
			void Clear();
			void ReDraw();

#if OS_MAC || OS_LINUX
			int ChangeTitle(const char* name, char* result = nullptr);
#elif OS_WINDOWS
			void ChangeTitle(const char* name);
#endif

#if OS_MAC || OS_LINUX
			int ResizeTerminal(Graphics::Library::Size size, char* result = nullptr);
#elif OS_WINDOWS
			void ResizeTerminal(Graphics::Library::Size size);
#endif
		protected:
			void Draw();

		protected:

		};
	}
}