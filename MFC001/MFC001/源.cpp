// 0. �ı���Ŀ���ԣ�����Ϊʹ��MFC��
// 1. ����MFC��ͷ�ļ�
#include <afxwin.h>
#include "MyDlg.h"// �Ի�����Դ��������
// 2. ����һ���̳���CWinApp����
class CMyApp :public CWinApp {
	// 3. ��д������麯��InitInstance
	BOOL InitInstance()override {
		// 4. �������ڣ��Ѵ���ָ�븳ֵ������ĳ�Ա����m_pMainWnd
		// ������ͨ����
	/*	CFrameWnd *p = new CFrameWnd;
		p->Create(NULL, L"�ҵĵ�һ��MFC���ڣ�");
		p->ShowWindow(SW_SHOW);
		m_pMainWnd = p;*/

		// ͨ����Դ�����Ի���
		// a. ��ӶԻ�����Դ���Ի������Ҽ������
		// b. �����.h�ļ������ͷ�ļ�����
		//#include "resource.h"
		//#include <afxdialogex.h>
		// C. ��ǰcpp����#include "MyDlg.h"
		// d. �����Զ�����Դ�Ի���
		CMyDlg *p = new CMyDlg;
		m_pMainWnd = p;
		// e. ��ģ̬
		//p->Create(IDD_DIALOG1, NULL);
		//p->ShowWindow(SW_SHOW);
		// f. ģ̬
		p->DoModal();
		return TRUE;
	}
};
// 5. ���������ȫ�ֱ���

CMyApp theApp;