#include "window.h"

rpe::Window* rpe::Window::Create(u16 width, u16 height, const wchar_t* title)
{
	s_width = width;
	s_height = height;
#ifdef _WIN32
	u16 posX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
	u16 posY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	s_instanceHandle = GetModuleHandle(0);
	s_wndClass.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
	s_wndClass.cbClsExtra = 0;
	s_wndClass.cbSize = sizeof(s_wndClass);
	s_wndClass.cbWndExtra = 0;
	s_wndClass.hbrBackground = 0;
	s_wndClass.hCursor = 0;
	s_wndClass.hIcon = 0;
	s_wndClass.hIconSm = 0;
	s_wndClass.hInstance = s_instanceHandle;
	s_wndClass.lpszClassName = title;
	s_wndClass.lpfnWndProc = MessageHandler;
	s_wndClass.lpszMenuName = 0;
	RegisterClassExW(&s_wndClass);
	s_wndHandle = CreateWindowExW(0, title, title, WS_SYSMENU, posX, posY, width, height, 0, 0, s_instanceHandle, 0);
	ShowWindow(s_wndHandle, SW_NORMAL);
	return (Window*)s_wndHandle;
#endif
}

void rpe::Window::Destroy(Window* wnd)
{
#ifdef _WIN32
	DestroyWindow((HWND)wnd);
	UnregisterClass(s_title, s_instanceHandle);
#endif
}

#ifdef _WIN32

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);

LRESULT rpe::Window::MessageHandler(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProcW(windowHandle, message, wParam, lParam);
}

PCWSTR rpe::Window::s_title;
HINSTANCE rpe::Window::s_instanceHandle;
WNDCLASSEXW rpe::Window::s_wndClass;
HWND rpe::Window::s_wndHandle;
rpe::u16 rpe::Window::s_width;
rpe::u16 rpe::Window::s_height;

#endif