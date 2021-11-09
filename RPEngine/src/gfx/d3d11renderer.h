#pragma once

#include "../utils/window.h"
#include "../Defines/Defines.h"
#include "utils/gfxlog.h"
#include "../Utilities/Logger.h"

#include <d3d11.h>
#include <d3dcompiler.h>
#include <array>
#include <DirectXMath.h>
#include <wrl.h>
#include <iostream>


namespace rpe
{
	class RPE_API D3D11Renderer
	{
	public:
		struct Vertex
		{
			float x;
			float y;
			float r;
			float g;
			float b;
		};
		D3D11Renderer(void* window);
		void SwapBuffers();
		void ClearBuffer(u8 red, u8 green, u8 blue);
		~D3D11Renderer();
		void DrawTriangle(Vertex vert1, Vertex vert2, Vertex vert3);
		void ResizeBuffer(u16 width, u16 height);
	public:
		Microsoft::WRL::ComPtr<ID3D11Device> m_device;
		Microsoft::WRL::ComPtr<ID3D11Resource> m_backBuffer;
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_context;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_target;
	private:
		void* m_window;
	public:
		u16 m_width;
		u16 m_height;
	};
}