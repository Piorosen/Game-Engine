#pragma once

#include "Func.h"

namespace Graphics
{
	template <typename... ARGS>
	class EventHandler
	{
	private:
		Graphics::Func<void, ARGS...> list[10];

	public:
		bool operator+=(void (*function)(ARGS...))
		{
			for (auto &i : list)
			{
				if (i == nullptr)
				{
					i = function;
					return true;
				}
			}
			return false;
		}

		bool operator+=(Graphics::Action<ARGS...> function)
		{
			for (auto &i : list)
			{
				if (i == nullptr)
				{
					i = function;
					return true;
				}
			}
			return false;
		}

		bool operator-=(void (*function)(ARGS...))
		{
			for (auto &i : list)
			{
				if (i == (void *)function)
				{
					i = nullptr;
					return true;
				}
			}
			return false;
		}

		bool operator-=(Graphics::Action<ARGS...> function)
		{
			for (auto &i : list)
			{
				if (i == (void *)function)
				{
					i = nullptr;
					return true;
				}
			}
			return false;
		}

		bool Clear()
		{
			for (auto i : list)
			{
				i = 0;
			}
			return true;
		}

		void BeginInvoke(void (*function)(), const ARGS... arguments) const
		{
			function();
			Invoke(arguments...);
		}
		void EndInvoke(void (*function)(), const ARGS... arguments) const
		{
			Invoke(arguments...);
			function();
		}

		void XInvoke(void (*begin)(), void (*end)()) const
		{
			begin();
			Invoke();
			end();
		}

		void Invoke(const ARGS... arguments) const
		{
			for (auto &i : list)
			{
				if (i != nullptr)
				{
					i(arguments...);
				}
			}
		}
	};
} // namespace Graphics