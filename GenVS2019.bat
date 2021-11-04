@echo off

del /s *.vcxproj
del /s *.csproj
del /s *.user
del /s *.filters
del /s *.sln
del /s *.cmake
del /s CMakeLists.txt
del /s *.m
del /s *.in
rd /s /q .vs\

call external\premake5.exe vs2019
pause