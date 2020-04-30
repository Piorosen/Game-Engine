#pragma once
#include "EventHandler.h"
#include "Point.h"
#include "IDevice.h"

using namespace Graphics::Library;

namespace Graphics {
	namespace Input {
		enum class MouseButton : unsigned char {
			Left,
			Right,
			Middle,
		};

		class MouseEvent {
		private:
			MouseButton ButtonId;

		public:
			MouseEvent(MouseButton id) {
				ButtonId = id;
				Pressed = false;
				Position = Point(-1, -1);
			}

			MouseButton GetMouseButton() const {
				return ButtonId;
			}

			bool Pressed;
			Point Position;
		};

        class Mouse : Library::Interface::IDevice {
		private:
			const static int BUTTON_SIZE = 3;
			MouseEvent event[BUTTON_SIZE] = { MouseEvent(MouseButton::Left), MouseEvent(MouseButton::Right), MouseEvent(MouseButton::Middle) };

			void KeyDown(MouseButton id, Point pos);
			void KeyUp(MouseButton id, Point pos);

		public:
			EventHandler<MouseEvent*, unsigned char> EventKeyChanged;
			EventHandler<MouseButton, Point> EventKeyDown;
			EventHandler<MouseButton, Point> EventKeyUp;

			void Refresh(void* data);
			
		};
	}
}
