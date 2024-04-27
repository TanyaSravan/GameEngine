#include "GEpch.h"
#include "log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace GameEngine {

	std::shared_ptr<spdlog::logger> log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> log::s_ClientLogger;

	void log::Init() {
		//color, time stamp, name of the logger, log message
		spdlog::set_pattern("%^[%T] %n: %v%$");

		s_CoreLogger = spdlog::stdout_color_mt("GAMEENGINE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}
