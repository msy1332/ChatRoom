#include "TextBox.h"

//绘制提示文本
void TextBox::DrawTips()
{
	if (UserInputText.empty())
	{
		settextcolor(BLACK);
		settextstyle(18, 0, L"Segoe UI");
		outtextxy(Textboxpos.x + 6, Textboxpos.y + 2,TextBoxTips.c_str());
	}
}

//绘制光标
void TextBox::DrawCursor()
{
	static int LastTime =0;
	static int CurrentTime =0;
	static int Interval = 500;
	static bool Reveal = true;

	CurrentTime = clock();
	if (CurrentTime - LastTime >= Interval)
	{
		if (Reveal)
		{
			Reveal = false;
		}
		else
		{
			Reveal = true;
		}
		LastTime = CurrentTime;
	}
	if (Reveal)
	{
		setlinecolor(BLACK);
		line(Textboxpos.x + 6 + TextTotal, Textboxpos.y + 3, Textboxpos.x + 6 + TextTotal, Textboxpos.y + 19);
	}
}

//绘制输入的文字
void TextBox::DrawInputText()
{
	settextcolor(BLACK);
	settextstyle(18, 0, L"Segoe UI");
	outtextxy(Textboxpos.x + 6, Textboxpos.y + 2, UserInputText.c_str());
}

//绘制文本输入框
void TextBox::DrawTextBox()
{
	switch (TextbosStatus)
	{
		case TextBoxEDITOR:
			setlinecolor(TextBoxLine.EDITOR);
			setfillcolor(TextBoxFill.EDITOR);
			fillrectangle(Textboxpos.x, Textboxpos.y, Textboxpos.x + Textboxpos.width, Textboxpos.y + TextBoxFixedHeight);
			DrawInputText();
			DrawCursor();
			DrawTips();
			break;
		case TextBoxSuspension:
			setlinecolor(TextBoxLine.Suspension);
			setfillcolor(TextBoxFill.Suspension);
			fillrectangle(Textboxpos.x, Textboxpos.y, Textboxpos.x + Textboxpos.width, Textboxpos.y + TextBoxFixedHeight);
			DrawInputText();
			DrawTips();
			break;
		case TextBoxNormal:
			setlinecolor(TextBoxLine.Normal);
			setfillcolor(TextBoxFill.Normal);
			fillrectangle(Textboxpos.x, Textboxpos.y, Textboxpos.x + Textboxpos.width, Textboxpos.y + TextBoxFixedHeight);
			DrawInputText();
			DrawTips();
			break;
	}
}

//计算文字的最大总宽度
void TextBox::ComputeTextMaxTotalWidth()
{
	TextMaxTotalWidth = Textboxpos.width - 12;
}

//读取用户输入
bool TextBox::ReadtUserInputString(const ExMessage msg)
{
	settextstyle(18, 0, L"Segoe UI");
	if (TextbosStatus == TextBoxEDITOR && msg.message == WM_CHAR)
	{
		wchar_t ch = (wchar_t)msg.wParam;
		if (ch == '\b' && !UserInputText.empty())
		{
			TextTotal -= textwidth(UserInputText.back());
			UserInputText.pop_back();	
			TextLen--;
		}
		else if ((Len != 0 ? (TextLen + 1 <= Len && TextTotal + textwidth(ch) < TextMaxTotalWidth) : (TextTotal + textwidth(ch) < TextMaxTotalWidth))&& ch != '\b' && ch != '\r' && ch != '\n')
		{
			TextTotal += textwidth(ch);
			UserInputText.push_back(ch);
			TextLen++;
		}
		else if(ch == '\n' || ch == '\r')
		{
			return 1;
		}
	}
	return 0;
}

void TextBox::ReadtUserInputPort(const ExMessage msg)
{
	settextstyle(18, 0, L"Segoe UI");
	if (TextbosStatus == TextBoxEDITOR && msg.message == WM_CHAR)
	{
		wchar_t ch = (wchar_t)msg.wParam;
		if (ch == '\b' && !UserInputText.empty())
		{
			TextTotal -= textwidth(UserInputText.back());
			UserInputText.pop_back();
			TextLen--;
		}
		else if (TextLen + 1 <= 5 && ch != '\b' && ch != '\r' && ch >=48 && ch <= 57)
		{
			TextTotal += textwidth(ch);
			UserInputText.push_back(ch);
			TextLen++;
		}
	}
}

//更新并判断文本输入框的状态
void TextBox::RenewalAndJudgmentTextBoxStatus(const ExMessage msg)
{
	if (TextbosStatus != TextBoxEDITOR)
	{
		if (JudgmentMouseTextBoxInside(msg.x, msg.y))
		{
			if (msg.message == WM_LBUTTONDOWN)
			{	
				TextbosStatus = TextBoxEDITOR;
			}
			else
			{
				TextbosStatus = TextBoxSuspension;
			}
		}
		else
		{
			TextbosStatus = TextBoxNormal;
		}
	}
	else if (TextbosStatus == TextBoxEDITOR && !JudgmentMouseTextBoxInside(msg.x, msg.y) && msg.message == WM_LBUTTONDOWN)
	{
		TextbosStatus = TextBoxNormal;
	}
}

//判断鼠标是否在文本输入框的里面
bool TextBox::JudgmentMouseTextBoxInside(const int x, const int y)
{
	return x > Textboxpos.x && x< Textboxpos.x + Textboxpos.width && y>Textboxpos.y && y < Textboxpos.y + TextBoxFixedHeight;
}

bool TextBox::Wstring_to_port()
{
	bool Legal = true;
	std::string PortString = "";
	int Port = 0;
	if (!UserInputText.empty())
	{
		PortString = tool.wstring_to_string(UserInputText);
		Port = std::stoi(PortString);
		if (Port < 0 || Port > 65535)
		{
			Legal = false;
		}
	}
	else
	{
		Legal = false;
	}
	if (Legal)
	{
		port = (u_short)Port;
		/*port = static_cast<u_short>(Port);*/
		std::cout << Port << std::endl;
	}
	return Legal;
}

//重置输入框
void TextBox::ResetTextBox()
{
	this->TextLen = 0;
	this->TextTotal = 0;
	this->UserInputText.clear();
}