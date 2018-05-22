#pragma once
#include "Model2D.h"


namespace Engine {
	namespace _2D {
		namespace Model2Ds {
			class Rect : public Model2D
			{
			public:
				Rect(Draw::Point _Location, Draw::Size _Size,
						Draw::Color _Outer, Draw::Color _Inner, char _Text = ' ')
				{
					Location = _Location;
					Size = _Size;
					Text = _Text;
					Outer = _Outer;
					Inner = _Inner;
				}

			};
		}
	}
}