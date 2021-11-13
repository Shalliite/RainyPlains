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
#include "D3D11RenderTargetView.h"
//

namespace rpe::gfx::api::dx
{

	D3D11RenderTargetView::D3D11RenderTargetView(D3D11Device* dev, D3D11DeviceContext* dc) :
		m_rtv(nullptr),
		m_dc(dc)
	{}

	void D3D11RenderTargetView::Clear(u8 red, u8 green, u8 blue)
	{
		float color[4] = {red / 255, green / 255, blue / 255, 1.0f};
		m_dc->Get()->ClearRenderTargetView(m_rtv, color);
	}

	void D3D11RenderTargetView::Bind()
	{
		m_dc->Get()->OMSetRenderTargets(1, &m_rtv, nullptr);
	}

	void D3D11RenderTargetView::Unbind()
	{
		ID3D11RenderTargetView* rtv = {};
		m_dc->Get()->OMSetRenderTargets(1, &rtv, nullptr);
	}

	D3D11RenderTargetView::~D3D11RenderTargetView()
	{
		if (m_rtv != nullptr) m_rtv->Release();
		m_dc = nullptr;
	}

	ID3D11RenderTargetView* D3D11RenderTargetView::Get() const
	{
		return m_rtv;
	}

	ID3D11RenderTargetView** D3D11RenderTargetView::GetAddress()
	{
		return &m_rtv;
	}

}