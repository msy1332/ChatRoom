#include "../API/Error.h"
#include "../API/Tool.h"
#include <iostream>
#include <easyx.h>
#include "Share.h"
#include <string>
#include <vector>
#pragma once

#define IpWidth 145 //ip输入框固定的宽度
#define IpHeight 22 //ip输入框固定的高度
#define Outtextx 8 //相对于ip输入框输出文字x坐标
#define Outtexty 5 //相对于ip输入框输出文字y坐标
#define Ip_address_segment_width 145 / 4 //ip地址段的宽度

enum IP_address_input_box_Status //ip输入框三个状态
{
	IP_address_input_box_EDITOR		= 0, //编辑状态
	IP_address_input_box_Suspension	= 1, //悬浮状态
	IP_address_input_box_Normal		= 2	 //普通状态
};

struct The_color_of_each_state_of_the_ip_input_box //ip输入框三个状态的颜色
{
	COLORREF EDITOR;	 //编辑状态的颜色
	COLORREF Suspension; //悬浮状态的颜色
	COLORREF Normal;	 //普通状态的颜色
};

struct Ip_input_box_coordinate //ip输入框的坐标
{
	int x;
	int y;
};

class Ip_input_box
{
	public:
		
		Tool tool;

		std::string Ip =""; //多字节字符串ip,就是将宽字节字符串ip地址转化为多字节字符串的ip地址
		std::wstring Wip = L""; //ip地址，最终将ip地址段合成一个完整的ip地址
		std::vector<int> Ip_address_segment_len; //每个ip地址段的长度
		std::vector<std::wstring> Ip_address_segment; //ip地址段，总共有4段

		Ip_input_box_coordinate Ip_input_box_pos; //ip输入框的坐标
		The_color_of_each_state_of_the_ip_input_box Ip_Input_field_fill_color; //ip输入框三个状态的填充颜色
		The_color_of_each_state_of_the_ip_input_box Ip_Input_field_line_color; //ip输入框三个状态的线条颜色

		void Draw_Cursor();//绘制光标
		void Draw_ip_input_box(); //绘制ip输入框
		void Read_User_Input_ip_address(const ExMessage msg); //读取用户输入的ip地址
		void Draw_ip_address_segment();//绘制ip地址段，以及ip地址段的分隔
		void Renewal_and_judgment_ip_input_box_status(const ExMessage msg); //更新并判断ip输入框的状态
		bool Judgment_mouse_ip_input_box_inside(const int x, const int y);//判断鼠标是否在IP输入框里面
		bool Ip_address_segment_transformation_ip_address(); //将ip地址段转化为ip地址
	private:
		int CursorX = 0; //光标相对于文字的输出位置的x坐标
		int Ip_input_box_status = IP_address_input_box_Normal; //ip输入框的状态
		int Ip_address_segment_size = 0; //ip地址段的总长度
		int Current_ip_address_segment = 0; //当前在哪个ip地址段
	protected:
};