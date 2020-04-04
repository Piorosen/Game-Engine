#pragma once


// OS
#if defined(__APPLE__) && !defined(Enviroment_OS)
#define Enviroment_OS OperatingSystem::MacOS;
#elif (defined(_WIN64) || defined(_WIN32)) && !defined(Enviroment_OS)
#define Enviroment_OS OperatingSystem::Windows;
#elif defined(__linux__) && !defined(Enviroment_OS)
#define Enviroment_OS OperatingSystem::Linux;
#endif

// Compiler
#if defined(_MSC_VER) && !defined(Enviroment_Compiler)
#define Enviroment_Compiler KindCompiler::MSVC;
#elif defined(__GNUC__) && !defined(Enviroment_Compiler)
#define Enviroment_Compiler KindCompiler::GNUC;
#elif (defined(__MINGW32__) || defined(__MINGW64__)) && !defined(Enviroment_Compiler)
#define Enviroment_OS KindCompiler::MingW;
#endif
