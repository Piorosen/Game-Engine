#pragma once

namespace Graphics {
	namespace Library {
		template<typename... ARGS>
		class EventHandler {
		private:
			void(*list[10])(ARGS...) = { 0, };

		public:
			bool operator+=(void(*function)(ARGS...));
			bool operator-=(void(*function)(ARGS...));

			bool Clear();

			void BeginInvoke(void(*function)()) const;
			void EndInvoke(void(*function)()) const;
			void XInvoke(void(*begin)(), void(*end)()) const;


			void Invoke(const ARGS... arguments) const;

		};
	}
}

