
// 01.TCP_SER_MSGDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "01.TCP_SER_MSG.h"
#include "01.TCP_SER_MSGDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy01TCP_SER_MSGDlg �Ի���



CMy01TCP_SER_MSGDlg::CMy01TCP_SER_MSGDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY01TCP_SER_MSG_DIALOG, pParent)
	, m_edit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy01TCP_SER_MSGDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edit);
}
#define WM_MYSOCKET WM_USER+1
BEGIN_MESSAGE_MAP(CMy01TCP_SER_MSGDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy01TCP_SER_MSGDlg::OnBnClickedButton1)
	ON_MESSAGE(WM_MYSOCKET, &CMy01TCP_SER_MSGDlg::OnMysocket)
END_MESSAGE_MAP()


// CMy01TCP_SER_MSGDlg ��Ϣ�������

BOOL CMy01TCP_SER_MSGDlg::OnInitDialog()
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

void CMy01TCP_SER_MSGDlg::OnPaint()
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
HCURSOR CMy01TCP_SER_MSGDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMy01TCP_SER_MSGDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// ����������
	if (m_tcp.InitServer("127.0.0.1", 0x1234))
	{
		MessageBox(L"�����������ɹ���");
	}
	else
	{
		MessageBox(L"����������ʧ�ܣ�");
		return;
	}
	// �����е������������������ڹ���
	// ��m_socket��FD_ACCEPT | FD_CLOSE�¼��йܸ�����m_hWnd
	// ����Ҫm_socket��ӦACCEPT��closeʱ������ͨ��WM_MYSOCKET(�Զ����)֪ͨ��
	// ��ͨ������OnMysocket(�Զ����)���������Ϣ
	WSAAsyncSelect(m_tcp.m_socket, m_hWnd, WM_MYSOCKET, FD_ACCEPT | FD_CLOSE);
}


afx_msg LRESULT CMy01TCP_SER_MSGDlg::OnMysocket(WPARAM wParam, LPARAM lParam)
{
	// wparam : socket  �й�ʱ��ĵ�1������
	// lparam: loword event �й�ʱ��ĵ�4������
	// lparam: hiword error code
	SOCKET s = wParam;
	WORD wEvent = WSAGETSELECTEVENT(lParam);
	WORD wErrorCode = WSAGETSELECTERROR(lParam);
	if (wErrorCode)
	{
		if (m_tcp.TcpClientExit(s))
		{
			UpdateData(TRUE);
			m_edit += L"�ͻ����˳�\r\n";
			UpdateData(FALSE);
		}
		return 0;
	}
	switch (wEvent)
	{
	case FD_ACCEPT:
	{
		// ���տͻ�������
		SOCKET s = m_tcp.TcpAccept();
		if (s == INVALID_SOCKET)
		{
			return 0;
		}
		// �Ѹÿͻ��˵������¼��йܸ�����
		WSAAsyncSelect(s, m_hWnd, WM_MYSOCKET, FD_READ | FD_CLOSE);
	}
	break;
	case FD_READ: {
		char buf[1024] = {};
		int nRet = m_tcp.TcpRecv(s, buf, 1024);
		if (nRet == SOCKET_ERROR) return 0;
		UpdateData(TRUE);
		m_edit += CString(buf);
		m_edit += L"\r\n";
		UpdateData(FALSE);
		break;
	}
	case FD_CLOSE:
	{
		if (m_tcp.TcpClientExit(s))
		{
			UpdateData(TRUE);
			m_edit += L"�ͻ����˳�\r\n";
			UpdateData(FALSE);
		}
		break;
	}
	default:
		break;
	}
	return 0;
}
