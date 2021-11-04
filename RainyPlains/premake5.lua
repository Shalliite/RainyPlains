project "RainyPlains"

    language "C#"
    kind "WindowedApp"

    flags { "WPF" }

    files { "**.cs", "**.xaml" }
    dependson { "RPEngine" }
    links { "PresentationCore", "PresentationFramework", "System", "System.Xaml", "WindowsBase", "AvalonDock", "AvalonDock.Themes.Aero", "AvalonDock.Themes.Expression", "AvalonDock.Themes.Metro", "AvalonDock.Themes.VS2010", "AvalonDock.Themes.VS2013" }