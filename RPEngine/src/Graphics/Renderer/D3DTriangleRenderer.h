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

//


/*
* Internal headers
*/
//
#include "../../Defines/Defines.h"
#include "../../Utilities/Utilities.h"

#include "../Platform/D3D11/D3D11Device.h"
#include "../Platform/D3D11/D3D11DeviceContext.h"
#include "../Platform/D3D11/D3D11RenderTargetView.h"
#include "../Platform/D3D11/D3D11Shader.h"
#include "../Platform/D3D11/D3D11VertexBuffer.h"

#include "Vertex.h"
//

namespace rpe::gfx
{
	class RPE_API TriangleRenderer
	{
	public:
		TriangleRenderer(api::dx::D3D11Device*, api::dx::D3D11DeviceContext*, api::dx::D3D11RenderTargetView*);
		void Draw(u16 width, u16 height, VertexXYRGBf vert1, VertexXYRGBf vert2, VertexXYRGBf vert3);
		~TriangleRenderer();
	private:
		api::dx::D3D11Device* m_dev;
		api::dx::D3D11DeviceContext* m_dc;
		api::dx::D3D11RenderTargetView* m_rtv;
	private:
		api::dx::D3D11Shader* m_pixelSh;
		api::dx::D3D11Shader* m_vertSh;
	};
}