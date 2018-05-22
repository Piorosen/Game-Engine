#pragma once

#include <stdio.h> 
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string>

#include "GameEngine.h"
#include "Rect.h"

using namespace Engine;


bool rendering(Aoi2DEngine* engine, void** data) {
	static int i = 0;
	i++;

	static Draw::Point pt = Draw::Point(20, 10);
	auto graphic = engine->GetGraphic2D();
	
	if (engine->IsClickedKeyboard(VK_UP)) {
		pt.Y -= 1;
	}
	if (engine->IsClickedKeyboard(VK_DOWN)) {
		pt.Y += 1;
	}
	if (engine->IsClickedKeyboard(VK_LEFT)) {
		pt.X -= 2;
	}
	if (engine->IsClickedKeyboard(VK_RIGHT)) {
		pt.X += 2;
	}
	graphic->ScreenClear();
	graphic->SetPixel(pt, Draw::Color(0xf, 0), "뭐야 이 시발것은");

	if (engine->IsClickedKeyboard(VK_ESCAPE)) {
		return false;
	}
	return true;
}
void gotoxy(int x, int y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x & 0xffff, y & 0xffff });
}

int main()
{
	char a[256] = "뭐야 이새키는";
	for (int i = 0; i < strlen(a); i++) {
		putchar(a[i]);
	}


	Engine::Aoi2DEngine* engine = new Engine::Aoi2DEngine(150, 40, "완2성3이당!");

	engine->Initialize(false);
	engine->render = rendering;
	engine->FPS = 30.0;
	engine->render_data = (void**)engine;

	engine->Render();
	
	engine->Shutdown();
	free(engine);
	engine = 0;
}