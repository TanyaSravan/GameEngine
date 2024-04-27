workspace "GameEngine"
    architecture "x64"
    configurations{
        "Debug",
        "Release",
        "Dist"
    }

outputsdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "GameEngine"
    location "GameEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/"..outputsdir.."/%{prj.name}")
    objdir ("bin-int/"..outputsdir.."/%{prj.name}")

    pchheader "GEpch.h"
    pchsource "GameEngine/src/GEpch.cpp"

    files{
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.h"
    }

    includedirs  {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines{
           "GE_PLATFORM_WINDOWS",
            "GE_BUILD_DLL"
        }

        postbuildcommands{
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputsdir.. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "GE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "GE_RELESE"
        symbols "On"

    filter "configurations:Dist"
        defines "GE_DIST"
        symbols "On"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/"..outputsdir.."/%{prj.name}")
    objdir ("bin-int/"..outputsdir.."/%{prj.name}")

    files{
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/src/**.h"
    }

    includedirs  {
        "GameEngine/vendor/spdlog/include",
        "GameEngine/src"
    }

    links{
        "GameEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines{
           "GE_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines "GE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "GE_RELEASE"
        symbols "On"

    filter "configurations:Dist"
        defines "GE_DIST"
        symbols "On"
