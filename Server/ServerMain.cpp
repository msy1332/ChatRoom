#define WIN32_LEAN_AND_MEAN  // ���� windows.h ���� winsock.h
#include "ServerTcpSocket.h"
#include "../API/Error.h"
#include "ServerUI.h"
#include <WinSock2.h>
#include <iostream>
#include <windows.h>
#include <easyx.h>
#pragma comment(lib,"ws2_32.lib")
using namespace std;

SOCKET ServerSocket; //�������׽���
ExMessage msg; //������Ϣ�ṹ��

enum Serevr_Stusus //��������״̬
{
	StartServer = 0, //����������״̬
	StopServer =1	 //�رշ�����״̬
};

int main()
{
	// ��ʼ������
	initgraph(600,300,EX_SHOWCONSOLE); //��������
	setbkmode(TRANSPARENT);//���ñ���ģʽΪ͸��ģʽ���������Ƴ������ֱ�������͸����
	setbkcolor(RGB(240, 240, 240));//���ñ�����ɫ
	cleardevice();//�����ͼ���ڣ����ñ�����ɫ�����������

	int Running = true; // ���������״̬
	int ServerStatus = StopServer; //��������״̬

	//��ʼ��
	ServerUI Serverui;
	Serverui.InitUI();

	//����ĳ�ʼ��
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
							Servertcpsocket.Log.push_back(L"�����������ɹ�!");
						}
						else
						{
							Servertcpsocket.Log.push_back(L"����������ʧ��!");
						}
					}
					else
					{
						Servertcpsocket.Log.push_back(L"����������ʧ��!");
						Error error(L"����ip��ַ�Ͷ˿ںŵĺϷ���", L"����");
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