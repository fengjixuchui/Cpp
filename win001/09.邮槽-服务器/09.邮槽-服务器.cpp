// 09.�ʲ�-������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>

int main()
{
	HANDLE hMailSlot = CreateMailslot(
		L"\\\\.\\mailslot\\sample",// �ʲ���
		0,// �������Ϣ����
		MAILSLOT_WAIT_FOREVER,// ������ʱ
		NULL
	);
	while (true)
	{
		DWORD dwCount = 0, dwSize = 0;
		GetMailslotInfo(
			hMailSlot,// �ʲ���
			NULL,// �������Ϣ����
			&dwSize,// ��һ����Ϣ��С
			&dwCount,// ��Ϣ����
			NULL);// ������ʱ
		if (dwSize == MAILSLOT_NO_MESSAGE)
		{
			Sleep(200);// ��ʱû����Ϣ
			continue;
		}
		while (dwCount)
		{
			PBYTE pBuf = new BYTE[dwSize+10]{};
			ReadFile(hMailSlot, pBuf, dwSize, &dwSize, NULL);
			printf("%s\n", pBuf);
			GetMailslotInfo(hMailSlot, 0, &dwSize, &dwCount, NULL);
			delete[] pBuf;
		}
	}
    return 0;
}

