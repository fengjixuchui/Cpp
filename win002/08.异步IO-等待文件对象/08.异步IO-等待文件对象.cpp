// 08.�첽IO-�ȴ��ļ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
typedef struct _MYOVERLAPPED{
	OVERLAPPED ol;
	HANDLE hFile;
	PBYTE pBuf;
	int nIndex;
}MYOVERLAPPED,*PMYOVERLAPPED;

DWORD WINAPI ThreadProc(LPVOID lParam) {
	PMYOVERLAPPED pol = (PMYOVERLAPPED)lParam;
	WaitForSingleObject(pol->hFile, INFINITE);
	for (int i=0;i<10;i++)
	{
		printf("%d:%02x \n", pol->nIndex,pol->pBuf[i]);
	}
	printf("�����ˣ�\n");
	return 0;
}

int main()
{
	// 1. �첽IO���
	// ���������� ���ļ��ͱ�Ϊ�ɵȴ����ں˶���
	// �����read write�����ͱ�Ϊ��������
	HANDLE hFile = CreateFile(L"..\\Debug\\123.exe", GENERIC_READ,
		FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL| FILE_FLAG_OVERLAPPED, NULL);
	// 2. �ļ���ȡ
	PMYOVERLAPPED pol = new MYOVERLAPPED{};
	pol->ol.Offset = 0x100;// ��ƫ��0x100���λ�ÿ�ʼ��
	// pol->hEvent == NULL; ϵͳ��ȡ��ɺ󣬻���ҵ�hFile��Ϊ���ź�״̬
	pol->hFile = hFile;
	pol->pBuf = new BYTE[0x1000]{};
	pol->nIndex =1;
	ReadFile(hFile,
		pol->pBuf,
		0x1000,
		NULL,//ʵ�ʶ�ȡ�ĸ�������OVERLAPPED�ṹ��ָ��
		(LPOVERLAPPED)pol);
	HANDLE hThread = CreateThread(NULL, NULL, ThreadProc, pol, NULL, NULL);
	
	
	PMYOVERLAPPED pol2 = new MYOVERLAPPED{};
	pol2->ol.Offset = 0x200;// ��ƫ��0x100���λ�ÿ�ʼ��
						   // pol->hEvent == NULL; ϵͳ��ȡ��ɺ󣬻���ҵ�hFile��Ϊ���ź�״̬
	pol2->hFile = hFile;
	pol2->pBuf = new BYTE[0x1000]{};
	pol2->nIndex = 2;
	ReadFile(hFile,
		pol2->pBuf,
		0x1000,
		NULL,//ʵ�ʶ�ȡ�ĸ�������OVERLAPPED�ṹ��ָ��
		(LPOVERLAPPED)pol2);
	HANDLE hThread2 = CreateThread(NULL, NULL, ThreadProc, pol2, NULL, NULL);

	
	
	// ......��������
	WaitForSingleObject(hThread, INFINITE);
	WaitForSingleObject(hThread2, INFINITE);
    return 0;
}

