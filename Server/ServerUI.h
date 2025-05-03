#include "../API/Ip_input_box_control.h"
#include "ServerTcpSocket.h"
#include "../API/TextBox.h"
#include "../API/Button.h"
#include <iostream>
#pragma once

class ServerUI
{
	public:
		TextBox TextBox1; //端口号输入框
		Button StartButton; //启动服务器按钮
		Button StopButton; //关闭服务器按钮
		Ip_input_box Ip_input_Box1; //ip地址输入框

		void InitUI();
		void Draw(ServerTcpSocket Servertcpsocket);
		void PrintfLog(ServerTcpSocket Servertcpsocket); //打印日志
	private:
	protected:
};