#pragma once


#ifdef _WIN32
#ifdef _WINDLL
#define RPE_API _declspec(dllexport)
#else
#define RPE_API _declspec(dllimport)
#endif
#define RPE_EXTERN extern "C"
#else
#define RPE_EXTERN
#define RPE_API
#endif