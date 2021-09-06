
project "RainyPlains"

    filter "configurations:Debug"
    kind "ConsoleApp"

    filter "configurations:Release"
    kind "WindowedApp"
    filter {}

    files { "**.cpp", "**.hpp", "**.c", "**.h" }

    links { "RPEngine" }

    