// 06.˫�����ػ�B.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>

int main()
{
	HANDLE hEventB = CreateEvent(NULL, FALSE, TRUE, L"����B");
	HANDLE hEventA = NULL;
	printf("����B\n");
	while (true)
	{
		hEventA = OpenEvent(SYNCHRONIZE, NULL, L"����A");
		if (!hEventA)
		{
			STARTUPINFO si = {};
			PROCESS_INFORMATION pi = {};
			if (!CreateProcess(L"..\\Debug\\05.˫�����ػ�A.exe",
				NULL, NULL, NULL, NULL, CREATE_NEW_CONSOLE, NULL,
				NULL, &si, &pi))
				return 0;
			WaitForSingleObject(pi.hProcess, INFINITE);
			//Sleep(100);
		}
		else
		{
			CloseHandle(hEventA);
		}
	}
	return 0;
}

