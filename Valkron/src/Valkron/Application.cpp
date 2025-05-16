#include "valkron_pch.hpp"

#include "Valkron/Application.hpp"

namespace Valkron {

    #define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));
    }

    Application::~Application() {
        // Destructor implementation
    }

    void Application::Run() {
        while (m_Running) {
            for (Layer* layer : m_LayerStack) {
                layer->OnUpdate();
            }
            m_Window->OnUpdate();
        }
    }

    void Application::OnEvent(Event& e) {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
            (*--it)->OnEvent(e);
            if (e.Handled()) {
                break;
            }
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e){
        m_Running = false;
        return true;
    }
}