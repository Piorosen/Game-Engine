#pragma once

#include <Windows.h>
#include <string>
#include <ctime>

#include "DrawLibrary.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics2D.h"


namespace Engine {
	class Aoi2DEngine {
	private:
		Draw::Point Size;
		std::string Title;
		
		LibInput::Keyboard* keyboard;
		LibInput::Mouse* mouse;
		_2D::Graphics2D* graphic;

		DWORD mode;

		HANDLE CIN = 0; // 입력 키보드, 마우스
		HANDLE COUT = 0; // 출력 모니터

		int be_input()
		{
			INPUT_RECORD input_record;
			DWORD input_count;
			PeekConsoleInput(CIN, &input_record, 1, &input_count);
			return input_count;
		}

		INPUT_RECORD select_input()
		{
			INPUT_RECORD input_record;
			DWORD input_count;
			ReadConsoleInput(CIN, &input_record, 1, &input_count);
			return input_record;
		}
		
		bool Frame();


	public:	
		double FPS = 60.0;
		bool(*render)(Aoi2DEngine* engine, void** data) = nullptr;
		void** render_data = nullptr;

		Aoi2DEngine(int _x, int _y, std::string title) 
		{
			Size.X = _x; Size.Y = _y; Title = title;
			keyboard = new LibInput::Keyboard();
		}


		bool IsClickedKeyboard(unsigned short ch) const
		{
			return keyboard->IsKeyDown(ch);
		}
		
		bool IsClickedtMouse() const
		{
			return mouse->IsClicked();
		}
		
		Draw::Point GetClickMousePosition() {
			return mouse->GetMousePosition();
		}


		inline _2D::Graphics2D* GetGraphic2D() {
			return graphic;
		}

		bool Render();
		void Shutdown();

		void Initialize(bool _cursor = FALSE);

	protected:



	};
}