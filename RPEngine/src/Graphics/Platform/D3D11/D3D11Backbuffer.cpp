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
#include "D3D11Backbuffer.h"
//

namespace rpe::gfx::api::dx
{

	D3D11Backbuffer::D3D11Backbuffer() :
		m_backbuffer(nullptr)
	{}

	D3D11Backbuffer::~D3D11Backbuffer()
	{
		if (m_backbuffer != nullptr) m_backbuffer->Release();
	}

	ID3D11Texture2D* D3D11Backbuffer::Get() const
	{
		return m_backbuffer;
	}

	ID3D11Texture2D** D3D11Backbuffer::GetAddress()
	{
		return &m_backbuffer;
	}

}