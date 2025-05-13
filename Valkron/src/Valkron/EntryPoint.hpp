#pragma once

#ifdef VALKRON_PLATFORM_WINDOWS

extern Valkron::Application* Valkron::CreateApplication();

int main(int argc, char** argv){
    
    Valkron::Log::Init();
    VALKRON_CORE_WARN("Initialized Log!");
    VALKRON_INFO("Hello from Valkron!");

    auto app = Valkron::CreateApplication();
    app->Run();
    delete app;
    
    return 0;
}

#endif