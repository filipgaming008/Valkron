#pragma once

#include "Event.hpp"

namespace Valkron{

    class VALKRON_API MouseMovedEvent : public Event{
    private:
        float m_X, m_Y;
    public:
        MouseMovedEvent(float x, float y) : m_X(x), m_Y(y) {}

        float GetX() const { return m_X; }
        float GetY() const { return m_Y; }

        std::string ToString() const override{
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_X << ", " << m_Y;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };

    class VALKRON_API MouseScrolledEvent : public Event{
    private:
        float m_XOffset, m_YOffset;
    public:
        MouseScrolledEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset) {}

        float GetXOffset() const { return m_XOffset; }
        float GetYOffset() const { return m_YOffset; }

        std::string ToString() const override{
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    };

    class VALKRON_API MouseButtonEvent : public Event{
    public:
        inline int GetMouseButton() const { return m_Button; }
        
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
            MouseButtonEvent(int button) : m_Button(button) {}
    
            int m_Button;
    };

    class VALKRON_API MouseButtonPressedEvent : public MouseButtonEvent{
    public:
        MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override{
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class VALKRON_API MouseButtonReleasedEvent : public MouseButtonEvent{
    public:
        MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

        std::string ToString() const override{
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_Button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };

}