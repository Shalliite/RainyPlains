#pragma once

#include "../utils/window.h"
#include "../../defs/defs.h"
#include "../utils/imgui/imgui_impl_win32.h"
#include "../utils/imgui/imgui_impl_dx11.h"

#include <d3d11.h>
#include <wrl.h>

namespace rpe
{
	class D3D11Renderer
	{
	public:
		D3D11Renderer(Window* window);
		void SwapBuffers();
		~D3D11Renderer();
	public:
		Microsoft::WRL::ComPtr<ID3D11Device> m_device;
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_context;
	};
}