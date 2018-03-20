// 08.�첽���̵���-��ɶ˿�(IOCP).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
typedef struct _MYOVERLAPPED {
	OVERLAPPED ol;
	HANDLE hFile;
	PBYTE pBuf;
	int nIndex;
}MYOVERLAPPED, *PMYOVERLAPPED;

DWORD WINAPI ThreadProc(LPVOID lParam) {
	PMYOVERLAPPED pol =nullptr;
	HANDLE hIOCP = lParam;
	while (TRUE)
	{
		DWORD dwNum = 0;
		ULONG_PTR uCompleteKey = 0;
		BOOL bRet = GetQueuedCompletionStatus(
			hIOCP,// �����ɶ˿���û�д���������(��������ɣ�֪ͨ��ɶ˿ڴ���)
			&dwNum,// ʵ�ʴ�����ֽ���
			&uCompleteKey,// �ĸ��豸������첽����
			(LPOVERLAPPED*)&pol,
			INFINITE);
		if (bRet == FALSE && ERROR_ABANDONED_WAIT_0 == GetLastError())
		{
			printf("��ɶ˿ڱ��ر�\n");
			return 0;
		}
		if (uCompleteKey == NULL && pol == nullptr)
		{
			PostQueuedCompletionStatus(hIOCP, NULL, NULL, NULL);
			printf("��ɶ˿��߳̽���!\n");
			return 0;
		}
		for (int i = 0; i < 10; i++)
		{
			
			printf("key:%d,%d:%02x \n", uCompleteKey,pol->nIndex, pol->pBuf[i]);
		}
		printf("�����ˣ�\n");
	}
	return 0;
}

int main()
{
	// 1. �첽IO���
	// ���������� ���ļ��ͱ�Ϊ�ɵȴ����ں˶���
	// �����read write�����ͱ�Ϊ��������
	HANDLE hFile = CreateFile(L"..\\Debug\\123.exe", GENERIC_READ,
		FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);
	
	// 2. ����һ����ɶ˿�
	// �Ȼ�ȡ������
	SYSTEM_INFO si = {};
	GetSystemInfo(&si);
	HANDLE hIOCP = CreateIoCompletionPort(
		INVALID_HANDLE_VALUE,// ������ɶ˿�,����ɶ˿ڵ�ʱ�����ļ����
		NULL,// ������ɶ˿ڵ�ʱ����NULL,�󶨵�ʱ������ɶ˿ھ��
		NULL,// ������ɶ˿ڵ�ʱ����NULL,�󶨵�ʱ�����Լ����õ�һ��ֵ���������ְ󶨵��ļ����ĸ�
		si.dwNumberOfProcessors);// ��ɶ˿��ϲ������е�����߳������󶨵�ʱ����NULL
	// 3.����ɶ˿ں��ļ��󶨣���������ļ��������첽������֪ͨ��������ɶ˿�
	CreateIoCompletionPort(
		hFile,
		hIOCP,
		0x12,// ��hFile�󶨵�ֵ��Ҳ������hFile����
		NULL
	);
	// 4. ������ɶ˿ڵķ����߳�
	for (int i=0;i<si.dwNumberOfProcessors*2;i++)
	{
		CreateThread(NULL, NULL, ThreadProc, hIOCP, NULL, NULL);
	}
	
	// 5. �ļ���ȡ
	PMYOVERLAPPED pol = new MYOVERLAPPED{};
	pol->ol.Offset = 0x100;// ��ƫ��0x100���λ�ÿ�ʼ��
	pol->pBuf = new BYTE[0x1000]{};
	pol->nIndex = 1;
	ReadFile(hFile,
		pol->pBuf,
		0x1000,
		NULL,//ʵ�ʶ�ȡ�ĸ�������OVERLAPPED�ṹ��ָ��
		(LPOVERLAPPED)pol);


	PMYOVERLAPPED pol2 = new MYOVERLAPPED{};
	pol2->ol.Offset = 0x200;// ��ƫ��0x100���λ�ÿ�ʼ��
	pol2->pBuf = new BYTE[0x1000]{};
	pol2->nIndex = 2;
	ReadFile(hFile,
		pol2->pBuf,
		0x1000,
		NULL,//ʵ�ʶ�ȡ�ĸ�������OVERLAPPED�ṹ��ָ��
		(LPOVERLAPPED)pol2);
	// ......��������
	// Ͷ��һ���������
	PostQueuedCompletionStatus(hIOCP, NULL, NULL, NULL);
	system("pause");
	return 0;
}


