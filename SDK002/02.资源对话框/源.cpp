#include <windows.h>
#include "resource.h"
INT_PTR CALLBACK DialogProc(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	// ģ̬�Ի���  �ͷ�ģ̬�Ի���
	// �ڲ��Դ�ѭ�� �����������ľ���ģ̬
	// ������Ƿ�ģ̬�Ի���
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
	//MessageBox(0, 0, 0, 0);
	//	HWND hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
//	while (...)
//	{
//...��Ϣѭ��
//	}
	return 0;
}

INT_PTR CALLBACK DialogProc(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
) {
	// �ʹ��ڻص�������һ�� 
	// 1. ����ֵ��һ��
	// 2. ������ʽ��һ�� һ����postquitmessage   һ����EndDialog
	// 3. ��ʼ����Ϣ��ͬWM_CREATE WM_INITDIALOG
	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		break;
	}
	case WM_COMMAND: {
		WORD wId = LOWORD(wParam);
		WORD wCode = HIWORD(wParam);
		HANDLE hChild = (HANDLE)lParam;
		if (wId == IDC_BUTTON1 && wCode == BN_CLICKED)
		{
			// �ƶ�������
			MoveWindow(hwndDlg, 500, 500, 1000, 1000, true);
			// �ƶ���������  ��ǰ����
			// �õ��ӿؼ��ľ��
			HWND hwnd = GetDlgItem(hwndDlg, IDC_BUTTON2);
			MoveWindow(hwnd, 20,20, 500, 100, true);
			// �ƶ��������� ��������
			MoveWindow((HWND)(0x0B08C4), 20, 20, 500, 100, true);
		}
		break;
	}
	case WM_CLOSE:
	{
		EndDialog(hwndDlg, 0);
		break;
	}
	default:
		break;
	}
	return 0;
}