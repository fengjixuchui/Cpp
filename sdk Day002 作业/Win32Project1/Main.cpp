#include <windows.h>
#include"resource.h"
#include<CommCtrl.h>
INT_PTR CALLBACK DialogProc2(
	_In_  HWND hwndDlg,
	_In_  UINT uMsg,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam
)
{

	switch (uMsg)
	{
	case WM_CLOSE:
	{
		EndDialog(hwndDlg, 0);
		return 0;
	}
	case WM_INITDIALOG:
	{
		
		HWND HIDC_LIST1 = GetDlgItem(hwndDlg, IDC_LIST1);
		RECT rt = {};
		GetClientRect(HIDC_LIST1, &rt);
		LV_COLUMN lc;
		lc.mask = LVCF_WIDTH | LVCF_TEXT| LVCF_FMT;
		lc.fmt = LVCFMT_CENTER;
		lc.cx = (rt.right - rt.left) / 4;
		lc.pszText = L"����";
		ListView_InsertColumn(HIDC_LIST1, 0, &lc);//ͨ���귢��Ϣ...LVM_INSERT
		lc.pszText = L"����";
		ListView_InsertColumn(HIDC_LIST1, 1, &lc);
		lc.pszText = L"����";
		ListView_InsertColumn(HIDC_LIST1, 2, &lc);
		lc.pszText = L"����";
		ListView_InsertColumn(HIDC_LIST1, 3, &lc);
		LV_ITEM li = {};
		ListView_SetExtendedListViewStyle(HIDC_LIST1, LVS_EX_FULLROWSELECT | LVS_EX_CHECKBOXES);
		for (int i = 0; i < 10; i++)
		{
			li.iItem = i;
			ListView_InsertItem(HIDC_LIST1, &li);
			ListView_SetItemText(HIDC_LIST1, i, 0, L"����");
			ListView_SetItemText(HIDC_LIST1, i, 1, L"12");
			ListView_SetItemText(HIDC_LIST1, i, 2, L"����");
			ListView_SetItemText(HIDC_LIST1, i, 3,L"1");

		}
		//List ��ȡ����ֵ

	}break;
	case WM_NOTIFY: //��ȡ����ֵ
	{
		//LPNMITEMACTIVATE
		LPNMLISTVIEW temp = (LPNMLISTVIEW)lParam; //WM_NOTIFY ����Ϣ�ṹ ���listView ��True  �ؼ�
		if (temp->hdr.code == NM_CLICK&&temp->hdr.idFrom == IDC_LIST1)
		{
			TCHAR str[100] = {};
			ListView_GetItemText(temp->hdr.hwndFrom, temp->iItem, temp->iSubItem, str, 100);
		   bool num=	ListView_GetCheckState(temp->hdr.hwndFrom,1);
			MessageBox(0, str, 0, 0);
		}
	}
	default:break;
	}
	return 0;
}



INT_PTR CALLBACK DialogProc1(
	_In_  HWND hwndDlg,
	_In_  UINT uMsg,
	_In_  WPARAM wParam,
	_In_  LPARAM lParam
)
{
	switch (uMsg)
	{
	case WM_LBUTTONDOWN:
	{
	//	MessageBox(0,L"1",0,0);
	}break;
	case WM_CLOSE:
	{
		EndDialog(hwndDlg, 0);
		exit(0);
		return 0;
	}
	case WM_INITDIALOG:
	{
		
		//HWND hPicture = CreateWindow(
		//	TEXT("static"),
		//	TEXT(""),
		//	WS_VISIBLE | WS_CHILD | SS_BITMAP | SS_CENTERIMAGE,
		//	7, 10, 420, 260,
		//	hwndDlg,
		//	NULL,
		//	GetModuleHandleW(0), 0);
		//
		//HBITMAP hBmp = LoadBitmap(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP2));
		//SendMessage(hPicture, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBmp);


		wchar_t  str[] = L"����";
		wchar_t  str1[] = L"�Ϻ�";
		wchar_t  str2[] = L"����";

		wchar_t  ComStr[100];
		wchar_t  ComStr1[100];
		HWND HIDC_COMBO1 = GetDlgItem(hwndDlg, IDC_COMBO1);
		LRESULT ret = NULL;
		ret = SendMessage(HIDC_COMBO1, CB_ADDSTRING, NULL, (LPARAM)str);
		ret = SendMessage(HIDC_COMBO1, CB_ADDSTRING, NULL, (LPARAM)str1);
		ret = SendMessage(HIDC_COMBO1, CB_ADDSTRING, NULL, (LPARAM)str2);
		ret = SendMessage(HIDC_COMBO1, CB_SETCURSEL, NULL, (LPARAM)str1);


		HWND HIDC_RADIO1 = GetDlgItem(hwndDlg, IDC_RADIO1);
		SendMessage(HIDC_RADIO1, BM_SETCHECK, BST_CHECKED, 0);


		wchar_t  STem[100] = {};
		wchar_t  STem1[100] = {};
		HWND HIDC_EDIT1 = GetDlgItem(hwndDlg, IDC_EDIT1);
		SetWindowText(HIDC_EDIT1, L"username"); //��������
		HWND HIDC_EDIT2 = GetDlgItem(hwndDlg, IDC_EDIT2);
		SetWindowText(HIDC_EDIT2, L"password"); //��������

	}break;
	case WM_COMMAND:
	{

		if (LOWORD(wParam) == IDC_BUTTON1)
		{
			HWND hdiag = CreateDialog(GetModuleHandleW(0), MAKEINTRESOURCE(IDD_DIALOG2), 0, DialogProc2);
			ShowWindow(hdiag, 1);
			MSG msg = {};
			// �Խ���Ϣѭ����Ҫ�յ�WM_QUIT��Ϣ�Ż��˳�ѭ��
			while (GetMessage(&msg, NULL, NULL, NULL))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg); //�ַ���Ϣ
			}
			return 0;
		}

	}break;

	default:break;
	}
	return 0;
}


int CALLBACK WinMain(
	_In_  HINSTANCE hInstance,
	_In_  HINSTANCE hPrevInstance,
	_In_  LPSTR lpCmdLine,
	_In_  int nCmdShow
)
{

	DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc1);

	return 0;
}

