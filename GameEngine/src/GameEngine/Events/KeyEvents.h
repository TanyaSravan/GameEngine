#pragma once

#include "Event.h"

namespace GameEngine {

	/*This is a really simple base event. No one should eb able to make this event except for the
	classes that derive from it*/

	class GAME_ENGINE_API KeyEvents :public Event {
	public:
		inline int GetKeyCode() const { return m_KeyCode; }			//Getter Fucntion

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);


	protected:
		//Protected constructor cause nothing else can construct it
		KeyEvents(int keycode) 
			:m_KeyCode(keycode) {}
		
		int m_KeyCode;
	};

	/*This is an actual event that we see in the engine */
	class GAME_ENGINE_API KeyPressedEvent : public KeyEvents {
	public:
		// this has a keycode and a repeat count -> the repeat count can also be a bool
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvents(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		EVENT_CLASS_TYPE(KeyPressed);

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_RepeatCount << " repeats" << ")";
			return ss.str();
		}

	private:
		int m_RepeatCount;
	};

	class GAME_ENGINE_API KeyReleasedEvent : public KeyEvents {
	public:
		// this has a keycode and a repeat count -> the repeat count can also be a bool
		KeyReleasedEvent(int keycode, int repeatCount)
			: KeyEvents(keycode) {}

		EVENT_CLASS_TYPE(KeyReleased);

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent";
			return ss.str();
		}
	};
}

