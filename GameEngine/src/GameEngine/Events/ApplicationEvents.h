#pragma once

#include "Event.h"
#include<sstream>

namespace GameEngine {

	class GAME_ENGINE_API WindowCloseEvent :public Event{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(WindowClose);
	};

	class GAME_ENGINE_API WindowResiseEvent : public Event {
	public:
		WindowResiseEvent(unsigned int width, unsigned int height)
			: m_WindowWidth(width), m_WindowHeight(height) {}
		
		inline unsigned int GetWindowWidth() { return m_WindowWidth; }
		inline unsigned int GetWindowHeight() { return m_WindowHeight; }

		std::string ToString() const override{
			std::stringstream ss;
			ss << "WindowResiseEvent: width: " << m_WindowWidth << ", Height: " << m_WindowHeight;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(WindowResize);

	private:
		unsigned int m_WindowWidth;
		unsigned int m_WindowHeight;
	};

	class GAME_ENGINE_API AppTickEvent :public Event {
	public:
		AppTickEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(AppTick);
	};

	class GAME_ENGINE_API AppUpdateEvent :public Event {
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(AppUpdate);
	};

	class GAME_ENGINE_API AppRenderEvent :public Event {
	public:
		AppRenderEvent() {}

		EVENT_CLASS_CATEGORY(EventCategoryApplication);
		EVENT_CLASS_TYPE(AppRender);
	};


}