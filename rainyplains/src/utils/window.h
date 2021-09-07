#pragma once

#include "../../defs/defs.h"
#include "inputmappings.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"

#ifdef _WIN32
#include "w32.h"
#endif


namespace rpe
{
	class Window
	{
	public:
		Window() = delete;
		static Window* Create(uint16 width, uint16 height, const wchar_t* title);
		static void Destroy(Window*);
	public:
		static void OnClose();
		static void OnKeyDown(input::KeyCode);
		static void OnKeyUp(input::KeyCode);
		static void OnMouseButtonDown(input::MouseBtn);
		static void OnMouseButtonUp(input::MouseBtn);
	public:
#ifdef _WIN32
		static PCWSTR s_title;
		static HINSTANCE s_instanceHandle;
		static WNDCLASSEXW s_wndClass;
		static HWND s_wndHandle;
		static LRESULT CALLBACK MessageHandler(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);
#endif
	};
}
