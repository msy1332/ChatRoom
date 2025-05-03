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
		Tool tool; //����

		TextBox Textbox1; //�ı������1
		TextBox Textbox2; //�ı������2
		Button LoinButton; //���밴ť
		Button SendButton; //������Ϣ��ť
		Button AttachmentButton; //������ť
		Ip_input_box Ip_Input_Box1;
		TextBox MessageTextBox; //��Ϣ�����

		IMAGE LoninBkImage; //�������ı���ͼƬ
		IMAGE ChatRoomBkImage; //�������ı���ͼƬ
		
		void PrintfMessage(ClientTcpSocket Clienttcpsocket); //��ӡ��Ϣ
		void DrawLonin(); //���Ƶ������
		void InitLoninScreen(); //��ʼ���������
		void InitChatRoomScreen(); //��ʼ���������
		void DrawChatRoom(ClientTcpSocket Clienttcpsocket); //�����������
	private:
	protected:
};