// 04.��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <TlHelp32.h>
bool EnumProcess() {
	// 1. �ȴ�������
	HANDLE hTool32 = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (INVALID_HANDLE_VALUE == hTool32)
	{
		printf("����error!\n");
		return false;
	}
	// 2. ��ʼ��������
	PROCESSENTRY32W psi = { sizeof(PROCESSENTRY32W) };
	BOOL bRet = Process32FirstW(hTool32, &psi);
	if (!bRet)
	{
		printf("Process32FirstW error!\n");
		return false;
	}
	printf("PID    EXE:\n");
	do
	{
		printf("%4d   %S\n", psi.th32ProcessID, psi.szExeFile);
	} while (Process32NextW(hTool32, &psi));
	return true;
}


int main()
{
	EnumProcess();
	return 0;
}

