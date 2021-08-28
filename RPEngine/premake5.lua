
project "RPEngine"
    kind "SharedLib"

    links { "GLFW", "ImGui", "opengl32.lib", "user32.lib" }