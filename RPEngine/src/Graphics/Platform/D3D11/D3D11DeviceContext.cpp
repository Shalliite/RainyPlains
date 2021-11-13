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
#include "D3D11DeviceContext.h"
//

namespace rpe::gfx::api::dx
{
	D3D11DeviceContext::D3D11DeviceContext() :
		m_context(nullptr)
	{}

	D3D11DeviceContext::~D3D11DeviceContext()
	{
		if (m_context != nullptr) m_context->Release();
	}

	ID3D11DeviceContext* D3D11DeviceContext::Get() const
	{
		return m_context;
	}

	ID3D11DeviceContext** D3D11DeviceContext::GetAddress()
	{
		return &m_context;
	}
}