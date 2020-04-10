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

			short Hz = 60;

		public:
			Graphics::Library::EventHandler<Graphics::Output::Pixel*, Graphics::Library::Size> EventDraw;

            
            
			void MainLoop() {
				
			}


		protected:

		};
	}
}
