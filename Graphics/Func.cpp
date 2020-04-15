#include "Func.h"

template <typename RETURN, typename... ARGS>
Graphics::Library::Function::Func<RETURN, ARGS...>::Func()
{
    func = nullptr;
}

template <typename RETURN, typename... ARGS>
Graphics::Library::Function::Func<RETURN, ARGS...>::Func(RETURN (*function)(ARGS...))
{
    this->func = function;
}

template <typename RETURN, typename... ARGS>
RETURN Graphics::Library::Function::Func<RETURN, ARGS...>::operator()(const ARGS... args) const
{
    return func(args...);
}

template <typename RETURN, typename... ARGS>
Graphics::Library::Function::Func<RETURN, ARGS...> Graphics::Library::Function::Func<RETURN, ARGS...>::operator=(RETURN (*function)(ARGS...))
{
    func = function;
    return func;
}

template <typename RETURN, typename... ARGS>
bool Graphics::Library::Function::Func<RETURN, ARGS...>::operator==(void *value) const
{
    if ((void *)func == value)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <typename RETURN, typename... ARGS>
bool Graphics::Library::Function::Func<RETURN, ARGS...>::operator!=(void *value) const
{
    if ((void *)func != value)
    {
        return true;
    }
    else
    {
        return false;
    }
}