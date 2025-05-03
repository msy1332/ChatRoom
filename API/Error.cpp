#include "Error.h"

void Error::ShowError()
{
	//����һ
	std::wstring CopyText = Text;
	std::wstring CopyTitle = Title;
	std::thread CreateErrorThread([CopyText, CopyTitle]() {
		MessageBox(GetHWnd(), CopyText.c_str(), CopyTitle.c_str(), MB_OK | MB_ICONERROR);
	});
	CreateErrorThread.detach();//�����߳�
	//������
	//std::thread([CopyText, CopyTitle]() {
	//	MessageBox(GetHWnd(), CopyText.c_str(), CopyTitle.c_str(), MB_OK | MB_ICONERROR);
	//	}).detach();
}

Error::Error(std::wstring Text, std::wstring Title) : Text(Text),Title(Title)
{
	ShowError();
}