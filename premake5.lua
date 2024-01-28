workspace "Game"
    configurations { "Debug", "Release" }
    startproject "Game"
    architecture "x86_64"

    flags { "MultiProcessorCompile" }

    filter "configurations:Debug"
        defines { "DEBUG", "DEBUG_SHADER" }
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "Speed"
        flags { "LinkTimeOptimization" }

outdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Game"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir ("bin/" .. outdir)
    objdir ("obj/" .. outdir)

    files {
        "src/**.cpp",
        "src/**.h",
        "vendor/glad/src/glad.c",
    }

    includedirs {
        "src",
        "vendor/glfw/include",
        "vendor/glad/include",
    }

    links {
        "GLFW",
    }

    filter "system:linux"
        links { "dl", "pthread" }

        defines { "_X11" }

    filter "system:windows"
        defines { "_WINDOWS" }

group "Dependencies"
    include "vendor/glfw"
