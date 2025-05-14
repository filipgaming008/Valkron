#pragma once

#include "Valkron/Core.hpp"
#include "Valkron/Window.hpp"

namespace Valkron{

    class VALKRON_API Application{
    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    public:
        Application();
        virtual ~Application();

        void Run();
    };

    // To be defined in CLIENT
    Application *CreateApplication();
}