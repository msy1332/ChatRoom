#include "ServerUI.h"

void ServerUI::InitUI()
{

	//��ʼ����¼��ť
	this->StartButton.LineColor.Normal = RGB(173, 173, 173);
	this->StartButton.FillColor.Normal = WHITE;
	this->StartButton.TextColor.Normal = BLACK;
	this->StartButton.LineColor.Suspension = RGB(0, 120, 215);
	this->StartButton.FillColor.Suspension = RGB(229, 241, 251);
	this->StartButton.TextColor.Suspension = BLACK;
	this->StartButton.LineColor.Press = RGB(0, 84, 153);
	this->StartButton.FillColor.Press = RGB(204, 228, 247);
	this->StartButton.TextColor.Press = BLACK;
	this->StartButton.Text = L"����������";
	this->StartButton.Textstyle.TextHeight = 12;
	this->StartButton.Textstyle.TextWidth = 0;
	this->StartButton.Textstyle.Typeface = L"����";
	this->StartButton.Buttonpositionsize.x = 393;
	this->StartButton.Buttonpositionsize.y = 20;
	this->StartButton.Buttonpositionsize.width = 80;
	this->StartButton.Buttonpositionsize.height = 22;
	this->StartButton.Compute_Centering_Text_Coordinate();
	this->StartButton.Buttontype = A_filled_rectangle_with_a_border;

	//��ʼ���رշ�������ť
	this->StopButton.CopyButton(StartButton);
	this->StopButton.Buttonpositionsize.x += (80 + 10);
	this->StopButton.Text = L"�رշ�����";
	this->StopButton.Compute_Centering_Text_Coordinate();

	//��ʼ��ip�����
	this->Ip_input_Box1.Ip_Input_field_fill_color.EDITOR = WHITE;
	this->Ip_input_Box1.Ip_Input_field_line_color.EDITOR = RGB(0, 120, 215);
	this->Ip_input_Box1.Ip_Input_field_fill_color.Suspension = WHITE;
	this->Ip_input_Box1.Ip_Input_field_line_color.Suspension = RGB(23, 23, 23);
	this->Ip_input_Box1.Ip_Input_field_fill_color.Normal = WHITE;
	this->Ip_input_Box1.Ip_Input_field_line_color.Normal = RGB(122, 122, 122);
	this->Ip_input_Box1.Ip_input_box_pos.x = 60;
	this->Ip_input_Box1.Ip_input_box_pos.y = 20;
	this->Ip_input_Box1.Ip_address_segment.resize(4);
	this->Ip_input_Box1.Ip_address_segment_len.resize(4);
	
	//��ʼ���˿ںŵ��ı������
	this->TextBox1.TextBoxFill.EDITOR = WHITE;
	this->TextBox1.TextBoxLine.EDITOR = RGB(0, 120, 215);
	this->TextBox1.TextBoxFill.Suspension = WHITE;
	this->TextBox1.TextBoxLine.Suspension = RGB(23, 23, 23);
	this->TextBox1.TextBoxFill.Normal = WHITE;
	this->TextBox1.TextBoxLine.Normal = RGB(122, 122, 122);
	this->TextBox1.Textboxpos.x = 238;
	this->TextBox1.Textboxpos.y = 20;
	this->TextBox1.Textboxpos.width = 145;
	this->TextBox1.Len = 5;
	this->TextBox1.ComputeTextMaxTotalWidth();
}

void ServerUI::Draw(ServerTcpSocket Servertcpsocket)
{
	//��������
	settextcolor(BLACK);
	settextstyle(16, 0, L"Segoe UI");
	outtextxy(37, 20 + 3,L"IP:");
	outtextxy(215, 20 + 3, L"�˿�:");

	this->TextBox1.DrawTextBox(); // ���ƶ˿������
	this->StartButton.Draw_Button(); // ����������������ť
	this->StopButton.Draw_Button(); // ���ƹرշ�������ť
	this->Ip_input_Box1.Draw_ip_input_box(); // ����ip�����

	//������־��ʾ��
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(37, 54, 37 + 526, 54 + 234);

	//������־
	PrintfLog(Servertcpsocket);
}

void ServerUI::PrintfLog(ServerTcpSocket Servertcpsocket)
{
	settextcolor(BLACK);
	settextstyle(18, 0, L"Segoe UI");
	static int LogRange = 0;//��־����ʾ��Χ
	int CurrentDrawLineLog = 0;//��ǰ�����˶�������־
	for (int i = LogRange; i < LogRange + 18 && i < (int)Servertcpsocket.Log.size(); i++)
	{
		int CurrentLongLineRange = 1; //��ǰ��־��Ҫ����������ʾ��Ĭ������Ҫһ��
		int OneLineRangeCharacter = 0;//�����ǰ��־��Ҫ��������ʾ���Ǿͼ���һ�µ�һ����Ҫ��ʾ���ٸ��ַ�
		int CurrentLogTotalWidth = 0;//��ǰ��־���ܿ��
		for (int j = 0; j < (int)Servertcpsocket.Log[i].size(); j++)
		{
			if (CurrentLogTotalWidth + textwidth(Servertcpsocket.Log[i][j]) > 526)
			{
				CurrentLongLineRange = 2;
				OneLineRangeCharacter = j - 1;
				break;
			}
			else
			{
				CurrentLogTotalWidth += textwidth(Servertcpsocket.Log[i][j]);
			}
		}
		if (CurrentLongLineRange == 1)
		{
			outtextxy(37, 54 + (CurrentDrawLineLog * 18), Servertcpsocket.Log[i].c_str());
			CurrentDrawLineLog++;
		}
		else if(CurrentLongLineRange == 2)
		{
			int CurrentLonWidth = 0; //��ǰ��־���ܿ��
			for (int j = 0; j <= OneLineRangeCharacter; j++)
			{
				outtextxy(37 + CurrentLonWidth, 54 + (CurrentDrawLineLog * 18), Servertcpsocket.Log[i][j]);
				CurrentLonWidth += textwidth(Servertcpsocket.Log[i][j]);
			}
			CurrentDrawLineLog++;
			CurrentLonWidth = 0;
			for (int j = OneLineRangeCharacter +1; j < (int)Servertcpsocket.Log[i].size(); j++)
			{
				outtextxy(37 + CurrentLonWidth, 54 + (CurrentDrawLineLog * 18), Servertcpsocket.Log[i][j]);
				CurrentLonWidth += textwidth(Servertcpsocket.Log[i][j]);
			}
			CurrentDrawLineLog++;
		}
		if (CurrentDrawLineLog >= 13)
		{
			LogRange += 1 + (CurrentDrawLineLog - 13);
		}
	}
}