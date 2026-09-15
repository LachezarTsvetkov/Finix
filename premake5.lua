workspace "Finix"
	architecture "x64"

	configurations
	{
		"Debug",
		"Development",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to the root folder:
IncludeDir = {}
IncludeDir["GLFW"] = "Finix/vendor/GLFW/include"
IncludeDir["Glad"] = "Finix/vendor/Glad/include"

include "Finix/vendor/GLFW"
include "Finix/vendor/Glad"

project "Finix"
	location "Finix"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "fxpch.h"
	pchsource "Finix/src/fxpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}"
	}

	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib",
		"dwmapi.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"FX_PLATFORM_WINDOWS",
			"FX_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "FX_DEBUG"
		buildoptions "/MDd"
		symbols "On"
		buildoptions { "/utf-8" }

	filter "configurations:Development"
		defines "FX_DEVELOPMENT"
		buildoptions "/MD"
		symbols "On"
		buildoptions { "/utf-8" }

	filter "configurations:Release"
		defines "FX_RELEASE"
		buildoptions "/MD"
		symbols "On"
		buildoptions { "/utf-8" }



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Finix/vendor/spdlog/include",
		"Finix/src"
	}

	links
	{
		"Finix"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"FX_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "FX_DEBUG"
		buildoptions "/MDd"
		symbols "On"
		buildoptions { "/utf-8" }

	filter "configurations:Development"
		defines "FX_DEVELOPMENT"
		buildoptions "/MD"
		symbols "On"
		buildoptions { "/utf-8" }

	filter "configurations:Release"
		defines "FX_RELEASE"
		buildoptions "/MD"
		symbols "On"
		buildoptions { "/utf-8" }