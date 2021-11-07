project "RainyPlains"

    language "C#"

    filter "configurations:Debug"
    kind "ConsoleApp"
    filter {}

    filter "configurations:Release"
    kind "WindowedApp"
    filter {}

    flags { "WPF" }

    files { "**.cs", "**.xaml" }
    dependson { "RPEngine" }
    nuget { "Dirkster.AvalonDock:4.60.0", "Dirkster.AvalonDock.Themes.VS2013:4.60.0", "Dirkster.AvalonDock.Themes.Expression:4.60.0", "Dirkster.AvalonDock.Themes.Metro:4.60.0", "Dirkster.AvalonDock.Themes.Aero:4.60.0", "Dirkster.AvalonDock.Themes.VS2010:4.60.0" }
    links { "PresentationCore", "PresentationFramework", "System", "System.Xaml", "WindowsBase", }