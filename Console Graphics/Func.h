#pragma once

namespace Graphics {
    namespace Library {
        namespace Function {
            template<typename RETURN, typename... ARGS>
            class Func {
            protected:
                RETURN(*func)(ARGS...) = nullptr;
                
            public:
                Func(){
                    func = nullptr;
                }
                
                Func(RETURN(*function)(ARGS...)){
                    this->func = function;
                }
                
                RETURN operator()(const ARGS... args) const {
                    return func(args...);
                }
                
                Func<RETURN, ARGS...> operator=(RETURN(*function)(ARGS...)) {
                    func = function;
                    return func;
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
                
            };
        }
    }
}