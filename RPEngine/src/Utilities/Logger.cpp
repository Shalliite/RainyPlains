
/*
*
* This header/source is part of RainyPlains game/rendering engine originally developed by Deivids Dukalskis
*
*/

/*
* External headers
*/
//
#include <spdlog/sinks/stdout_color_sinks.h>
//

/*
* Internal headers
*/
//
#include "Logger.h"
//

#ifdef _DEBUG

namespace rpe::util
{
	std::shared_ptr<spdlog::logger>& Logger::Log()
	{
		if(!s_initialized)
		{
			spdlog::sink_ptr logSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
			logSink->set_pattern(" [%T] %^ %v %$");

			s_logger = std::make_shared<spdlog::logger>("RP_LOG", logSink);
			spdlog::register_logger(s_logger);
			s_logger->set_level(spdlog::level::trace);
			s_logger->flush_on(spdlog::level::trace);
			s_initialized = true;
		}
		return s_logger;
	}

	void Logger::LogImplHresult(s32 line, const char* filename, HRESULT hr)
	{
		if(!(hr==S_OK))
		{
			std::string errTxt = std::system_category().message(hr);
			std::ostringstream hrHex;
			hrHex << std::hex << hr;
			std::string hrTxt(hrHex.str());
			std::ostringstream stream;
			stream << "ERR_CODE: [0x" << hrTxt << "] DESC: " << errTxt;
			LogImplErr(line, filename, stream.str().c_str());
		}
	}

	std::shared_ptr<spdlog::logger> Logger::s_logger;
	bool Logger::s_initialized = false;
}


#endif