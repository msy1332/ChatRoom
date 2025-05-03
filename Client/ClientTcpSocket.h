#define WIN32_LEAN_AND_MEAN  // ���� windows.h ���� winsock.h
#include "../API/Error.h"
#include "../API/Tool.h"
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#pragma comment(lib,"Ws2_32.lib")
#pragma once
	
class ClientTcpSocket
{	
	public:
		std::vector<std::wstring> MessageLast; //��Ϣ�б�
		void RecvMessage(SOCKET Server , int ClietStatu); //����������Ϣ
		void InitClientSocket(); //��ʼ���ͻ��˵����绷��
		void CleanClientSocket(); //����ͻ��˵����绷��
		SOCKET InitSocket(u_short port, std::string ip); //��ʼ���ͻ���Socket�׽���
	private:
		Tool tool; //�ַ�����ת������
	protected:
};