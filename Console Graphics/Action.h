#pragma once
#include "Func.h"

namespace Graphics {
    namespace Library {
        namespace Func {
            template<typename... ARGS>
            class Action : public Func<void, ARGS...> {
                
            };
        }
    }
}
