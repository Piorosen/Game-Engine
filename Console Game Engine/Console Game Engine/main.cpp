#pragma once

#include <stdio.h> 
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string>

#include "GameEngine.h"
#include "Color.h"

using namespace Engine;


bool rendering(Aoi2DEngine* engine, void** data) {
	static int i = 0;
	auto graphic = engine->GetGraphic2D();
	if (engine->IsClickedMouse()) {
		graphic->SetPixel(engine->GetMousePosition(),
			Draw::Color(i, Draw::ColorList::Black),
			" ");
	}
	if (engine->IsClickedKeyboard('N')) {
		i++;
	}

	if (engine->IsClickedKeyboard('D')) {
		graphic->SetPixel(engine->GetMousePosition(),
			Draw::Color(Draw::ColorList::Black, Draw::ColorList::Black),
			" ");
	}
	if (engine->IsClickedKeyboard(VK_DELETE)) {
		graphic->ScreenClear();
	}
	if (engine->IsClickedKeyboard(VK_ESCAPE)) {
		return false;
	}
	return true;
}


int main()
{
	Engine::Aoi2DEngine* engine = new Engine::Aoi2DEngine(50, 25, "완2성3이당!");

	engine->Initialize(false);
	engine->render = rendering;
	engine->FPS = 1000.0;
	engine->render_data = (void**)engine;

	engine->Render();

	
	engine->Shutdown();
	free(engine);
	engine = 0;
}