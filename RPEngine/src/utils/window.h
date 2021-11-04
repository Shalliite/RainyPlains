#pragma once

#include "../../defs/defs.h"
#include "inputmappings.h"


#ifdef _WIN32
#include "w32.h"
#endif


namespace rpe
{
	extern "C" {
		class RPE_API Window
		{
		public:
			Window() = delete;
			static Window* Create(uint16 width, uint16 height, const wchar_t* title);
			static void Destroy(Window*);
		public:
			static uint16 s_width;
			static uint16 s_height;
	#ifdef _WIN32
			static PCWSTR s_title;
			static HINSTANCE s_instanceHandle;
			static WNDCLASSEXW s_wndClass;
			static HWND s_wndHandle;
			static LRESULT CALLBACK MessageHandler(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);
	#endif
		};
	}
}
