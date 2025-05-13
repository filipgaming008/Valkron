#pragma once

#include "Core.hpp"

namespace Valkron{

    class VLKR_API Application{
    public:
        Application();
        virtual ~Application();

        void Run();
    };


    // To be defined in CLIENT
    Application *CreateApplication();
}