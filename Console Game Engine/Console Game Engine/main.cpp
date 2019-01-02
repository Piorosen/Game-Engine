#pragma once

#include <iostream>

#include "GameEngine.h"
#include "Rect.h"

#include "Player.hpp"


using namespace Engine;
using namespace Engine::_2D::Model2Ds;
using namespace Engine::Draw;


bool rendering(Aoi2DEngine* engine, void** data) {
	Player* player = (Player*)data;

	engine->GetGraphic2D()->ScreenClear();
	if (engine->IsClickedKeyboard(VK_UP)) {
		player->Move(true);
	}
	if (engine->IsClickedKeyboard(VK_DOWN)) {
		player->Move(false);
	}
	if (engine->IsClickedKeyboard(VK_LEFT)) {
		player->Rotate(-10);
	}
	if (engine->IsClickedKeyboard(VK_RIGHT)) {
		player->Rotate(10);
	}

	player->Draw(100, 40, engine);
	return true;
}

int main()
{
	Aoi2DEngine* engine = new Aoi2DEngine(100, 40, "완성이당!");

	engine->Initialize(false);
	engine->render = rendering;
	engine->FPS = 15.0;

	Player* tmp = new Player(5, 4);
	tmp->MapLoad("D:\\map.txt");

	engine->render_data = (void**)(tmp);
	engine->Render();
	
	engine->Shutdown();
	free(engine);
	engine = 0;
}