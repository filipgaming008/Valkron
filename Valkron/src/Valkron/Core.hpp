#pragma once

#ifdef VLKR_PLATFORM_WINDOWS
    #ifdef VLKR_BUILD_DLL
        #define VLKR_API __declspec(dllexport)
    #else
        #define VLKR_API __declspec(dllimport)
    #endif
#else
    #error Valkron only supports Windows!
#endif