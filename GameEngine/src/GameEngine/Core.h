#pragma once

#ifdef GE_PLATFORM_WINDOWS
	#ifdef GE_BUILD_DLL
		#define GAME_ENGINE_API __declspec(dllexport)
	#else
		#define GAME_ENGINE_API __declspec(dllimport)
	#endif
	#else 
		#error Game engine only supports Windows
#endif

// Bit definition for the event filter 
#define BIT(x) (1<<x)
