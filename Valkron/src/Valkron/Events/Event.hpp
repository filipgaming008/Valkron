#pragma once

#include "Valkron/Core.hpp"

namespace Valkron{

    // Events are blocking
    enum class EventType{
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory{
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };

    
    class VALKRON_API Event {
    private:
        friend class EventDispatcher;
    public:
        virtual EventType GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }
        
        inline bool IsInCategory(EventCategory category){
            return GetCategoryFlags() & category;
        }

        inline bool Handled() const { return m_Handled; }
    protected:
        bool m_Handled = false;
    };
    
    class EventDispatcher{
    private:
        Event& m_Event;
        
        template<typename T>
        using EventFunction = std::function<bool(T&)>;
    public:
        EventDispatcher(Event& event) : m_Event(event) {}
        
        template<typename T>
        bool Dispatch(EventFunction<T> func) {
            if(m_Event.GetEventType() == T::GetStaticType()){
                m_Event.m_Handled = func(*(T*)&m_Event);
                return true;
            }
            return false;
        }
    };
    
    #define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                                    virtual EventType GetEventType() const override { return GetStaticType(); }\
                                    virtual const char* GetName() const override { return #type; }
    
    #define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
    
    inline std::ostream& operator<<(std::ostream& os, const Event& e){
        return os << e.ToString();
    }
}
