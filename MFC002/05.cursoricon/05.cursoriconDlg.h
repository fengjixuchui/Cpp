
// 05.cursoriconDlg.h : ͷ�ļ�
//

#pragma once


// CMy05cursoriconDlg �Ի���
class CMy05cursoriconDlg : public CDialogEx
{
// ����
public:
	CMy05cursoriconDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MY05CURSORICON_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	CToolBar m_toolbar1;
	CToolBar m_toolbar2;
	afx_msg void On������1��();
	afx_msg void OnͼƬ��1��();
	CStatusBar m_status;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void On����();
	afx_msg void On��̬();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};
