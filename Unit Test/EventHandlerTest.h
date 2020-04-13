#pragma once

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
	Graphics::Library::EventHandler<int, float> d;

	d += test1;
	d += test2;
	d += test4;
	d += test3;
	d -= test1;

	d.Invoke(2, 3);
}

void delay(int miliSecond){
#if OS_MAC || OS_LINUX
    float f = miliSecond;
    char data[100] = { 0, };
    sprintf(data, "sleep %f", f / 1000.0);
    system(data);
#elif OS_WINDOWS
    Sleep(miliSecond);
#endif
}

void DisplayResizeTest(){
    Graphics::Output::Display d(Graphics::Library::Size(20, 30));


	delay(500);
    
    d.ResizeTerminal(Graphics::Library::Size(100, 60));
	delay(500);
    d.ResizeTerminal(Graphics::Library::Size(60, 10));
	delay(500);
    
    d.ResizeTerminal(Graphics::Library::Size(200, 40));
	delay(500);
    
}
