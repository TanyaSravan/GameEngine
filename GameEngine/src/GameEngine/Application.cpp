#include "GEpch.h"
#include "Application.h"
#include <GameEngine/Events/ApplicationEvents.h>
#include "log.h"
namespace GameEngine {
	Application::Application() {

	}

	Application:: ~Application() {

	}
	
	void Application:: Run() {
		WindowResiseEvent e(1280, 760);
		GE_TRACE(e);
		while (true);
	}
}