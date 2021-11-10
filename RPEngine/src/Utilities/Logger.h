#pragma once

/*
* 
* This header/source is part of RainyPlains game/rendering engine originally developed by Deivids Dukalskis
* 
*/


/*
* External headers
*/
//
#include <sstream>
#include <system_error>
#include <spdlog/spdlog.h>
//


/*
* Internal headers
*/
//
#include "../Defines/Defines.h"
//

#ifdef _DEBUG

namespace rpe
{
	namespace util
	{
		class RPE_API Logger
		{
		public:
			template<typename ...Args>
			static void LogImplErr(s32 line, const char* fileName, Args&& ...args)
			{
				std::ostringstream stream;
				stream << "**ERROR** FILE: [" << fileName << "] LINE: [" << line << "] : ";
				(stream << ... << std::forward<Args>(args));

				Log()->error(stream.str().c_str());
			}
			static void LogImplHresult(s32 line, const char* filename, HRESULT hr);
			static std::shared_ptr<spdlog::logger>& Log();
			static std::shared_ptr<spdlog::logger> s_logger;
			static bool s_initialized;
		};
	}
}

#define RP_INFO_LOG(...)		rpe::util::Logger::Log()->trace(__VA_ARGS__)
#define RP_WARN_LOG(...)		rpe::util::Logger::Log()->warn(__VA_ARGS__)
#define RP_ERR_LOG(...)			rpe::util::Logger::LogImplErr(__LINE__, __FILE__, __VA_ARGS__)
#define RP_HRESULT_CHECK(hresult) rpe::util::Logger::LogImplHresult(__LINE__, __FILE__, hresult)

#else

#define RP_INFO_LOG(x)
#define RP_WARN_LOG(x)
#define RP_ERR_LOG(x)

#endif

