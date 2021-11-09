using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Interop;
using System.Runtime.InteropServices;

namespace RainyPlains.src
{
	class ControlHost : HwndHost
	{
		public Native_Wnd_WindowStruct m_nws;
		public IntPtr m_renderer;
		public int m_width = 0;
		public int m_height = 0;
		public ControlHost(double width, double height)
		{
			m_width = (int)width;
			m_height = (int)height;
		}
		protected override HandleRef BuildWindowCore(HandleRef hwndParent)
		{
			m_nws = Native.Native_Wnd_CreateWindow(hwndParent.Handle);
			m_renderer = Native.Native_Rend_GetNativeRenderer(m_nws.hostWindow);
			return new HandleRef(this, m_nws.hostWindow);
		}

		protected override void DestroyWindowCore(HandleRef hwnd)
		{
			Native.Native_Wnd_DestroyWindow(m_nws);
		}
	}
}
