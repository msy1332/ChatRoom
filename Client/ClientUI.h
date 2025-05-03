#include "../API//Ip_input_box_control.h"
#define WIN32_LEAN_AND_MEAN
#include "ClientTcpSocket.h"
#include "../API/TextBox.h"
#include "../API/Button.h"
#include "../API/Lable.h"
#include "../API/Tool.h"
#include <iostream>
#include <easyx.h>
#include <vector>
#pragma once

class ClientUI
{
	public:
		Tool tool; //工具

		TextBox Textbox1; //文本输入框1
		TextBox Textbox2; //文本输入框2
		Button LoinButton; //登入按钮
		Button SendButton; //发送消息按钮
		Button AttachmentButton; //附件按钮
		Ip_input_box Ip_Input_Box1;
		TextBox MessageTextBox; //消息输入框

		IMAGE LoninBkImage; //登入界面的背景图片
		IMAGE ChatRoomBkImage; //聊天界面的背景图片
		
		void PrintfMessage(ClientTcpSocket Clienttcpsocket); //打印消息
		void DrawLonin(); //绘制登入界面
		void InitLoninScreen(); //初始化登入界面
		void InitChatRoomScreen(); //初始化聊天界面
		void DrawChatRoom(ClientTcpSocket Clienttcpsocket); //绘制聊天界面
	private:
	protected:
};