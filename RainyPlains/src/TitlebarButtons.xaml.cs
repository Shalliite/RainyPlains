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

namespace RainyPlains.src
{
	/// <summary>
	/// Interaction logic for TitlebarButtons.xaml
	/// </summary>
	public partial class TitlebarButtons : UserControl
	{
		public static readonly RoutedEvent minimizeEvent = EventManager.RegisterRoutedEvent("Minimize", RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(TitlebarButtons));
		public static readonly RoutedEvent maximizeEvent = EventManager.RegisterRoutedEvent("Maximize", RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(TitlebarButtons));
		public static readonly RoutedEvent restoreEvent = EventManager.RegisterRoutedEvent("Restore", RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(TitlebarButtons));
		public static readonly RoutedEvent closeEvent = EventManager.RegisterRoutedEvent("Close", RoutingStrategy.Bubble, typeof(RoutedEventHandler), typeof(TitlebarButtons));

		public event RoutedEventHandler Minimize
		{
			add { AddHandler(minimizeEvent, value); }
			remove { RemoveHandler(minimizeEvent, value); }
		}
		public event RoutedEventHandler Maximize
		{
			add { AddHandler(maximizeEvent, value); }
			remove { RemoveHandler(maximizeEvent, value); }
		}
		public event RoutedEventHandler Restore
		{
			add { AddHandler(restoreEvent, value); }
			remove { RemoveHandler(restoreEvent, value); }
		}
		public event RoutedEventHandler Close
		{
			add { AddHandler(closeEvent, value); }
			remove { RemoveHandler(closeEvent, value); }
		}

		public void MinimizeButton_Click(Object obj, RoutedEventArgs e)
		{
			RaiseEvent(new RoutedEventArgs(minimizeEvent, this));
		}
		public void MaximizeButton_Click(Object obj, RoutedEventArgs e)
		{
			RaiseEvent(new RoutedEventArgs(maximizeEvent, this));
		}
		public void RestoreButton_Click(Object obj, RoutedEventArgs e)
		{
			RaiseEvent(new RoutedEventArgs(restoreEvent, this));
		}
		public void CloseButton_Click(Object obj, RoutedEventArgs e)
		{
			RaiseEvent(new RoutedEventArgs(closeEvent, this));
		}
		public TitlebarButtons()
		{
			InitializeComponent();
		}
	}
}
