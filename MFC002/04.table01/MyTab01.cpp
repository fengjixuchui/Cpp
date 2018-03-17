// MyTab01.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "04.table01.h"
#include "MyTab01.h"


// CMyTab01

IMPLEMENT_DYNAMIC(CMyTab01, CTabCtrl)

CMyTab01::CMyTab01()
{

}

CMyTab01::~CMyTab01()
{
}

// ����  �Ի���  �Ի���ID
void CMyTab01::MyInsertItem(DWORD dwCount, ...)
{
	va_list va;
	va_start(va, dwCount);
	m_dwCount = dwCount;
	for (DWORD i = 0 ; i< dwCount;i++)
	{
		TCHAR* pHeader = va_arg(va, TCHAR*);
		CDialogEx*pWnd = va_arg(va, CDialogEx*);
		UINT uID = va_arg(va, UINT);
		InsertItem(i, pHeader);
		pWnd->Create(uID, this);
		m_child[i] = pWnd;
	}
	va_end(va);
	// ���Ӵ����ƶ����Ϳͻ���һ����
	CRect rt = {};
	GetClientRect(&rt);
	rt.DeflateRect(0, 25, 0, 0);
	m_child[0]->MoveWindow(&rt);
	m_child[0]->ShowWindow(SW_SHOW);
}

BEGIN_MESSAGE_MAP(CMyTab01, CTabCtrl)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, &CMyTab01::OnTcnSelchange)
END_MESSAGE_MAP()



// CMyTab01 ��Ϣ�������




void CMyTab01::OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	int nSel = GetCurSel();
	// ����֮ǰ�Ĵ��ڣ�ֻ��ʾ���ڵ���������ǩ���ڵĴ���
	for (int i = 0; i < m_dwCount; i++)
	{
		m_child[i]->ShowWindow(SW_HIDE);
	}
	// ���Ӵ����ƶ����Ϳͻ���һ����
	CRect rt = {};
	GetClientRect(&rt);
	rt.DeflateRect(0, 25, 0, 0);
	m_child[nSel]->MoveWindow(&rt);
	m_child[nSel]->ShowWindow(SW_SHOW);
}
