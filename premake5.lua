workspace "PaperPixel"
architecture "x64"
configurations { "Debug", "Release" }

project "PaperPixel"
    location "PaperPixel"
    kind "SharedLib"
    language "C++"
    cppdialect "C++17"
    files { "%{prj.name}/src/**.cpp", "%{prj.name}/src/**.h" } --, "%{prj.name}/include/**.h" }
    targetdir "bin/%{cfg.buildcfg}/%{prj.name}"
    objdir "obj/%{cfg.buildcfg}/%{prj.name}"
    includedirs { "Dependencies/GLFW/include", "Dependencies/Glad/include", "Dependencies/GLM/include", "Dependencies/stb_image/include", "%{prj.name}/include" }
    defines { "PP_BUILD_DLL" }
    pchheader "pch.h"
    pchsource "%{prj.name}/src/pch.cpp"

filter "system:windows"
    libdirs { "Dependencies/Glad/lib", "Dependencies/GLFW/lib", "Dependencies/stb_image/lib" }
    links { "stb_image.lib", "glad.lib", "glfw3.lib" }
    defines { "PP_WINDOWS" }
    postbuildcommands { "{COPYFILE} %{cfg.buildtarget.relpath} ../bin/%{cfg.buildcfg}/Sandbox" }

filter "not system:windows"
    -- Not sure how to link .lib file equivilant on other platforms 
    files { "Dependencies/**.c", "Dependencies/**.cpp" }

filter "configurations:Debug"
    defines { "PP_DEBUG" }

filter "configurations:Release"
    defines { "PP_RELEASE" }

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    files { "%{prj.name}/src/**.cpp", "%{prj.name}/src/**.h" }
    targetdir "bin/%{cfg.buildcfg}/%{prj.name}"
    objdir "obj/%{cfg.buildcfg}/%{prj.name}"
    includedirs { "PaperPixel/include", "Dependencies/GLM/include" }
    links { "PaperPixel" }

    postbuildcommands { "{COPYDIR} %{prj.location}res ../bin/%{cfg.buildcfg}/%{prj.name}/res" }

filter "system:windows"
    defines { "PP_WINDOWS" }
