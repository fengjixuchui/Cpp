
// 01.ListTree.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy01ListTreeApp: 
// �йش����ʵ�֣������ 01.ListTree.cpp
//

class CMy01ListTreeApp : public CWinApp
{
public:
	CMy01ListTreeApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy01ListTreeApp theApp;