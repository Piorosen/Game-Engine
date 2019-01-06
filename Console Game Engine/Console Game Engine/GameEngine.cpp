#include "GameEngine.h"
#include "Player.hpp"


bool Engine::Aoi2DEngine::Frame()
{
	static int Click = 0;
	if (be_input()) {
		auto input = select_input();
		switch (input.EventType) {
		case KEY_EVENT:
			if (input.Event.KeyEvent.bKeyDown) {
				keyboard->KeyDown(input.Event.KeyEvent.wVirtualKeyCode);
			//	printf("Ű���� �Է� : %d : Down\n", input.Event.KeyEvent.wVirtualKeyCode);
			}
			else {
				keyboard->KeyUp(input.Event.KeyEvent.wVirtualKeyCode);
		//		printf("Ű���� �Է� : %d : Up\n", input.Event.KeyEvent.wVirtualKeyCode);
			}
			break;
		case MOUSE_EVENT:
			COORD pos;
			CONSOLE_SCREEN_BUFFER_INFO csbi;

			GetConsoleScreenBufferInfo(COUT, &csbi);
			pos = input.Event.MouseEvent.dwMousePosition;
			pos.X -= csbi.srWindow.Left;
			pos.Y -= csbi.srWindow.Top;

			// Down
			if (GetKeyState(VK_LBUTTON) < 0 && Click == 0) {
				mouse->SetClickMousePosition(pos);
				Click = 1;
		//		printf("���콺 �Է� : Down\n");
			} // UP
			else if (GetKeyState(VK_LBUTTON) >= 0 && Click == 1) {
				mouse->SetClickMousePosition(-10, -10);
				Click = 0;
			//	printf("���콺 �Է� : Up\n");
			}
			mouse->SetMousePostion(pos);
			break;
		}
	}
	return true;
}

bool Engine::Aoi2DEngine::Render()
{
	static int Frames = 0;
	bool Return = true;
	while (Return) {
		time_t start, end;
		start = clock();
		end = clock();
		while ((double)(end - start) < (1000.0 / FPS)) {
			if (!Frame()) {
				Return = false;
			}
			end = clock();
		}

		if (render != nullptr) {
			if (!render(this, render_data)) {
				Return = false;
			}
		}

		if (!graphic->Render()) {
			Return = false;
		}
		
		
		graphic->gotoxy(0, 0);
		graphic->SetColor(0x0, 0xF);
		end = clock();
		printf("������ : %lf : %lf", ((Player*)render_data)->Location.x, ((Player*)render_data)->Location.y);

		Frames++;
		
	}
	return true;
}

void Engine::Aoi2DEngine::Shutdown()
{
	free(keyboard);
	keyboard = 0;
	free(mouse);
	mouse = 0;
	graphic->Shutdown();
	free(graphic);
	graphic = 0;
}

void Engine::Aoi2DEngine::Initialize(bool _cursor)
{
	// �ڵ��� �����ɴϴ�.
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	render = nullptr;

	// â ũ�⸦ �ٲߴϴ�.
	char str[256]; sprintf_s(str, "mode con:lines=%d cols=%d", Size.Y, Size.X);
	system(str);

	// Ŀ���� ���� ����

	CONSOLE_CURSOR_INFO cursorinfo = { 0, };
	cursorinfo.dwSize = 1;
	cursorinfo.bVisible = _cursor;
	SetConsoleCursorInfo(COUT, &cursorinfo);

	// �ܼ�â�� ������ �ٲߴϴ�.
	SetConsoleTitle(Title.c_str());

	
	

	// ���콺 Ȱ��ȭ
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	keyboard = new LibInput::Keyboard();
	mouse = new LibInput::Mouse();
	graphic = new _2D::Graphics2D();
	
	keyboard->Initialize();
	mouse->Initialize();
	graphic->Initialize(Size.X, Size.Y);

}