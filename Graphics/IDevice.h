#pragma once


namespace Graphics {
    namespace Library {
        namespace Interface {
            class IDevice {
                virtual void Initialize() = 0;
				virtual void Refresh(void*) = 0;

            };
        }
    }
}
