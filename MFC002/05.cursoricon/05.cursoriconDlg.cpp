
// 05.cursoriconDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "05.cursoricon.h"
#include "05.cursoriconDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMy05cursoriconDlg �Ի���



CMy05cursoriconDlg::CMy05cursoriconDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY05CURSORICON_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy05cursoriconDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMy05cursoriconDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMy05cursoriconDlg::OnBnClickedButton1)
	ON_COMMAND(ID_BUTTON32771, &CMy05cursoriconDlg::On������1��)
	ON_COMMAND(0x5001, &CMy05cursoriconDlg::OnͼƬ��1��)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32776, &CMy05cursoriconDlg::On����)
	ON_COMMAND(0x7001, &CMy05cursoriconDlg::On��̬)
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()


// CMy05cursoriconDlg ��Ϣ�������

BOOL CMy05cursoriconDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	// ������
	m_toolbar1.Create(this);
	m_toolbar1.LoadToolBar(IDR_TOOLBAR1);
	m_toolbar2.Create(this);
	m_toolbar2.LoadBitmapW(IDB_BITMAP1);
	UINT uId[] = {0x5001,0x5002,0x5003};
	m_toolbar2.SetButtons(uId,3);
	// ״̬��
	m_status.Create(this);
	// ����״̬��Ϊ����
	UINT uId2[] = { 0x6001,0x6002,0x6003 };
	m_status.SetIndicators(uId2, 3);
	// ����״̬������ʽ ���ı�
	m_status.SetPaneInfo(0, 0x6001, SBPS_NORMAL, 80);
	m_status.SetPaneInfo(1, 0x6002, SBPS_NORMAL, 80);
	m_status.SetPaneInfo(2, 0x6003, SBPS_NORMAL, 80);
	m_status.SetPaneText(0, L"����һ��״̬��");
	m_status.SetPaneText(1, L"���Ƕ���״̬��");
	m_status.SetPaneText(2, L"��������״̬��");

	// ��ʾ������״̬����
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy05cursoriconDlg::OnPaint()
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
HCURSOR CMy05cursoriconDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// �ı�ͼ��
void CMy05cursoriconDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HICON hIcon = AfxGetApp()->LoadIconW(IDI_ICON1);
	SetIcon(hIcon,FALSE);
}


void CMy05cursoriconDlg::On������1��()
{
	// TODO: �ڴ���������������
	MessageBox(L"���ǹ�����1��");
}

void CMy05cursoriconDlg::OnͼƬ��1��()
{
	MessageBox(L"����ͼƬ��1��");
}


void CMy05cursoriconDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	GetCursorPos(&point);
	::ScreenToClient(m_hWnd,&point);
	CString str;
	str.Format(L"x:%d,y:%d", point.x, point.y);
	m_status.SetPaneText(0, str.GetBuffer());
	CDialogEx::OnMouseMove(nFlags, point);
}


void CMy05cursoriconDlg::On����()
{
	// TODO: �ڴ���������������
	MessageBox(L"���ǹ���");
}


void CMy05cursoriconDlg::On��̬()
{
	MessageBox(L"���Ƕ�̬");
}

void CMy05cursoriconDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CPoint pt;
	GetCursorPos(&pt);
	CMenu mu;
	mu.LoadMenuW(IDR_MENU2);
	CMenu *pSub = mu.GetSubMenu(0);
	// ��pSub�żӸ��˵���
	pSub->AppendMenuW(MF_STRING, 0x7001, L"���Ƕ�̬����2��");
	TrackPopupMenu(pSub->m_hMenu, TPM_LEFTALIGN, pt.x, pt.y,
		NULL, m_hWnd, NULL);
	CDialogEx::OnRButtonUp(nFlags, point);
}
