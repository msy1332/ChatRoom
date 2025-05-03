#define WIN32_LEAN_AND_MEAN
#include "../API/Tool.h"
#include <WinSock2.h>
#include <iostream>
#include <easyx.h>
#include <string>
#include <time.h>
#pragma comment(lib,"Ws2_32.lib")
#pragma once

#define TextBoxFixedHeight 22 //文本输入框固定高度

enum TextBoxStatus //文本输入框的状态
{
	TextBoxEDITOR = 0,		 //编辑状态
	TextBoxSuspension = 1,  //悬浮状态
	TextBoxNormal = 2		 //普通状态
};

struct TextBoxPosition //文本输入框的坐标及大小
{
	int x;	     //文本输入框的x坐标
	int y;	     //文本输入框的y坐标
	int width;   //文本输入框的宽度
	int height;  //文本输入框的高度
};

struct TextBoxStatusColor //文本输入框三个状态的颜色
{
	COLORREF EDITOR; 
	COLORREF Suspension;
	COLORREF Normal;
};

class TextBox
{
	public:
		u_short port = 0; //端口号
		Tool tool; //将宽字符串转化为多字节字符串的一个类

		int TextLen = 0; //输入字符的总长度
		int Len = 0; //最大输入字符的总长度，也就是最大只能输入的字符个数，如果为0，就按照计算出来的文本最大输入的宽度来限制文本输入的字符个数

		std::wstring UserInputText;//用户输入的字符串或端口
		std::wstring TextBoxTips; //文本输入框的提示文字

		TextBoxPosition Textboxpos;//文本输入坐标及大小
		TextBoxStatusColor TextBoxFill;//文本输入框三个状态的填充颜色
		TextBoxStatusColor TextBoxLine;//文本输入框三个状态的线条颜色

		void DrawTips();//绘制提示文本
		void DrawCursor(); //绘制光标
		void ResetTextBox(); //重置输入框
		void DrawInputText(); //绘制输入的文字
		void DrawTextBox(); //绘制文本输入框
		void ComputeTextMaxTotalWidth();//计算文字的最大总宽度
		bool Wstring_to_port(); //将宽字节字符串转化为端口号
		bool ReadtUserInputString(const ExMessage msg);//读取用户输入字符串
		void ReadtUserInputPort(const ExMessage msg);//读取用户输入端口
		void RenewalAndJudgmentTextBoxStatus(const ExMessage msg); //更新并判断文本输入框的状态
		bool JudgmentMouseTextBoxInside(const int x,const int y); //判断鼠标是否在文本输入框的里面
	private:
		int TextTotal = 0;//文字的总宽度
		int TextMaxTotalWidth = 0;//文字的最大宽度
		int TextbosStatus = TextBoxNormal; //文本输入框的状态
	protected:
};