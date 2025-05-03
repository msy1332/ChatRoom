#define WIN32_LEAN_AND_MEAN
#include "ClientTcpSocket.h"
#include "../API/Error.h"
#include "../API/Tool.h"
#include "ClientUI.h"
#include <Windows.h>
#include <iostream>
#include <easyx.h>
#include <cstdio>
#include <thread>
using namespace std;

enum State_of_window { // 这是聊天室的三种状态
	Be_beingLogin,//正在登入状态
	LoninSuccessful,//登入成功状态
	Chat_room_status//进入聊天室状态
};

SOCKET Server; //定义了一个套接字
ExMessage msg;//定义消息结构体
bool  Running = true;//程序的运行状态
string Nickname = ""; //进入聊天室的昵称
int SystemStutas = Be_beingLogin;//聊天室的状态

//void Window_movement(HWND hwnd,ExMessage msg)
//{
//	if (msg.message == WM_LBUTTONDOWN && msg.x > 0 && msg.x < 378 && msg.y>0 && msg.y < 22)//判断鼠标是否在上方隐藏标签栏里面并且按下了鼠标的左键，如果按下那就释放一次鼠标控制权，来移动窗口，如果不释放鼠标控制权的话会导致系统不能知道鼠标在哪，来进行移动窗口
//	{
//		ReleaseCapture();//释放一次鼠标控制权
//		SendMessage(hwnd, WM_SYSCOMMAND, SC_MOVE | HTCAPTION, 0);// 发送消息给窗口，要求它模拟点击窗口标题栏那样移动窗口的操作
//		/*
//			1.SendMessage(hwnd, WM_SYSCOMMAND, SC_MOVE | HTCAPTION, 0); 语法解析：
//			  SendMessage() 是 Windows API 中的一个函数，作用是 发送消息给窗口，要求它执行某些操作。其语法是：
//			  函数原型：SendMessage(hwnd, msg, wParam, lParam);
//				hwnd: 目标窗口的句柄（你要操作的窗口）
//				msg: 消息的类型，告诉系统你想要它执行什么操作
//				wParam 和 lParam: 额外的参数，根据消息类型而不同，用来传递与消息相关的附加信息
//				wParam:这是一个标识符，通常是一个常量，告诉系统你想执行哪个操作。例如，SC_MOVE 代表移动窗口，SC_MINIMIZE 代表最小化窗口。
//			2. WM_SYSCOMMAND：系统命令消息
//			WM_SYSCOMMAND 是一个 系统命令消息，告诉窗口系统你要进行某个系统级的操作，比如移动窗口、改变窗口大小、最小化、最大化等。
//			具体来说，WM_SYSCOMMAND 是一个通知窗口系统的消息，窗口系统根据 wParam 和 lParam 的内容来决定执行什么操作。
//			3. SC_MOVE：表示“移动窗口”命令
//			SC_MOVE 是 一个常量，告诉系统：我要移动窗口。它表示你希望窗口进入“移动”状态。
//			这个操作会将窗口从当前位置开始拖动，你可以用鼠标把窗口移动到新的位置。
//			4. HTCAPTION：模拟点击窗口标题栏
//			HTCAPTION 是 一个常量，表示窗口的标题栏（或边框区域）。
//			在这里，HTCAPTION 告诉系统，“我希望像点击窗口标题栏那样拖动窗口”。
//			即使你已经隐藏了窗口的标题栏，调用 HTCAPTION 让系统假装你点击了标题栏，这样就能拖动窗口了。
//			5.lParam 参数
//			lParam 通常用来传递额外的消息信息，在这个 SC_MOVE 的情况下，lParam 不需要用到，所以传递 0 表示没有额外信息。
//			这个参数在大多数情况下没有用（或者用不到）。在处理 SC_MOVE 时，它通常设置为 0。
//		*/
//	}
//}

int main()
{
	//窗口的初始化
	initgraph(400, 500);//创建登入窗口
	setbkmode(TRANSPARENT);//设置背景模式为透明模式，这样绘制出的文字背景就是透明的
	setbkcolor(WHITE);//设置背景颜色
	cleardevice();//清除绘图窗口，并用背景颜色填充整个窗口

	//初始化UI
	ClientUI clientui;
	clientui.InitLoninScreen(); //初始化登录界面
	clientui.InitChatRoomScreen(); //初始化聊天室界面

	//网络的初始化
	ClientTcpSocket Clienttcpsocket;
	Clienttcpsocket.InitClientSocket();

	Tool tool; //工具

	BeginBatchDraw();//开启双缓冲绘图
	while (Running)
	{
		while (peekmessage(&msg, EX_MOUSE | EX_KEY | EX_CHAR))//获取鼠标,键盘和字符消息
		{
			if (SystemStutas == Be_beingLogin)//聊天室的状态为正在登入
			{
				clientui.Ip_Input_Box1.Renewal_and_judgment_ip_input_box_status(msg);
				clientui.Ip_Input_Box1.Read_User_Input_ip_address(msg);
				clientui.Textbox1.RenewalAndJudgmentTextBoxStatus(msg);
				clientui.Textbox1.ReadtUserInputPort(msg);
				clientui.Textbox2.RenewalAndJudgmentTextBoxStatus(msg);
				clientui.Textbox2.ReadtUserInputString(msg);
				if (clientui.LoinButton.Renewal_And_Judgment_Button_Status(msg))
				{
					if (clientui.Ip_Input_Box1.Ip_address_segment_transformation_ip_address() && clientui.Textbox1.Wstring_to_port() && !(clientui.Textbox2.UserInputText.empty()))
					{
						Server = Clienttcpsocket.InitSocket(clientui.Textbox1.port, clientui.Ip_Input_Box1.Ip);
						if (Server != -1)
						{
							SystemStutas = LoninSuccessful;
						}
						else
						{
							SystemStutas = Be_beingLogin;
						}
					}
					else
					{
						Error error(L"请检查ip地址或端口号或昵称的合法性", L"错误");
					}
				}
				/*clientui.SignInButton.Renewal_And_Judgment_Button_Status(msg);*/

				//if (clientui.CloseButton.Renewal_And_Judgment_Button_Status(msg))
				//{
				//	Running = false;
				//}
				/*Window_movement(GetHWnd(), msg);*/
			}
			else if(SystemStutas == LoninSuccessful)
			{
				cout << "create windows" << endl;
				closegraph();
				//窗口的初始化
				initgraph(800, 600);//创建登聊天室口
				setbkmode(TRANSPARENT);//设置背景模式为透明模式，这样绘制出的文字背景就是透明的
				setbkcolor(WHITE);//设置背景颜色
				cleardevice();//清除绘图窗口，并用背景颜色填充整个窗口
				char buf[1024] = "";
				Nickname = tool.wstring_to_string(clientui.Textbox2.UserInputText);
				sprintf(buf, "欢迎%s进入聊天室", Nickname.c_str());
				cout << "UserSend: " << buf << endl;
				if (send(Server, buf, sizeof(buf), 0) == SOCKET_ERROR)
				{
					wstring ErrorStr = L"";
					ErrorStr = L"错误码:" + to_wstring(GetLastError());
					Error error(ErrorStr, L"错误");
					SystemStutas = Be_beingLogin;
				}
				else
				{
					Clienttcpsocket.MessageLast.push_back(L"欢迎我进入聊天室");
					thread RecvThread([&Clienttcpsocket,&clientui]()
					{
						Clienttcpsocket.RecvMessage(Server,SystemStutas);
					});
					RecvThread.detach();
					SystemStutas = Chat_room_status;
				}
			}
			else if(SystemStutas == Chat_room_status)//聊天室的状态
			{
				clientui.MessageTextBox.RenewalAndJudgmentTextBoxStatus(msg);
				if (clientui.MessageTextBox.ReadtUserInputString(msg) && !clientui.MessageTextBox.UserInputText.empty())
				{
					char SendString[1024] = "";
					/*
						注意
						tool.wstring_to_string(clientui.MessageTextBox.UserInputText)这个是一个表达式
						而tool.wstring_to_string()这个函数返回是一个临时对象，当表达式计算完，临时对象的生命周期结束，临时对象会被摧毁，我们必须用一个变量来存储这个临时对象，来延迟这个对象的生命周期
					*/
					string SendMessage1 = tool.wstring_to_string(clientui.MessageTextBox.UserInputText);
					sprintf(SendString, "[%s]:%s", Nickname.c_str(), SendMessage1.c_str());
					if (send(Server, SendString, sizeof(SendString), 0) == SOCKET_ERROR)
					{
						wstring ErrorStr = L"";
						ErrorStr = L"错误码:" + to_wstring(GetLastError());
						Error error(ErrorStr, L"错误");
						SystemStutas = Be_beingLogin;

						closegraph();
						initgraph(400, 500, EX_SHOWCONSOLE);//创建登入窗口
						setbkmode(TRANSPARENT);//设置背景模式为透明模式，这样绘制出的文字背景就是透明的
						setbkcolor(WHITE);//设置背景颜色
						cleardevice();//清除绘图窗口，并用背景颜色填充整个窗口
					}
					else
					{
						/*
							注意
							tool.wstring_to_string(clientui.MessageTextBox.UserInputText)这个是一个表达式
							而tool.wstring_to_string()这个函数返回是一个临时对象，当表达式计算完，临时对象的生命周期结束，临时对象会被摧毁，我们必须用一个变量来存储这个临时对象，来延迟这个对象的生命周期
						*/
						sprintf(SendString, "%s[我]:%s", Nickname.c_str(), SendMessage1.c_str());
						Clienttcpsocket.MessageLast.push_back(tool.string_to_wstring(SendString));
						clientui.MessageTextBox.ResetTextBox(); //重置文本输入框
					}
				}
				clientui.AttachmentButton.Renewal_And_Judgment_Button_Status(msg);
				if (clientui.SendButton.Renewal_And_Judgment_Button_Status(msg) && !clientui.MessageTextBox.UserInputText.empty())
				{
					char SendString[1024] = "";
					/*
						注意
						tool.wstring_to_string(clientui.MessageTextBox.UserInputText)这个是一个表达式
						而tool.wstring_to_string()这个函数返回是一个临时对象，当表达式计算完，临时对象的生命周期结束，临时对象会被摧毁，我们必须用一个变量来存储这个临时对象，来延迟这个对象的生命周期
					*/
					string SendMessage1 = tool.wstring_to_string(clientui.MessageTextBox.UserInputText);
					sprintf(SendString, "[%s]:%s", Nickname.c_str(), SendMessage1.c_str());
					if (send(Server, SendString, sizeof(SendString), 0) == SOCKET_ERROR)
					{
						wstring ErrorStr = L"";
						ErrorStr = L"错误码:" + to_wstring(GetLastError());
						Error error(ErrorStr, L"错误");
						SystemStutas = Be_beingLogin;

						closegraph();
						initgraph(400, 500, EX_SHOWCONSOLE);//创建登入窗口
						setbkmode(TRANSPARENT);//设置背景模式为透明模式，这样绘制出的文字背景就是透明的
						setbkcolor(WHITE);//设置背景颜色
						cleardevice();//清除绘图窗口，并用背景颜色填充整个窗口
					}
					else
					{
						/*
							注意
							tool.wstring_to_string(clientui.MessageTextBox.UserInputText)这个是一个表达式
							而tool.wstring_to_string()这个函数返回是一个临时对象，当表达式计算完，临时对象的生命周期结束，临时对象会被摧毁，我们必须用一个变量来存储这个临时对象，来延迟这个对象的生命周期
						*/
						sprintf(SendString, "%s[我]:%s", Nickname.c_str(), SendMessage1.c_str());
						Clienttcpsocket.MessageLast.push_back(tool.string_to_wstring(SendString));
						clientui.MessageTextBox.ResetTextBox(); //重置文本输入框
					}
				}
			}
		}
		cleardevice();
		if (SystemStutas == Be_beingLogin)
		{
			clientui.DrawLonin();
		}
		else if (SystemStutas == Chat_room_status)
		{
			clientui.DrawChatRoom(Clienttcpsocket);
		}
		FlushBatchDraw();//刷新双缓冲绘图缓冲区
	}
	Clienttcpsocket.CleanClientSocket();
	EndBatchDraw();//关闭双缓冲绘图
	return 0;
}
/*
	#include <windows.h>

int main() {
    MessageBox(
        NULL,                           // 窗口句柄
        L"这是一个错误消息",             // 消息内容
        L"错误",                       // 标题
        MB_ICONERROR | MB_OK            // 图标和按钮
    );
    return 0;
}
*/