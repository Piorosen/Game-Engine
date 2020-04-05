#pragma once

#include <time.h>

#include "Point.h"
#include "Pixel.h"
#include "Cursor.h"
#include "EventHandler.h"

namespace Graphics {
	namespace Output {
		class Dispaly {
		private:
			Graphics::Library::Size Size;
			Graphics::Output::Pixel* Pixel;
			Graphics::Output::Cursor Cursor;

			short Hz = 3;

		public:
			Graphics::Library::EventHandler<Graphics::Output::Pixel*, Graphics::Library::Size> EventDraw;

			void MainLoop() {
				bool Return = true;

				while (Return) {
					time_t start, end;
					start = clock();
					end = clock();
					while ((double)(end - start) < (1000.0 / Hz)) {
						end = clock();
					}
					EventDraw.Invoke(Pixel, Size);
					
					
					end = clock();
				}
			}


		protected:

		};
	}
}