/*
*
* This header/source is part of RainyPlains game/rendering engine originally developed by Deivids Dukalskis
*
*/


/*
* External headers
*/
//

//


/*
* Internal headers
*/
//
#include "DXGISwapChain.h"
//

namespace rpe::gfx::api::dx
{

	DXGISwapChain::DXGISwapChain(D3DDevice dev, ptr outputWnd, u16 width, u16 height) :
		m_scd({}),
		m_swapChain(nullptr),
		m_dxgiFactory(nullptr),
		m_dxgiDevice(nullptr),
		m_dxgiAdapter(nullptr)
	{
		m_scd.BufferDesc.Width = width;
		m_scd.BufferDesc.Height = height;
		m_scd.OutputWindow = (HWND)outputWnd;
		m_scd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		m_scd.BufferDesc.RefreshRate.Numerator = 60;
		m_scd.BufferDesc.RefreshRate.Denominator = 1;
		m_scd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		m_scd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		m_scd.SampleDesc.Count = 1;
		m_scd.SampleDesc.Quality = 0;
		m_scd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		m_scd.BufferCount = 1;
		m_scd.Windowed = TRUE;
		m_scd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		m_scd.Flags = 0;
		RP_HRESULT_CHECK(dev.Get()->QueryInterface(
			__uuidof(IDXGIDevice),
			(void**)&m_dxgiDevice));
		RP_HRESULT_CHECK(m_dxgiDevice->GetAdapter(&m_dxgiAdapter));
		RP_HRESULT_CHECK(m_dxgiAdapter->GetParent(
			__uuidof(IDXGIFactory),
			(void**)&m_dxgiFactory));
		RP_HRESULT_CHECK(m_dxgiFactory->CreateSwapChain(
			dev.Get(),
			&m_scd,
			&m_swapChain));
	}

	DXGISwapChain::~DXGISwapChain()
	{
		if (m_swapChain != nullptr) m_swapChain->Release();
		if (m_dxgiFactory != nullptr) m_dxgiFactory->Release();
		if (m_dxgiAdapter != nullptr) m_dxgiAdapter->Release();
		if (m_dxgiDevice != nullptr) m_dxgiDevice->Release();
	}

	IDXGISwapChain* DXGISwapChain::Get() const
	{
		return m_swapChain;
	}

	IDXGISwapChain** DXGISwapChain::GetAddress()
	{
		return &m_swapChain;
	}

}