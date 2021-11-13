#pragma once

/*
*
* This header/source is part of RainyPlains game/rendering engine originally developed by Deivids Dukalskis
*
*/


/*
* External headers
*/
//
#include <dxgi.h>
//


/*
* Internal headers
*/
//
#include "../../../Defines/Defines.h"
#include "../../../Utilities/Utilities.h"

#include "../D3D/D3DDevice.h"
#include "../D3D/D3DDeviceContext.h"
#include "../D3D/D3DRenderTargetView.h"

#include "../D3D/Types/ID3DDevice.h"
#include "../D3D/Types/ID3DDeviceContext.h"
#include "../D3D/Types/ID3DTexture2D.h"
#include "../D3D/Types/ID3DRenderTargetView.h"
//

namespace rpe::gfx::api::dx
{
	class RPE_API DXGISwapChain
	{
	public:
		DXGISwapChain(D3DDevice*, D3DRenderTargetView*, ptr outputWnd, u16 width, u16 height);
		void Resize(u16 width, u16 height, D3DDevice*, D3DDeviceContext*, D3DRenderTargetView*);
		void Swap();
		~DXGISwapChain();
	public:
		IDXGISwapChain* Get() const;
		IDXGISwapChain** GetAddress();
	private:
		DXGI_SWAP_CHAIN_DESC m_scd;
		IDXGIDevice* m_dxgiDevice;
		IDXGIAdapter* m_dxgiAdapter;
		IDXGIFactory* m_dxgiFactory;
		IDXGISwapChain* m_swapChain;
	};
}