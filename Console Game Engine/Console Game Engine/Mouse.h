#pragma once

#include <Windows.h>

#include "DrawLibrary.h"

namespace Engine {
	namespace LibInput {
		class Mouse {
		private:
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

			Draw::Point pt;
			Draw::Point MousePoint;

		public:
			void Initialize() {
				pt = Draw::Point(-10, -10);
			}

			bool IsClicked() const {
				if (pt.X == -10 && pt.Y == -10)
					return false;
				return true;
			}

			Draw::Point GetClickMousePosition(){
				return pt;
			}

			Draw::Point GetMousePosition(){
				return MousePoint;
			}

			void SetMousePostion(Draw::Point _pt) {
				MousePoint = _pt;
			}

			void SetClickMousePosition(Draw::Point _pt) {
				pt = _pt;
			}
			void SetClickMousePosition(int x, int y) {
				pt.X = x;
				pt.Y = y;
			}
		};
	}
}