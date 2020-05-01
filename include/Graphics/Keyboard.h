#pragma once
#include "EventHandler.h"

namespace Graphics
{
	class Keyboard
	{
	private:
		bool Key[256] = {
			0,
		};

		void KeyUp(unsigned short ch);
		void KeyDown(unsigned short ch);

		Keyboard();

	public:
		EventHandler<unsigned short> EventKeyDown;
		EventHandler<unsigned short> EventKeyUp;
		EventHandler<unsigned short, bool> EventKeyChanged;

		void Refresh(void *data);

	};
} // namespace Graphics
