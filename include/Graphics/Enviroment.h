#pragma once

// OS
#if defined(__APPLE__) && !defined(Enviroment_OS)
	#define Enviroment_OS OperatingSystem::MacOS;
	#define OS_MAC true
	#define OS_WINDOWS false
	#define OS_LINUX false
	#define OS_OTHERS false
#elif (defined(_WIN64) || defined(_WIN32)) && !defined(Enviroment_OS)
	#define Enviroment_OS OperatingSystem::Windows;
	#define OS_MAC false
	#define OS_WINDOWS true
	#define OS_LINUX false
	#define OS_OTHERS false
#elif defined(__linux__) && !defined(Enviroment_OS)
	#define Enviroment_OS OperatingSystem::Linux;
	#define OS_MAC false
	#define OS_WINDOWS false
	#define OS_LINUX true
	#define OS_OTHERS false
#else
	#define Enviroment_OS OperatingSystem::Others;
	#define OS_MAC false
	#define OS_WINDOWS false
	#define OS_LINUX false
	#define OS_OTHERS true
#endif

// Compiler
#if defined(_MSC_VER) && !defined(Enviroment_Compiler)
	#define Enviroment_Compiler KindCompiler::MSVC;
	#define COMPILER_MSVC true
	#define COMPILER_GNUC false
	#define COMPILER_MINGW false
	#define COMPILER_OTHERS false
#elif defined(__GNUC__) && !defined(Enviroment_Compiler)
	#define Enviroment_Compiler KindCompiler::GNUC;
	#define COMPILER_MSVC false
	#define COMPILER_GNUC true
	#define COMPILER_MINGW false
	#define COMPILER_OTHERS false
#elif (defined(__MINGW32__) || defined(__MINGW64__)) && !defined(Enviroment_Compiler)
	#define Enviroment_OS KindCompiler::MingW;
	#define COMPILER_MSVC false
	#define COMPILER_GNUC false
	#define COMPILER_MINGW true
	#define COMPILER_OTHERS false
#else
	#define Enviroment_OS KindCompiler::Others;
	#define COMPILER_MSVC false
	#define COMPILER_GNUC false
	#define COMPILER_MINGW false
	#define COMPILER_OTHERS true
#endif

// Architecture
#if OS_WINDOWS
	#if defined(_WIN64)
		#define Enviroment_Architecture KindArchitecture::X64
		#define ARCHITECTURE_X64 true
		#define ARCHITECTURE_X86 false
	#elif defined(_WIN32)
		#define Enviroment_Architecture KindArchitecture::X86
		#define ARCHITECTURE_X64 false
		#define ARCHITECTURE_X86 true
	#endif
#elif COMPILER_GNUC
	#if __x86_64__ || __ppc64__
		#define Enviroment_Architecture KindArchitecture::X64
		#define ARCHITECTURE_X64 true
		#define ARCHITECTURE_X86 false
	#else
		#define Enviroment_Architecture KindArchitecture::X86
		#define ARCHITECTURE_X64 false
		#define ARCHITECTURE_X86 true
	#endif	
#else
	#define Enviroment_Architecture KindArchitecture::Others
	#define ARCHITECTURE_X64 false
	#define ARCHITECTURE_X86 false
#endif

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

		enum class KindArchitecture {
			X86,
			X64,
			Others
		};

		constexpr OperatingSystem OS = Enviroment_OS;
		constexpr KindCompiler Compiler = Enviroment_Compiler;
		constexpr KindArchitecture Architecture = Enviroment_Architecture;
	}
}