
// 02.MFC��ĿDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CMy02MFC��ĿDlg �Ի���
class CMy02MFC��ĿDlg : public CDialogEx
{
// ����
public:
	CMy02MFC��ĿDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY02MFC_DIALOG };
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
	CString m_str;
	afx_msg void OnBnClickedButton1();
	CString m_str2;
	CEdit m_edit;
	afx_msg void ��ť2�������();
	afx_msg void �Զ��尴ť3�������();
	CButton m_btn;
};
