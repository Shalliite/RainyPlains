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

	D3D11RenderTargetView::D3D11RenderTargetView() :
		m_renderTarget(nullptr)
	{}

	D3D11RenderTargetView::~D3D11RenderTargetView()
	{
		if (m_renderTarget != nullptr) m_renderTarget->Release();
	}

	ID3D11RenderTargetView* D3D11RenderTargetView::Get() const
	{
		return m_renderTarget;
	}

	ID3D11RenderTargetView** D3D11RenderTargetView::GetAddress()
	{
		return &m_renderTarget;
	}

}