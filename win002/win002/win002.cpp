// win002.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>

int g_nNum = 0;
DWORD WINAPI ThreadProc(LPVOID lParam) {
	for (int i=0;i<100000;i++)
	{
		// �������ڱ���һ�δ��룬��Ҫ�������ڴ����4�ֽ�
		InterlockedIncrement((ULONG*)&g_nNum);
	}
	printf("%d\n", g_nNum);
	return 0;
}

int main()
{
	HANDLE hThread1 = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
	HANDLE hThread2 = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
	printf("%d\n", g_nNum);
    return 0;
}

