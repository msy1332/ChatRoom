#define WIN32_LEAN_AND_MEAN
#include "../API/Error.h"
#include <windows.h>
#include <iostream>
#include <string>
#pragma once

class Tool
{
	public:
		//std::wchar_t char_to_wchar_t(); //将char转化为whar_t,也就是将宽字节字符转化为多字节字符
		std::string wstring_to_string(std::wstring str); //将宽字节字符串转化为多字节字符串
		std::wstring string_to_wstring(std::string str);//将string转化为wstring,也就是将多字节字符串转化为宽字节字符串
	private:
	protected:
};