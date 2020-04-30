#pragma once
#include "IDevice.h"
#include "EventHandler.h"

using namespace Graphics::Library;

namespace Graphics {
	namespace Input {
        class Keyboard : Library::Interface::IDevice {
		private:
			bool Key[256] = { 0, };

			void KeyUp(unsigned short ch);

			void KeyDown(unsigned short ch);
            
		public:
			EventHandler<unsigned short> EventKeyDown;
			EventHandler<unsigned short> EventKeyUp;
			EventHandler<unsigned short, bool> EventKeyChanged;

			void Refresh(void* data);
			
			Keyboard();
		};
	}
}
