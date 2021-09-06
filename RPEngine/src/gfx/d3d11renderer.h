#pragma once

#include "../utils/window.h"
#include "../../defs/defs.h"

#include <d3d11.h>

namespace rpe
{
	class RPE_API D3D11Renderer
	{
	public:
		D3D11Renderer(w32_window* window);
		void SwapBuffers();
		~D3D11Renderer();
	public:
		ID3D11Device* m_device;
		IDXGISwapChain* m_swapChain;
		ID3D11DeviceContext* m_context;
	};
}