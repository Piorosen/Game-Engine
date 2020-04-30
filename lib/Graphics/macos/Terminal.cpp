
#include "Terminal.h"

Graphics::Output::Terminal::Terminal(const Graphics::Library::Size size) : Display(size)
{
}

bool Graphics::Output::Terminal::hasInput()
{
    return false;
}

void Graphics::Output::Terminal::RefreshInputDevice()
{
    Keyboard.Refresh(nullptr);
}
