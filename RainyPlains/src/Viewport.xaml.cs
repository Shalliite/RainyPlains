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
			WM_SIZE = 0x0005
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
			Content = controlHost;
		}

		protected virtual void Dispose(bool disposing)
		{
			if (!disposedValue)
			{
				if (disposing)
				{
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

		protected override void OnRender(DrawingContext drawingContext)
		{
			Native.RenderD3D11(ActualWidth, ActualHeight);
		}
	}
}
