
// 05.cursoricon.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy05cursoriconApp: 
// �йش����ʵ�֣������ 05.cursoricon.cpp
//

class CMy05cursoriconApp : public CWinApp
{
public:
	CMy05cursoriconApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy05cursoriconApp theApp;