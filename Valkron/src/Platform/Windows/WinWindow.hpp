#pragma once

#include "Valkron/Window.hpp"

#include <GLFW/glfw3.h>

namespace Valkron{

    class WinWindow : public Window{
    private:
        GLFWwindow* m_Window;
        
        struct WindowData{
            std::string Title;
            unsigned int Width, Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;

    public:
        WinWindow(const WindowProps& props);
        virtual ~WinWindow();

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }

        inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
            void SetVSync(bool enabled) override;
        inline bool IsVSync() const override { return m_Data.VSync; }

        void* GetNativeWindow() const { return m_Window; }
    };


}