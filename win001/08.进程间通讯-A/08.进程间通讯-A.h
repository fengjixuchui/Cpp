
// 08.���̼�ͨѶ-A.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy08���̼�ͨѶAApp: 
// �йش����ʵ�֣������ 08.���̼�ͨѶ-A.cpp
//

class CMy08���̼�ͨѶAApp : public CWinApp
{
public:
	CMy08���̼�ͨѶAApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy08���̼�ͨѶAApp theApp;