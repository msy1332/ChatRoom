#include "../API/Ip_input_box_control.h"
#include "ServerTcpSocket.h"
#include "../API/TextBox.h"
#include "../API/Button.h"
#include <iostream>
#pragma once

class ServerUI
{
	public:
		TextBox TextBox1; //�˿ں������
		Button StartButton; //������������ť
		Button StopButton; //�رշ�������ť
		Ip_input_box Ip_input_Box1; //ip��ַ�����

		void InitUI();
		void Draw(ServerTcpSocket Servertcpsocket);
		void PrintfLog(ServerTcpSocket Servertcpsocket); //��ӡ��־
	private:
	protected:
};