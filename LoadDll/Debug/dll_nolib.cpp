#include "objbase.h"
#include <stdio.h>
BOOL APIENTRY DllMain(_In_ void* hModule, _In_ unsigned long dwReason, _In_opt_ void* lpReserved)
{
	HANDLE g_hModule;
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		printf("Dll is attached!/n");
		g_hModule = (HINSTANCE)hModule;
		break;
	case DLL_PROCESS_DETACH:
		printf("Dll is detached!/n");
		g_hModule = NULL;
		break;
	default:
		break;
	}
}