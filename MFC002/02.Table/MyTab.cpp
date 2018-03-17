// MyTab.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "02.Table.h"
#include "MyTab.h"
#include "MyDlgA.h"
#include "MyDlgB.h"
#include "MyDlgC.h"


// CMyTab

IMPLEMENT_DYNAMIC(CMyTab, CTabCtrl)

CMyTab::CMyTab()
{

}

CMyTab::~CMyTab()
{
}


BEGIN_MESSAGE_MAP(CMyTab, CTabCtrl)
	ON_NOTIFY_REFLECT(TCN_SELCHANGE, &CMyTab::OnTcnSelchange)
END_MESSAGE_MAP()



// CMyTab ��Ϣ�������




void CMyTab::PreSubclassWindow()
{
	// TODO: �ڴ����ר�ô����/����û���
	InsertItem(0, L"A");
	InsertItem(1, L"B");
	InsertItem(2, L"C");
	m_child[0] = new CMyDlgA;
	m_child[0]->Create(IDD_DIALOG1,this);
	m_child[1] = new CMyDlgB;
	m_child[1]->Create(IDD_DIALOG2,this);
	m_child[2] = new CMyDlgC;
	m_child[2]->Create(IDD_DIALOG3,this);
	// ���Ӵ����ƶ����Ϳͻ���һ����
	CRect rt = {};
	GetClientRect(&rt);
	rt.DeflateRect(0, 25, 0, 0);
	m_child[0]->MoveWindow(&rt);
	m_child[0]->ShowWindow(SW_SHOW);
	CTabCtrl::PreSubclassWindow();
}


void CMyTab::OnTcnSelchange(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	int nSel = GetCurSel();
	// ����֮ǰ�Ĵ��ڣ�ֻ��ʾ���ڵ���������ǩ���ڵĴ���
	for (int i=0;i<3;i++)
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
