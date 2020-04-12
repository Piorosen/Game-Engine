#pragma once
#include "EventHandler.h"
#include "Point.h"
#include "IDevice.h"

using namespace Graphics::Library;

namespace Graphics {
	namespace Input {
		enum class MouseButton {
			Left,
			Right,
			Middle,
		};

        class Mouse : Library::Interface::IDevice {
		private:
			int left = 0;
			int right = 0;

			void SetClickMousePosition(Point pt) {
				this->pt = pt;
			}
			
			void SetMousePostion(Point pt) {
				MousePoint = pt;
			}
			/*

			void MouseClick(int *x, int *y)
			{
				HANDLE       hIn, hOut;
				DWORD        dwNOER;
				INPUT_RECORD rec;

				hIn = GetStdHandle(STD_INPUT_HANDLE);
				hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleMode(hIn, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);

				while (TRUE) {
					ReadConsoleInput(hIn, &rec, 1, &dwNOER);

					if (rec.EventType == MOUSE_EVENT) {
						if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) {
							*x = rec.Event.MouseEvent.dwMousePosition.X;
							*y = rec.Event.MouseEvent.dwMousePosition.Y;
							return;
						}
					}
				}
			}
			*/

			Point pt;
			Point MousePoint;

		public:

			EventHandler<MouseButton, Point> EventKeyDown;
			EventHandler<MouseButton, Point> EventKeyUp;

			EventHandler<MouseButton, Point, bool> EventKeyChanged;


			void Initialize() {
				pt = Point(-10, -10);
			}

			bool IsClicked() const {
				if (pt.X == -10 && pt.Y == -10)
					return false;
				return true;
			}

			Point GetClickMousePosition() {
				return pt;
			}

			Point GetMousePosition() {
				return MousePoint;
			}
			void Refresh(void* data) {
#if OS_WINDOWS
				INPUT_RECORD input = *(INPUT_RECORD*)data;

				COORD pos;
				CONSOLE_SCREEN_BUFFER_INFO csbi;

				GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
				pos = input.Event.MouseEvent.dwMousePosition;
				pos.X -= csbi.srWindow.Left;
				pos.Y -= csbi.srWindow.Top;

				// Down
				if (GetKeyState(VK_LBUTTON) < 0 && left == 0) {
					SetClickMousePosition(Graphics::Library::Point(pos.X, pos.Y));
					left = 1;
					//		printf("마우스 입력 : Down\n");
				} // UP
				else if (GetKeyState(VK_LBUTTON) >= 0 && left == 1) {
					SetClickMousePosition(Graphics::Library::Point(-1, -1));
					left = 0;
					//	printf("마우스 입력 : Up\n");
				}
				SetMousePostion(Graphics::Library::Point(pos.X, pos.Y));
#endif
			}
			

			
		};
	}
}
