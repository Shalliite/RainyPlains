
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
#include "../../Graphics/Platform/D3D11/D3D11Device.h"
#include "../../Graphics/Platform/DXGI/DXGISwapChain.h"
#include "../../Graphics/Renderer/D3DTriangleRenderer.h"
//

namespace rpe
{
	RPE_EXTERN struct RPE_API Native_Rend_D3D11RendererStruct
	{
		gfx::api::dx::D3D11DeviceContext* devCon;
		gfx::api::dx::D3D11Device* device;
		gfx::api::dx::D3D11RenderTargetView* rtv;
		gfx::api::dx::DXGISwapChain* swapChain;
		gfx::TriangleRenderer* tr;
	};
	RPE_EXTERN RPE_API Native_Rend_D3D11RendererStruct Native_Rend_GetNativeRenderer(ptr hostWindow)
	{
		using namespace gfx::api::dx;
		D3D11DeviceContext* devCon = new D3D11DeviceContext();
		D3D11Device* device = new D3D11Device(devCon);
		D3D11RenderTargetView* rtv = new D3D11RenderTargetView(device, devCon);
		DXGISwapChain* swapChain = new DXGISwapChain(device, rtv, hostWindow, 0, 0);
		gfx::TriangleRenderer* tr = new gfx::TriangleRenderer(device, devCon, rtv);
		return { devCon, device, rtv, swapChain, tr};
	}
	RPE_EXTERN RPE_API void Native_Rend_SwapBuffers(Native_Rend_D3D11RendererStruct renderer)
	{
		renderer.swapChain->Swap();
	}
	RPE_EXTERN RPE_API void Native_Rend_ClearBuffer(Native_Rend_D3D11RendererStruct renderer,
													u8 colorR,
													u8 colorG,
													u8 colorB,
													u16 width,
													u16 height)
	{
		renderer.rtv->Clear(colorR, colorG, colorB);
		renderer.tr->Draw(width, height, {-0.5f, -0.5f, 1.0f, 0.0f, 0.0f}, {0.0f, 0.5f, 0.0f, 1.0f, 0.0f}, {0.5f, -0.5f, 0.0f, 0.0f, 1.0f});
	}
	RPE_EXTERN RPE_API void Native_Rend_ResizeBuffer(Native_Rend_D3D11RendererStruct renderer, u16 width, u16 height)
	{
		renderer.swapChain->Resize(width, height, renderer.device, renderer.devCon, renderer.rtv);
	}
	RPE_EXTERN RPE_API void Native_Rend_DisposeRenderer(Native_Rend_D3D11RendererStruct renderer)
	{
		delete renderer.rtv;
		delete renderer.swapChain;
		delete renderer.devCon;
		delete renderer.device;
		delete renderer.tr;
	}
}