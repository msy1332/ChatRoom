#define WIN32_LEAN_AND_MEAN 
#include <windows.h>
#include <iostream>
#include <string>
#include <thread>
#include <easyx.h>
#pragma once

class Error
{
	public:
		void ShowError(); //��ʾ������Ϣ����Ϊ������Ϣ����һ���߳�
		Error(std::wstring Text, std::wstring Title); //��ʼ�������
	private:
		std::wstring Text = L""; //��������Ϣ����
		std::wstring Title = L""; //�����ı���
	protected:
};