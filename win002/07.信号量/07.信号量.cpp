// 07.�ź���.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <windows.h>
HANDLE hSemphore;
int g_nNum = 0;
DWORD WINAPI ThreadProc(LPVOID lParam) {
		WaitForSingleObject(hSemphore, INFINITE);
	for (int i = 0; i < 100000; i++)
	{
		g_nNum++;
	}
	printf("%d\n", g_nNum);
	ReleaseSemaphore(hSemphore,
		1,// �ͷŵ��źŸ������Դ���1�������ͷź���źŸ���+֮ǰ�Ĳ��ܴ������ֵ�������ͷ�ʧ��
		NULL);
	return 0;
}

int main()
{
	 hSemphore = CreateSemaphore(
		NULL,
		1,// ��ʼ�źŸ���
		1,// ����źŸ�������������ͬʱ���ʱ�����Դ���߳���
		NULL);
	HANDLE hThread1 = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
	HANDLE hThread2 = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
	printf("%d\n", g_nNum);
	return 0;
}


