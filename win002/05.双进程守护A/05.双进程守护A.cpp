// 05.˫�����ػ�A.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>

int main()
{
	HANDLE hEventA = CreateEvent(NULL, FALSE, TRUE, L"����A");
	HANDLE hEventB = NULL;
	printf("����A\n");
	while (true)
	{
		hEventB = OpenEvent(SYNCHRONIZE, NULL, L"����B");
		if (!hEventB)
		{
			STARTUPINFO si = {};
			PROCESS_INFORMATION pi = {};
			if (!CreateProcess(L"..\\Debug\\06.˫�����ػ�B.exe",
				NULL, NULL, NULL, NULL, CREATE_NEW_CONSOLE, NULL,
				NULL, &si, &pi))
				return 0;
			WaitForSingleObject(pi.hProcess, INFINITE);
			Sleep(100);
		}
		else
		{
			CloseHandle(hEventB);
			Sleep(200);
		}
	}
	return 0;
}

