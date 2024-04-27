#pragma once

#include "GameEngine/Core.h"

//C++ std lib should all be in precomplied headers not here
#include <string>
#include<functional>

namespace GameEngine {
	
	//BLOCKING MECHANISM 

	/* Enum to describe the event type.All the individul implementations are in their own files.
	There to tell which type each event is */

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick,AppUpdate,AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	/* We may want to filter certain events. Like isolate all the mouse events or keyboard event. 
	Why do we want bit streams and not just 1 2 3 4 is because we can have the same events be in 
	different categories*/

	enum EventCategory {
		None = 0,
		EventCategoryApplication     = BIT(0),
		EventCategoryInput           = BIT(1),
		EventCategoryKeyboard        = BIT(2),
		EventCategoryMouse           = BIT(3),
		EventCategoryMouseButton     = BIT(4),
	};

	/*we want to at run time check to see what type the event is. We dont really need this type func
	to be a memeber fucntion and its enough if it is a static func cause a key pressed event will always 
	be a key pressed event. 
	
	Now the reason to have a virtual event override is cause if we just have a pointer to the event class 
	then we can call type on event and find out what event it actually is*/
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType(){return EventType:: ##type;}\
								virtual EventType GetEventType() const override {return GetStaticType();}\
								virtual const char* GetName() const override {return #type;} 

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override {return category;}


	//EVENT CLASS
	/* Base Class for events */

	class GAME_ENGINE_API Event {
		friend class EventDispatcher;
	public:
		//All pure virtual meaning everyone needs to implement them
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;						//DEBUG ONLY
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); } 		//DEBUG ONLY

		/* Is this event in the given category*/
		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}

	protected:
		/* we need to be able to see if the event has been handled or not.
		If handled then we dont need to propagate the event further */
		bool m_Handled = false;
	};

	/**/
	class EventDispatcher {
		template <typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& event)
			: m_Event(event) { }

		template <typename T>
		bool Dispatch(EventFn<T> func) {
			if (m_Event.GetEventType() == T::GetStaticType()) {
				m_Event.m_Handled = func(*(T)&m_Event);
				return true;
			}
			return false;
		}

	private:
		Event& m_Event;
	};

	inline std::ostream& operator << (std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}
