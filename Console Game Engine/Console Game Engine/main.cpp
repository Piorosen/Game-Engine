#pragma once

#include <stdio.h> 
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string>

#include "GameEngine.h"
#include "Rect.h"

using namespace Engine;
using namespace Engine::_2D::Model2Ds;
using namespace Engine::Draw;


bool rendering(Aoi2DEngine* engine, void** data) {
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

	if (pt.X < 0)
		pt.X = 0;
	else if (pt.X > 144) {
		pt.X = 144;
	}if (pt.Y < 0) {
		pt.Y = 0;
	}
	else if (pt.Y > 37) {
		pt.Y = 37;
	}

	Rect rect = Rect(Point(0, 0), Size(150, 40), Color(0xf, 0x4), Color(0x2, 0x9));
	graphic->DrawModel(rect, 2);


	Rect rect2 = Rect(pt, Size(6, 3), Color(0x0, 0x0), Color(0x3, 0x3));
	graphic->DrawModel(rect2, 2);

	if (engine->IsClickedKeyboard(VK_ESCAPE)) {
		return false;
	}
	if (engine->IsClickedKeyboard(VK_DELETE)) {
		graphic->ScreenClear();
	}

	return true;
}

int main()
{
	Engine::Aoi2DEngine* engine = new Engine::Aoi2DEngine(150, 40, "완2성3이당!");

	engine->Initialize(false);
	engine->render = rendering;
	engine->FPS = 2000.0;
	engine->render_data = (void**)engine;

	engine->Render();
	
	engine->Shutdown();
	free(engine);
	engine = 0;
}