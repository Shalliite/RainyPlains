#include "window.h"

rpe::Window* rpe::Window::Create(uint16 width, uint16 height, const wchar_t* title)
{
#ifdef _WIN32
	uint16 posX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
	uint16 posY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
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
	s_wndHandle = CreateWindowExW(WS_EX_APPWINDOW, title, title, WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, posX, posY, width, height, 0, 0, s_instanceHandle, 0);
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

void rpe::Window::OnClose()
{
	PostQuitMessage(0);
}

void rpe::Window::OnKeyDown(input::KeyCode)
{}

void rpe::Window::OnKeyUp(input::KeyCode)
{}

void rpe::Window::OnMouseButtonDown(input::MouseBtn)
{}

void rpe::Window::OnMouseButtonUp(input::MouseBtn)
{}

#ifdef _WIN32

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);

LRESULT rpe::Window::MessageHandler(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam)
{
	uint16 posX = 0;
	uint16 posY = 0;
	ImGui_ImplWin32_WndProcHandler(windowHandle, message, wParam, lParam);
	switch (message)
	{
	case WM_CLOSE:
		OnClose();
		break;
	case WM_KEYDOWN:
		OnKeyDown((void*)wParam);
		break;
	case WM_KEYUP:
		OnKeyUp((void*)wParam);
		break;
	case WM_LBUTTONDOWN:
		posX = GET_X_LPARAM(lParam);
		posY = GET_Y_LPARAM(lParam);
		OnMouseButtonDown(input::Left);
		break;
	case WM_LBUTTONUP:
		OnMouseButtonUp(input::Left);
		break;
	}
	return DefWindowProcW(windowHandle, message, wParam, lParam);
}

PCWSTR rpe::Window::s_title;
HINSTANCE rpe::Window::s_instanceHandle;
WNDCLASSEXW rpe::Window::s_wndClass;
HWND rpe::Window::s_wndHandle;

#endif