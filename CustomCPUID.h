
#pragma once

//more about this in reference 1
#ifdef CUSTOMCPUID_EXPORTS
#define CUSTOMCPUID  __declspec(dllexport)   // export DLL information

#else
#define CUSTOMCPUID  __declspec(dllimport)   // import DLL information

#endif

extern "C" CUSTOMCPUID bool isAVX2supported();
