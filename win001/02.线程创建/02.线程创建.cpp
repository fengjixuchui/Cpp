// 02.�̴߳���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
int g_nNum = 0;

DWORD WINAPI ThreadProc(LPVOID lParam) {
	printf("�����̣߳�\n");
	for (int i=0;i<100000;i++)
	{
		g_nNum++;
	}
	printf("%d\n", g_nNum);
	return 0;
}

int main()
{

	CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);
	CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);

	system("pause");
	printf("%d\n", g_nNum);
    return 0;
}

