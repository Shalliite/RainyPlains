#pragma once


#include "../defs/defs.h"
#include "gfx/gfx.h"
#include "utils/window.h"
#include "utils/imgui/imgui_impl_win32.h"
#include "utils/imgui/imgui_impl_dx11.h"


namespace rpe
{
	class Application
	{
	public:
		Application();
		void Run();
		void InitImGui();
		void DestroyImGui();
		virtual ~Application();
	public:
		bool m_shouldRun = false;
	private:
		D3D11Renderer* d3d11r;
		Window* wnd;
	};
}