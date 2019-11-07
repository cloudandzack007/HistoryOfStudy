#include "pch.h"
_declspec(dllexport) void Fun0(void)
{
	return;
}
_declspec(dllexport) void Fun1(void)
{
	return;
}
_declspec(dllexport) void Fun2(void)
{
	return;
}
BOOL APIENTRY DllMain(HMODULE /* hModule */, DWORD ul_reason_for_call, LPVOID /* lpReserved */)
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
