#pragma once


// CMyDlgNew �Ի���

class CMyDlgNew : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlgNew)

public:
	CMyDlgNew(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyDlgNew();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	afx_msg void OnBnClickedButton1();
};
