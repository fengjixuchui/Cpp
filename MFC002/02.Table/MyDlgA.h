#pragma once


// CMyDlgA �Ի���

class CMyDlgA : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlgA)

public:
	CMyDlgA(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyDlgA();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
