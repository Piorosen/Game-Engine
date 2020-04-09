#pragma once

#include "Func.h"


namespace Graphics {
    namespace Library {
        namespace Func {
            template<typename... ARGS>
            class Predicate : public Func<bool, ARGS...> {
                
            };
        }
    }
}
