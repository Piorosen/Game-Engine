# Game-Engine


+ namespace: Engine
	+ class: Aoi2DEngine
		```
		bool IsClickedKeyboard(unsigned ch) const
		bool IsClickedMouse
		
		Point GetMousePosition() const
		Point GetClickmousePosition() const
		Graphics2D GetGraphic2D() const
		```
	+ namespace: _2D
		+ class: Graphics2D
			```
			SetPixel(Point, Color, std::string)
			SetPixel(int, int, Color, std::string)
			gotoxy(int, int)
			gotoxy(Point)
			SetColor(char, char)
			SetColor(Color)
			ScreenClear()
			```

	+ namespace: Draw
		+ Point
			```
			int X
			int Y
			```
		+ Color
			```
			BackColor
			TextColor
			```

		+ ColorList
			```
			char Black
			char Blue
			char Green
			char BluGreen
			char Red 0
			char YellRed
			char Yellow 
			char White
			char Gray 
			char WhiteBlue
			char WhiteGreen 
			char WhiteBluGreen 
			char WhiteRed
			char WhiteYellRed
			char WhiteYellow 
			char WhiteWhite 
			```

		+ Graphic_Pixel
			```
			SetPixel(Color, char)
			Color GetColor() const
			char GetText() const
			```
