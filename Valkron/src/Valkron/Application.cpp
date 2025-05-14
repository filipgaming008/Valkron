#include "valkron_pch.hpp"
#include "Application.hpp"

#include "Events/ApplicationEvent.hpp"
#include "Log.hpp"

namespace Valkron {

    Application::Application() {
        // Constructor implementation
    }

    Application::~Application() {
        // Destructor implementation
    }

    void Application::Run() {
        WindowMovedEvent e(100, 200);
        VALKRON_TRACE(e);
    
        while (true) {
            // Main loop implementation
        }
    }
}