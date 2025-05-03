#include <iostream>
#include <easyx.h>
#include <string>
#pragma once

struct LablePosition //是你要绘制标签在哪个的矩形区域的位置，以及矩形的高度和宽度
{
	int x; //矩形的x坐标
	int y; //矩形的y坐标
	int RectWidth; //矩形的宽度
	int RectHeight; //矩形的高度
};

struct LableStyle //标签的样式
{
	COLORREF color; //标签文字的颜色
	int LableWidth; //标签文字的宽度
	int LableHeight; //标文字签的高度
	std::wstring LableTypeface; //标签文字的字体
};

class Lable
{
	public:
		std::wstring Text;//标签的文字

		LableStyle Lablestyle; //标签的样式
		LablePosition Lableposition; //标签在哪个矩形区域居中位置的矩形的坐标和大小

		void DrawLable();
		void Compute_Centering_Text_Coordinate();
	private:
		int TextWidth;
		int TextHeight;
		int Centering_Text_X;
		int Centering_Text_Y;
	protected:
};