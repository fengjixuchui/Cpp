#include "stdafx.h"
#include "MyTCP.h"


CMyTCP::CMyTCP()
{
}


CMyTCP::~CMyTCP()
{
}

SOCKET CMyTCP::TcpAccept()
{
	SOCKADDR addr = {};
	int nLen = sizeof(SOCKADDR);
	SOCKET s = accept(m_socket, &addr, &nLen);
	if (s == INVALID_SOCKET)
	{
		return INVALID_SOCKET;
	}
	m_vecSocket.push_back(s);
	return s;
}



int CMyTCP::TcpRecv(SOCKET s, char*buf, int nLen)
{
	int nRet = recv(s, buf, nLen,NULL);
	if (nRet == SOCKET_ERROR) return nRet;
	for (auto &each:m_vecSocket)
	{
		if(each == s) continue;
		send(each, buf, nLen, NULL);
	}
	return nRet;
}

bool CMyTCP::InitServer(char* pIp/*="127.0.0.1"*/, short port/*=0x1234*/)
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
	m_socket = socket(
		AF_INET,// IP4Э��
		SOCK_STREAM,// ��ʽ�׽���
		IPPROTO_TCP);// Э������(TCP)
	if (m_socket == INVALID_SOCKET)
	{
		printf("����socketʧ�ܣ�\n");
		WSACleanup();
		return 0;
	}
	// 3. �쿨
	SOCKADDR_IN addrSer = {};
	addrSer.sin_addr.S_un.S_addr = inet_addr(pIp);
	addrSer.sin_port = htons(port);// host to net short
	addrSer.sin_family = AF_INET;
	int nLen = sizeof(SOCKADDR_IN);
	int nRet = bind(m_socket, (SOCKADDR*)&addrSer, nLen);
	if (nRet == SOCKET_ERROR) {/*�ر��׽��֣�������*/return 0; }
	// 4. ����
	nRet = listen(m_socket, SOMAXCONN);
	if (nRet == SOCKET_ERROR) {/*�ر��׽��֣�������*/return 0; }
	return true;
}

bool CMyTCP::TcpClientExit(SOCKET s)
{
	for (int i=0;i<m_vecSocket.size();i++)
	{
		if (m_vecSocket[i] == s)
		{
			m_vecSocket.erase(m_vecSocket.begin() + i);
			closesocket(s);
			return true;
		}
	}
	return false;
}
