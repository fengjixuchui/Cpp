
// MFCApplication2Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "ccmymodo.h"

// CMFCApplication2Dlg �Ի���
class CMFCApplication2Dlg : public CDialogEx
{
// ����
public:
	CMFCApplication2Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION2_DIALOG };
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
	CRect rc;
	int nwidth;
	bool EnumProcess();
	CListCtrl cclistctrl;
	ccmymodo* ccmymodo1;
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
};
