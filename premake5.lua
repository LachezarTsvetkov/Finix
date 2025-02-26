workspace "Finix"
	architecture "x64"

	configurations
	{
		"Debug",
		"Development",
		"Release"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Finix"
	location "Finix"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include;"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"FX_PLATFORM_WINDOWS",
			"FX_BUILD_DLL",
		}

		postbuildcommands 
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "FX_DEBUG"
		symbols "On"
		buildoptions { "/utf-8" }

	filter "configurations:Development"
		defines "FX_DEVELOPMENT"
		symbols "On"
		buildoptions { "/utf-8" }

	filter "configurations:Release"
		defines "FX_RELEASE"
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
		"Finix/vendor/spdlog/include;",
		"Finix/src;"
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
		symbols "On"
		buildoptions { "/utf-8" }

	filter "configurations:Development"
		defines "FX_DEVELOPMENT"
		symbols "On"
		buildoptions { "/utf-8" }

	filter "configurations:Release"
		defines "FX_RELEASE"
		symbols "On"
		buildoptions { "/utf-8" }