#include <iostream>

#define OUTPUT_CONSOLE
// #define OUTPUT_FILE
#include "Graphics.h"
#include "TestModule.hpp"
#include "GraphicsTest.h"

using namespace Graphics::Library;

void asdf(int a){
    std::cout << a;
}

int main()
{
    Config();
    GrahpicsTest();
    
    return 0;
}
