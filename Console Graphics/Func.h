#pragma once

namespace Graphics {
    namespace Library {
        namespace Func {
            template<typename RETURN, typename... ARGS>
            class Func {
            private:
                RETURN(*func)(ARGS...) = nullptr;
                
            public:
                RETURN operator()(const ARGS... args) const {
                    func(args...);
                }
                
                void operator=(RETURN(*function)(ARGS...)) {
                    func = function;
                }
                
                bool operator==(void* value) const {
                    if ((void*)func == value){
                        return true;
                    }else {
                        return false;
                    }
                }
                
                bool operator!=(void* value) const {
                    if ((void*)func != value){
                        return true;
                    }else {
                        return false;
                    }
                }
                
                
            protected:
                
                
            };
        }
    }
}
