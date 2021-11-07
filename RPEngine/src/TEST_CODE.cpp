#include "rainyapi.h"


rpe::D3D11Renderer* a_rend = nullptr;
WNDCLASSEXW a_wc = {};
PCWSTR a_className = L"surf";
HWND a_hwnd = nullptr;
HWND a_parentHwnd = nullptr;
rpe::u16 a_width = 0;
rpe::u16 a_height = 0;
MSG a_msg = {};

static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (hWnd == a_hwnd) {
		switch (msg)
		{
		case WM_PAINT:
			a_rend->ClearBuffer(0.0f, 0.0f, 0.0f);
			a_rend->DrawTriangle({ -0.5f, -0.5f, 1.0f, 0.0f, 0.0f }, { 0.0f, 0.5f, 0.0f, 1.0f, 0.0f }, { 0.5f, -0.5f, 0.0f, 0.0f, 1.0f });
			a_rend->SwapBuffers();
			break;
		case WM_SIZE:
			a_rend->ResizeBuffer(a_width, a_height);
			break;
		}
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}
extern "C" _declspec(dllexport) void CreateWnd(HWND parentHwnd, rpe::u16 width, rpe::u16 height)
{
	a_width = width;
	a_height = height;
	a_wc.cbSize = sizeof(a_wc);
	a_wc.hCursor = 0;
	a_wc.hbrBackground = 0;
	a_wc.hInstance = GetModuleHandle(0);
	a_wc.lpszClassName = a_className;
	a_wc.lpfnWndProc = WndProc;
	a_wc.cbClsExtra = 0;
	a_wc.cbWndExtra = 0;
	a_wc.hIcon = 0;
	a_wc.hIconSm = 0;
	a_wc.lpszMenuName = 0;
	a_wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
	RegisterClassExW(&a_wc);
	a_hwnd = CreateWindowExW(0, a_className, a_className, WS_CHILD, 0, 0, a_width, a_height, parentHwnd, 0, GetModuleHandle(0), 0);
	ShowWindow(a_hwnd, SW_NORMAL);
}


extern "C" _declspec(dllexport) void DestroyWnd()
{
	DestroyWindow(a_hwnd);
	UnregisterClassW(a_className, GetModuleHandle(0));
}

extern "C" _declspec(dllexport) void CreateD3D11()
{
	a_rend = new rpe::D3D11Renderer(a_hwnd);
}
extern "C" _declspec(dllexport) void RenderD3D11(double width, double height)
{
	a_width = (rpe::u16)width;
	a_height = (rpe::u16)height;
}

extern "C" _declspec(dllexport) HWND GetWindowHandle()
{
	return a_hwnd;
}