#pragma once


// CMyDlgC �Ի���

class CMyDlgC : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlgC)

public:
	CMyDlgC(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyDlgC();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
