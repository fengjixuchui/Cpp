
// 01.TCP_SER_MSGDlg.h : ͷ�ļ�
//

#pragma once
#include "MyTCP.h"


// CMy01TCP_SER_MSGDlg �Ի���
class CMy01TCP_SER_MSGDlg : public CDialogEx
{
// ����
public:
	CMy01TCP_SER_MSGDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY01TCP_SER_MSG_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CMyTCP m_tcp;
	afx_msg void OnBnClickedButton1();
protected:
	afx_msg LRESULT OnMysocket(WPARAM wParam, LPARAM lParam);
public:
	CString m_edit;
};
