#pragma once
#include "Func.h"

namespace Graphics {
    namespace Library {
        namespace Function {
            template<typename... ARGS>
            using Action = Func<void, ARGS...>;
        }
    }
}
