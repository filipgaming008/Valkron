#pragma once

#include "Valkron/Core.hpp"
#include "Valkron/Window.hpp"
#include "Valkron/LayerStack.hpp"
#include "Valkron/Events/Event.hpp"
#include "Valkron/Events/ApplicationEvent.hpp"

namespace Valkron{

    class VALKRON_API Application{
    private:
        LayerStack m_LayerStack;
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        bool OnWindowClose(WindowCloseEvent& e);
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer) { m_LayerStack.PushLayer(layer); }
        void PushOverlay(Layer* overlay) { m_LayerStack.PushOverlay(overlay); }
    };

    // To be defined in CLIENT
    Application *CreateApplication();
}