#include <windows.h>
#include "resource.h"
#include <commctrl.h>
//#pragma comment(lib,"Comctl32.lib")
// 2013 ��Ҫ InitCommonControls();
INT_PTR CALLBACK DialogProc(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
	return 0;
}

INT_PTR CALLBACK DialogProc(
	_In_ HWND   hwndDlg,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
) {
	switch (uMsg)
	{
	case WM_COMMAND: {
		WORD wId = LOWORD(wParam);
		WORD wCode = HIWORD(wParam);
		HANDLE hChild = (HANDLE)lParam;
		if (wId == IDC_BUTTON1 && wCode == BN_CLICKED)
		{
			// ����������ʾ�ı�
			//SetWindowText(GetDlgItem(hwndDlg, IDC_EDIT1), L"1234");
			// ��Ϊ�ӿؼ���ʾ�ı�����
			//SetDlgItemText(hwndDlg, IDC_EDIT1, L"asdbvfvd");
			// ��ȡ��ѡ���״̬
			for (int i = 0; i < 3; i++)
			{
				int nRet = SendMessage(GetDlgItem(hwndDlg, IDC_RADIO1 + i), BM_GETCHECK, 0, 0);
				if (nRet == BST_CHECKED)
				{
					TCHAR tSex[3] = {};
					GetDlgItemText(hwndDlg, IDC_RADIO1 + i, tSex, 3);
					SetDlgItemText(hwndDlg, IDC_EDIT1, tSex);
					break;
					//MessageBox(0, 0, 0, 0);
				}
			}
			// ��ȡ��ѡ���״̬
			int nRet = SendDlgItemMessage(hwndDlg, IDC_CHECK1, BM_GETSTATE, 0, 0);
			const TCHAR *p[3] = { L"����:\r\n��" ,L"����:\r\n��" ,L"����:\r\nδ֪" };

			SetDlgItemText(hwndDlg, IDC_EDIT1, p[nRet]);
		}
		else if (wId == IDC_BUTTON2 && wCode == BN_CLICKED)
		{// �л�ͼƬ
			// 1. ��̬���ͼƬ�����picture control
			// ����ͼƬ���� typeΪbitmap
			// ���BMPͼƬ��Դ
			// ѡ��picture control��image����Ϊ��ӵ�ͼƬ��ԴID
			// 2. ��̬���ͼƬ
			/*static BOOL b = FALSE;
			HBITMAP hBmp = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(b?IDB_BITMAP2: IDB_BITMAP1));
			b = !b;
			SendDlgItemMessage(hwndDlg, IDC_STATIC1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBmp);*/
			SetTimer(hwndDlg,
				123,// ��ʱ��ID
				300,//���ٺ��봥��һ��
				NULL);
		}
		else if (wId == IDC_BUTTON3 && wCode == BN_CLICKED)
		{
			//ListView_SetExtendedListViewStyleEx()
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_SETEXTENDEDLISTVIEWSTYLE,
				0, LVS_EX_CHECKBOXES|LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
			// 1. ����б���
			//ListView_InsertColumn()
			LVCOLUMN lvc = {};
			lvc.pszText = (WCHAR*)L"��1��";
			lvc.cchTextMax = 3;
			lvc.cx = 80;
			lvc.mask = LVCF_TEXT| LVCF_WIDTH;
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_INSERTCOLUMN, 0, (LPARAM)&lvc);
			lvc.pszText = (WCHAR*)L"��2��";
			lvc.cchTextMax = 3;
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_INSERTCOLUMN, 1, (LPARAM)&lvc);
			// 2. ����б���
			LVITEM lvi = {};
			lvi.pszText = (WCHAR*)L"��1��";
			lvi.cchTextMax = 3;
			lvi.iItem = 0;// �ڼ���
			lvi.iSubItem = 0;//�ڼ���
			lvi.mask = LVIF_TEXT;
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_INSERTITEM,0, (LPARAM)&lvi);
			lvi.pszText = (WCHAR*)L"��2��";
			lvi.iItem = 1;
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_INSERTITEM, 0, (LPARAM)&lvi);
			// 3. �������
			lvi.pszText = (WCHAR*)L"����";
			lvi.iSubItem = 1;
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_SETITEMTEXT, 0, (LPARAM)&lvi);
			lvi.pszText = (WCHAR*)L"����";
			lvi.iItem = 1;
			lvi.iSubItem = 1;
			SendDlgItemMessage(hwndDlg, IDC_LIST1, LVM_SETITEM, 0, (LPARAM)&lvi);

		}
		break;
	}
	case WM_TIMER: {
		if (wParam == 123)
		{
			static BOOL b = FALSE;
			HBITMAP hBmp = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(b ? IDB_BITMAP2 : IDB_BITMAP1));
			b = !b;
			
			SendDlgItemMessage(hwndDlg, IDC_STATIC1, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBmp);
		}
		break;
	}
	case WM_HSCROLL: {
		if (LOWORD(wParam) == SB_THUMBTRACK)
		{
			WORD wPos = HIWORD(wParam);
			SendDlgItemMessage(hwndDlg, IDC_PROGRESS1, PBM_SETPOS, wPos, 0);
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