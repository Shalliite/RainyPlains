#include "window.h"

rpe::Window::Window(WindowProperties& props, bool centered) : m_props(props)
{
#ifdef _WIN32
	if (centered)
	{
		m_props.m_posX = (GetSystemMetrics(SM_CXSCREEN) - m_props.m_width) / 2;
		m_props.m_posY = (GetSystemMetrics(SM_CYSCREEN) - m_props.m_height) / 2;
	}
	m_instanceHandle = GetModuleHandle(0);
	m_wndClass.style = CS_OWNDC | CS_VREDRAW | CS_HREDRAW;
	m_wndClass.cbClsExtra = 0;
	m_wndClass.cbSize = sizeof(m_wndClass);
	m_wndClass.cbWndExtra = 0;
	m_wndClass.hbrBackground = 0;
	m_wndClass.hCursor = 0;
	m_wndClass.hIcon = 0;
	m_wndClass.hIconSm = 0;
	m_wndClass.hInstance = m_instanceHandle;
	m_wndClass.lpszClassName = m_props.m_title;
	m_wndClass.lpfnWndProc = CreateMessageHandler;
	m_wndClass.lpszMenuName = 0;
	RegisterClassExW(&m_wndClass);
	m_wndHandle = CreateWindowExW(WS_EX_APPWINDOW, m_props.m_title, m_props.m_title, WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX, m_props.m_posX, m_props.m_posY, m_props.m_width, m_props.m_height, 0, 0, m_instanceHandle, this);
	ShowWindow(m_wndHandle, SW_NORMAL);
#endif
}

rpe::Window::WindowProperties::~WindowProperties()
{}

rpe::Window::~Window()
{}

void rpe::Window::OnClose()
{}

void rpe::Window::OnKeyDown(input::KeyCode)
{}

void rpe::Window::OnKeyUp(input::KeyCode)
{}

void rpe::Window::OnMouseButtonDown(input::MouseBtn, Position)
{}

void rpe::Window::OnMouseButtonUp(input::MouseBtn)
{}

#ifdef _WIN32

LRESULT rpe::Window::CreateMessageHandler(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_NCCREATE)
	{
		Window* wnd = (Window*)lParam;
		SetWindowLongPtrW(windowHandle, GWLP_WNDPROC, (LONG_PTR)StaticMessageHandler);
		SetWindowLongPtrW(windowHandle, GWLP_USERDATA, (LONG_PTR)wnd);
		return wnd->MessageHandler(windowHandle, message, wParam, lParam);
	}
	return DefWindowProcW(windowHandle, message, wParam, lParam);
}

LRESULT rpe::Window::StaticMessageHandler(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam)
{
	Window* wnd = (Window*)GetWindowLongPtrW(windowHandle, GWLP_USERDATA);
	return wnd->MessageHandler(windowHandle, message, wParam, lParam);
}

LRESULT rpe::Window::MessageHandler(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam)
{
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
		uint16 posX = GET_X_LPARAM(lParam);
		uint16 posY = GET_Y_LPARAM(lParam);
		OnMouseButtonDown(input::Left, { posX, posY });
		break;
	case WM_LBUTTONUP:
		OnMouseButtonUp(input::Right);
		break;
	}
	return DefWindowProcW(windowHandle, message, wParam, lParam);
}

#endif