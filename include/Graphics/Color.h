#pragma once
#include "Enviroment.h"

namespace Graphics
{
	enum class ColorBackground
	{
#if OS_WINDOWS
		Black = 0,
		Gray = 8,
		Blue = 1,
		LightBlue = 9,
		Green = 2,
		LightGreen = 0xA,
		Aqua = 3,
		LightAqua = 0xB,
		Red = 4,
		LightRed = 0xC,
		Purple = 5,
		LightPurple = 0xD,
		Yellow = 6,
		LightYellow = 0xE,
		White = 7,
		BrightWhite = 0xF,
#elif OS_MAC || OS_LINUX
		Black = 40,
		Red = 41,
		Green = 42,
		Yellow = 43,
		Blue = 44,
		Magenta = 45,
		Cyan = 46,
		White = 47,

#endif
	};
	enum class ColorForground
	{
#if OS_WINDOWS
		Black = 0,
		Gray = 8,
		Blue = 1,
		LightBlue = 9,
		Green = 2,
		LightGreen = 0xA,
		Aqua = 3,
		LightAqua = 0xB,
		Red = 4,
		LightRed = 0xC,
		Purple = 5,
		LightPurple = 0xD,
		Yellow = 6,
		LightYellow = 0xE,
		White = 7,
		BrightWhite = 0xF,
#elif OS_MAC || OS_LINUX
		Black = 30,
		Red = 31,
		Green = 32,
		Yellow = 33,
		Blue = 34,
		Magenta = 35,
		Cyan = 36,
		White = 37,
#endif
	};

	class Color
	{
	private:
		ColorForground Forground;
		ColorBackground Background;

	public:
		Color();
		Color(ColorForground forground, ColorBackground background);

		bool operator==(const Color &c) const;
		bool operator!=(const Color &c) const;

		ColorForground GetForground() const;
		ColorBackground GetBackground() const;
	};
	
} // namespace Graphics