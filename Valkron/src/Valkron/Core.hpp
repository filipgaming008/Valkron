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

#ifdef VALKRON_ENABLE_ASSERTS
    #define VALKRON_ASSERT(x, ...) { if(!(x)) { VALKRON_ERROR("Assertion Failed: {0}", (__VA_ARGS__)); __debugbreak(); } }
    #define VALKRON_CORE_ASSERT(x, ...) { if(!(x)) { VALKRON_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__)); __debugbreak(); } }
#else
    #define VALKRON_ASSERT(x, ...)
    #define VALKRON_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)