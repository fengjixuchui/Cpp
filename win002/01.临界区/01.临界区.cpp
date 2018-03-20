// win002.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>

CRITICAL_SECTION cs = {};

int g_nNum = 0;
DWORD WINAPI ThreadProc(LPVOID lParam) {
	// 2. �����ٽ���
	// cs�и�����LockSemaphore�ǲ��Ǳ�����
	// ������EnterCriticalSection��ʾ�ٽ�����������OwningThread���Ǹ��߳�
	// ��������EnterCriticalSection�����������ʱ���߳��Ƿ���ͬһ���߳�
	// ������ǣ�����Enter���߳̾�����
	// ����ǣ��Ͱ���������LockCount+1
	// �м���Enter�͵��м���Leave
	// ���ǣ�����ӵ�����̵߳��˲�������Leave
	EnterCriticalSection(&cs);
	for (int i = 0; i < 100000; i++)
	{
		g_nNum++;
	}
	printf("%d\n", g_nNum);
	// 3. �뿪�ٽ���
	// ��һ����û�е���Leave�����߳̾ͱ����ˣ�����ѭ����..
	// ����ȴ����˾���Զ�ȴ�
	// �ٽ��������ں˶��� ���ܿ����ͬ��
	LeaveCriticalSection(&cs);
	return 0;
}

int main()
{
	// 1. ��ʼ���ٽ���
	InitializeCriticalSection(&cs);
	HANDLE hThread1 = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
	HANDLE hThread2 = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
	printf("%d\n", g_nNum);
	// 4. �����ٽ���
	DeleteCriticalSection(&cs);
	return 0;
}

