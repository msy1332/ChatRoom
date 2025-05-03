#include "Ip_input_box_control.h"

//���ƹ��
void Ip_input_box::Draw_Cursor()
{
	static int LastTime = 0; //��һ�εĻ���ʱ��
	static int CurrentTiem = 0; //��ǰʱ��
	static int Reveal = true; //�Ƿ���ʾ���
	static int Interval = 500; //ʱ����,���Ǹ����ٺ�����˸һ�ι��

	CurrentTiem = clock();
	if (CurrentTiem - LastTime >= Interval)
	{
		if (Reveal)
		{
			Reveal = false;
		}
		else
		{
			Reveal = true;
		}
		LastTime = CurrentTiem;
	}
	
	if (Reveal)
	{
		setlinecolor(BLACK);
		line(Ip_input_box_pos.x+ Outtextx + CursorX, Ip_input_box_pos.y+ Outtexty, Ip_input_box_pos.x + Outtextx + CursorX, Ip_input_box_pos.y + 18);
	}
}

//����ip�����
void Ip_input_box::Draw_ip_input_box()
{
	switch (Ip_input_box_status)
	{
		case IP_address_input_box_EDITOR:
			setlinecolor(Ip_Input_field_line_color.EDITOR);
			setfillcolor(Ip_Input_field_fill_color.EDITOR);
			fillrectangle(Ip_input_box_pos.x, Ip_input_box_pos.y, Ip_input_box_pos.x + IpWidth, Ip_input_box_pos.y + IpHeight);
			Draw_ip_address_segment();
			Draw_Cursor();
		break;
		case IP_address_input_box_Suspension:
			setlinecolor(Ip_Input_field_line_color.Suspension);
			setfillcolor(Ip_Input_field_fill_color.Suspension);
			fillrectangle(Ip_input_box_pos.x, Ip_input_box_pos.y, Ip_input_box_pos.x + IpWidth, Ip_input_box_pos.y + IpHeight);
			Draw_ip_address_segment();
		break;
		case IP_address_input_box_Normal:
			setlinecolor(Ip_Input_field_line_color.Normal);
			setfillcolor(Ip_Input_field_fill_color.Normal);
			fillrectangle(Ip_input_box_pos.x, Ip_input_box_pos.y, Ip_input_box_pos.x + IpWidth, Ip_input_box_pos.y + IpHeight);
			Draw_ip_address_segment();
		break;
	}
}

//����ip��ַ
void Ip_input_box::Read_User_Input_ip_address(const ExMessage msg)
{
	if (Ip_input_box_status == IP_address_input_box_EDITOR)
	{
		if(msg.message==WM_CHAR)
		{
			wchar_t ch = (wchar_t)msg.wParam;
			if ((ch >= 48 && ch <= 57) || ch == '\b')
			{
				if (ch == '\b')
				{
					if (!Ip_address_segment[Current_ip_address_segment].empty())
					{
						CursorX -= textwidth(Ip_address_segment[Current_ip_address_segment].back());
						Ip_address_segment[Current_ip_address_segment].pop_back();
						Ip_address_segment_len[Current_ip_address_segment]--;
						Ip_address_segment_size--;
					}
					else if (Ip_address_segment[Current_ip_address_segment].empty() && Current_ip_address_segment != 0)
					{
						Current_ip_address_segment--;
						Ip_address_segment[Current_ip_address_segment].pop_back();
						CursorX = Current_ip_address_segment * Ip_address_segment_width + textwidth(Ip_address_segment[Current_ip_address_segment].c_str());
						Ip_address_segment_len[Current_ip_address_segment]--;
						Ip_address_segment_size--;
					}
				}
				else
				{
					if (Ip_address_segment_size + 1 <= 12 && Ip_address_segment_len[Current_ip_address_segment] + 1 <= 3)
					{
						CursorX += textwidth(ch);
						Ip_address_segment[Current_ip_address_segment].push_back(ch);
						Ip_address_segment_len[Current_ip_address_segment]++;
						Ip_address_segment_size++;
					}
					if (Ip_address_segment_len[Current_ip_address_segment] == 3 && Current_ip_address_segment != 3)
					{
						Current_ip_address_segment++;
						CursorX = Current_ip_address_segment * Ip_address_segment_width;
					}
				}
			}
		}
		else if(msg.message == WM_KEYDOWN)
		{
			if (msg.vkcode == VK_RIGHT && Current_ip_address_segment !=3 && !Ip_address_segment[Current_ip_address_segment].empty())
			{
				Current_ip_address_segment++;
				CursorX = Current_ip_address_segment * Ip_address_segment_width;
			}
		}
	}
}

//����ip��ַ�Σ��Լ�ip��ַ�εķָ�
void Ip_input_box::Draw_ip_address_segment()
{
	settextcolor(BLACK);
	settextstyle(16, 0, L"Segoe UI");
	outtextxy(Ip_input_box_pos.x + Ip_address_segment_width, Ip_input_box_pos.y + 5, L".");
	outtextxy(Ip_input_box_pos.x + Ip_address_segment_width * 2, Ip_input_box_pos.y + 5, L".");
	outtextxy(Ip_input_box_pos.x + Ip_address_segment_width * 3, Ip_input_box_pos.y + 5, L".");
	outtextxy(Ip_input_box_pos.x + Outtextx, Ip_input_box_pos.y + Outtexty, Ip_address_segment[0].c_str());
	outtextxy(Ip_input_box_pos.x + Outtextx + Ip_address_segment_width, Ip_input_box_pos.y + Outtexty, Ip_address_segment[1].c_str());
	outtextxy(Ip_input_box_pos.x + Outtextx + Ip_address_segment_width * 2, Ip_input_box_pos.y + Outtexty, Ip_address_segment[2].c_str());
	outtextxy(Ip_input_box_pos.x + Outtextx + Ip_address_segment_width * 3, Ip_input_box_pos.y + Outtexty, Ip_address_segment[3].c_str());
}

//���²��ж�ip������״̬
void Ip_input_box::Renewal_and_judgment_ip_input_box_status(const ExMessage msg)
{
	if (Ip_input_box_status != IP_address_input_box_EDITOR)
	{
		if (Judgment_mouse_ip_input_box_inside(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{
				Ip_input_box_status = IP_address_input_box_EDITOR;
			}
			else
			{
				Ip_input_box_status = IP_address_input_box_Suspension;
			}
		}
		else
		{
			Ip_input_box_status = IP_address_input_box_Normal;
		}
	}
	else
	{
		if (!Judgment_mouse_ip_input_box_inside(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
		{
			Ip_input_box_status = IP_address_input_box_Normal;
		}
	}
}

//�ж�����Ƿ���IP���������
bool Ip_input_box::Judgment_mouse_ip_input_box_inside(const int x, const int y)
{
	return x > Ip_input_box_pos.x && x< Ip_input_box_pos.x + IpWidth && y >Ip_input_box_pos.y && y < Ip_input_box_pos.y + IpHeight;
}


//��ip��ַ��ת��Ϊip��ַ
bool Ip_input_box::Ip_address_segment_transformation_ip_address()
{
	bool Legal = true; //���ip��ַ���Ƿ�Ϸ�
	for (int i = 0; i < 4; i++)
	{
		std::string Ip_address_segment_String = tool.wstring_to_string(Ip_address_segment[i]);
		if (Ip_address_segment[i].empty() || std::stoi(Ip_address_segment_String) > 255)
		{
			Legal = false;
			break;
		}
	}
	if (Legal)
	{
		Wip = Ip_address_segment[0] + L"." + Ip_address_segment[1] + L"." + Ip_address_segment[2] + L"." + Ip_address_segment[3];
		Ip = tool.wstring_to_string(Wip);
		std::cout << Ip << std::endl;
	}
	return Legal;
}