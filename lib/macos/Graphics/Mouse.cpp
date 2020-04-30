#include "Mouse.h"


void Graphics::Mouse::KeyDown(MouseButton id, Point pos)
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

void Graphics::Mouse::KeyUp(MouseButton id, Point pos)
{
    event[(int)id].Position = pos;
    event[(int)id].Pressed = false;

    EventKeyUp.Invoke(id, pos);
    EventKeyChanged.Invoke(event, BUTTON_SIZE);
}

void Graphics::Mouse::Refresh(void *data)
{
    
}