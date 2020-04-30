#include "Keyboard.h"
#include "Enviroment.h"

void Graphics::Keyboard::KeyUp(unsigned short ch)
{
	Key[ch] = false;
	EventKeyUp.Invoke(ch);
	EventKeyChanged.Invoke(ch, false);
}

void Graphics::Keyboard::KeyDown(unsigned short ch)
{
	Key[ch] = true;
	EventKeyDown.Invoke(ch);
	EventKeyChanged.Invoke(ch, true);
}

Graphics::Keyboard::Keyboard()
{
	for (int i = 0; i < sizeof(Key) / sizeof(bool); i++)
	{
		Key[i] = false;
	}
}

void Graphics::Keyboard::Refresh(void *data)
{
	KEY_EVENT_RECORD input = *(KEY_EVENT_RECORD *)data;
	
	if (input.bKeyDown)
	{
		KeyDown(input.wVirtualKeyCode);
	}
	else
	{
		KeyUp(input.wVirtualKeyCode);
	}
}