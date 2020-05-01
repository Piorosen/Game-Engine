#include "Enviroment.h"

void EnviromentTest() {
    switch (Enviroment::OS) {
        case Enviroment::OperatingSystem::Linux:
            cout << "Linux" << endl;
        break;
        case Enviroment::OperatingSystem::MacOS:
            cout << "MacOS" << endl;
        break;
        case Enviroment::OperatingSystem::Windows:
            cout << "Windows" << endl;
        break;
        case Enviroment::OperatingSystem::Others:
            cout << "Others" << endl;
        break;
    }

    switch (Enviroment::Compiler) {
        case Enviroment::KindCompiler::GNUC:
            cout << "GNUC" << endl;
        break;
        case Enviroment::KindCompiler::MingW:
            cout << "MingW" << endl;
        break;
        case Enviroment::KindCompiler::MSVC:
            cout << "MSVC" << endl;
        break;
        case Enviroment::KindCompiler::Others:
            cout << "Others" << endl;
        break;
    }

    switch (Enviroment::Architecture){
        case Enviroment::KindArchitecture::X64:
            cout << "X64" << endl;
        break;
        case Enviroment::KindArchitecture::X86:
            cout << "X86" << endl;
        break;
    }
}

