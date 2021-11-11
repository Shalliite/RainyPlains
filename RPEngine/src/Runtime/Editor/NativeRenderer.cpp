
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
//

namespace rpe
{
	RPE_EXTERN struct RPE_API Native_Rend_D3D11RendererStruct
	{
		gfx::api::dx::D3D11DeviceContext* devCon;
		gfx::api::dx::D3D11Device* device;
		gfx::api::dx::D3D11Backbuffer* bbuf;
		gfx::api::dx::D3D11RenderTargetView* rtv;
		gfx::api::dx::DXGISwapChain* swapChain;
	};
	RPE_EXTERN RPE_API Native_Rend_D3D11RendererStruct Native_Rend_GetNativeRenderer(ptr hostWindow)
	{
		using namespace gfx::api::dx;
		D3D11DeviceContext* devCon = new D3D11DeviceContext();
		D3D11Device* device = new D3D11Device(devCon);
		D3D11Backbuffer* bbuf = new D3D11Backbuffer();
		D3D11RenderTargetView* rtv = new D3D11RenderTargetView();
		DXGISwapChain* swapChain = new DXGISwapChain(device, hostWindow, 0, 0);
		swapChain->BindBackbuffer(bbuf);
		device->CreateRenderTarget(rtv, bbuf);
		return { devCon, device, bbuf, rtv, swapChain };
	}
	RPE_EXTERN RPE_API void Native_Rend_SwapBuffers(Native_Rend_D3D11RendererStruct renderer)
	{
		renderer.swapChain->Swap();
	}
	RPE_EXTERN RPE_API void Native_Rend_ClearBuffer(Native_Rend_D3D11RendererStruct renderer, u8 colorR, u8 colorG, u8 colorB)
	{
		renderer.devCon->ClearTarget(colorR, colorG, colorB, renderer.rtv);
	}
	RPE_EXTERN RPE_API void Native_Rend_ResizeBuffer(Native_Rend_D3D11RendererStruct renderer, u16 width, u16 height)
	{
		renderer.swapChain->Resize(width, height, renderer.device, renderer.bbuf, renderer.devCon, renderer.rtv);
	}
	RPE_EXTERN RPE_API void Native_Rend_DisposeRenderer(Native_Rend_D3D11RendererStruct renderer)
	{
		delete renderer.bbuf;
		delete renderer.rtv;
		delete renderer.swapChain;
		delete renderer.devCon;
		delete renderer.device;
	}
}