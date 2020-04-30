#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <time.h>
#include <cstring>
#include <windows.h>
#include <iostream>

#include "Point.h"
#include "Pixel.h"
#include "EventHandler.h"

namespace Graphics {
	class Display
	{
	private:
		char *buffer;
		Graphics::Size Size;
		Graphics::Pixel *DisplayPixel;
		Graphics::Pixel *NewPixel;

	public:
		short Hz = 60;

		Graphics::EventHandler<Graphics::Pixel *, Graphics::Size> EventDraw;

		Display(Graphics::Size displaySize);
		~Display();

		void Clear();
		void ReDraw();

#if OS_MAC || OS_LINUX
			int EraseCursor(bool isShowCursor, char* result = nullptr, int index = 0);
			int FontColor(const Graphics::Color color, char* result = nullptr, int index = 0);
			int GotoXY(Graphics::Point pt, char* result = nullptr, int index = 0);
			int ChangeTitle(const char* name, char* result = nullptr, int index = 0);
			int ResizeTerminal(Graphics::Size size, char* result = nullptr, int index = 0);
#elif OS_WINDOWS
			void EraseCursor(bool isShowCursor);
			void FontColor(const Graphics::Color color);
			void GotoXY(Graphics::Point pt);
			void ChangeTitle(const char* name);
			void ResizeTerminal(Graphics::Size size);
#endif
		protected:
			void Draw();

		protected:
	};
}
