
// 03.������.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy03������App: 
// �йش����ʵ�֣������ 03.������.cpp
//

class CMy03������App : public CWinApp
{
public:
	CMy03������App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy03������App theApp;