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
		void ShowError(); //显示错误消息，并为错误消息开启一个线程
		Error(std::wstring Text, std::wstring Title); //初始化错误框
	private:
		std::wstring Text = L""; //错误框的消息内容
		std::wstring Title = L""; //错误框的标题
	protected:
};