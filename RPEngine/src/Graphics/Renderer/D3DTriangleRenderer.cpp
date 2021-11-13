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
#include "D3DTriangleRenderer.h"
//

namespace rpe::gfx
{
	TriangleRenderer::TriangleRenderer(api::dx::D3D11Device* dev, api::dx::D3D11DeviceContext* dc, api::dx::D3D11RenderTargetView* rtv) :
		m_dc(dc),
		m_dev(dev),
		m_rtv(rtv)
	{
		dc->Get()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		m_pixelSh = new api::dx::D3D11Shader(api::dx::D3D11Shader::PIXEL, L"PixelShader.cso", m_dev);
		m_vertSh = new api::dx::D3D11Shader(api::dx::D3D11Shader::VERTEX, L"VertexShader.cso", m_dev);
	}
	void TriangleRenderer::Draw(u16 width, u16 height, VertexXYRGBf vert1, VertexXYRGBf vert2, VertexXYRGBf vert3)
	{
		VertexXYRGBf vertices[] =
		{
			vert1, vert2, vert3
		};
		api::dx::D3D11VertexBuffer vertBuff = api::dx::D3D11VertexBuffer(m_dev, vertices);
		vertBuff.Bind(m_dc);
		m_pixelSh->Bind(m_dc);
		m_vertSh->Bind(m_dc);
		m_rtv->Bind();
		D3D11_VIEWPORT vp;
		vp.Width = width;
		vp.Height = height;
		vp.MinDepth = 0;
		vp.MaxDepth = 1;
		vp.TopLeftX = 0;
		vp.TopLeftY = 0;
		m_dc->Get()->RSSetViewports(1u, &vp);
		m_dc->Get()->Draw((UINT)std::size(vertices), 0u);
		//vertBuff.Unbind();
		//m_pixelSh->Unbind();
		//m_vertSh->Unbind();
		//m_rtv->Unbind();
	}
	TriangleRenderer::~TriangleRenderer()
	{}
}