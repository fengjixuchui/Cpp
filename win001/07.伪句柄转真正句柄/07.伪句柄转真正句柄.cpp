// 07.α���ת�������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>

DWORD WINAPI ChildThread(PVOID pParam) {
	HANDLE hThreadParent = (HANDLE)pParam;
	FILETIME stcCreationTime, stcExitTime;
	FILETIME stcKernelTime, stcUserTime;
	GetThreadTimes(hThreadParent, &stcCreationTime,
		&stcExitTime, &stcKernelTime, &stcUserTime);
	return 0;
}

DWORD WINAPI ShowParentTime() {
	HANDLE hThreadParent = GetCurrentThread();
	// ��α���ת���������ľ��ֵ
	HANDLE hTranslate = 0;
	DuplicateHandle(
		GetCurrentProcess(),//��Ҫת���ľ��ֵ���ڵĽ��̾��
		hThreadParent,// ��Ҫת���ĸ����
		GetCurrentProcess(),// ��Ҫת���ľ�����ĸ�����
		&hTranslate,
		DUPLICATE_SAME_ACCESS,// һ����Ȩ��
		NULL,
		DUPLICATE_SAME_ACCESS);
	CreateThread(NULL, 0, ChildThread,
		(PVOID)hTranslate, 0, NULL);
	return 0;
}

int main()
{
	FILETIME stcCreationTime, stcExitTime;
	FILETIME stcKernelTime, stcUserTime;
	GetThreadTimes(GetCurrentThread(), &stcCreationTime,
		&stcExitTime, &stcKernelTime, &stcUserTime);
	ShowParentTime();
	system("pause");
    return 0;
}

