#pragma once

#include "Func.h"

namespace Graphics {
	namespace Library {
		template<typename... ARGS>
		class EventHandler {
		private:
            Function::Func<void, ARGS...> list[10];

		public:
			bool operator+=(void(*function)(ARGS...));
            bool operator+=(Function::Action<ARGS...> function);
            
			bool operator-=(void(*function)(ARGS...));
            bool operator-=(Function::Action<ARGS...> function);
            
			bool Clear();

			void BeginInvoke(void(*function)(), const ARGS... arguments) const;
			void EndInvoke(void(*function)(), const ARGS... arguments) const;
			void XInvoke(void(*begin)(), void(*end)()) const;

			void Invoke(const ARGS... arguments) const;

		};
	}
}

