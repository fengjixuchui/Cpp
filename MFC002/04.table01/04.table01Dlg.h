
// 04.table01Dlg.h : ͷ�ļ�
//

#pragma once
#include "MyTab01.h"


// CMy04table01Dlg �Ի���
class CMy04table01Dlg : public CDialogEx
{
// ����
public:
	CMy04table01Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY04TABLE01_DIALOG };
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
	CMyTab01 m_tab;
};
