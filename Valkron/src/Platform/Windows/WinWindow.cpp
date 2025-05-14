#include "valkron_pch.hpp"
#include "Platform/Windows/WinWindow.hpp"

namespace Valkron{

    static bool s_GLFWInitialized = false;

    Window* Window::Create(const WindowProps& props){
        return new WinWindow(props);
    }

    WinWindow::WinWindow(const WindowProps& props){
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        VALKRON_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized){
            int verify = glfwInit();
            VALKRON_CORE_ASSERT(verify, "Could not initialize GLFW!");

            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }

    WinWindow::~WinWindow(){
        glfwDestroyWindow(m_Window);    
    }

    void WinWindow::OnUpdate(){
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WinWindow::SetVSync(bool enabled){
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }
}