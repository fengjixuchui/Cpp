
// 02.Table.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy02TableApp: 
// �йش����ʵ�֣������ 02.Table.cpp
//

class CMy02TableApp : public CWinApp
{
public:
	CMy02TableApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy02TableApp theApp;