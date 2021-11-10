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
//

namespace rpe::gfx::api::dx
{
	class RPE_API D3D11Device
	{
	public:
		D3D11Device(D3D11DeviceContext);
		~D3D11Device();
		ID3D11Device* Get() const;
		ID3D11Device** GetAddress();
	private:
		ID3D11Device* m_device;
	};
}