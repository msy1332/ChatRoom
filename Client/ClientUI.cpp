#include "ClientUI.h"
void ClientUI::InitLoninScreen()
{
	/*
			去掉窗口默认的标签栏的方法
			//修改窗口样式，使用HWND窗口句柄数据类型，这个是Windows API 中用于表示窗口句柄（Window Handle）的数据类型，用来获取窗口的句柄
			HWND hwnd = GetHWnd();//获取窗口的句柄
			LONG style = GetWindowLong(hwnd, GWL_STYLE);//使用LONG数据类型来获取窗口的样式,获取GWL_STYLE(标题栏的窗口样式)，HWND代表你要获取哪个窗口的句柄的样式
			注释：
				下面是什么意思呢
				假如 WS_CAPTION(标题栏) 00010000
				假如 获取到的窗口样式style = 00010100   // 表示你当前既有标题栏，又有边框
				我们可以把他WS_CAPTION，style理解为一个 8 位开关集合但真实，是一个真实的 32 位或者 64 位整型，
				在开关集合中1代表开，0代表关
				如果我们现在要关掉第六位也就是标题栏(类比)
				我们先取反用~也就是0取反为1，1取反为0，也就是WS_CAPTION ~00010000 =11101111
				下一步使用按位与操作& 将style = 00010100&(~WS_CAPTION)=00010100&11101111=00000100,按位与两个都是1才是1，否则是0
				这样子就可以实现关闭标题栏的效果
				这其实就是一种巧妙的算法或者说是一种特性
			style &= ~WS_CAPTION;      // 去掉标题栏(WS_CAPTION)
			style &= ~WS_THICKFRAME;   // 去掉可调整大小的边框(WS_THICKFRAME)
			SetWindowLong(hwnd, GWL_STYLE, style);//修改hwnd窗口句柄的标题栏样式，style是你修改完的样式LONG，虽然修改了样式但窗口还没有属刷新
			注释：
				这个函数会让窗口立刻应用你刚刚设置的新样式
				第一个参数是你要更改的窗口的句柄
				第二个参数是控制窗口的 Z 顺序（即哪个窗口在上、哪个在下）。常见值：NULL（不改变），HWND_TOP（置顶）等
				第三个参数是窗口在屏幕上新的位置（左上角的坐标）。如果不改变位置，可用 SWP_NOMOVE
				第四个参数是窗口新的宽高。如果不改变大小，可用 SWP_NOSIZE
				第五个参数是一个或多个选项标志，控制函数行为
				🧩 常见的 uFlags 标志位：
				标志位	含义
				SWP_NOMOVE	不改变窗口位置
				SWP_NOSIZE	不改变窗口大小
				SWP_NOZORDER	不改变窗口的 Z 顺序
				SWP_FRAMECHANGED	强制重新绘制窗口边框样式（这个很重要❗用于刷新窗口样式）
				注意：如果你想“不改变位置”或“不改变大小”，你必须明确加上对应的标志位：
				如果你不加这些标志位，哪怕你填的是 0，也会真的把窗口移动到 (0,0)，变成 0 宽高的窗口！
				结论： 👉 仅仅填 0 不代表“不改变”，
				👉 必须配合使用 SWP_NOMOVE / SWP_NOSIZE 这些标志位，系统才会“忽略”你填的值。
				这样子就实现了关闭标题栏的效果
			SetWindowPos(hwnd, NULL, 0, 0, 400, 500, SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);//这个函数会让窗口立刻应用你刚刚设置的新样式
		*/

	//加载背景图片
	loadimage(&this->LoninBkImage, L"Res/bk2.jpg",400,500);

	//登入按钮的初始化
	this->LoinButton.Text = L"登入";
	this->LoinButton.FillColor.Normal = RGB(0, 162, 232);
	this->LoinButton.TextColor.Normal = WHITE;
	this->LoinButton.FillColor.Suspension =  RGB(153, 217, 234);
	this->LoinButton.TextColor.Suspension = WHITE;
	this->LoinButton.FillColor.Press = RGB(63, 72, 204);
	this->LoinButton.TextColor.Press = WHITE;
	this->LoinButton.Textstyle.TextHeight = 20;
	this->LoinButton.Textstyle.TextWidth = 0;
	this->LoinButton.Textstyle.Typeface = L"宋体";
	this->LoinButton.Buttonpositionsize.x = 150;
	this->LoinButton.Buttonpositionsize.y = 263 +30;
	this->LoinButton.Buttonpositionsize.width = 100;
	this->LoinButton.Buttonpositionsize.height = 50;
	this->LoinButton.Buttonpositionsize.ellipsewidth = 30;
	this->LoinButton.Buttonpositionsize.ellipseheight = 30;
	this->LoinButton.Compute_Centering_Text_Coordinate();
	this->LoinButton.Buttontype = Fill_rounded_rectangles_without_borders;

	////注册按钮的初始化
	//this->SignInButton.CopyButton(this->LoinButton);
	//this->SignInButton.Text = L"注册";
	//this->SignInButton.Buttonpositionsize.x = 250;
	//this->SignInButton.Compute_Centering_Text_Coordinate();

	////关闭按钮的初始化
	//this->CloseButton.Text = L"×";
	//this->CloseButton.FillColor.Normal = WHITE;
	//this->CloseButton.TextColor.Normal = RGB(5,7,8);
	//this->CloseButton.FillColor.Suspension = RGB(232,17,35);
	//this->CloseButton.TextColor.Suspension = WHITE;
	//this->CloseButton.FillColor.Press = RGB(241,112,122);
	//this->CloseButton.TextColor.Press = BLACK;
	//this->CloseButton.Textstyle.TextHeight = 20;
	//this->CloseButton.Textstyle.TextWidth = 0;
	//this->CloseButton.Textstyle.Typeface = L"微软雅黑";
	//this->CloseButton.Buttonpositionsize.x = 378;
	//this->CloseButton.Buttonpositionsize.y = 0;
	//this->CloseButton.Buttonpositionsize.width = 22;
	//this->CloseButton.Buttonpositionsize.height = 22;
	//this->CloseButton.Compute_Centering_Text_Coordinate();
	//this->CloseButton.Buttontype = Fill_rectangle_without_border;

	//ip输入框的初始化
	this->Ip_Input_Box1.Ip_input_box_pos.x = 139;
	this->Ip_Input_Box1.Ip_input_box_pos.y = 90+60;
	this->Ip_Input_Box1.Ip_Input_field_fill_color.EDITOR = WHITE;
	this->Ip_Input_Box1.Ip_Input_field_line_color.EDITOR = RGB(0,120,215);
	this->Ip_Input_Box1.Ip_Input_field_fill_color.Suspension = WHITE;
	this->Ip_Input_Box1.Ip_Input_field_line_color.Suspension = RGB(23,23,23);
	this->Ip_Input_Box1.Ip_Input_field_fill_color.Normal = WHITE;
	this->Ip_Input_Box1.Ip_Input_field_line_color.Normal = RGB(122,122,122);
	this->Ip_Input_Box1.Ip_address_segment.resize(4);
	this->Ip_Input_Box1.Ip_address_segment_len.resize(4);

	//端口文本输入框初始化
	this->Textbox1.TextBoxFill.EDITOR = WHITE;
	this->Textbox1.TextBoxLine.EDITOR = RGB(0, 120, 215);
	this->Textbox1.TextBoxFill.Suspension = WHITE;
	this->Textbox1.TextBoxLine.Suspension = RGB(23, 23, 23);
	this->Textbox1.TextBoxFill.Normal = WHITE;
	this->Textbox1.TextBoxLine.Normal = RGB(122, 122, 122);
	this->Textbox1.Textboxpos.x = 139;
	this->Textbox1.Textboxpos.y = 122+60;
	this->Textbox1.Textboxpos.width = 145;
	this->Textbox1.Len = 5;
	this->Textbox1.ComputeTextMaxTotalWidth();

	//昵称文本输入框初始化
	this->Textbox2.TextBoxFill.EDITOR = WHITE;
	this->Textbox2.TextBoxLine.EDITOR = RGB(0, 120, 215);
	this->Textbox2.TextBoxFill.Suspension = WHITE;
	this->Textbox2.TextBoxLine.Suspension = RGB(23, 23, 23);
	this->Textbox2.TextBoxFill.Normal = WHITE;
	this->Textbox2.TextBoxLine.Normal = RGB(122, 122, 122);
	this->Textbox2.Textboxpos.x = 139;
	this->Textbox2.Textboxpos.y = 180 +60;
	this->Textbox2.Textboxpos.width = 145;
	this->Textbox2.Len = 3;
	this->Textbox2.ComputeTextMaxTotalWidth();
}

void ClientUI::DrawLonin()
{
	putimage(0, 0, &LoninBkImage);

	//setfillcolor(WHITE);
	//solidrectangle(0, 0, 378, 22);

	settextcolor(BLACK);
	settextstyle(18, 0, L"Segoe UI");
	outtextxy(116, 69+60 , L"----------服务器设置---------");

	settextstyle(16, 0, L"Segoe UI");
	outtextxy(116, 93+60 , L"IP:");
	outtextxy(116, 125+60, L"端口:");

	settextstyle(18, 0, L"Segoe UI");
	outtextxy(116, 161+60, L"-----------用户输入-----------");

	settextstyle(16, 0, L"Segoe UI");
	outtextxy(116, 183+60, L"昵称:");

	this->Textbox1.DrawTextBox();
	this->Textbox2.DrawTextBox();
	this->LoinButton.Draw_Button();
	//this->CloseButton.Draw_Button();
	this->Ip_Input_Box1.Draw_ip_input_box();
}

void ClientUI::InitChatRoomScreen()
{
	//closegraph();
	////窗口的初始化
	//initgraph(800, 600, EX_SHOWCONSOLE);//创建登入窗口
	//setbkmode(TRANSPARENT);//设置背景模式为透明模式，这样绘制出的文字背景就是透明的
	//setbkcolor(WHITE);//设置背景颜色
	//cleardevice();//清除绘图窗口，并用背景颜色填充整个窗口
	/*
		去掉窗口默认的标签栏的方法
		//修改窗口样式，使用HWND窗口句柄数据类型，这个是Windows API 中用于表示窗口句柄（Window Handle）的数据类型，用来获取窗口的句柄
		HWND hwnd = GetHWnd();//获取窗口的句柄
		LONG style = GetWindowLong(hwnd, GWL_STYLE);//使用LONG数据类型来获取窗口的样式,获取GWL_STYLE(标题栏的窗口样式)，HWND代表你要获取哪个窗口的句柄的样式
		注释：
			下面是什么意思呢
			假如 WS_CAPTION(标题栏) 00010000
			假如 获取到的窗口样式style = 00010100   // 表示你当前既有标题栏，又有边框
			我们可以把他WS_CAPTION，style理解为一个 8 位开关集合但真实，是一个真实的 32 位或者 64 位整型，
			在开关集合中1代表开，0代表关
			如果我们现在要关掉第六位也就是标题栏(类比)
			我们先取反用~也就是0取反为1，1取反为0，也就是WS_CAPTION ~00010000 =11101111
			下一步使用按位与操作& 将style = 00010100&(~WS_CAPTION)=00010100&11101111=00000100,按位与两个都是1才是1，否则是0
			这样子就可以实现关闭标题栏的效果
			这其实就是一种巧妙的算法或者说是一种特性
		style &= ~WS_CAPTION;      // 去掉标题栏(WS_CAPTION)
		style &= ~WS_THICKFRAME;   // 去掉可调整大小的边框(WS_THICKFRAME)
		SetWindowLong(hwnd, GWL_STYLE, style);//修改hwnd窗口句柄的标题栏样式，style是你修改完的样式LONG，虽然修改了样式但窗口还没有属刷新
		注释：
			这个函数会让窗口立刻应用你刚刚设置的新样式
			第一个参数是你要更改的窗口的句柄
			第二个参数是控制窗口的 Z 顺序（即哪个窗口在上、哪个在下）。常见值：NULL（不改变），HWND_TOP（置顶）等
			第三个参数是窗口在屏幕上新的位置（左上角的坐标）。如果不改变位置，可用 SWP_NOMOVE
			第四个参数是窗口新的宽高。如果不改变大小，可用 SWP_NOSIZE
			第五个参数是一个或多个选项标志，控制函数行为
			🧩 常见的 uFlags 标志位：
			标志位	含义
			SWP_NOMOVE	不改变窗口位置
			SWP_NOSIZE	不改变窗口大小
			SWP_NOZORDER	不改变窗口的 Z 顺序
			SWP_FRAMECHANGED	强制重新绘制窗口边框样式（这个很重要❗用于刷新窗口样式）
			注意：如果你想“不改变位置”或“不改变大小”，你必须明确加上对应的标志位：
			如果你不加这些标志位，哪怕你填的是 0，也会真的把窗口移动到 (0,0)，变成 0 宽高的窗口！
			结论： 👉 仅仅填 0 不代表“不改变”，
			👉 必须配合使用 SWP_NOMOVE / SWP_NOSIZE 这些标志位，系统才会“忽略”你填的值。
			这样子就实现了关闭标题栏的效果
		SetWindowPos(hwnd, NULL, 0, 0, 400, 500, SWP_NOMOVE | SWP_NOZORDER | SWP_FRAMECHANGED);//这个函数会让窗口立刻应用你刚刚设置的新样式
	*/

	//加载背景图片
	loadimage(&this->ChatRoomBkImage, L"Res/bk2.jpg", 800, 600);

	//消息输入框的初始化
	this->MessageTextBox.TextBoxFill.EDITOR = WHITE;
	this->MessageTextBox.TextBoxLine.EDITOR = RGB(0, 120, 215);
	this->MessageTextBox.TextBoxFill.Suspension = WHITE;
	this->MessageTextBox.TextBoxLine.Suspension = RGB(23, 23, 23);
	this->MessageTextBox.TextBoxFill.Normal = WHITE;
	this->MessageTextBox.TextBoxLine.Normal = RGB(122, 122, 122);
	this->MessageTextBox.TextBoxTips = L"请输入你要发送的消息";
	this->MessageTextBox.Textboxpos.x = 20;
	this->MessageTextBox.Textboxpos.y = 568;
	this->MessageTextBox.Textboxpos.width = 580;
	this->MessageTextBox.ComputeTextMaxTotalWidth();

	//发送消息按钮的初始化
	this->SendButton.FillColor.Normal = RGB(86, 126, 255);
	this->SendButton.FillColor.Suspension = RGB(0, 64, 253);
	this->SendButton.FillColor.Press = RGB(0, 51, 204);
	this->SendButton.TextColor.Normal = WHITE;
	this->SendButton.TextColor.Suspension = WHITE;
	this->SendButton.TextColor.Press = WHITE;
	this->SendButton.Buttonpositionsize.x = 610;
	this->SendButton.Buttonpositionsize.y = 568;
	this->SendButton.Buttonpositionsize.width = 80;
	this->SendButton.Buttonpositionsize.height = 22;
	this->SendButton.Text = L">";
	this->SendButton.Textstyle.TextHeight = 13;
	this->SendButton.Textstyle.TextWidth = 0;
	this->SendButton.Textstyle.Typeface = L"宋体";
	this->SendButton.Compute_Centering_Text_Coordinate();
	this->SendButton.Buttontype = Fill_rectangle_without_border;

	//附件按钮的初始化
	this->AttachmentButton.CopyButton(SendButton);
	this->AttachmentButton.Buttonpositionsize.x = 700;
	this->AttachmentButton.Text = L"📁";
}

void ClientUI::DrawChatRoom(ClientTcpSocket Clienttcpsocket)
{
	putimage(0, 0, &ChatRoomBkImage); //绘制背景图片
	
	//绘制消息显示框)
	setfillcolor(WHITE);
	setlinecolor(BLACK);
	fillrectangle(20, 5, 20 + 760, 5 + 558);

	this->PrintfMessage(Clienttcpsocket); //绘制消息
	this->MessageTextBox.DrawTextBox(); //绘制消息文本输入框
	this->SendButton.Draw_Button(); //绘制发送消息按钮
	this->AttachmentButton.Draw_Button(); //绘制附件按钮
}

void ClientUI::PrintfMessage(ClientTcpSocket Clienttcpsocket)
{
	static int MessageRange = 0; //消息的显示范围
	int CurrentDrawLineMessage = 0;//当前绘制了多少行消息
	settextcolor(BLACK);
	settextstyle(18, 0, L"宋体");
	for (int i = MessageRange; i < MessageRange + 31 && i < Clienttcpsocket.MessageLast.size(); i++)
	{
		int MeassWidth = 0; //当前绘制的消息的总宽度
		int MessageLine = 1; //当前绘制的消息需要多少行来显示该消息
		int OneLineMessageLen = 0; //第一行消息显示多少个字符
		for (int j = 0; j < Clienttcpsocket.MessageLast[i].size(); j++)
		{
			if (MeassWidth + textwidth(Clienttcpsocket.MessageLast[i][j]) > 760)
			{
				MessageLine = 2;
				OneLineMessageLen = j - 1;
				//std::cout << "break" << std::endl;
				//std::cout << "MessageLine: " << MessageLine << "\t" << "OneLineMessageLen:" << OneLineMessageLen << std::endl;
				break;
			}
			else
			{
				MeassWidth += textwidth(Clienttcpsocket.MessageLast[i][j]);
			}
		}

		if (MessageLine == 1)
		{
			outtextxy(20, 5 + (CurrentDrawLineMessage * 18), (Clienttcpsocket.MessageLast[i]).c_str());
			CurrentDrawLineMessage++;
		}
		else if (MessageLine == 2)
		{
			int CurrentLineMessageWidth = 0;
			for (int j = 0; j <= OneLineMessageLen; j++)
			{
				outtextxy(20 + CurrentLineMessageWidth, 5 + (CurrentDrawLineMessage * 18), Clienttcpsocket.MessageLast[i][j]);
				CurrentLineMessageWidth += textwidth(Clienttcpsocket.MessageLast[i][j]);
			}

			CurrentDrawLineMessage++;
			CurrentLineMessageWidth = 0;
			for (int j = OneLineMessageLen + 1; j < Clienttcpsocket.MessageLast[i].size(); j++)
			{
				outtextxy(20 + CurrentLineMessageWidth, 5 + (CurrentDrawLineMessage * 18), Clienttcpsocket.MessageLast[i][j]);
				CurrentLineMessageWidth += textwidth(Clienttcpsocket.MessageLast[i][j]);
			}
			CurrentDrawLineMessage++;
		}
		if (CurrentDrawLineMessage >= 31)
		{
			MessageRange += 1 + (CurrentDrawLineMessage - 31);
		}
	}
}