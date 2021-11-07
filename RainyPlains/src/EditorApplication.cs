using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;

namespace RainyPlains.src {
	class EditorApplication {
		[STAThread]
		public static void Main() {
			Application app = new Application();
			Editor editor = new Editor();
			app.MainWindow = editor;
			app.Run(editor);
		}
	}
}
