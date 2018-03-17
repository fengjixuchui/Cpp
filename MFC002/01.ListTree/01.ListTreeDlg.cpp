
// 01.ListTreeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "01.ListTree.h"
#include "01.ListTreeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMy01ListTreeDlg �Ի���



CMy01ListTreeDlg::CMy01ListTreeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MY01LISTTREE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy01ListTreeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_TREE1, m_tree);
	DDX_Control(pDX, IDC_MFCSHELLTREE1, m_mfcTree);
	DDX_Control(pDX, IDC_MFCSHELLLIST1, m_mfcList);
}

BEGIN_MESSAGE_MAP(CMy01ListTreeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CMy01ListTreeDlg::OnNMClickList1)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CMy01ListTreeDlg::OnTvnSelchangedTree1)
	ON_NOTIFY(NM_CLICK, IDC_TREE1, &CMy01ListTreeDlg::OnNMClickTree1)
END_MESSAGE_MAP()


// CMy01ListTreeDlg ��Ϣ�������

BOOL CMy01ListTreeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	InitImgList();
	InitList();
	InitTree();
	m_mfcTree.SetRelatedList(&m_mfcList);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMy01ListTreeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMy01ListTreeDlg::OnPaint()
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
HCURSOR CMy01ListTreeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMy01ListTreeDlg::InitList()
{
	// ������չ���  ������  ����ѡ��
	m_list.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	// ����list�Ĺ���ͼ������
	m_list.SetImageList(&m_img, LVSIL_SMALL);
	// ����������Ϣ
	// 1. �������б���
	m_list.InsertColumn(0, L"��1��", 0, 80);
	m_list.InsertColumn(1, L"��2��", 0, 80);
	m_list.InsertColumn(2, L"��3��", 0, 80);
	// 2. �ٲ�������Ϣ   �б���  ������
	for (int i=0;i<20;i++)
	{
		TCHAR szShow[20] = {};
		swprintf_s(szShow, 20, L"��%d��",i+1);
		// �б��� 
		m_list.InsertItem(i, szShow,i%4);
		// ������
		swprintf_s(szShow, 20, L"��%d��%d��", i + 1,1);
		m_list.SetItemText(i, 1, szShow);
		swprintf_s(szShow, 20, L"��%d��%d��", i + 1, 2);
		m_list.SetItemText(i, 2, szShow);
	}

}

void CMy01ListTreeDlg::InitImgList()
{
	// ÿ��icon����Ϣ  ��С��
	// ����һ��ԱΪ32*32��Сʹ��32λɫ��icon���飬
	// �����ʼ�ռ��СΪ4��������֮��1����
	m_img.Create(32, 32, ILC_COLOR32, 4, 1);
	m_img.Add(AfxGetApp()->LoadIconW(IDI_ICON1));
	m_img.Add(AfxGetApp()->LoadIconW(IDI_ICON2));
	m_img.Add(AfxGetApp()->LoadIconW(IDI_ICON3));
	m_img.Add(AfxGetApp()->LoadIconW(IDI_ICON4));

}



void CMy01ListTreeDlg::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	CString str = m_list.GetItemText(pNMItemActivate->iItem, pNMItemActivate->iSubItem);
	MessageBox(str.GetBuffer());
}

void CMy01ListTreeDlg::InitTree()
{
	// ���ù���ͼ��
	m_tree.SetImageList(&m_img, TVSIL_NORMAL);
	// 1���ڵ�
	HTREEITEM hParent = m_tree.InsertItem(
		L"SDK",// �����ı�
		0,// �����������ʾ��ͼ���������е�����
		3,// �ýڵ㱻�����ʱ����ʾ��ͼ���������е�����
		TVI_ROOT,// ���ڵ�
		TVI_LAST// ���뷽ʽ
	);
	// 2���ڵ�
	m_tree.InsertItem(L"SDK001", 1,3,hParent, TVI_LAST);
	m_tree.InsertItem(L"SDK002", 2,3,hParent, TVI_LAST);
	// 1���ڵ�
	hParent = m_tree.InsertItem(L"MFC", 0,3,TVI_ROOT, TVI_LAST);
	m_tree.InsertItem(L"MFC001", 1, 3, hParent, TVI_LAST);
	m_tree.InsertItem(L"MFC002", 2, 3, hParent, TVI_LAST);
}


void CMy01ListTreeDlg::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	m_tree.Invalidate();
}


void CMy01ListTreeDlg::OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
	CPoint pt;
	GetCursorPos(&pt);
	// ��Ļ����ת�ͻ������� 
	m_tree.ScreenToClient(&pt);
	UINT uFlags = 0;
	//TVHT_ONITEMLABEL 
	HTREEITEM hTree  = m_tree.HitTest(pt, &uFlags);
	if (uFlags == TVHT_ONITEMLABEL || 
		uFlags == TVHT_ONITEMICON)
	{
		CString str = m_tree.GetItemText(hTree);
		MessageBox(str);
	}
	
}
