#pragma once

#include "Valkron/Events/Event.hpp"

namespace Valkron {

    class VALKRON_API WindowCloseEvent : public Event{
    public:
        WindowCloseEvent() {}

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class VALKRON_API WindowResizeEvent : public Event{
    private:
        unsigned int m_Width, m_Height;
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

        unsigned int GetWidth() const { return m_Width; }
        unsigned int GetHeight() const { return m_Height; }

        std::string ToString() const override{
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class VALKRON_API WindowMovedEvent : public Event{
    private:
        unsigned int m_X, m_Y;
    public:
        WindowMovedEvent(unsigned int x, unsigned int y) : m_X(x), m_Y(y) {}

        unsigned int GetX() const { return m_X; }
        unsigned int GetY() const { return m_Y; }

        std::string ToString() const override{
            std::stringstream ss;
            ss << "WindowMovedEvent: " << m_X << ", " << m_Y;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowMoved)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class VALKRON_API AppTickEvent : public Event{
    public:
        AppTickEvent() {}

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class VALKRON_API AppUpdateEvent : public Event{
    public:
        AppUpdateEvent() {}

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };

    class VALKRON_API AppRenderEvent : public Event{
    public:
        AppRenderEvent() {}

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
}