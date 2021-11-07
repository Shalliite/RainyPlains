#pragma once


#include "Defines/Defines.h"
#include "gfx/gfx.h"
#include "utils/window.h"

namespace rpe
{
	class RPE_API Application
	{
	public:
		Application(void* window);
		void Run();
		void InitImGui();
		void DestroyImGui();
		virtual ~Application();
	public:
		bool m_shouldRun = false;
		static double m_r;
		static double m_g;
		static double m_b;
	private:
		D3D11Renderer* d3d11r;
		D3D11Renderer* viewport;
		Window* wnd;
	};
}