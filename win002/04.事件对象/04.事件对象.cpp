// 04.�¼�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
HANDLE hEvent1, hEvent2;
DWORD WINAPI ThreadProcA(LPVOID lParam) {
	for (int i = 0; i < 10; i++){
		WaitForSingleObject(hEvent1, INFINITE);
		printf("A ");
		SetEvent(hEvent2);
	}
	return 0;
}

DWORD WINAPI ThreadProcB(LPVOID lParam) {
	for (int i = 0; i < 10; i++){
		WaitForSingleObject(hEvent2, INFINITE);
		printf("B ");
		SetEvent(hEvent1);
	}
	return 0;
}

int main()
{
	// �¼����󣬸߶��Զ����
	 hEvent1 = CreateEvent(
		NULL,
		FALSE,// �Զ�����
		TRUE,// ���ź�
		NULL);
	// hEvent1�Զ�����  ��ʼ���ź�  �κ���ͨ��setevent��Ϊ���ź� resetevent��Ϊ���ź�
	// hEvent2�Զ�����  ��ʼ���ź�
	 hEvent2 = CreateEvent(NULL, FALSE, FALSE, NULL);
	HANDLE hThread1 = CreateThread(NULL, NULL, ThreadProcA, NULL, NULL, NULL);
	HANDLE hThread2 = CreateThread(NULL, NULL, ThreadProcB, NULL, NULL, NULL);
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
	return 0;
}

