#pragma once
#include "EnviromentDefine.h"

#if OS_WINDOWS
#include <Windows.h>
#endif

namespace Graphics{
	namespace Enviroment {
		enum class OperatingSystem {
			Windows,
			Linux,
			MacOS,
			Others
		};
		enum class KindCompiler {
			MSVC,
			MingW,
			GNUC,
			Others
		};

		//enum class Architecture {
		//	Bit32,
		//	Bit64
		//};

		constexpr OperatingSystem OS = Enviroment_OS;
		constexpr KindCompiler Compiler = Enviroment_Compiler;


	}
}