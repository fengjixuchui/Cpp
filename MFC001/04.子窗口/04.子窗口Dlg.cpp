
// 04.�Ӵ���Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "04.�Ӵ���.h"
#include "04.�Ӵ���Dlg.h"
#include "afxdialogex.h"
#include "MyDlgNew.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy04�Ӵ���Dlg �Ի���



CMy04�Ӵ���Dlg::CMy04�Ӵ���Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY04_DIALOG, pParent)
	, m_reg(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy04�Ӵ���Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_reg);
}

BEGIN_MESSAGE_MAP(CMy04�Ӵ���Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy04�Ӵ���Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMy04�Ӵ���Dlg ��Ϣ�������

BOOL CMy04�Ӵ���Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy04�Ӵ���Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMy04�Ӵ���Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy04�Ӵ���Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_reg == L"12345")
	{
		// ��¼�ɹ������ص�ǰ���ڣ���ʾ��¼���������
		//ShowWindow(SW_HIDE);
		//CMyDlgNew p;
		//p.DoModal();
		//ShowWindow(SW_SHOW);
		CMyDlgNew *p = new CMyDlgNew;
		p->Create(IDD_DIALOG1, this);
		p->ShowWindow(SW_SHOW);
	}
}
