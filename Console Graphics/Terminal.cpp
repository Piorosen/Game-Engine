#include "Terminal.h"

Graphics::Output::Display::Display(Graphics::Library::Size displaySize) {
	DisplayPixel = nullptr;
	NewPixel = nullptr;

	Size = displaySize;
	this->Cursor = Graphics::Output::Cursor();
	ResizeTerminal(displaySize);
}

#if OS_MAC || OS_LINUX
int Graphics::Output::Display::ResizeTerminal(Graphics::Library::Size size, char* result = nullptr, int index = 0)
#elif OS_WINDOWS
void Graphics::Output::Display::ResizeTerminal(Graphics::Library::Size size)
#endif
{
	this->Size = size;
	if (DisplayPixel != nullptr) {
		delete[] DisplayPixel;
		DisplayPixel = nullptr;
	}

	if (NewPixel != nullptr) {
		delete[] NewPixel;
		NewPixel = nullptr;
	}

	DisplayPixel = new Graphics::Output::Pixel[size.X * size.Y];
	NewPixel = new Graphics::Output::Pixel[size.X * size.Y];

	for (int i = 0; i < Size.X * Size.Y; i++) {
		DisplayPixel[i] = Graphics::Output::Pixel();
		NewPixel[i] = Graphics::Output::Pixel();
	}
#if OS_MAC || OS_LINUX
	if (result == nullptr) {
		std::cout << "\e[8;" << size.Y << ";" << size.X << "t";
	}
	else {
		char save[100] = { 0, };

		sprintf(save, "\e[8;%d;%dt", size.Y, size.X);
		strcat(result, save);
		index = (int)strlen(save);
	}
	return index;
#elif OS_WINDOWS
	char text[256];
	sprintf(text, "mode con:lines=%d cols=%d", Size.Y, Size.X);
	system(text);
#endif
}

bool Graphics::Output::Display::AddDrawEvent(Graphics::Library::Function::Action<Graphics::Output::Pixel*, Graphics::Library::Size> event)
{
	return (EventDraw += event);
}

void Graphics::Output::Display::Clear()
{
#if OS_MAC || OS_LINUX
	system("clear");
#elif OS_WINDOWS
	system("cls");
#endif
}

void Graphics::Output::Display::Draw() {
#if OS_MAC || OS_LINUX
	int size = Size.X * Size.Y * 30;
	char* buffer = new char[size];

	for (int i = 0; i < size; i++) {
		buffer[i] = '\0';
	}

	int index = 0;
	for (int y = 0; y < Size.Y; y++) {
		index += Cursor.GotoXY(Graphics::Library::Point(0, y), buffer, index);
		index--;
		for (int x = 0; x < Size.X; x++) {
			index += Cursor.FontColor(Pixel[y * Size.X + x].Color, buffer, index);
			index--;
			buffer[index++] = Pixel[y * Size.X + x].Ascii;
		}
	}
	buffer[index++] = '\0';
	std::cout << buffer;

	delete[] buffer;
#elif OS_WINDOWS
	Graphics::Library::Point prev(0, 0);

	for (int y = 0; y < Size.Y; y++) {
		for (int x = 0; x < Size.X; x++) {
			if (DisplayPixel[y * Size.X + x] != NewPixel[y * Size.X + x]) {
				if (Graphics::Library::Point(x - 1, y) != prev) {
					Cursor.GotoXY(Graphics::Library::Point(x, y));
				}

				Cursor.FontColor(NewPixel[y * Size.X + x].Color);
				putchar(NewPixel[y * Size.X + x].Ascii);
				prev = Graphics::Library::Point(x, y);
			}
		}
	}
#endif
}

void Graphics::Output::Display::ReDraw()
{
	EventDraw.Invoke(NewPixel, Size);
	Draw();
}
