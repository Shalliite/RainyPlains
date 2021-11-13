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
#include "D3D11VertexBuffer.h"
//

namespace rpe::gfx::api::dx
{
	D3D11VertexBuffer::D3D11VertexBuffer(D3D11Device* dev, VertexXYRGBf* vert) :
		m_dc(nullptr),
		m_buff(nullptr),
		m_bd({}),
		m_sd({})
	{
		m_bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		m_bd.Usage = D3D11_USAGE_DEFAULT;
		m_bd.CPUAccessFlags = 0;
		m_bd.MiscFlags = 0;
		m_bd.ByteWidth = sizeof(vert);
		m_bd.StructureByteStride = sizeof(VertexXYRGBf);
		m_sd.pSysMem = vert;
		RP_HRESULT_CHECK(dev->Get()->CreateBuffer(&m_bd, &m_sd, &m_buff));
	}
	void D3D11VertexBuffer::Bind(D3D11DeviceContext* dc)
	{
		m_dc = dc;
		const UINT stride = sizeof(VertexXYRGBf);
		const UINT offset = 0;
		dc->Get()->IASetVertexBuffers(0, 1, &m_buff, &stride, &offset);
	}
	void D3D11VertexBuffer::Unbind()
	{
		m_dc->Get()->IASetVertexBuffers(0, 0, nullptr, nullptr, nullptr);
		m_dc = nullptr;
	}
	D3D11VertexBuffer::~D3D11VertexBuffer()
	{
		if (m_buff != nullptr) m_buff->Release();
	}
}