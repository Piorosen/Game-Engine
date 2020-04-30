#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include <time.h>
#include <cstring>
#include <windows.h>
#include <iostream>

#include "Point.h"
#include "Pixel.h"
#include "EventHandler.h"

namespace Graphics
{
	class Display
	{
	private:

#if OS_WINDOWS
		
#endif
		Graphics::Size Size;

		Graphics::Pixel *DisplayPixel;
		Graphics::Pixel *NewPixel;

#if OS_MAC || OS_LINUX 
		char *buffer;
		int index;
		int EraseCursor(bool isShowCursor, int index);
		int FontColor(const Graphics::Color color, int index);
		int GotoXY(Graphics::Point pt, int index);
		int ChangeTitle(const char *name, int index);
		int ResizeTerminal(Graphics::Size size, int index);
		int Write(const char *text, int index);
#endif

	public:
		short Hz = 60;

		Graphics::EventHandler<Graphics::Pixel *, Graphics::Size> EventDraw;

		Display(Graphics::Size displaySize);
		~Display();

		void Clear();
		void ReDraw();

		void EraseCursor(bool isShowCursor);
		void FontColor(const Graphics::Color color);
		void GotoXY(Graphics::Point pt);
		void ChangeTitle(const char *name);
		void ResizeTerminal(Graphics::Size size);
		void Write(const char* text);

	protected:
		void Draw();

	protected:
	};
} // namespace Graphics
