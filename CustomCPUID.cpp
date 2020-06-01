// CustomCPUID.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "CustomCPUID.h"

#include <immintrin.h>

BOOL APIENTRY CustomCPUID( HMODULE hModule,
                           DWORD  ul_reason_for_call,
                           LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

bool isAVX2supported()
{
    int cpui[4];
    __cpuidex(cpui, 0, 0);
    int nIds = cpui[0];

    bool AVXsupported = false;
	
    if (nIds >= 0x00000001) {
        __cpuidex(cpui, 0x00000001, 0);

        bool osUsesXSAVE_XRSTORE = (cpui[2] & (1 << 27)) != 0;
        bool cpuAVXsupported = (cpui[2] & (1 << 28)) != 0;

    	if (osUsesXSAVE_XRSTORE && cpuAVXsupported)
    	{
            unsigned long long xcrFeatureMask = _xgetbv(_XCR_XFEATURE_ENABLED_MASK);
            AVXsupported = (xcrFeatureMask & 0x6) == 0x6;
    	}
    }
	
    if (nIds >= 0x00000007 && AVXsupported) {
        __cpuidex(cpui, 0x00000007, 0);
    	return (cpui[1] & ((int)1 << 5)) != 0;
    } else
    {
        return false;
    }
}