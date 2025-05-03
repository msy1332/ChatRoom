#include "Button.h"

//绘制按钮
void Button::Draw_Button()
{
	switch (Buttontype)
	{
		case A_filled_rectangle_with_a_border:
			switch (ButtonStatus)
			{
				case Button_Normal:
					setlinecolor(LineColor.Normal);
					setfillcolor(FillColor.Normal);
					settextcolor(TextColor.Normal);
					settextstyle(Textstyle.TextHeight, Textstyle.TextWidth, Textstyle.Typeface.c_str());
					fillrectangle(Buttonpositionsize.x, Buttonpositionsize.y, Buttonpositionsize.x + Buttonpositionsize.width, Buttonpositionsize.y + Buttonpositionsize.height);
					outtextxy(Centering_Text_X, Centering_Text_Y, Text.c_str());
					break;
				case Button_Suspension:
					setlinecolor(LineColor.Suspension);
					setfillcolor(FillColor.Suspension);
					settextcolor(TextColor.Suspension);
					settextstyle(Textstyle.TextHeight, Textstyle.TextWidth, Textstyle.Typeface.c_str());
					fillrectangle(Buttonpositionsize.x, Buttonpositionsize.y, Buttonpositionsize.x + Buttonpositionsize.width, Buttonpositionsize.y + Buttonpositionsize.height);
					outtextxy(Centering_Text_X, Centering_Text_Y, Text.c_str());
					break;
				case Button_Press:
					setlinecolor(LineColor.Press);
					setfillcolor(FillColor.Press);
					settextcolor(TextColor.Press);
					settextstyle(Textstyle.TextHeight, Textstyle.TextWidth, Textstyle.Typeface.c_str());
					fillrectangle(Buttonpositionsize.x, Buttonpositionsize.y, Buttonpositionsize.x + Buttonpositionsize.width, Buttonpositionsize.y + Buttonpositionsize.height);
					outtextxy(Centering_Text_X, Centering_Text_Y, Text.c_str());
					break;
				default:
					break;
			}
		break;
		case Fill_rectangle_without_border:
			switch (ButtonStatus)
			{
				case Button_Normal:
					setfillcolor(FillColor.Normal);
					settextcolor(TextColor.Normal);
					settextstyle(Textstyle.TextHeight, Textstyle.TextWidth, Textstyle.Typeface.c_str());
					solidrectangle(Buttonpositionsize.x, Buttonpositionsize.y, Buttonpositionsize.x + Buttonpositionsize.width, Buttonpositionsize.y + Buttonpositionsize.height);
					outtextxy(Centering_Text_X, Centering_Text_Y, Text.c_str());
					break;
				case Button_Suspension:
					setfillcolor(FillColor.Suspension);
					settextcolor(TextColor.Suspension);
					settextstyle(Textstyle.TextHeight, Textstyle.TextWidth, Textstyle.Typeface.c_str());
					solidrectangle(Buttonpositionsize.x, Buttonpositionsize.y, Buttonpositionsize.x + Buttonpositionsize.width, Buttonpositionsize.y + Buttonpositionsize.height);
					outtextxy(Centering_Text_X, Centering_Text_Y, Text.c_str());
					break;
				case Button_Press:
					setfillcolor(FillColor.Press);
					settextcolor(TextColor.Press);
					settextstyle(Textstyle.TextHeight, Textstyle.TextWidth, Textstyle.Typeface.c_str());
					solidrectangle(Buttonpositionsize.x, Buttonpositionsize.y, Buttonpositionsize.x + Buttonpositionsize.width, Buttonpositionsize.y + Buttonpositionsize.height);
					outtextxy(Centering_Text_X, Centering_Text_Y, Text.c_str());
					break;
				default:
					break;
			}
		break;
		case A_filled_rounded_rectangle_with_a_border:
			switch (ButtonStatus)
			{
				case Button_Normal:
					setlinecolor(LineColor.Normal);
					setfillcolor(FillColor.Normal);
					settextcolor(TextColor.Normal);
					settextstyle(Textstyle.TextHeight, Textstyle.TextWidth, Textstyle.Typeface.c_str());
					fillroundrect(Buttonpositionsize.x, Buttonpositionsize.y, Buttonpositionsize.x + Buttonpositionsize.width, Buttonpositionsize.y + Buttonpositionsize.height, Buttonpositionsize.ellipsewidth, Buttonpositionsize.ellipseheight);
					outtextxy(Centering_Text_X, Centering_Text_Y, Text.c_str());
					break;
				case Button_Suspension:
					setlinecolor(LineColor.Suspension);
					setfillcolor(FillColor.Suspension);
					settextcolor(TextColor.Suspension);
					settextstyle(Textstyle.TextHeight, Textstyle.TextWidth, Textstyle.Typeface.c_str());
					fillroundrect(Buttonpositionsize.x, Buttonpositionsize.y, Buttonpositionsize.x + Buttonpositionsize.width, Buttonpositionsize.y + Buttonpositionsize.height, Buttonpositionsize.ellipsewidth, Buttonpositionsize.ellipseheight);
					outtextxy(Centering_Text_X, Centering_Text_Y, Text.c_str());
					break;
				case Button_Press:
					setlinecolor(LineColor.Press);
					setfillcolor(FillColor.Press);
					settextcolor(TextColor.Press);
					settextstyle(Textstyle.TextHeight, Textstyle.TextWidth, Textstyle.Typeface.c_str());
					fillroundrect(Buttonpositionsize.x, Buttonpositionsize.y, Buttonpositionsize.x + Buttonpositionsize.width, Buttonpositionsize.y + Buttonpositionsize.height, Buttonpositionsize.ellipsewidth, Buttonpositionsize.ellipseheight);
					outtextxy(Centering_Text_X, Centering_Text_Y, Text.c_str());
					break;
				default:
					break;
			}
		break;
		case Fill_rounded_rectangles_without_borders:
			switch (ButtonStatus)
			{
				case Button_Normal:
					setfillcolor(FillColor.Normal);
					settextcolor(TextColor.Normal);
					settextstyle(Textstyle.TextHeight, Textstyle.TextWidth, Textstyle.Typeface.c_str());
					solidroundrect(Buttonpositionsize.x, Buttonpositionsize.y, Buttonpositionsize.x + Buttonpositionsize.width, Buttonpositionsize.y + Buttonpositionsize.height, Buttonpositionsize.ellipsewidth, Buttonpositionsize.ellipseheight);
					outtextxy(Centering_Text_X, Centering_Text_Y, Text.c_str());
					break;
				case Button_Suspension:
					setfillcolor(FillColor.Suspension);
					settextcolor(TextColor.Suspension);
					settextstyle(Textstyle.TextHeight, Textstyle.TextWidth, Textstyle.Typeface.c_str());
					solidroundrect(Buttonpositionsize.x, Buttonpositionsize.y, Buttonpositionsize.x + Buttonpositionsize.width, Buttonpositionsize.y + Buttonpositionsize.height, Buttonpositionsize.ellipsewidth, Buttonpositionsize.ellipseheight);
					outtextxy(Centering_Text_X, Centering_Text_Y, Text.c_str());
					break;
				case Button_Press:
					setfillcolor(FillColor.Press);
					settextcolor(TextColor.Press);
					settextstyle(Textstyle.TextHeight, Textstyle.TextWidth, Textstyle.Typeface.c_str());
					solidroundrect(Buttonpositionsize.x, Buttonpositionsize.y, Buttonpositionsize.x + Buttonpositionsize.width, Buttonpositionsize.y + Buttonpositionsize.height, Buttonpositionsize.ellipsewidth, Buttonpositionsize.ellipseheight);
					outtextxy(Centering_Text_X, Centering_Text_Y, Text.c_str());
					break;
				default:
					break;
			}
		break;
		default:
		break;
	}
}

//复制按钮
void Button::CopyButton(Button& button)										
{
	this->Text = button.Text;
	this->Textstyle = button.Textstyle;
	this->FillColor = button.FillColor;
	this->LineColor = button.LineColor;
	this->TextColor = button.TextColor;
	this->Buttontype = button.Buttontype;
	this->ButtonStatus = button.ButtonStatus;
	this->Buttonpositionsize = button.Buttonpositionsize;
}

//计算文字居中的坐标
void Button::Compute_Centering_Text_Coordinate()									
{
	settextstyle(Textstyle.TextHeight, Textstyle.TextWidth, Textstyle.Typeface.c_str());
	Text_Width = textwidth(Text.c_str());
	Text_Height = textheight(Text.c_str());
	Centering_Text_X = Buttonpositionsize.x + (Buttonpositionsize.width - Text_Width)/2;
	Centering_Text_Y = Buttonpositionsize.y + (Buttonpositionsize.height -Text_Height)/2;
}

//更新按钮的状态
bool Button::Renewal_And_Judgment_Button_Status(const ExMessage msg)
{
	switch (msg.message)
	{
		case WM_LBUTTONDOWN:
			if (Judgment_Mouse_Button_Inside(msg.x, msg.y))
			{
				ButtonStatus = Button_Press;	
				return 1;
			}
			else
			{
				ButtonStatus = Button_Normal;
				return 0;
			}
		break;
		case WM_LBUTTONUP:
			if (Judgment_Mouse_Button_Inside(msg.x, msg.y))
			{
				ButtonStatus = Button_Suspension;
				return 0;
			}
			else
			{
				ButtonStatus = Button_Normal;
				return 0;
			}
		break;
		default:
			if (Judgment_Mouse_Button_Inside(msg.x, msg.y))
			{
				ButtonStatus = Button_Suspension;
				return 0;
			}
			else
			{
				ButtonStatus = Button_Normal;
				return 0;
			}
		break;
	}
}

//判断鼠标是否在按钮里面
bool Button::Judgment_Mouse_Button_Inside(const int Mouse_X,const int Mouse_Y)	
{
	if (Mouse_X > Buttonpositionsize.x && Mouse_X < Buttonpositionsize.x + Buttonpositionsize.width && Mouse_Y > Buttonpositionsize.y && Mouse_Y < Buttonpositionsize.y +Buttonpositionsize.height) 
	{
		return true;
	}
	else
	{
		return false;
	}	
}