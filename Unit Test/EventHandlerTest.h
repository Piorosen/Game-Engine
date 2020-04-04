#pragma once

#include "EventHandler.h"

void test1(int a, float b) {
	printf("a %d %f\n", a, b);
}
void test2(int a, float b) {
	printf("b %d %f\n", a, b);
}
void test3(int a, float b) {
	printf("c %d %f\n", a, b);
}
void test4(int a, float b) {
	printf("d %d %f\n", a, b);
}

void EventHanlderTest() {
	Graphics::EventHandler<int, float> d;

	d += test1;
	d += test2;
	d += test4;
	d += test3;
	d -= test1;

	d.Invoke(2, 3);
}
