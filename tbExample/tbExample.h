
// tbExample.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CtbExampleApp:
// �йش����ʵ�֣������ tbExample.cpp
//

class CtbExampleApp : public CWinApp
{
public:
	CtbExampleApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CtbExampleApp theApp;