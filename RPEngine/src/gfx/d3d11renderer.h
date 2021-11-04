#pragma once

#include "../utils/window.h"
#include "../../defs/defs.h"

#include <d3d11.h>
#include <d3dcompiler.h>
#include <array>
#include <DirectXMath.h>
#include <wrl.h>



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
		void ClearBuffer(float red, float green, float blue);
		~D3D11Renderer();
		void DrawTriangle(Vertex vert1, Vertex vert2, Vertex vert3);
		void ResizeBuffer(uint16 width, uint16 height);
	public:
		Microsoft::WRL::ComPtr<ID3D11Device> m_device;
		Microsoft::WRL::ComPtr<ID3D11Resource> m_backBuffer;
		Microsoft::WRL::ComPtr<IDXGISwapChain> m_swapChain;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> m_context;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_target;
	private:
		void* m_window;
	public:
		uint16 m_width;
		uint16 m_height;
	};
}