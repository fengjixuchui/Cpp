// 05.�����߳�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <TlHelp32.h>
bool EnumThreads(DWORD dwPID) {
	// 1. �ȴ�������
	HANDLE hTool32 = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, NULL);
	if (INVALID_HANDLE_VALUE == hTool32)
	{
		printf("����error!\n");
		return false;
	}
	// 2. ��ʼ��������
	THREADENTRY32 ti = { sizeof(THREADENTRY32) };
	BOOL bRet = Thread32First(hTool32, &ti);
	if (!bRet)
	{
		printf("Thread32First error!\n");
		return false;
	}
	printf("tID    pid:\n");
	do
	{
		if (ti.th32OwnerProcessID == dwPID)
		{
			printf("%6d   %6d\n", ti.th32ThreadID, ti.th32OwnerProcessID);
		}
	} while (Thread32Next(hTool32, &ti));
	return true;
}

int main()
{
	EnumThreads(7568);
	return 0;
}


