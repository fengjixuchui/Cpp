// MyDlgNew.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "04.�Ӵ���.h"
#include "MyDlgNew.h"
#include "afxdialogex.h"


// CMyDlgNew �Ի���

IMPLEMENT_DYNAMIC(CMyDlgNew, CDialogEx)

CMyDlgNew::CMyDlgNew(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CMyDlgNew::~CMyDlgNew()
{
}

void CMyDlgNew::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDlgNew, CDialogEx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON1, &CMyDlgNew::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMyDlgNew ��Ϣ�������


void CMyDlgNew::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//delete this;
	CDialogEx::OnClose();
}


void CMyDlgNew::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//HWND hParent = GetParent()->m_hWnd;
	this->m_hWnd;
	MessageBox(0);
}
