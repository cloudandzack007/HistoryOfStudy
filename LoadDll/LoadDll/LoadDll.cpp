// LoadDll.cpp : �������̨Ӧ�ó������ڵ㡣
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

