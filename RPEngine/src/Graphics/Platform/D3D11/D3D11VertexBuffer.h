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
#include "../../Renderer/Vertex.h"
//

namespace rpe::gfx::api::dx
{
	class RPE_API D3D11VertexBuffer
	{
	public:
		D3D11VertexBuffer(D3D11Device*, VertexXYRGBf*);
		void Bind(D3D11DeviceContext*);
		void Unbind();
		~D3D11VertexBuffer();
	private:
		D3D11DeviceContext* m_dc;
	private:
		D3D11_BUFFER_DESC m_bd;
		D3D11_SUBRESOURCE_DATA m_sd;
		ID3D11Buffer* m_buff;
	};
}