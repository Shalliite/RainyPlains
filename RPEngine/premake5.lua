
project "RPEngine"
    kind "SharedLib"

    files { "**.cpp", "**.hpp", "**.c", "**.h" }
    links { "opengl32.lib", "user32.lib", "d3d11.lib" }