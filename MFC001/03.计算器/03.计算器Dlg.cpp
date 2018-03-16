
// 03.������Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "03.������.h"
#include "03.������Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy03������Dlg �Ի���



CMy03������Dlg::CMy03������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY03_DIALOG, pParent)
	, m_EditResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy03������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_EditResult);
}

BEGIN_MESSAGE_MAP(CMy03������Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND_RANGE(IDC_BUTTON1, IDC_BUTTON0, &CMy03������Dlg::OnCmdRange)
	//ON_BN_CLICKED(IDC_BUTTON0, &CMy03������Dlg::OnBnClickedButton0)
	//ON_BN_CLICKED(IDC_BUTTON1, &CMy03������Dlg::OnBnClickedButton1)
	//ON_BN_CLICKED(IDC_BUTTON2, &CMy03������Dlg::OnBnClickedButton2)
	//ON_BN_CLICKED(IDC_BUTTON3, &CMy03������Dlg::OnBnClickedButton2)
	//ON_BN_CLICKED(IDC_BUTTON4, &CMy03������Dlg::OnBnClickedButton3)
	//ON_BN_CLICKED(IDC_BUTTON5, &CMy03������Dlg::OnBnClickedButton5)
	//ON_BN_CLICKED(IDC_BUTTON6, &CMy03������Dlg::OnBnClickedButton6)
	//ON_BN_CLICKED(IDC_BUTTON7, &CMy03������Dlg::OnBnClickedButton7)
	//ON_BN_CLICKED(IDC_BUTTON8, &CMy03������Dlg::OnBnClickedButton8)
	//ON_BN_CLICKED(IDC_BUTTON9, &CMy03������Dlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// CMy03������Dlg ��Ϣ�������

BOOL CMy03������Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//m_EditResult = L"123+456";
	//DWORD dwOp1, dwOp2;
	//WCHAR wOpChar;
	//swscanf_s(m_EditResult.GetBuffer(), L"%d%c%d", &dwOp1, &wOpChar,1, &dwOp2);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy03������Dlg::OnPaint()
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
HCURSOR CMy03������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMy03������Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_EditResult += L"3";
	UpdateData(FALSE);
}


void CMy03������Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_EditResult += L"4";
	UpdateData(FALSE);
}


void CMy03������Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_EditResult += L"2";
	UpdateData(FALSE);
}


void CMy03������Dlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_EditResult += L"6";
	UpdateData(FALSE);
}


void CMy03������Dlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_EditResult += L"5";
	UpdateData(FALSE);
}


void CMy03������Dlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_EditResult += L"7";
	UpdateData(FALSE);
}


void CMy03������Dlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_EditResult += L"9";
	UpdateData(FALSE);
}


void CMy03������Dlg::OnCmdRange(UINT uID)
{
	// 1 1001
	// 2 1002
	// 9 1009
	// 0 1010
	UpdateData(TRUE);
	if (uID == IDC_BUTTON0)
	{
		uID = IDC_BUTTON1 - 1;
	}
	if (m_EditResult[0] == L'0')
	{
		m_EditResult.Format(L"%d", uID - IDC_BUTTON1 + 1);
	}
	else
	{
		m_EditResult.Format(L"%s%d", m_EditResult, uID - IDC_BUTTON1 + 1);
	}
	//m_EditResult += L"8";
	UpdateData(FALSE);
}

void CMy03������Dlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_EditResult += L"8";
	UpdateData(FALSE);
}


void CMy03������Dlg::OnBnClickedButton0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	m_EditResult += L"0";
	UpdateData(FALSE);
}


void CMy03������Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	if (m_EditResult[0] == L'0')
	{
		m_EditResult = L"1";
	}
	else
	{
		m_EditResult += L"1";
	}
	UpdateData(FALSE);
}
