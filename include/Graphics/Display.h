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

	Display();

#if OS_WINDOWS
		Graphics::Point curPosition;
		Graphics::Color curColor;	
#endif
		Graphics::Size Size;

		Graphics::Pixel *DisplayPixel;
		Graphics::Pixel *NewPixel;
		
	public:
		static Display* Instance() {
			static Display* display = new Display();
			return display;
		}
		

		short Hz = 60;

		~Display();

		void Clear();
		void ReDraw();

		void EraseCursor(bool isShowCursor);
		void FontColor(const Graphics::Color color);
		void GotoXY(Graphics::Point pt);
		void ChangeTitle(const char *name);
		void ResizeTerminal(Graphics::Size size);
		void Write(const char* text);

		bool SetPixel(const Graphics::Point pt, const Graphics::Pixel value);
		Graphics::Pixel GetPixel(const Graphics::Point pt) const;
	protected:
		void Draw();

	protected:
	};
} // namespace Graphics
