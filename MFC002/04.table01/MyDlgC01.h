#pragma once


// CMyDlgC01 �Ի���

class CMyDlgC01 : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlgC01)

public:
	CMyDlgC01(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMyDlgC01();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
