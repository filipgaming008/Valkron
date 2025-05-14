#pragma once

#include "Valkron/Core.hpp"
#include "Valkron/Events/Event.hpp"

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Valkron{
    class VALKRON_API Log{
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;

    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
    };
}

// Core log macros
#define VALKRON_CORE_TRACE(...) ::Valkron::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VALKRON_CORE_INFO(...) ::Valkron::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VALKRON_CORE_WARN(...) ::Valkron::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VALKRON_CORE_ERROR(...) ::Valkron::Log::GetCoreLogger()->error(__VA_ARGS__
#define VALKRON_CORE_FATAL(...) ::Valkron::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define VALKRON_TRACE(...) ::Valkron::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VALKRON_INFO(...) ::Valkron::Log::GetClientLogger()->info(__VA_ARGS__)
#define VALKRON_WARN(...) ::Valkron::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VALKRON_ERROR(...) ::Valkron::Log::GetClientLogger()->error(__VA_ARGS__)
#define VALKRON_FATAL(...) ::Valkron::Log::GetClientLogger()->fatal(__VA_ARGS__)

// Enable spdlog/fmt formatting for all Valkron::Event-derived types
#include <type_traits>
template<typename T>
struct fmt::formatter<T, char, std::enable_if_t<std::is_base_of<Valkron::Event, T>::value, void>> : fmt::ostream_formatter {};