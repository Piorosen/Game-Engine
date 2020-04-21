// #include "EventHandler.h"

// template <typename... ARGS>
// bool Graphics::Library::EventHandler<ARGS...>::operator+=(void (*function)(ARGS...))
// {
//     for (auto &i : list)
//     {
//         if (i == nullptr)
//         {
//             i = function;
//             return true;
//         }
//     }
//     return false;
// }

// template <typename... ARGS>
// bool Graphics::Library::EventHandler<ARGS...>::operator+=(Function::Action<ARGS...> function)
// {
//     for (auto &i : list)
//     {
//         if (i == nullptr)
//         {
//             i = function;
//             return true;
//         }
//     }
//     return false;
// }
// template <typename... ARGS>
// bool Graphics::Library::EventHandler<ARGS...>::operator-=(void (*function)(ARGS...))
// {
//     for (auto &i : list)
//     {
//         if (i == (void *)function)
//         {
//             i = nullptr;
//             return true;
//         }
//     }
//     return false;
// }

// template <typename... ARGS>
// bool Graphics::Library::EventHandler<ARGS...>::operator-=(Function::Action<ARGS...> function)
// {
//     for (auto &i : list)
//     {
//         if (i == (void *)function)
//         {
//             i = nullptr;
//             return true;
//         }
//     }
//     return false;
// }
// template <typename... ARGS>
// bool Graphics::Library::EventHandler<ARGS...>::Clear()
// {
//     for (auto i : list)
//     {
//         i = 0;
//     }
// }

// template <typename... ARGS>
// void Graphics::Library::EventHandler<ARGS...>::Invoke(const ARGS... arguments) const
// {
//     for (auto &i : list)
//     {
//         if (i != nullptr)
//         {
//             i(arguments...);
//         }
//     }
// }

// template <typename... ARGS>
// void Graphics::Library::EventHandler<ARGS...>::BeginInvoke(void (*function)(), const ARGS... arguments) const
// {
//     function();
//     Invoke(arguments...);
// }

// template <typename... ARGS>
// void Graphics::Library::EventHandler<ARGS...>::XInvoke(void (*begin)(), void (*end)()) const
// {
//     begin();
//     Invoke();
//     end();
// }

// template <typename... ARGS>
// void Graphics::Library::EventHandler<ARGS...>::EndInvoke(void (*function)(), const ARGS... arguments) const
// {
//     Invoke(arguments...);
//     function();
// }
