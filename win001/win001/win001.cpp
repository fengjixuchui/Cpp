// win001.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<windows.h>

int main()
{
	STARTUPINFO si = {};
	PROCESS_INFORMATION pi = {};
	BOOL bRet = CreateProcess(
		L"123",
		NULL, NULL, NULL, FALSE, NULL, NULL, NULL,
		&si, &pi
	);
	if (bRet == FALSE)
	{
		printf("����ʧ�ܣ�\n");
	}
    return 0;
}

