#pragma once


#include "../defs/defs.h"
#include "utils/window.h"

namespace rpe
{
	class RPE_API Application
	{
	private:
		w32_window* m_wnd;
	public:
		Application();
		void Run();
		virtual ~Application();
	};
}