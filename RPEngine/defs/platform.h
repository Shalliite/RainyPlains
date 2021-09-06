#pragma once

#ifdef _WIN32
#ifdef _WINDLL
#define RPE_API _declspec(dllexport)
#else
#define RPE_API _declspec(dllimport)
#endif
#else
#define RPE_API
#endif