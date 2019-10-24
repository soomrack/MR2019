#pragma once

#ifdef LIBRARYTEST_EXPORTS
#define LIBRARYTEST_API __declspec(dllexport)
#else
#define LIBRARYTEST_API __declspec(dllimport)
#endif


extern "C" LIBRARYTEST_API int StartTest();