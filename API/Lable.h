#include <iostream>
#include <easyx.h>
#include <string>
#pragma once

struct LablePosition //����Ҫ���Ʊ�ǩ���ĸ��ľ��������λ�ã��Լ����εĸ߶ȺͿ��
{
	int x; //���ε�x����
	int y; //���ε�y����
	int RectWidth; //���εĿ��
	int RectHeight; //���εĸ߶�
};

struct LableStyle //��ǩ����ʽ
{
	COLORREF color; //��ǩ���ֵ���ɫ
	int LableWidth; //��ǩ���ֵĿ��
	int LableHeight; //������ǩ�ĸ߶�
	std::wstring LableTypeface; //��ǩ���ֵ�����
};

class Lable
{
	public:
		std::wstring Text;//��ǩ������

		LableStyle Lablestyle; //��ǩ����ʽ
		LablePosition Lableposition; //��ǩ���ĸ������������λ�õľ��ε�����ʹ�С

		void DrawLable();
		void Compute_Centering_Text_Coordinate();
	private:
		int TextWidth;
		int TextHeight;
		int Centering_Text_X;
		int Centering_Text_Y;
	protected:
};