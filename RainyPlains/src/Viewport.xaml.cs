using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Windows.Interop;

namespace RainyPlains.src
{
	/// <summary>
	/// Interaction logic for Viewport.xaml
	/// </summary>
	public partial class Viewport : UserControl, IDisposable
	{
		ControlHost controlHost = null;
		private bool disposedValue;
		private enum Win32Msg
		{
			WM_SIZING = 0x0214,
			WM_ENTERSIZEMOVE = 0x0231,
			WM_EXITSIZEMOVE = 0x0232,
			WM_SIZE = 0x0005,
			WM_PAINT = 0x000F
		}

		public Viewport()
		{
			InitializeComponent();
			Loaded += OnSurfaceLoaded;
		}

		private void OnSurfaceLoaded(object sender, RoutedEventArgs e)
		{
			Loaded -= OnSurfaceLoaded;
			controlHost = new ControlHost(ActualWidth, ActualHeight);
			controlHost.MessageHook += new HwndSourceHook(MessageHandler);
			Content = controlHost;
		}

		private IntPtr MessageHandler(IntPtr hwnd, int msg, IntPtr wParam, IntPtr lParam, ref bool handled)
		{
			switch ((Win32Msg)msg)
			{
				case Win32Msg.WM_ENTERSIZEMOVE:
					break;
				case Win32Msg.WM_EXITSIZEMOVE:
					break;
				case Win32Msg.WM_SIZING:
					break;
				case Win32Msg.WM_PAINT:
					Native.Native_Rend_ClearBuffer(controlHost.m_renderer, 255, 0, 0);
					Native.Native_Rend_SwapBuffers(controlHost.m_renderer);
					break;
				case Win32Msg.WM_SIZE:
					Native.Native_Rend_ResizeBuffer(controlHost.m_renderer, (ushort)ActualWidth, (ushort)ActualHeight);
					break;
				default:
					break;
			}
			return IntPtr.Zero;
		}

		protected virtual void Dispose(bool disposing)
		{
			if (!disposedValue)
			{
				if (disposing)
				{
					Native.Native_Rend_DisposeRenderer(controlHost.m_renderer);
					controlHost.Dispose();
					// TODO: dispose managed state (managed objects)
				}

				// TODO: free unmanaged resources (unmanaged objects) and override finalizer
				// TODO: set large fields to null
				disposedValue = true;
			}
		}

		// // TODO: override finalizer only if 'Dispose(bool disposing)' has code to free unmanaged resources
		// ~Viewport()
		// {
		//     // Do not change this code. Put cleanup code in 'Dispose(bool disposing)' method
		//     Dispose(disposing: false);
		// }

		public void Dispose()
		{
			// Do not change this code. Put cleanup code in 'Dispose(bool disposing)' method
			Dispose(disposing: true);
			GC.SuppressFinalize(this);
		}
	}
}
