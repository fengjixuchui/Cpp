// 03.���࿪.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>

int main()
{
	if (OpenMutex(SYNCHRONIZE, NULL, L"24��"))
	{
		// ˵����������ڣ��Ѿ��򿪹�һ�γ���
		return 0;
	}
	HANDLE hMutex = CreateMutex(NULL, NULL, L"24��");
	system("pause");
    return 0;
}

