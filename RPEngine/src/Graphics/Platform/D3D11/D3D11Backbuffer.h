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
	class RPE_API D3D11Backbuffer
	{
	public:
		D3D11Backbuffer();
		~D3D11Backbuffer();
	public:
		ID3D11Texture2D* Get() const;
		ID3D11Texture2D** GetAddress();
	private:
		ID3D11Texture2D* m_backbuffer;
	};
}