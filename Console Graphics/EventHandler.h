#pragma once

namespace Graphics {
	namespace Library {
		template<typename... ARGS>
		class EventHandler {
		private:
			void(*list[10])(ARGS...) = { 0, };

		public:
			bool operator+=(void(*function)(ARGS...)) {
				for (auto& i : list) {
					if (i == nullptr) {
						i = function;
						return true;
					}
				}
				return false;
			}
			bool operator-=(void(*function)(ARGS...)) {
				for (auto& i : list) {
					if (i == function) {
						i = nullptr;
						return true;
					}
				}
				return false;
			}

			bool Clear() {
				for (auto i : list) {
					i = 0;
				}
			}

			void BeginInvoke(void(*function)()) const {
				function();
				Invoke();
			}
			void EndInvoke(void(*function)()) const {
				Invoke();
				function();
			}
			void XInvoke(void(*begin)(), void(*end)()) const {
				begin();
				Invoke();
				end();
			}

			void Invoke(const ARGS... arguments) const {
				for (auto& i : list) {
					if (i != nullptr) {
						i(arguments...);
					}
				}
			}

		};
	}
}

