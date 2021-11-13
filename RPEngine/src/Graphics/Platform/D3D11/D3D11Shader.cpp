
/*
*
* This header/source is part of RainyPlains game/rendering engine originally developed by Deivids Dukalskis
*
*/


/*
* External headers
*/
//
#include <d3dcompiler.h>
//


/*
* Internal headers
*/
//
#include "D3D11Shader.h"
//

namespace rpe::gfx::api::dx
{
	D3D11Shader::D3D11Shader(TYPE type, LPCWSTR shaderLocation, D3D11Device* dev) :
		m_vertex(nullptr),
		m_pixel(nullptr),
		m_blob(nullptr),
		m_dc(nullptr),
		m_il(nullptr),
		m_type(type)
	{
		RP_HRESULT_CHECK(D3DReadFileToBlob(shaderLocation, &m_blob));
		switch (m_type)
		{
			case VERTEX:
				RP_HRESULT_CHECK(dev->Get()->CreateVertexShader(m_blob->GetBufferPointer(), m_blob->GetBufferSize(), nullptr, &m_vertex));
				RP_HRESULT_CHECK(dev->Get()->CreateInputLayout(ied, (UINT)std::size(ied),
															   m_blob->GetBufferPointer(),
															   m_blob->GetBufferSize(),
															   &m_il));
				break;
			case PIXEL:
				RP_HRESULT_CHECK(dev->Get()->CreatePixelShader(m_blob->GetBufferPointer(), m_blob->GetBufferSize(), nullptr, &m_pixel));
				break;
			default:
				break;
		}
	}

	void D3D11Shader::Bind(D3D11DeviceContext* dc)
	{
		m_dc = dc;
		switch (m_type)
		{
			case VERTEX:
				m_dc->Get()->VSSetShader(m_vertex, nullptr, 0);
				m_dc->Get()->IAGetInputLayout(&m_il);
				break;
			case PIXEL:
				m_dc->Get()->PSSetShader(m_pixel, nullptr, 0);
				break;
			default:
				break;
		}
	}

	void D3D11Shader::Unbind()
	{
		switch (m_type)
		{
			case VERTEX:
				m_dc->Get()->VSSetShader(nullptr, nullptr, 0);
				break;
			case PIXEL:
				m_dc->Get()->PSSetShader(nullptr, nullptr, 0);
				break;
			default:
				break;
		}
		m_dc = nullptr;
	}

	D3D11Shader::~D3D11Shader()
	{
		if (m_vertex != nullptr) m_vertex->Release();
		if (m_pixel != nullptr) m_pixel->Release();
		if (m_il != nullptr) m_il->Release();
		if (m_blob != nullptr) m_blob->Release();
	}
}
