#pragma once


// CMyDlgB �Ի���

class CMyDlgB : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlgB)

public:
	CMyDlgB(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyDlgB();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
