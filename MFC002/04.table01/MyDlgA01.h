#pragma once


// CMyDlgA01 �Ի���

class CMyDlgA01 : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlgA01)

public:
	CMyDlgA01(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyDlgA01();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
