#include <windows.h>

// ���������
LRESULT CALLBACK WindowProc(
	_In_ HWND   hwnd,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
);



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {
	// ��ע�ᴰ����
	WNDCLASS wcs = {};
	wcs.lpszClassName = L"24��";
	wcs.lpfnWndProc = WindowProc;
	wcs.hbrBackground = (HBRUSH)(COLOR_CAPTIONTEXT + 1);
	RegisterClass(&wcs);
	HWND hWnd = CreateWindow(L"24��", L"��2��", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		0, 0, 500, 500,
		NULL, NULL, hInstance, NULL);
	// ���ַ��  WS_OVERLAPPEDWINDOW  WS_POPUPWINDOW  WS_CHILDWINDOW
	CreateWindow(L"BUTTON", L"���ǰ�ť", WS_CHILD | WS_VISIBLE,
		10, 10,// �ڸ����ڵĿͻ�����λ�ã�
		100, 50,// �� ��
		hWnd,// ������
		(HMENU)0x1001,// ����Ƕ��㴰�� ���ǲ˵���� �Ӵ��ھ��Ǳ����ID
		hInstance, NULL);
	ShowWindow(hWnd, SW_SHOW);
	MSG msg = {};
	while (GetMessage(&msg,0,0,0))
	{
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WindowProc(
	_In_ HWND   hwnd,
	_In_ UINT   uMsg,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
) {
	switch (uMsg)
	{
	case WM_CREATE: {
		DWORD dwStyle = ES_LEFT | WS_CHILD | WS_OVERLAPPED | WS_VISIBLE;
		DWORD dwExStyle = WS_EX_CLIENTEDGE | WS_EX_LEFT | WS_EX_LTRREADING | WS_EX_RIGHTSCROLLBAR;
		
		HWND hWnd = ::CreateWindowEx(
			dwExStyle, //dwExStyle ��չ��ʽ
			L"Edit", //lpClassName ��������
			L"text", //lpWindowName ���ڱ���
			dwStyle, //dwStyle ������ʽ
			20, //x ���λ��
			20, //y ����λ��
			200, //nWidth ���
			20, //nHeight �߶�
			hwnd, //hWndParent �����ھ��
			(HMENU)0x1002, //ID
			GetModuleHandle(0), //hInstance Ӧ�ó�����
			NULL //lpParam ���Ӳ���
			);
		break;
	}
	case WM_CLOSE:
	{
		PostQuitMessage(0);
		break;
	}
	default:
		break;
	}
	// ����Ĭ�ϵĴ��ڴ������
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}