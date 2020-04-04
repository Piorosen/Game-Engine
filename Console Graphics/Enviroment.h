#pragma once
#include "EnviromentDefine.h"
namespace Graphics{
	namespace Enviroment {
		enum class OperatingSystem {
			Windows,
			Linux,
			MacOS
		};
		enum class KindCompiler {
			MSVC,
			MingW,
			GNUC,
		};

		//enum class Architecture {
		//	Bit32,
		//	Bit64
		//};

		constexpr OperatingSystem OS = Enviroment_OS;
		constexpr KindCompiler Compiler = Enviroment_Compiler;

	}
}