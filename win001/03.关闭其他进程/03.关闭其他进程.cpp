// 03.�ر���������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>

bool KillProcess(DWORD dwPid) {
	// �򿪽���
	HANDLE hProcess = OpenProcess(PROCESS_TERMINATE,NULL,dwPid);
	if (!hProcess)
	{
		return false;
	}
	TerminateProcess(hProcess, 0);
	CloseHandle(hProcess);
	return true;
}

int main()
{
	KillProcess(4484);
	//exit(0);
    return 0;
}

