#pragma once

#include "Action.h"
#include "Predicate.h"
#include "Func.h"

using namespace Graphics::Library::Function;

void test(int c){
    std::cout << c << std::endl;
}

bool pre(int a, int b){
    return a + b;
}

bool pre2(int a, int b){
    return a - b;
}

void FunctionTest() {
    Action<int> a;
    Func<void, int> b;
    
    a = test;
    b = test;
    
    a(5);
    b(123);
    test(444);
    
    Predicate<int, int> c = pre;
    std::cout << (c(123, -123) ? "true" : "false") << std::endl;
    
    Func<bool, int, int> d = pre2;
    std::cout << (d(123, -123) ? "true" : "false") << std::endl;
    
    c = d;
    std::cout << (c(123, -123) ? "true" : "false") << std::endl;
    
    
}
