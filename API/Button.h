#include <windows.h>
#include <iostream>
#include <easyx.h>
#include <string>
#pragma once

enum Button_status //按钮的状态
{
	Button_Normal		= 0, //普通状态
	Button_Suspension	= 1, //悬浮状态
	Button_Press		= 2  //按下状态
};

enum ButtonType //按钮的类型
{
	A_filled_rectangle_with_a_border			= 0, //有边框的填充矩形
	Fill_rectangle_without_border				= 1, //无边框的填充矩形
	A_filled_rounded_rectangle_with_a_border	= 2, //有边框的填充圆角矩形
	Fill_rounded_rectangles_without_borders		= 3  //无边框的填充圆角矩形
};

struct TextStyle //按钮里面居中文字的属性
{
	//填0就是自适应
	int TextWidth;			//文字的宽度
	int TextHeight;			//文字的高度
	std::wstring Typeface;	//文字的字体
};

struct ButtonPositionSize//按钮的大小及坐标
{
	int x;		//按钮的x坐标
	int y;		//按钮的y坐标
	int width;	//按钮的宽度
	int height;	//按钮的高度
	int ellipsewidth; //构成圆角矩形的圆角椭圆的宽度
	int ellipseheight; //构成圆角矩形的圆角椭圆的高度
};

struct ButtonStatusColor //按钮三个状态的颜色
{
	COLORREF Normal;      //普通
	COLORREF Suspension;  //悬浮
	COLORREF Press;       //按下
};

class Button
{
	public:

		
		int Buttontype;		//按钮的类型
		std::wstring Text = L"";	//文字
		TextStyle Textstyle;//文字的样式及大小
		ButtonStatusColor FillColor;//三个状态的填充颜色
		ButtonStatusColor LineColor;//三个状态的线条颜色
		ButtonStatusColor TextColor;//三个状态的文字颜色
		ButtonPositionSize Buttonpositionsize;//按钮的坐标
		
		void Draw_Button();															//绘制按钮
		void CopyButton(Button& button);											//复制按钮
		void Compute_Centering_Text_Coordinate();									//计算文字居中的坐标
		bool Renewal_And_Judgment_Button_Status(const ExMessage msg);							//更新按钮的状态
		bool Judgment_Mouse_Button_Inside(const int Mouse_X,const int Mouse_Y);	//判断鼠标是否在按钮里面

	private:

		int Text_Width;			//文字的宽度
		int Text_Height;		//文字的高度
		int Centering_Text_X;	//文字居中的x坐标
		int Centering_Text_Y;	//文字居中的y坐标
		int ButtonStatus= Button_Normal; //按钮的状态

	protected:
};