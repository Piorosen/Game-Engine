#pragma once
#include <array>

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

			void KeyDown(MouseButton id, Point pos) {
				if (event[(int)id].Position == pos && event[(int)id].GetMouseButton() == id) {
					return;
				}

				event[(int)id].Position = pos;
				event[(int)id].Pressed = true;

				EventKeyDown.Invoke(id, pos);
				EventKeyChanged.Invoke(event, BUTTON_SIZE);
			}

			void KeyUp(MouseButton id, Point pos) {
				event[(int)id].Position = pos;
				event[(int)id].Pressed = false;

				EventKeyUp.Invoke(id, pos);
				EventKeyChanged.Invoke(event, BUTTON_SIZE);
			}

		public:
			EventHandler<MouseEvent*, unsigned char> EventKeyChanged;
			EventHandler<MouseButton, Point> EventKeyDown;
			EventHandler<MouseButton, Point> EventKeyUp;

			void Refresh(void* data) {
#if OS_WINDOWS
				MOUSE_EVENT_RECORD input = *(MOUSE_EVENT_RECORD*)data;

				COORD pos;
				CONSOLE_SCREEN_BUFFER_INFO csbi;

				GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
				pos = input.dwMousePosition;
				pos.X -= csbi.srWindow.Left;
				pos.Y -= csbi.srWindow.Top;

				for (int i = 0; i < BUTTON_SIZE; i++){
					// Down
					MouseButton key = event[i].GetMouseButton();
					int vk_Key = 1 << ((int)key);

					if (GetKeyState(vk_Key) < 0) {
						KeyDown(key, Point(pos.X, pos.Y));
						event[i].Pressed = true;
					} // UP
					else if (GetKeyState(vk_Key) >= 0 && event[i].Pressed == true) {
						KeyUp(key, Point(-1, -1));
						event[i].Pressed = false;
					}
				}
#endif
			}
			

			
		};
	}
}
