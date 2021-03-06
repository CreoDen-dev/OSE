#ifndef OSE_LOGGER_H
#define OSE_LOGGER_H

#ifndef OSE_DISABLE_LOGGER

#include <OSE/Core.h>
#include <iostream>
#include <string>

namespace OSE {

	using std::string;

	#define LOG_OSE_TRACE   1
	#define LOG_OSE_INFO    2
	#define LOG_OSE_WARNING 3
	#define LOG_OSE_ERROR   4

	#define LOG_APP_TRACE   -1
	#define LOG_APP_INFO    -2
	#define LOG_APP_WARNING -3
	#define LOG_APP_ERROR   -4

	class OSE_API Logger {
	public:
		static Logger* instance;

		Logger();
		~Logger();

		void Log(int LogLevel, string message);

		void Start();

		void Stop();
	};

	template<typename T>
	string to_str(const T& x) {
		string res = "";
		t_float* ptr = (t_float*)(&x);
		int size = sizeof(x) / sizeof(t_float);
		for (int i = 0; i < size; i++) {
			res += std::to_string(ptr[i]);
			if (i + 1 < size) {
				res += " ";
			}
		}
		return res;
	}
}

#define OSE_LOG(...);	::OSE::Logger::instance->Log(__VA_ARGS__);

#else
#define OSE_LOG(...)
#endif

#endif