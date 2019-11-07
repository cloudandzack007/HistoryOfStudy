// LoadDll.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <wtypes.h>


int main()
{
	HINSTANCE hinst = ::LoadLibrary("Dll.dll");
	if (NULL != hinst)
	{
		printf("loaded");
		system("Pause");
	}
	return 0;
}

