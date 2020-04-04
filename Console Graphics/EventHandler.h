#pragma once

namespace Graphics {
	template<typename... ARGS>
	class EventHandler {
	private:
		int index = 0;
		void(*list[10])(ARGS...) = { 0, };

	public:
		bool operator+=(void(*function)(ARGS...)) {
			list[index] = function;
			index++;
			return true;
		}
		bool operator-=(void(*function)(ARGS...));

		bool Clear() {
			for (auto i : list) {
				i = 0;
			}
		}
		
		void BeginInvoke(void(*function)()) {
			function();
			Invoke();
		}
		void EndInvoke(void(*function)()) {
			Invoke();
			function();
		}
		void XInvoke(void(*begin)(), void(*end)()) {
			begin();
			Invoke();
			end();
		}


		void Invoke(ARGS... arguments) {
			for (auto i : list) {
				if (i != nullptr) {
					i(arguments...);
				}
			}
		}
		
	};


}

