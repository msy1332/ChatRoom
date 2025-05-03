#define WIN32_LEAN_AND_MEAN  // ���� windows.h ���� winsock.h
#include "../API/Error.h"
#include "../API/Tool.h"
#include <WinSock2.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <cstdio>
#include <cstring>
#pragma comment(lib,"ws2_32.lib")

#pragma once
class ServerTcpSocket
{
	public:	
		ServerTcpSocket();
		void DeleteClient(SOCKET Client); //���ҿͻ���������
		void InitSocket(); //��ʼ�����绷��
		void CleanSocket(); //������绷��
		void SendClient(char* buf,int len,SOCKET Client); //��ÿ�����߿ͻ��˷�����Ϣ
		void RecvClient(SOCKET Clien, int ServerStatust); //�������ܿͻ��˵���Ϣ������Ϣ����ÿһ�����ߵĿͻ���
		void AcceptClient(SOCKET SerevrSocket, int ServerStatus); //ͬ��ͻ��˵��������󣬵�Ȼʵ�ʲ��������ӵģ���˼�ǻ�ȡ�µĿͻ����׽���������������������ͻ��˽���ͨ��
		SOCKET CreateServerSocket(short port,std::string ip); //��ʼ���������׽���
		std::vector<std::wstring> Log; //����������־
	private:
		Tool tool; //����
		std::vector<SOCKET> ClientList; //�����洢�ͻ��˵�������
	protected:
};