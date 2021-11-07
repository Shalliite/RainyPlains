workspace "RainyPlains"
    configurations {"Debug", "Release"}
    architecture "x86_64"
    startproject "RainyPlains"

    objdir ("%{wks.location}/obj/%{prj.name}")
    targetdir ("%{wks.location}/bin/%{cfg.buildcfg}")

    include "RPEngine"
    include "RainyPlains"
