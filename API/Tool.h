#define WIN32_LEAN_AND_MEAN
#include "../API/Error.h"
#include <windows.h>
#include <iostream>
#include <string>
#pragma once

class Tool
{
	public:
		//std::wchar_t char_to_wchar_t(); //��charת��Ϊwhar_t,Ҳ���ǽ����ֽ��ַ�ת��Ϊ���ֽ��ַ�
		std::string wstring_to_string(std::wstring str); //�����ֽ��ַ���ת��Ϊ���ֽ��ַ���
		std::wstring string_to_wstring(std::string str);//��stringת��Ϊwstring,Ҳ���ǽ����ֽ��ַ���ת��Ϊ���ֽ��ַ���
	private:
	protected:
};