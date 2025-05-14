#include "valkron_pch.hpp"

#include "Valkron/Application.hpp"

#include "Valkron/Events/ApplicationEvent.hpp"

namespace Valkron {

    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application() {
        // Destructor implementation
    }

    void Application::Run() {
        while (m_Running) {
            m_Window->OnUpdate();
        }
    }
}