#include "ServerTcpSocket.h"

void ServerTcpSocket::InitSocket()
{
	WSAData Data;
	if (WSAStartup(MAKEWORD(2, 2), &Data) != 0)
	{
		std::wstring ErrorString = L"";
		ErrorString = L"´íÎóÂë:" + std::to_wstring(WSAGetLastError());
		Error error(ErrorString, L"´íÎó");
	}
}

void ServerTcpSocket::CleanSocket()
{
	if (WSACleanup() != 0)
	{
		std::wstring ErrorString = L"";
		ErrorString = L"´íÎóÂë:" + std::to_wstring(WSAGetLastError());
		Error error(ErrorString, L"´íÎó");
	}
}

SOCKET ServerTcpSocket::CreateServerSocket(short port,std::string ip)
{
	std::cout << "CreateServerSocket()" << std::endl;
	SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (ServerSocket == INVALID_SOCKET)
	{
		std::wstring ErrorString = L"";
		ErrorString = L"´íÎóÂë:" + std::to_wstring(WSAGetLastError());
		Error error(ErrorString, L"´íÎó");
		return -1;
	}

	sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.S_un.S_addr = inet_addr(ip.c_str());
	if (bind(ServerSocket, (sockaddr*)&addr, sizeof(addr)) ==  SOCKET_ERROR)
	{
		std::wstring ErrorString = L"";
		ErrorString = L"´íÎóÂë:" + std::to_wstring(WSAGetLastError());
		Error error(ErrorString, L"´íÎó");
		return -1;
	}

	listen(ServerSocket, 10);
	return ServerSocket;
}

ServerTcpSocket::ServerTcpSocket()
{
	ClientList.resize(10);
}

void ServerTcpSocket::AcceptClient(SOCKET ServerSocket ,int ServerStatus)
{
	std::cout << "AcceptClient()" << std::endl;
	while (ServerStatus != 1)
	{
		std::wstring LogString; //ÈÕÖ¾×Ö·û´®
		std::cout << "AcceptClient() While()" << std::endl;
		SOCKET Client = accept(ServerSocket, NULL, 0);
		LogString = L"SOCKET:" + std::to_wstring(Client) + L" Go online...";
		Log.push_back(LogString);
		if (Client == SOCKET_ERROR)
		{
			break;
		}
		std::cout << "ClientSocket: " << Client << " Go online..." << std::endl;
		std::thread(
			[Client,this, ServerStatus]() {
				RecvClient(Client, ServerStatus);
			}).detach();
		ClientList.push_back(Client);
	}
}

void ServerTcpSocket::RecvClient(SOCKET Client, int ServerStatus)
{
	std::wstring LogString; //ÈÕÖ¾×Ö·û´®
	while (1)
	{
		std::cout << "RecvClient() While(1)" << std::endl;
		char buf[1024];
		int len = recv(Client, buf, 1024, 0);
		if (len == SOCKET_ERROR)
		{
			std::cout << "ClientSocket: " << Client << " Offline..." << std::endl;
			DeleteClient(Client);
			break;
		}
		std::cout << "RecvClientMessage" << buf << std::endl;
		/*Log.push_back(tool.string_to_wstring(buf));*/
		SendClient(buf, len, Client);
	}
	LogString = L"SOCKET:" + std::to_wstring(Client) + L" Offline...";
	Log.push_back(LogString);
}

void ServerTcpSocket::SendClient(char* buf,int len, SOCKET Client)
{
	for (int i = 0; i < (int)ClientList.size(); i++)
	{
		if (ClientList[i] != Client)
		{
			send(ClientList[i], buf, len, 0);
		}
	}
	std::cout << "Sizeof(buf)" << sizeof(buf) << "\t" << "SendClientMessage" << buf << std::endl;
}

void ServerTcpSocket::DeleteClient(SOCKET Client)
{
	for (int i = 0; i < (int)ClientList.size(); i++)
	{
		if (ClientList[i] == Client)
		{
			SOCKET a = ClientList[i];
			ClientList[i] = ClientList[ClientList.size() - 1];
			ClientList[ClientList.size() - 1] = a;
			ClientList.pop_back();
			break;
		}
	}
}