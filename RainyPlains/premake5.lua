
project "rainyplains"

    filter "configurations:Debug"
    kind "ConsoleApp"

    filter "configurations:Release"
    kind "WindowedApp"
    filter {}

    files { "**.cpp", "**.hpp", "**.c", "**.h" }

    links { "d3d11.lib", "user32.lib" }

    