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
	class RPE_API D3D11DeviceContext
	{
	public:
		D3D11DeviceContext();
		~D3D11DeviceContext();
		ID3D11DeviceContext* Get() const;
		ID3D11DeviceContext** GetAddress();
	private:
		ID3D11DeviceContext* m_context;
	};
}