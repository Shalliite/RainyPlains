
/*
*
* This header/source is part of RainyPlains game/rendering engine originally developed by Deivids Dukalskis
*
*/


/*
* External headers
*/
//
#include <Windows.h>
//


/*
* Internal headers
*/
//
#include "../../Defines/Defines.h"
//

namespace rpe
{
	RPE_EXTERN RPE_API struct Native_Wnd_WindowStruct
	{
		rpe::ptr hostWindow;
		rpe::ptr instanceHandle;
		char* wndClass;
	};

	RPE_EXTERN RPE_API Native_Wnd_WindowStruct Native_Wnd_CreateWindow(rpe::ptr parent)
	{
		Native_Wnd_WindowStruct nws;
		nws.wndClass = "window";
		nws.instanceHandle = GetModuleHandle(0);
		WNDCLASSEXA wc;
		wc.cbClsExtra = 0;
		wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
		wc.cbSize = sizeof(wc);
		wc.hCursor = 0;
		wc.hbrBackground = 0;
		wc.hInstance = (HINSTANCE)nws.instanceHandle;
		wc.lpszClassName = nws.wndClass;
		wc.hIcon = 0;
		wc.hIconSm = 0;
		wc.cbWndExtra = 0;
		wc.lpfnWndProc = DefWindowProc;
		wc.lpszMenuName = 0;
		RegisterClassExA(&wc);
		nws.hostWindow = CreateWindowExA(0, nws.wndClass, nws.wndClass, WS_CHILD, 0, 0, 0, 0, (HWND)parent, 0, (HINSTANCE)nws.instanceHandle, 0);
		ShowWindow((HWND)nws.hostWindow, SW_NORMAL);
		return nws;
	}

	RPE_EXTERN RPE_API void Native_Wnd_DestroyWindow(Native_Wnd_WindowStruct nws)
	{
		DestroyWindow((HWND)nws.hostWindow);
		UnregisterClassA(nws.wndClass, (HINSTANCE)nws.instanceHandle);
		
	}
}