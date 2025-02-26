#pragma once

#ifdef FX_PLATFORM_WINDOWS
	#ifdef FX_BUILD_DLL
		#define FINIX_API __declspec(dllexport)
	#else
		#define FINIX_API __declspec(dllimport)
	#endif
#else
#error Finix only supports Windows!
#endif

#define BIT(x) (1 << x)