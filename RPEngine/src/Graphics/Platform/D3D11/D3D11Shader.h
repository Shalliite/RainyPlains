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
#include <d3d11.h>
//


/*
* Internal headers
*/
//
#include "../../../Defines/Defines.h"
#include "../../../Utilities/Utilities.h"

#include "D3D11Device.h"
#include "D3D11DeviceContext.h"
//

namespace rpe::gfx::api::dx
{
	class RPE_API D3D11Shader
	{
	public:
		enum TYPE
		{
			VERTEX = 0,
			PIXEL
		};
	public:
		D3D11Shader(TYPE, LPCWSTR shaderLocation, D3D11Device*);
		~D3D11Shader();
		void Bind(D3D11DeviceContext*);
		void Unbind();
	private:
		const D3D11_INPUT_ELEMENT_DESC ied[2] =
		{
			{ "Position",0,DXGI_FORMAT_R32G32_FLOAT,0,0,D3D11_INPUT_PER_VERTEX_DATA,0 },
			{ "Color",0,DXGI_FORMAT_R32G32B32_FLOAT,0,8,D3D11_INPUT_PER_VERTEX_DATA,0 },
		};
		D3D11DeviceContext* m_dc;
		TYPE m_type;
	private:
		ID3D11VertexShader* m_vertex;
		ID3D11InputLayout* m_il;
		ID3D11PixelShader* m_pixel;
		ID3DBlob* m_blob;
	};
}