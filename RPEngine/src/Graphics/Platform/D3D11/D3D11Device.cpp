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
#include "D3D11Device.h"
//

namespace rpe::gfx::api::dx
{

	D3D11Device::D3D11Device(D3D11DeviceContext* dc) :
		m_device(nullptr)
	{
		RP_HRESULT_CHECK(D3D11CreateDevice(
			nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			nullptr,
			0,
			nullptr,
			0,
			D3D11_SDK_VERSION,
			&m_device,
			nullptr,
			dc->GetAddress()));
	}

	D3D11Device::~D3D11Device()
	{
		if (m_device != nullptr) m_device->Release();
	}

	ID3D11Device* D3D11Device::Get() const
	{
		return m_device;
	}

	ID3D11Device** D3D11Device::GetAddress()
	{
		return &m_device;
	}

	void D3D11Device::CreateRenderTarget(D3D11RenderTargetView* rtv, D3D11Backbuffer* bbuf)
	{
		RP_HRESULT_CHECK(m_device->CreateRenderTargetView(bbuf->Get(), nullptr, rtv->GetAddress()));
	}

}