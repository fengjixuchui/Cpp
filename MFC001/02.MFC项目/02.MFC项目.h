
// 02.MFC��Ŀ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy02MFC��ĿApp: 
// �йش����ʵ�֣������ 02.MFC��Ŀ.cpp
//

class CMy02MFC��ĿApp : public CWinApp
{
public:
	CMy02MFC��ĿApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy02MFC��ĿApp theApp;