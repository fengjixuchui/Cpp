
// MFC002Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFC002.h"
#include "MFC002Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC002Dlg �Ի���



CMFC002Dlg::CMFC002Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFC002_DIALOG, pParent)
	, m_strShow(_T(""))
	, m_radioSex(0)
	, m_checkLove(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFC002Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strShow);
	DDX_Radio(pDX, IDC_RADIO1, m_radioSex);
	DDX_Check(pDX, IDC_CHECK1, m_checkLove);
	DDX_Control(pDX, IDC_COMBO1, m_combox);
	DDX_Control(pDX, IDC_BUTTON2, m_BtnAdd);
	DDX_Control(pDX, IDC_STATIC1, m_staticPic);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_SLIDER1, m_slider);
}

BEGIN_MESSAGE_MAP(CMFC002Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFC002Dlg::OnBtn1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFC002Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFC002Dlg::OnBnClickedButton3)
	ON_WM_TIMER()
	ON_NOTIFY(NM_THEMECHANGED, IDC_SLIDER1, &CMFC002Dlg::OnNMThemeChangedSlider1)
	ON_NOTIFY(TRBN_THUMBPOSCHANGING, IDC_SLIDER1, &CMFC002Dlg::OnTRBNThumbPosChangingSlider1)
END_MESSAGE_MAP()


// CMFC002Dlg ��Ϣ�������

BOOL CMFC002Dlg::OnInitDialog()
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

void CMFC002Dlg::OnPaint()
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
HCURSOR CMFC002Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFC002Dlg::OnBtn1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);// �ؼ�������
	const TCHAR* szSex[] = {L"��",L"Ů",L"δ֪"};
	m_strShow = L"�Ա�";
	// m_radioSex�󶨵���1��group����Ϊtrue��radio��
	m_strShow += szSex[m_radioSex];
	m_strShow += L"\r\n";
	const TCHAR* szlove[] = { L"��",L"��",L"��ȷ��" };
	m_strShow += L"����(IT)��";
	// m_checkLove�Ȱ󶨵�check�ϣ�Ȼ���ٰ�check�ı�Ϊtri-state
	m_strShow += szlove[m_checkLove];
	UpdateData(FALSE);// ���µ��ؼ���
}

// combobox
void CMFC002Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_combox.AddString(L"BJ");
	m_combox.AddString(L"sh");
	m_combox.AddString(L"gz");
	m_combox.AddString(L"sz");
	m_combox.SetCurSel(0);
	//m_BtnAdd.ShowWindow(SW_HIDE);
	m_BtnAdd.EnableWindow(FALSE);
}


void CMFC002Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/*static bool b = false;
	CBitmap bmp;
	bmp.LoadBitmapW(b?IDB_BITMAP1:IDB_BITMAP2);
	m_staticPic.SetBitmap(bmp);
	b = !b;*/
	SetTimer(0x1001, 100, NULL);
	SetTimer(0x1002, 1000, NULL);

}


void CMFC002Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (nIDEvent == 0x1001)
	{
		static bool b = false;
		CBitmap bmp;
		bmp.LoadBitmapW(b ? IDB_BITMAP1 : IDB_BITMAP2);
		m_staticPic.SetBitmap(bmp);
		b = !b;
	}
	else if(nIDEvent == 0x1002)
	{
		// �ڵ�ǰλ����ƫ��10
		// getpos  setpos
		// m_progress.OffsetPos(10);
		m_progress.SetStep(30);// ���ò���ֵ��ֻ������1��
		m_progress.StepIt();

	}
	CDialogEx::OnTimer(nIDEvent);
}


void CMFC002Dlg::OnNMThemeChangedSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// �ù���Ҫ��ʹ�� Windows XP ����߰汾��
	// ���� _WIN32_WINNT ���� >= 0x0501��
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//int nPos = m_slider.GetPos();
	//m_progress.SetPos(nPos);
	*pResult = 0;
}


void CMFC002Dlg::OnTRBNThumbPosChangingSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// �˹���Ҫ�� Windows Vista ����߰汾��
	// _WIN32_WINNT ���ű��� >= 0x0600��
	NMTRBTHUMBPOSCHANGING *pNMTPC = reinterpret_cast<NMTRBTHUMBPOSCHANGING *>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// ���޸Ŀؼ�����  notify before move
	m_progress.SetPos(pNMTPC->dwPos);
	*pResult = 0;
}
