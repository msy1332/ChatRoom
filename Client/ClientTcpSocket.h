#define WIN32_LEAN_AND_MEAN  // 避免 windows.h 包含 winsock.h
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
		std::vector<std::wstring> MessageLast; //消息列表
		void RecvMessage(SOCKET Server , int ClietStatu); //用来接收消息
		void InitClientSocket(); //初始化客户端的网络环境
		void CleanClientSocket(); //清除客户端的网络环境
		SOCKET InitSocket(u_short port, std::string ip); //初始化客户端Socket套接字
	private:
		Tool tool; //字符串的转化工具
	protected:
};