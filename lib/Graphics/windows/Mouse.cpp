#include <Windows.h>

#include "Mouse.h"


void Graphics::Input::Mouse::KeyDown(MouseButton id, Point pos)
{
    if (event[(int)id].Position == pos && event[(int)id].GetMouseButton() == id)
    {
        return;
    }

    event[(int)id].Position = pos;
    event[(int)id].Pressed = true;

    EventKeyDown.Invoke(id, pos);
    EventKeyChanged.Invoke(event, BUTTON_SIZE);
}

void Graphics::Input::Mouse::KeyUp(MouseButton id, Point pos)
{
    event[(int)id].Position = pos;
    event[(int)id].Pressed = false;

    EventKeyUp.Invoke(id, pos);
    EventKeyChanged.Invoke(event, BUTTON_SIZE);
}

void Graphics::Input::Mouse::Refresh(void *data)
{
    MOUSE_EVENT_RECORD input = *(MOUSE_EVENT_RECORD *)data;

    COORD pos;
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    pos = input.dwMousePosition;
    pos.X -= csbi.srWindow.Left;
    pos.Y -= csbi.srWindow.Top;

    for (int i = 0; i < BUTTON_SIZE; i++)
    {
        // Down
        MouseButton key = event[i].GetMouseButton();
        int vk_Key = 1 << ((int)key);

        if (GetKeyState(vk_Key) < 0)
        {
            KeyDown(key, Point(pos.X, pos.Y));
            event[i].Pressed = true;
        } // UP
        else if (GetKeyState(vk_Key) >= 0 && event[i].Pressed == true)
        {
            KeyUp(key, Point(-1, -1));
            event[i].Pressed = false;
        }
    }
}