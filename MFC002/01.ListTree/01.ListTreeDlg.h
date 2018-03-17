
// 01.ListTreeDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxshelltreectrl.h"
#include "afxshelllistctrl.h"


// CMy01ListTreeDlg �Ի���
class CMy01ListTreeDlg : public CDialogEx
{
// ����
public:
	CMy01ListTreeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY01LISTTREE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	// ��ʼ��list
	void InitList();
	// ��ʼ��ͼ������
	CImageList m_img;
	void InitImgList();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	// ��ʼ�����ؼ�
	CTreeCtrl m_tree;
	void  InitTree();
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickTree1(NMHDR *pNMHDR, LRESULT *pResult);
	CMFCShellTreeCtrl m_mfcTree;
	CMFCShellListCtrl m_mfcList;
};
