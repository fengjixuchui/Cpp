
// 08.���̼�ͨѶ-B.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMy08���̼�ͨѶBApp: 
// �йش����ʵ�֣������ 08.���̼�ͨѶ-B.cpp
//

class CMy08���̼�ͨѶBApp : public CWinApp
{
public:
	CMy08���̼�ͨѶBApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMy08���̼�ͨѶBApp theApp;