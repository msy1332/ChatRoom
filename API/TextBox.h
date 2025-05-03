#define WIN32_LEAN_AND_MEAN
#include "../API/Tool.h"
#include <WinSock2.h>
#include <iostream>
#include <easyx.h>
#include <string>
#include <time.h>
#pragma comment(lib,"Ws2_32.lib")
#pragma once

#define TextBoxFixedHeight 22 //�ı������̶��߶�

enum TextBoxStatus //�ı�������״̬
{
	TextBoxEDITOR = 0,		 //�༭״̬
	TextBoxSuspension = 1,  //����״̬
	TextBoxNormal = 2		 //��ͨ״̬
};

struct TextBoxPosition //�ı����������꼰��С
{
	int x;	     //�ı�������x����
	int y;	     //�ı�������y����
	int width;   //�ı������Ŀ��
	int height;  //�ı������ĸ߶�
};

struct TextBoxStatusColor //�ı����������״̬����ɫ
{
	COLORREF EDITOR; 
	COLORREF Suspension;
	COLORREF Normal;
};

class TextBox
{
	public:
		u_short port = 0; //�˿ں�
		Tool tool; //�����ַ���ת��Ϊ���ֽ��ַ�����һ����

		int TextLen = 0; //�����ַ����ܳ���
		int Len = 0; //��������ַ����ܳ��ȣ�Ҳ�������ֻ��������ַ����������Ϊ0���Ͱ��ռ���������ı��������Ŀ���������ı�������ַ�����

		std::wstring UserInputText;//�û�������ַ�����˿�
		std::wstring TextBoxTips; //�ı���������ʾ����

		TextBoxPosition Textboxpos;//�ı��������꼰��С
		TextBoxStatusColor TextBoxFill;//�ı����������״̬�������ɫ
		TextBoxStatusColor TextBoxLine;//�ı����������״̬��������ɫ

		void DrawTips();//������ʾ�ı�
		void DrawCursor(); //���ƹ��
		void ResetTextBox(); //���������
		void DrawInputText(); //�������������
		void DrawTextBox(); //�����ı������
		void ComputeTextMaxTotalWidth();//�������ֵ�����ܿ��
		bool Wstring_to_port(); //�����ֽ��ַ���ת��Ϊ�˿ں�
		bool ReadtUserInputString(const ExMessage msg);//��ȡ�û������ַ���
		void ReadtUserInputPort(const ExMessage msg);//��ȡ�û�����˿�
		void RenewalAndJudgmentTextBoxStatus(const ExMessage msg); //���²��ж��ı�������״̬
		bool JudgmentMouseTextBoxInside(const int x,const int y); //�ж�����Ƿ����ı�����������
	private:
		int TextTotal = 0;//���ֵ��ܿ��
		int TextMaxTotalWidth = 0;//���ֵ������
		int TextbosStatus = TextBoxNormal; //�ı�������״̬
	protected:
};