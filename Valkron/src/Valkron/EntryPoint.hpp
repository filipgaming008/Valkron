#pragma once

#ifdef VLKR_PLATFORM_WINDOWS

extern Valkron::Application* Valkron::CreateApplication();

int main(int argc, char** argv){
    
    auto app = Valkron::CreateApplication();
    app->Run();
    delete app;
    
    return 0;
}

#endif