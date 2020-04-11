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
			Graphics::Output::Pixel* Pixel;
			Graphics::Output::Cursor Cursor;

			short Hz = 60;

		public:
            Display(Graphics::Library::Size displaySize){
                Pixel = nullptr;
                Size = displaySize;
                this->Cursor = Graphics::Output::Cursor();
                ResizeTerminal(displaySize);
            }
            
			Graphics::Library::EventHandler<Graphics::Output::Pixel*, Graphics::Library::Size> EventDraw;

#if OS_MAC || OS_LINUX
            int ResizeTerminal(Graphics::Library::Size size, char* result = nullptr, int index = 0) {
#elif OS_WINDOWS
            void ResizeTerminal(Graphics::Library::Size size) {
#endif
                this->Size = size;
                if (Pixel != nullptr) {
                    delete[] Pixel;
                    Pixel = nullptr;
                }
                
                Pixel = new Graphics::Output::Pixel[size.X * size.Y];
                for (int i = 0; i < Size.X * Size.Y; i++){
                    Pixel[i] = Graphics::Output::Pixel();
                }
                
#if OS_MAC || OS_LINUX
                if (result == nullptr) {
                    std::cout << "\e[8;" << size.Y << ";" << size.X << "t";
                }else {
                    char save[100] = { 0, };
                    
                    sprintf(save, "\e[8;%d;%dt", size.Y, size.X);
                    strcat(result, save);
                    index = (int)strlen(save);
                }
                return index;
#elif OS_WINDOWS
                std::cout << "???";

#endif
            }
            
            void Clear() {
#if OS_MAC || OS_LINUX
                system("clear");
#elif OS_WINDOWS
                system("cls");
#endif
            }
            
            void ReDraw(){
                EventDraw.Invoke(Pixel, Size);
                Draw();
            }
            
        protected:
            void Draw(){
                int size = Size.X * Size.Y * 30;
                
                char* buffer = new char[size];
                
                for (int i = 0; i < size; i++){
                    buffer[i] = '\0';
                }
                
#if OS_MAC || OS_LINUX
                
                int index = 0;
                for (int y = 0; y < Size.Y; y++){
                    index += Cursor.GotoXY(Graphics::Library::Point(0, y), buffer, index);
                    index--;
                    for (int x = 0; x < Size.X; x++){
                        index += Cursor.FontColor(Pixel[y * Size.X + x].Color, buffer, index);
                        index--;
                        buffer[index++] = Pixel[y * Size.X + x].Ascii;
                    }
                }
                buffer[index++] = '\0';
                std::cout << buffer;
#elif OS_WINDOWS
                
#endif
            }
            

		protected:

		};
	}
}
