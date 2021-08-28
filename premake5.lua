
workspace "RainyPlains"
    configurations {"Debug", "Release"}
    architecture "x86_64"
    startproject "RainyPlains"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("%{wks.location}/bin")
    objdir ("%{wks.location}/obj/%{prj.name}")
    flags { "MultiProcessorCompile" }

    defines { "UNICODE", "_UNICODE", "_CRT_SECURE_NOT_WARNINGS" }
    
    filter "configurations:Debug"
    defines { "DEBUG", "_DEBUG" }

    filter "configurations:Release"
    defines { "NDEBUG", "_NDEBUG" }

    filter "kind:SharedLib"
    defines { "WINDLL", "_WINDLL" }

    include "RPEngine"
    include "RPEngine/external/GLFW"
    include "RPEngine/external/ImGui"
    include "RainyPlains"
