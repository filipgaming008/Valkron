#include <Valkron.hpp>

class ExampleLayer : public Valkron::Layer{
public:
    ExampleLayer() : Layer("Example") {
        // Constructor implementation
    }

    void OnUpdate() override {
        VALKRON_INFO("ExampleLayer::Update");
    }

    void OnEvent(Valkron::Event& event) override {
        VALKRON_TRACE("{0}", event);
    }
};

class Sandbox : public Valkron::Application{
public:
    Sandbox(){
        PushLayer(new ExampleLayer());
    }

    ~Sandbox(){
        // Destructor implementation
    }
};

Valkron::Application *Valkron::CreateApplication(){
    return new Sandbox();
}