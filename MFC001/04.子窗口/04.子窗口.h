
// 04.�Ӵ���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy04�Ӵ���App: 
// �йش����ʵ�֣������ 04.�Ӵ���.cpp
//

class CMy04�Ӵ���App : public CWinApp
{
public:
	CMy04�Ӵ���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy04�Ӵ���App theApp;