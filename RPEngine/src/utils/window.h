#pragma once

#include "../../defs/defs.h"
#include "inputmappings.h"
#include <string>

#ifdef _WIN32
#include "w32.h"
#endif


namespace rpe
{
	class RPE_API Window
	{
	public:
		struct WindowProperties
		{
			WindowProperties(uint16 width, uint16 height, uint16 posX, uint16 posY, const wchar_t* title)
				: m_width(width = 800), m_height(height = 600), m_posX(posX = ), m_posY(posY), m_title(title) {}
			~WindowProperties();
			uint16 m_width;
			uint16 m_height;
			uint16 m_posX;
			uint16 m_posY;
			const wchar_t* m_title;
		};
		struct Position
		{
			uint16 m_posX;
			uint16 m_posY;
		};
	public:
		Window(WindowProperties&, bool centered);
		virtual ~Window();
	protected:
		virtual void OnClose();
		virtual void OnKeyDown(input::KeyCode);
		virtual void OnKeyUp(input::KeyCode);
		virtual void OnMouseButtonDown(input::MouseBtn, Position);
		virtual void OnMouseButtonUp(input::MouseBtn);
	private:
		WindowProperties m_props;
	private:
#ifdef _WIN32
		HINSTANCE m_instanceHandle;
		WNDCLASSEXW m_wndClass;
		HWND m_wndHandle;
		static LRESULT CALLBACK CreateMessageHandler(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK StaticMessageHandler(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);
		LRESULT MessageHandler(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);
#endif
	};
}