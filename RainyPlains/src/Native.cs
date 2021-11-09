using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace RainyPlains.src
{
	[StructLayout(LayoutKind.Sequential)]
	public struct Native_Wnd_WindowStruct
	{
		public IntPtr hostWindow;
		public IntPtr instanceHandle;
		public IntPtr className;
	}
	class Native
	{
		[DllImport("RPEngine.dll")]
		public static extern Native_Wnd_WindowStruct Native_Wnd_CreateWindow(IntPtr parentWnd);
		[DllImport("RPEngine.dll")]
		public static extern void Native_Wnd_DestroyWindow(Native_Wnd_WindowStruct nws);
		[DllImport("RPEngine.dll")]
		public static extern IntPtr Native_Rend_GetNativeRenderer(IntPtr hostWnd);
		[DllImport("RPEngine.dll")]
		public static extern void Native_Rend_SwapBuffers(IntPtr renderer);
		[DllImport("RPEngine.dll")]
		public static extern void Native_Rend_ClearBuffer(IntPtr renderer, byte colorR, byte colorG, byte colorB);
		[DllImport("RPEngine.dll")]
		public static extern void Native_Rend_ResizeBuffer(IntPtr renderer, ushort width, ushort height);
		[DllImport("RPEngine.dll")]
		public static extern void Native_Rend_DisposeRenderer(IntPtr renderer);
	}
}
