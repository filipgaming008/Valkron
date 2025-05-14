#pragma once

#include "valkron_pch.hpp"

#include "Valkron/Core.hpp"
#include "Valkron/Events/Event.hpp"
#include "Valkron/Log.hpp"

namespace Valkron{

    struct WindowProps{
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "Valkron Engine", unsigned int width = 1280, unsigned int height = 720)
            : Title(title), Width(width), Height(height) {}
    };

    class VALKRON_API Window{
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;

        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };
}