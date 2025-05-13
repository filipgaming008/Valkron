#include <Valkron.hpp>

class Sandbox : public Valkron::Application{
public:
    Sandbox(){
        // Constructor implementation
    }

    ~Sandbox(){
        // Destructor implementation
    }
};

Valkron::Application *Valkron::CreateApplication(){
    return new Sandbox();
}