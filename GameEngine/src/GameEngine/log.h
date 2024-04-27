#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace GameEngine {

	class GAME_ENGINE_API log
	{
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
	
}

//Core log macros

#define GE_CORE_ERROR(...)    ::GameEngine::log::GetCoreLogger()->error(__VA_ARGS__)
#define GE_CORE_WARN(...)     ::GameEngine::log::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_INFO(...)     ::GameEngine::log::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_TRACE(...)    ::GameEngine::log::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_CRITICAL(...) ::GameEngine::log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log macros

#define GE_ERROR(...)    ::GameEngine::log::GetClientLogger()->error(__VA_ARGS__)
#define GE_WARN(...)     ::GameEngine::log::GetClientLogger()->warn(__VA_ARGS__)
#define GE_INFO(...)     ::GameEngine::log::GetClientLogger()->info(__VA_ARGS__)
#define GE_TRACE(...)    ::GameEngine::log::GetClientLogger()->trace(__VA_ARGS__)
#define GE_CRITICAL(...) ::GameEngine::log::GetClientLogger()->critical(__VA_ARGS__)
