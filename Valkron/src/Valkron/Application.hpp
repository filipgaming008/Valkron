#pragma once

#include "Valkron/Core.hpp"
#include "Valkron/Window.hpp"

#include "Valkron/Events/ApplicationEvent.hpp"

namespace Valkron{

    class VALKRON_API Application{
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        bool OnWindowClose(WindowCloseEvent& e);
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);
    };

    // To be defined in CLIENT
    Application *CreateApplication();
}