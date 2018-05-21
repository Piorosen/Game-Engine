#pragma once
#include "DrawLibrary.h"

namespace Engine {
	namespace _2D {
		class Model2D
		{
		private:
			

		public:
			Model2D();
			virtual ~Model2D();

		protected:
			Draw::Point Location;
			Draw::Size Size;

		
		};

	}
}