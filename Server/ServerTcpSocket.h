#define WIN32_LEAN_AND_MEAN  // 避免 windows.h 包含 winsock.h
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
		void DeleteClient(SOCKET Client); //查找客户端描述符
		void InitSocket(); //初始化网络环境
		void CleanSocket(); //清除网络环境
		void SendClient(char* buf,int len,SOCKET Client); //给每个在线客户端发送消息
		void RecvClient(SOCKET Clien, int ServerStatust); //用来接受客户端的消息并将消息发给每一个在线的客户端
		void AcceptClient(SOCKET SerevrSocket, int ServerStatus); //同意客户端的连接请求，当然实际不是这样子的，意思是获取新的客户端套接字描述符，这样才能与客户端进行通信
		SOCKET CreateServerSocket(short port,std::string ip); //初始化服务器套接字
		std::vector<std::wstring> Log; //服务器的日志
	private:
		Tool tool; //工具
		std::vector<SOCKET> ClientList; //用来存储客户端的描述符
	protected:
};