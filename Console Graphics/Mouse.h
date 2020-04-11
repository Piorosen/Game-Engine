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

			

			
		};
	}
}
