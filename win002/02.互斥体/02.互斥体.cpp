// win002.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
HANDLE hMutex = 0;
int g_nNum = 0;
// �ٽ����ͻ�����Ƚ�
// 1. �������Ǹ��ں˶��󣬿��Կ����ͬ��,�ٽ�������
// 2. �����ǵ�ӵ�����̶߳�������ʱ�򣬻�������Ա�ϵͳ�ͷţ���Ϊ���źţ������ĵȴ�����������������
// �ٽ�������,������Ǽ���(��ѭ��������Ӧ)�����Ƕ�������
// 3. �ٽ��������ں˶������Է����ٶȱȻ������
DWORD WINAPI ThreadProc(LPVOID lParam) {
	// �ȴ�ĳ���ں˶������źžͷ��أ����źž�һֱ�ȴ�
	// ����ʱ�ѵȴ��Ķ����Ϊ���ź�״̬
	WaitForSingleObject(hMutex, INFINITE);
	for (int i = 0; i < 100000; i++)
	{
		g_nNum++;
	}
	printf("%d\n", g_nNum);
	// �ѻ������Ϊ���ź�״̬
	ReleaseMutex(hMutex);
	return 0;
}

int main()
{
	// 1. ����һ��������
	hMutex = CreateMutex(
		NULL,
		FALSE,// �Ƿ񴴽�ʱ�ͱ������߳�ӵ��
		NULL);// ����������
	HANDLE hThread1 = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
	HANDLE hThread2 = CreateThread(NULL, NULL, ThreadProc, NULL, NULL, NULL);
	WaitForSingleObject(hThread1, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
	printf("%d\n", g_nNum);
	return 0;
}

