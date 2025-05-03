#include <windows.h>
#include <iostream>
#include <easyx.h>
#include <string>
#pragma once

enum Button_status //��ť��״̬
{
	Button_Normal		= 0, //��ͨ״̬
	Button_Suspension	= 1, //����״̬
	Button_Press		= 2  //����״̬
};

enum ButtonType //��ť������
{
	A_filled_rectangle_with_a_border			= 0, //�б߿��������
	Fill_rectangle_without_border				= 1, //�ޱ߿��������
	A_filled_rounded_rectangle_with_a_border	= 2, //�б߿�����Բ�Ǿ���
	Fill_rounded_rectangles_without_borders		= 3  //�ޱ߿�����Բ�Ǿ���
};

struct TextStyle //��ť����������ֵ�����
{
	//��0��������Ӧ
	int TextWidth;			//���ֵĿ��
	int TextHeight;			//���ֵĸ߶�
	std::wstring Typeface;	//���ֵ�����
};

struct ButtonPositionSize//��ť�Ĵ�С������
{
	int x;		//��ť��x����
	int y;		//��ť��y����
	int width;	//��ť�Ŀ��
	int height;	//��ť�ĸ߶�
	int ellipsewidth; //����Բ�Ǿ��ε�Բ����Բ�Ŀ��
	int ellipseheight; //����Բ�Ǿ��ε�Բ����Բ�ĸ߶�
};

struct ButtonStatusColor //��ť����״̬����ɫ
{
	COLORREF Normal;      //��ͨ
	COLORREF Suspension;  //����
	COLORREF Press;       //����
};

class Button
{
	public:

		
		int Buttontype;		//��ť������
		std::wstring Text = L"";	//����
		TextStyle Textstyle;//���ֵ���ʽ����С
		ButtonStatusColor FillColor;//����״̬�������ɫ
		ButtonStatusColor LineColor;//����״̬��������ɫ
		ButtonStatusColor TextColor;//����״̬��������ɫ
		ButtonPositionSize Buttonpositionsize;//��ť������
		
		void Draw_Button();															//���ư�ť
		void CopyButton(Button& button);											//���ư�ť
		void Compute_Centering_Text_Coordinate();									//�������־��е�����
		bool Renewal_And_Judgment_Button_Status(const ExMessage msg);							//���°�ť��״̬
		bool Judgment_Mouse_Button_Inside(const int Mouse_X,const int Mouse_Y);	//�ж�����Ƿ��ڰ�ť����

	private:

		int Text_Width;			//���ֵĿ��
		int Text_Height;		//���ֵĸ߶�
		int Centering_Text_X;	//���־��е�x����
		int Centering_Text_Y;	//���־��е�y����
		int ButtonStatus= Button_Normal; //��ť��״̬

	protected:
};