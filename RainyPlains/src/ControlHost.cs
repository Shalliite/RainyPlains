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
		public IntPtr m_hwndHost = IntPtr.Zero;
		public int m_width = 0;
		public int m_height = 0;
		public ControlHost(double width, double height)
		{
			m_width = (int)width;
			m_height = (int)height;
		}
		protected override HandleRef BuildWindowCore(HandleRef hwndParent)
		{
			Native.CreateWnd(hwndParent.Handle, m_width, m_height);
			Native.CreateD3D11();
			m_hwndHost = Native.GetWindowHandle();
			return new HandleRef(this, m_hwndHost);
		}

		protected override void DestroyWindowCore(HandleRef hwnd)
		{
			Native.DestroyWnd();
			m_hwndHost = IntPtr.Zero;
		}
	}
}
