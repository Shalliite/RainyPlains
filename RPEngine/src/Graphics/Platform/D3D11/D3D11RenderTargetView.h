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

#include "D3D11DeviceContext.h"
#include "D3D11Device.h"
//

namespace rpe::gfx::api::dx
{
	class RPE_API D3D11RenderTargetView
	{
	public:
		D3D11RenderTargetView(D3D11Device*, D3D11DeviceContext*);
		void Clear(u8 red, u8 green, u8 blue);
		void Bind();
		void Unbind();
		~D3D11RenderTargetView();
	public:
		ID3D11RenderTargetView* Get() const;
		ID3D11RenderTargetView** GetAddress();
	private:
		D3D11DeviceContext* m_dc;
	private:
		ID3D11RenderTargetView* m_rtv;
	};
}