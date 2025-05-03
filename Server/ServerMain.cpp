#define WIN32_LEAN_AND_MEAN  // 避免 windows.h 包含 winsock.h
#include "ServerTcpSocket.h"
#include "../API/Error.h"
#include "ServerUI.h"
#include <WinSock2.h>
#include <iostream>
#include <windows.h>
#include <easyx.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

SOCKET ServerSocket; //服务器套接字
ExMessage msg; //定义消息结构体

enum Serevr_Stusus //服务器的状态
{
	StartServer = 0, //启动服务器状态
	StopServer =1	 //关闭服务器状态
};

int main()
{
	// 初始化窗口
	initgraph(600,300,EX_SHOWCONSOLE); //创建窗口
	setbkmode(TRANSPARENT);//设置背景模式为透明模式，这样绘制出的文字背景就是透明的
	setbkcolor(RGB(240, 240, 240));//设置背景颜色
	cleardevice();//清除绘图窗口，并用背景颜色填充整个窗口

	int Running = true; // 程序的运行状态
	int ServerStatus = StopServer; //服务器的状态

	//初始化
	ServerUI Serverui;
	Serverui.InitUI();

	//网络的初始化
	ServerTcpSocket Servertcpsocket;
	Servertcpsocket.InitSocket();

	BeginBatchDraw();
	while (Running)
	{
		while (peekmessage(&msg, EX_MOUSE | EX_KEY | EX_CHAR))
		{
			if (ServerStatus == StopServer)
			{
				Serverui.Ip_input_Box1.Renewal_and_judgment_ip_input_box_status(msg);
				Serverui.Ip_input_Box1.Read_User_Input_ip_address(msg);
				Serverui.TextBox1.RenewalAndJudgmentTextBoxStatus(msg);
				Serverui.TextBox1.ReadtUserInputPort(msg);
				if (Serverui.StartButton.Renewal_And_Judgment_Button_Status(msg))
				{
					if (Serverui.Ip_input_Box1.Ip_address_segment_transformation_ip_address() && Serverui.TextBox1.Wstring_to_port())
					{
						ServerSocket = Servertcpsocket.CreateServerSocket(Serverui.TextBox1.port, Serverui.Ip_input_Box1.Ip);
						if (ServerSocket != -1)
						{
							ServerStatus = StartServer;
							thread([&Servertcpsocket,&ServerStatus]() 
							{
								cout << "ServerStatus: " << ServerStatus<<endl;
								Servertcpsocket.AcceptClient(ServerSocket, ServerStatus);
							}).detach();	
							Servertcpsocket.Log.push_back(L"服务器启动成功!");
						}
						else
						{
							Servertcpsocket.Log.push_back(L"服务器启动失败!");
						}
					}
					else
					{
						Servertcpsocket.Log.push_back(L"服务器启动失败!");
						Error error(L"请检查ip地址和端口号的合法性", L"错误");
					}
				}
				if(Serverui.StopButton.Renewal_And_Judgment_Button_Status(msg))
				{
					Running = false;
				}
			}
			else
			{
				Serverui.StartButton.Renewal_And_Judgment_Button_Status(msg);
				if (Serverui.StopButton.Renewal_And_Judgment_Button_Status(msg))
				{
					ServerStatus = StopServer;
					Running = false;
				}
			}
		}
		cleardevice();
		Serverui.Draw(Servertcpsocket);
		FlushBatchDraw();
	}
	EndBatchDraw();
	closesocket(ServerSocket);
	Servertcpsocket.CleanSocket();
	return 0;
}