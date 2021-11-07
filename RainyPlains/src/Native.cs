using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace RainyPlains.src
{
	class Native
	{
		[DllImport("RPEngine.dll")]
		public static extern void CreateWnd(IntPtr hWnd, int width, int height);
		[DllImport("RPEngine.dll")]
		public static extern void CreateD3D11();
		[DllImport("RPEngine.dll")]
		public static extern void RenderD3D11(double width, double height);
		[DllImport("RPEngine.dll")]
		public static extern void DestroyWnd();
		[DllImport("RPEngine.dll")]
		public static extern IntPtr GetWindowHandle();
	}
}
