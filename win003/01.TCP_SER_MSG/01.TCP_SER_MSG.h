
// 01.TCP_SER_MSG.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy01TCP_SER_MSGApp: 
// �йش����ʵ�֣������ 01.TCP_SER_MSG.cpp
//

class CMy01TCP_SER_MSGApp : public CWinApp
{
public:
	CMy01TCP_SER_MSGApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy01TCP_SER_MSGApp theApp;