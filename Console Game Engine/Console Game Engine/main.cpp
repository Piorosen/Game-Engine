#pragma once

#include <stdio.h> 
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string>

#include "GameEngine.h"
#include "Color.h"
bool rendering(Engine::Aoi2DEngine* engine, void** data) {
	if (engine->IsClickedKeyboard(VK_ESCAPE)) {
		return false;
	}
	return true;
}

int main()
{
	Engine::Aoi2DEngine* engine = new Engine::Aoi2DEngine(50, 25, L"완2성3이당!");

	engine->Initialize();
	engine->render = rendering;
	engine->FPS = 144.0;
	engine->render_data = (void**)engine;

	engine->Render();

	
	engine->Shutdown();
	free(engine);
	engine = 0;
}