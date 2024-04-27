#pragma once


#ifdef GE_PLATFORM_WINDOWS

extern GameEngine::Application* GameEngine::CreateApplication();

	int main(int argc, char** argv) {
		GameEngine::log::Init();
		GE_CORE_WARN("Initiallised Log");
		int a = 5;
		GE_INFO("Initiallised Hello! Var = {0}",a);

		auto app = GameEngine::CreateApplication();
		app->Run();
		delete app;
	}

#endif  

