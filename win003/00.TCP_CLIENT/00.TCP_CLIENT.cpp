// 00.TCP_CLIENT.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
// 1. ����ͷ�ļ�����  Ҫд������ͷ�ļ�(����windows.h)֮ǰ
#include <WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")
DWORD WINAPI RecvThread(LPVOID lParam) {
	SOCKET sClient = (SOCKET)lParam;
	while (true)
	{
		char buf[1024] = {};
		int nRet = recv(sClient, buf, 1024, NULL);
		if (nRet == SOCKET_ERROR) {
			printf("�������ر�\n");
			exit(0);
			return 0; 
		}
		printf("%s\n", buf);
	}
	return 0;
}
int main()
{	// 1. �źż��
	WSADATA wsd = {};
	WSAStartup(MAKEWORD(2, 2), &wsd);
	if (LOBYTE(wsd.wVersion) != 2 ||
		HIBYTE(wsd.wVersion) != 2)
	{
		printf("��汾��֧��\n");
		return 0;
	}
	// 2. ���ֻ�
	SOCKET sClient = socket(
		AF_INET,// IP4Э��
		SOCK_STREAM,// ��ʽ�׽���
		IPPROTO_TCP);// Э������(TCP)
	if (sClient == INVALID_SOCKET)
	{
		printf("����socketʧ�ܣ�\n");
		WSACleanup();
		return 0;
	}
	// 3. �쿨
	SOCKADDR_IN addrSer = {};
	addrSer.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrSer.sin_port = htons(0x1234);// host to net short
	addrSer.sin_family = AF_INET;
	int nLen = sizeof(SOCKADDR_IN);
	// ��+ͨѶ  ֱ�Ӻͷ�����ͨѶ���Զ���
	int nRet = connect(sClient, (SOCKADDR*)&addrSer, nLen);
	if (nRet == SOCKET_ERROR) { /*������ �ر��׽���*/return 0; }
	CreateThread(NULL, NULL, RecvThread, (LPVOID)sClient, NULL, NULL);
	while (true)
	{
		char buf[1024] = {};
		scanf_s("%s", buf, 1024);
		nRet = send(sClient, buf, 1024, NULL);
		if (nRet == SOCKET_ERROR)
		{
			closesocket(sClient);
			WSACleanup();
			return 0;
		}
	}
    return 0;
}

