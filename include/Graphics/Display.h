#pragma once

#include <time.h>
#include <cstring>
#include <iostream>

#include "Enviroment.h"
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
#elif OS_MAC || OS_LINUX
		char* buffer;
		int index;
#endif


		Graphics::Size Size;

		Graphics::Pixel *DisplayPixel;
		Graphics::Pixel *NewPixel;
		
	public:
		static Display* Instance() {
            static Display* inst = new Display();
            return inst;
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
