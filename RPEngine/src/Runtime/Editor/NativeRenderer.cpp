
/*
*
* This header/source is part of RainyPlains game/rendering engine originally developed by Deivids Dukalskis
*
*/


/*
* External headers
*/
//
#include <Windows.h>
//


/*
* Internal headers
*/
//
#include "../../Defines/Defines.h"
#include "../../gfx/d3d11renderer.h"  //TEMPORARY. MUST BE IN NEW CLASS
//

namespace rpe
{
	RPE_EXTERN RPE_API ptr Native_Rend_GetNativeRenderer(ptr hostWindow)
	{
		D3D11Renderer* rend = new D3D11Renderer(hostWindow);
		return rend;
	}
	RPE_EXTERN RPE_API void Native_Rend_SwapBuffers(ptr renderer)
	{
		D3D11Renderer* d3drend = reinterpret_cast<D3D11Renderer*>(renderer);
		d3drend->SwapBuffers();
	}
	RPE_EXTERN RPE_API void Native_Rend_ClearBuffer(ptr renderer, u8 colorR, u8 colorG, u8 colorB)
	{
		D3D11Renderer* d3drend = reinterpret_cast<D3D11Renderer*>(renderer);
		d3drend->ClearBuffer(colorR, colorG, colorB);
	}
	RPE_EXTERN RPE_API void Native_Rend_ResizeBuffer(ptr renderer, u16 width, u16 height)
	{
		D3D11Renderer* d3drend = reinterpret_cast<D3D11Renderer*>(renderer);
		d3drend->ResizeBuffer(width, height);
	}
	RPE_EXTERN RPE_API void Native_Rend_DisposeRenderer(ptr renderer)
	{
		D3D11Renderer* d3drend = reinterpret_cast<D3D11Renderer*>(renderer);
		delete d3drend;
		d3drend = nullptr;
	}
}