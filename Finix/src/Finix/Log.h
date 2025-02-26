#pragma once
#pragma warning(push)
#pragma warning(disable:4251)

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Finix
{
	class FINIX_API Log
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

// Core log macros
#define FX_CORE_TRACE(...)	::Finix::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FX_CORE_INFO(...)	::Finix::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FX_CORE_WARN(...)	::Finix::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FX_CORE_ERROR(...)	::Finix::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FX_CORE_FATAL(...)	::Finix::Log::GetCoreLogger()->fatak(__VA_ARGS__)

// Client log macros
#define FX_TRACE(...)		::Finix::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FX_INFO(...)		::Finix::Log::GetClientLogger()->info(__VA_ARGS__)
#define FX_WARN(...)		::Finix::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FX_ERROR(...)		::Finix::Log::GetClientLogger()->error(__VA_ARGS__)
#define FX_FATAL(...)		::Finix::Log::GetClientLogger()->fatak(__VA_ARGS__)