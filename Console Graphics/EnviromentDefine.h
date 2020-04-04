#pragma once


// OS
#if defined(__APPLE__) && !defined(Enviroment_OS)
#define Enviroment_OS OperatingSystem::MacOS;
#define OS_MACOS true
#define OS_WINDOWS false
#define OS_LINUX false
#define OS_MACOS false
#define OS_OTHERS false

#elif (defined(_WIN64) || defined(_WIN32)) && !defined(Enviroment_OS)
#define Enviroment_OS OperatingSystem::Windows;
#define OS_MACOS false
#define OS_WINDOWS true
#define OS_LINUX false
#define OS_OTHERS false

#elif defined(__linux__) && !defined(Enviroment_OS)
#define Enviroment_OS OperatingSystem::Linux;
#define OS_MACOS false
#define OS_WINDOWS false
#define OS_LINUX true
#define OS_OTHERS false

#else
#define Enviroment_OS OperatingSystem::Others;
#define OS_MACOS false
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
