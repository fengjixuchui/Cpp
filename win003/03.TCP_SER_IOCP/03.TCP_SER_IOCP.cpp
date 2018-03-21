// 03.TCP_SER_IOCP.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MyTCP.h"
#include <windows.h>
CMyTCP g_tcp;

typedef struct _MYOVERLAPPED
{
	OVERLAPPED ol;
	WSABUF wsa;
	char buf[1024];
}MYOVERLAPPED,*PMYOVERLAPPED;

DWORD WINAPI IOCP_Thread(LPVOID lParam) {
	HANDLE hIOCP = lParam;
	while (true)
	{
		DWORD dwTransfered = 0;// ������ֽ���
		DWORD dwCompleteKey = 0;// ��ɼ�
		PMYOVERLAPPED mol = 0;
		int nRet = GetQueuedCompletionStatus(
			hIOCP, &dwTransfered, &dwCompleteKey, (LPOVERLAPPED*)&mol, INFINITE);
		if (nRet == NULL && GetLastError() == ERROR_ABANDONED_WAIT_0)
		{
			printf("��ɶ˿ڱ��ر�\n");
			return 0;
		}
		if (nRet == NULL && dwCompleteKey)
		{
			g_tcp.TcpClientExit(dwCompleteKey);
			printf("�ͻ����˳�\n");
			continue;
		}
		// ����recv
		g_tcp.TcpRecv(dwCompleteKey, mol->buf, 1024);
		printf("%s\n", mol->buf);
		ZeroMemory(mol, sizeof(MYOVERLAPPED));
		mol->wsa.buf = mol->buf;
		mol->wsa.len = 1024;
		DWORD dwFlags = 0;
		WSARecv(
			dwCompleteKey,
			&mol->wsa,//��ȡ�����ݷ�����
			1,// α��С����recv����������ɶ˿�
			NULL,// ʵ�ʶ�ȡ�Ĵ�С����OVERLAPPED����Ҫ��
			&dwFlags,
			(LPOVERLAPPED)mol, NULL);
	}
	return 0;
}
int main()
{
	// 1 ׼������ɶ˿�
	SYSTEM_INFO si = {};
	GetSystemInfo(&si);
	HANDLE hIOCP = CreateIoCompletionPort(
		INVALID_HANDLE_VALUE, NULL, NULL, si.dwNumberOfProcessors);
	// 2. ��ɶ˿ڵķ����߳�
	for (int i = 0; i < si.dwNumberOfProcessors*2; i++)
	{
		CreateThread(
			NULL, NULL, IOCP_Thread, hIOCP, NULL, NULL);
	}
	// 3. ���豸(socket)
	g_tcp.InitServer();
	while (true)
	{
		SOCKET sClient = g_tcp.TcpAccept();
		if (sClient == INVALID_SOCKET) return 0;
		// �ѿͻ���socket����ɶ˿ڰ�
		CreateIoCompletionPort((HANDLE)sClient, hIOCP, sClient, NULL);
		PMYOVERLAPPED mol = new MYOVERLAPPED{};
		mol->wsa.buf = mol->buf;
		mol->wsa.len = 1024;
		DWORD dwFlags = 0;
		WSARecv(
			sClient,
			&mol->wsa,//��ȡ�����ݷ�����
			1,// α��С����recv����������ɶ˿�
			NULL,// ʵ�ʶ�ȡ�Ĵ�С����OVERLAPPED����Ҫ��
			&dwFlags,
			(LPOVERLAPPED)mol, NULL);
	}
    return 0;
}

