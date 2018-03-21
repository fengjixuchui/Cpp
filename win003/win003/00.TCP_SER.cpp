// win003.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
// 1. ����ͷ�ļ�����  Ҫд������ͷ�ļ�(����windows.h)֮ǰ
#include <WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")
#include <vector>
using std::vector;
vector<SOCKET> m_vecSocket;
/*
ÿһ���ͻ������ӽ�������Ҫ����һ���߳�
����ģ�ͣ�
��Ϣѡ��ģ��
�¼�ѡ��ģ��
��ɶ˿�ģ��
*/
DWORD WINAPI RecvThread(LPVOID lParam) {
	SOCKET sClient = (SOCKET)lParam;
	while (true)
	{
		char buf[1024] = {};
		int nRet = recv(sClient, buf, 1024, NULL);
		if (nRet == SOCKET_ERROR) {
			// �Ѹÿͻ��˴�������ɾ��
			for (int i=0;i<m_vecSocket.size();i++)
			{
				if (m_vecSocket[i] == sClient)
				{
					m_vecSocket.erase(m_vecSocket.begin() + i);
					printf("�ͻ����˳�\n");
					break;
				}
			}
			closesocket(sClient);
			return 0; 
		}
		printf("%s\n", buf);
		// ת���������Ŀͻ���
		for (auto &each:m_vecSocket)
		{
			if(each == sClient) continue;
			send(each, buf, 1024, NULL);
		}
	}
	return 0;
}

int main()
{
	// 1. �źż��
	WSADATA wsd = {};
	WSAStartup(MAKEWORD(2, 2), &wsd);
	if (LOBYTE(wsd.wVersion) != 2 ||
		HIBYTE(wsd.wVersion) != 2)
	{
		printf("��汾��֧��\n");
		return 0;
	}
	// 2. ���ֻ�
	SOCKET sSer = socket(
		AF_INET,// IP4Э��
		SOCK_STREAM,// ��ʽ�׽���
		IPPROTO_TCP);// Э������(TCP)
	if (sSer == INVALID_SOCKET)
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
	int nRet = bind(sSer, (SOCKADDR*)&addrSer, nLen);
	if (nRet == SOCKET_ERROR) {/*�ر��׽��֣�������*/return 0; }
	// 4. ����
	nRet = listen(sSer, SOMAXCONN);
	if (nRet == SOCKET_ERROR) {/*�ر��׽��֣�������*/return 0; }
	// 5. �ȴ��ͻ�������
	SOCKADDR_IN  addrClient = {};
	while (true)
	{
		nLen = sizeof(SOCKADDR_IN);
		// �ȴ��ͻ�������
		SOCKET sClient = accept(sSer, (SOCKADDR*)&addrClient, &nLen);
		if (sClient == INVALID_SOCKET) {/*�ر��׽��֣�������*/return 0; }
		// �������ӽ����Ŀͻ���
		m_vecSocket.push_back(sClient);
		CreateThread(NULL, NULL, RecvThread, (LPVOID)sClient, NULL, NULL);
	}
	return 0;
}

