#pragma once

#ifdef VALKRON_PLATFORM_WINDOWS
    #ifdef VALKRON_BUILD_DLL
        #define VALKRON_API __declspec(dllexport)
    #else
        #define VALKRON_API __declspec(dllimport)
    #endif
#else
    #error Valkron only supports Windows!
#endif

#define BIT(x) (1 << x)