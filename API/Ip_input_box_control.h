#include "../API/Error.h"
#include "../API/Tool.h"
#include <iostream>
#include <easyx.h>
#include "Share.h"
#include <string>
#include <vector>
#pragma once

#define IpWidth 145 //ip�����̶��Ŀ��
#define IpHeight 22 //ip�����̶��ĸ߶�
#define Outtextx 8 //�����ip������������x����
#define Outtexty 5 //�����ip������������y����
#define Ip_address_segment_width 145 / 4 //ip��ַ�εĿ��

enum IP_address_input_box_Status //ip���������״̬
{
	IP_address_input_box_EDITOR		= 0, //�༭״̬
	IP_address_input_box_Suspension	= 1, //����״̬
	IP_address_input_box_Normal		= 2	 //��ͨ״̬
};

struct The_color_of_each_state_of_the_ip_input_box //ip���������״̬����ɫ
{
	COLORREF EDITOR;	 //�༭״̬����ɫ
	COLORREF Suspension; //����״̬����ɫ
	COLORREF Normal;	 //��ͨ״̬����ɫ
};

struct Ip_input_box_coordinate //ip����������
{
	int x;
	int y;
};

class Ip_input_box
{
	public:
		
		Tool tool;

		std::string Ip =""; //���ֽ��ַ���ip,���ǽ����ֽ��ַ���ip��ַת��Ϊ���ֽ��ַ�����ip��ַ
		std::wstring Wip = L""; //ip��ַ�����ս�ip��ַ�κϳ�һ��������ip��ַ
		std::vector<int> Ip_address_segment_len; //ÿ��ip��ַ�εĳ���
		std::vector<std::wstring> Ip_address_segment; //ip��ַ�Σ��ܹ���4��

		Ip_input_box_coordinate Ip_input_box_pos; //ip����������
		The_color_of_each_state_of_the_ip_input_box Ip_Input_field_fill_color; //ip���������״̬�������ɫ
		The_color_of_each_state_of_the_ip_input_box Ip_Input_field_line_color; //ip���������״̬��������ɫ

		void Draw_Cursor();//���ƹ��
		void Draw_ip_input_box(); //����ip�����
		void Read_User_Input_ip_address(const ExMessage msg); //��ȡ�û������ip��ַ
		void Draw_ip_address_segment();//����ip��ַ�Σ��Լ�ip��ַ�εķָ�
		void Renewal_and_judgment_ip_input_box_status(const ExMessage msg); //���²��ж�ip������״̬
		bool Judgment_mouse_ip_input_box_inside(const int x, const int y);//�ж�����Ƿ���IP���������
		bool Ip_address_segment_transformation_ip_address(); //��ip��ַ��ת��Ϊip��ַ
	private:
		int CursorX = 0; //�����������ֵ����λ�õ�x����
		int Ip_input_box_status = IP_address_input_box_Normal; //ip������״̬
		int Ip_address_segment_size = 0; //ip��ַ�ε��ܳ���
		int Current_ip_address_segment = 0; //��ǰ���ĸ�ip��ַ��
	protected:
};