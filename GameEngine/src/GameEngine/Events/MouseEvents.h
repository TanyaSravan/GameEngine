#pragma once
#include "Event.h"
#include <sstream>


namespace GameEngine {

	class GAME_ENGINE_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x), m_MouseY(y) {}

		inline float GetMouseX() const {
			return m_MouseX;
		}

		inline float GetMouseY() const {
			return m_MouseY;
		}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: x:" << m_MouseX << ", y:" << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);
		EVENT_CLASS_TYPE(MouseMoved);

	private:
		float m_MouseX;
		float m_MouseY;
	};

	class GAME_ENGINE_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: m_xOffset(xOffset), m_yOffset(yOffset) {}

		inline float GetMouseXOffset() const {
			return m_xOffset;
		}

		inline float GetMouseXOffset() const {
			return m_yOffset;
		}
		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: x:" << m_xOffset << ", y:" << m_yOffset;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);
		EVENT_CLASS_TYPE(MouseScrolled);

	private:
		float m_xOffset;
		float m_yOffset;

	};

	class GAME_ENGINE_API MouseButtonEvent : public Event {

	public:
		inline int GetMouseButton() { return m_MouseButton; }

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

	protected:

		MouseButtonEvent(int button)
			: m_MouseButton(button) {}

		int m_MouseButton;
	};

	class GAME_ENGINE_API MouseButtonPressed : public MouseButtonEvent {
	public:
		MouseButtonPressed(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressed: " << m_MouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class GAME_ENGINE_API MouseButtonReleased : public MouseButtonEvent {
	public:
		MouseButtonReleased(int button)
			: MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleased: " << m_MouseButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

}