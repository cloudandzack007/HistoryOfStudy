
// SmartPointer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSmartPointerApp: 
// �йش����ʵ�֣������ SmartPointer.cpp
//

class CSmartPointerApp : public CWinApp
{
public:
	CSmartPointerApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSmartPointerApp theApp;