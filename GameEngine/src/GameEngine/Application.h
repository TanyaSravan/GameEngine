#pragma once
#include "Core.h"
#include "Events/Event.h"

namespace GameEngine {

	class GAME_ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//Defined in client
	Application* CreateApplication();
}
