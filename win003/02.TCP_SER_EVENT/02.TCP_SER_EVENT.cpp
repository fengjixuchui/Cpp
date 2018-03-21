// 02.TCP_SER_EVENT.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MyTCP.h"

int main()
{
	vector<HANDLE> m_vecEvent;
	vector<SOCKET> m_vecSocket;
	CMyTCP tcp;
	tcp.InitServer();
	HANDLE hEvent = WSACreateEvent();
	m_vecEvent.push_back(hEvent);
	// ��m_socket��Ҫ��ӦFD_ACCEPT | FD_CLOSE�¼�ʱ
	// ϵͳ�ἤ��hEvent������������ź�״̬
	WSAEventSelect(tcp.m_socket, hEvent, FD_ACCEPT | FD_CLOSE);
	m_vecSocket.push_back(tcp.m_socket);
	while (true)
	{
		int nCount = m_vecEvent.size();
		// nCount���ܳ���64
		int nRet = WSAWaitForMultipleEvents(
			nCount,// �ȴ����¼����� HEVENT
			&m_vecEvent[0], // �ȴ��Ķ���¼��������ַ
			FALSE, // �Ƿ�ȴ������¼���������
			INFINITE,// �ȴ���ʱʱ��
			FALSE);// �Ƿ�ɾ���
		if (nRet == WSA_WAIT_FAILED) continue;
		int nIndex = nRet - WSA_WAIT_EVENT_0;
		// ��ȡ��������¼���Ӧ��socket�������¼�
		WSANETWORKEVENTS we = {};
		WSAEnumNetworkEvents(m_vecSocket[nIndex], m_vecEvent[nIndex], &we);
		if (we.lNetworkEvents & FD_ACCEPT)
		{
			SOCKET s = tcp.TcpAccept();
			HANDLE hEvent2 = WSACreateEvent();
			m_vecEvent.push_back(hEvent2);
			// ��m_socket��Ҫ��ӦFD_ACCEPT | FD_CLOSE�¼�ʱ
			// ϵͳ�ἤ��hEvent������������ź�״̬
			WSAEventSelect(s, hEvent2, FD_READ | FD_CLOSE);
			m_vecSocket.push_back(s);
		}
		if (we.lNetworkEvents & FD_READ)
		{
			char buf[1024] = {};
			tcp.TcpRecv(m_vecSocket[nIndex], buf, 1024);
			printf("%s\n", buf);
		}
		if (we.lNetworkEvents & FD_CLOSE)
		{
			if (we.iErrorCode[FD_CLOSE_BIT] != 0)
				printf("�ͻ�����åʽ�ر�\n");
			else
			{
				printf("�ͻ����˳�\n");
			}
			tcp.TcpClientExit(m_vecSocket[nIndex]);
		}
	}
    return 0;
}

