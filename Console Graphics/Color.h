#pragma once
#include "Enviroment.h"

namespace Graphics{
	enum class Color {
#if OS_WINDOWS
		Black	=	0,	Gray		=	8,
		Blue	=	1,	LightBlue	=	9,
		Green	=	2,	LightGreen	=	0xA,
		Aqua	=	3,	LightAqua	=	0xB,
		Red		=	4,	LightRed	=	0xC,
		Purple	=	5, LightPurple	=	0xD,
		Yellow	=	6, LightYellow	=	0xE,
		White	=	7,	BrightWhite	 =	0xF,
#elif OS_MACOS || OS_LINUX
		ForgroundBlack		= 30, ForgroundBlack	= 40,
		ForgroundRed		= 31, ForgroundRed		= 41,
		ForgroundGreen		= 32, ForgroundGreen	= 42,
		ForgroundYellow		= 33, ForgroundYellow	= 43,
		ForgroundBlue		= 34, ForgroundBlue		= 44,
		ForgroundMagenta	= 35, ForgroundMagenta	= 45,
		ForgroundCyan		= 36, ForgroundCyan		= 46,
		ForgroundWhite		= 37, ForgroundWhite	= 47,
#endif
	};
	enum class Font {
#if OS_MACOS || OS_LINUX
		reset			 = 0,	// (everything back to normal)
		BoldAndBrightOn  = 1,	// (often a brighter shade of the same colour)
		UnderLineOn		 = 4,
		InverseOn		 = 7,	// (swap foreground and background colours)
		BoldAndBrightOff = 21,
		UnderLineOff	 = 24,
		InverseOff		 = 27
#endif
	};
}