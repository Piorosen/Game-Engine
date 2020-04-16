#pragma once

namespace Graphics {
    namespace Library {
        namespace Function {
            template<typename RETURN, typename... ARGS>
            class Func {
            protected:
                RETURN(*func)(ARGS...) = nullptr;
                
            public:
                Func();
                Func(RETURN(*function)(ARGS...));
                
                RETURN operator()(const ARGS... args) const;
                
                Func<RETURN, ARGS...> operator=(RETURN(*function)(ARGS...));
                
                bool operator==(void* value) const;
                
                bool operator!=(void* value) const;
                
            };

            template<typename... ARGS>
            using Action = Func<void, ARGS...>;
            
            template<typename... ARGS>
            using Predicate = Func<bool, ARGS...>;
        }
    }
}

#include "Func.h"