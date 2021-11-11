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
//

namespace rpe::gfx::api::dx
{
	class RPE_API D3D11RenderTargetView
	{
	public:
		D3D11RenderTargetView();
		~D3D11RenderTargetView();
	public:
		ID3D11RenderTargetView* Get() const;
		ID3D11RenderTargetView** GetAddress();
	private:
		ID3D11RenderTargetView* m_renderTarget;
	};
}