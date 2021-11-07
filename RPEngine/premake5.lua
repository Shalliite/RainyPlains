
project "RPEngine"

    kind "SharedLib"
    
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    defines { "UNICODE", "_UNICODE", "_CRT_SECURE_NO_WARNINGS" }
    
    filter "configurations:Debug"
    runtime "Debug"
    defines { "DEBUG", "_DEBUG" }
    filter {}

    filter "configurations:Release"
    runtime "Release"
    defines { "NDEBUG", "_NDEBUG" }
    filter {}

    filter "kind:SharedLib"
    defines { "WINDLL", "_WINDLL" }
    filter {}

    includedirs { "%{prj.location}/external/spdlog/include" }
    flags { "MultiProcessorCompile" }

    files { "**.cpp", "**.hpp", "**.c", "**.h", "**.hlsl" }
    links { "d3d11.lib", "user32.lib", "D3DCompiler.lib" }