#include "ClientTcpSocket.h"

SOCKET ClientTcpSocket::InitSocket(u_short port,std::string ip)
{
	std::wstring ErrorStr;
	SOCKET Client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (Client == INVALID_SOCKET)
	{
		int Error_code = GetLastError(); // »ñÈ¡´íÎóÂë
		ErrorStr = L"´íÎóÂë:" + std::to_wstring(Error_code);
		Error error(ErrorStr, L"´íÎó");
	}

	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.S_un.S_addr = inet_addr(ip.c_str());
	if (connect(Client, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR)
	{
		int Error_code = GetLastError(); // »ñÈ¡´íÎóÂë
		ErrorStr = L"´íÎóÂë:" + std::to_wstring(Error_code);
		Error error(ErrorStr, L"´íÎó");
		return -1;
	}
	return Client;
}

void ClientTcpSocket::InitClientSocket()
{
	WSAData Data;
	std::wstring ErrorStr;
	int error = WSAStartup(MAKEWORD(2, 2), &Data);
	if(error != 0)
	{
		ErrorStr = L"´íÎóÂë:"+ std::to_wstring(error);
		Error error(ErrorStr,L"´íÎó");
	}
}

void ClientTcpSocket::CleanClientSocket()
{
	std::wstring ErrorStr;
	int error = WSACleanup();
	if (error == SOCKET_ERROR)
	{
		int Error_code = GetLastError(); // »ñÈ¡´íÎóÂë
		ErrorStr = L"´íÎóÂë:" + std::to_wstring(Error_code);
		Error error(ErrorStr, L"´íÎó");
	}
}

void ClientTcpSocket::RecvMessage(SOCKET Server, int ClietStatus)
{
	while (1)
	{
		char buf[1024] = "";
		if (recv(Server, buf, 1024, 0) == SOCKET_ERROR)
		{
			std::wstring ErrorString=L"";
			ErrorString = L"´íÎóÂë:" + std::to_wstring(GetLastError());
			Error error(ErrorString, L"´íÎó");
			ClietStatus = 0;
			break;
		}
		std::cout << buf << std::endl;
		MessageLast.push_back(tool.string_to_wstring(buf));
	}
}