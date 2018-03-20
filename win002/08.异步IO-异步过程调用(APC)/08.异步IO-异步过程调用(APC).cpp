// 08.�첽IO-�첽���̵���(APC).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
typedef struct _MYOVERLAPPED {
	OVERLAPPED ol;
	HANDLE hFile;
	PBYTE pBuf;
	int nIndex;
}MYOVERLAPPED, *PMYOVERLAPPED;


// �ύ������̴߳��������߳̿���
VOID CALLBACK FileIOCompletionRoutine(
	_In_    DWORD        dwErrorCode,
	_In_    DWORD        dwNumberOfBytesTransfered,
	_Inout_ LPOVERLAPPED lpOverlapped
) {
	PMYOVERLAPPED pol = (PMYOVERLAPPED)lpOverlapped;
	for (int i = 0; i < 10; i++)
	{
		printf("%d:%02x \n", pol->nIndex, pol->pBuf[i]);
	}
	printf("�����ˣ�\n");
}


int main()
{
	// 1. �첽IO���
	// ���������� ���ļ��ͱ�Ϊ�ɵȴ����ں˶���
	// �����read write�����ͱ�Ϊ��������
	HANDLE hFile = CreateFile(L"..\\Debug\\123.exe", GENERIC_READ,
		FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, NULL);
	// 2. �ļ���ȡ
	PMYOVERLAPPED pol = new MYOVERLAPPED{};
	pol->ol.Offset = 0x100;// ��ƫ��0x100���λ�ÿ�ʼ��
	// hEvent������   hFileҲ������
	//pol->ol.hEvent = CreateEvent(NULL, NULL, FALSE, NULL); //ϵͳ��ȡ��ɺ󣬻���ҵ�hFile��Ϊ���ź�״̬
	pol->hFile = hFile;// ������
	pol->pBuf = new BYTE[0x1000]{};
	pol->nIndex = 1;
	ReadFileEx(hFile,
		pol->pBuf,
		0x1000,
		(LPOVERLAPPED)pol,
		FileIOCompletionRoutine);// ��ɺ�ֱ�ӵ��øûص����������õȴ��ļ����/�¼�����

	PMYOVERLAPPED pol2 = new MYOVERLAPPED{};
	pol2->ol.Offset = 0x200;// ��ƫ��0x100���λ�ÿ�ʼ��
	//pol2->ol.hEvent = CreateEvent(NULL, NULL, FALSE, NULL); //ϵͳ��ȡ��ɺ󣬻���ҵ�hFile��Ϊ���ź�״̬
	//pol2->hFile = hFile;// ������
	pol2->pBuf = new BYTE[0x1000]{};
	pol2->nIndex = 2;
	ReadFileEx(hFile,
		pol2->pBuf,
		0x1000,
		(LPOVERLAPPED)pol2,
		FileIOCompletionRoutine);
	// FileIOCompletionRoutine��ϵͳ����
	// �ĸ��߳�ִ�иú�����
	// �ĸ��߳�read/write �ĸ��߳�ִ��
	// ......��������

	// æ����  ��������������������������
	// CPU��⵽��ǰ�̵߳�APC�������к�����Ҫִ��
	// ��ȥִ�иú�����ִ���귵��
	// ֻ�е���2��������TRUE��ȥִ��
	SleepEx(200, TRUE);
//	WaitForSingleObjectEx()
	return 0;
}
