#pragma once


#ifdef NEWTESTLIBRARY_EXPORTS
#define NEWTESTLIBRARY_API __declspec(dllexport)
#else
#define NEWTESTLIBRARY_API __declspec(dllimport)
#endif

extern "C" NEWTESTLIBRARY_API int Start_Princess_Test();