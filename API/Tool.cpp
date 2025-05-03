#include "Tool.h"

std::string Tool::wstring_to_string(std::wstring str)
{
	/*
		🧩 函数原型回顾：
		int WideCharToMultiByte(
			UINT   CodePage,         // 【参数1】编码方式
			DWORD  dwFlags,          // 【参数2】标志，一般写0
			LPCWCH lpWideCharStr,    // 【参数3】输入的wchar_t字符串
			int    cchWideChar,      // 【参数4】输入字符个数
			LPSTR  lpMultiByteStr,   // 【参数5】输出char缓冲区
			int    cbMultiByte,      // 【参数6】输出缓冲区大小（字节）
			LPCCH  lpDefaultChar,    // 【参数7】出错时用什么替代字符
			LPBOOL lpUsedDefaultChar // 【参数8】有没有用到替代字符
		);
		📌 每个参数详细解释 + 举例
		✅ 【参数1】CodePage —— 使用哪种编码？,就是你转化后是以哪种编码格式存储到char里面
		这个告诉系统：“我要转成哪种编码的 char”。
		代码页	含义	常用吗？
		CP_ACP	系统默认编码（GBK）	✅常用
		CP_UTF8	UTF-8 编码	✅现代推荐
		CP_OEMCP	控制台窗口用的编码	有时用
		换句话来说就是，CodePage 参数决定了转换后 char 字节流的编码格式。
		✅ 如果你做中文程序，Windows 默认是 GBK，可以用 CP_ACP
		✅ 如果你想跨平台/支持 emoji/国际字符，建议用 CP_UTF8
		✅ 【参数2】dwFlags —— 有没有特殊要求？
		这个控制转换方式。大多数时候你直接写 0 就可以了。
		0：最普通转换
		WC_NO_BEST_FIT_CHARS：不允许“差不多”的字符匹配，如果你填了，那么他就不会用？或者其他的字符去替代，而是将最后一个参数的BOOL类型的值设为TRUE就是告诉你这个字符串不能转，就是最后一个参数传进来一个BOOL类型的变量
		✅ 【参数3】lpWideCharStr —— 输入的宽字符字符串（wchar_t）
		这个是你要转换的字符串，例如：
		std::wstring ws = L"你好";  // wchar_t 类型的字符串
		WideCharToMultiByte(..., ws.c_str(), ...);
		✅ 【参数4】cchWideChar —— 字符串长度（字符个数）
		写 -1：代表这个字符串是以 \0 结尾的（最常见！）
		或者你自己数有多少个字符（不包括结尾 \0）
		一般写 -1 就好，省心。
		✅ 【参数5】lpMultiByteStr —— 转换后的结果放哪？
		这就是 char* 缓冲区，也就是你要放转换结果的地方。
		但是！如果你只是想“先问问转换后多大”，那就：
		lpMultiByteStr = NULL;
		cbMultiByte = 0;
		这是第一步，先问“你需要多大空间”。
		✅ 【参数6】cbMultiByte —— 输出缓冲区的大小（单位：字节）
		如果你是“问大小”，就传 0
		如果你准备好了 char[]，那这里写你开的大小
		✅ 【参数7】lpDefaultChar —— 出错时用什么代替？
		如果某些字符转换不了（比如 emoji 转 GBK），你可以指定用 '?' 之类来代替。
		写 NULL：用系统默认的 '?'
		一般不用特意管它，写 NULL 就行。
		✅ 【参数8】lpUsedDefaultChar —— 有没有用过默认字符？
		系统会把结果写到这个 BOOL* 里
		如果有字符没法转，它会被设为 TRUE
		这个是可选监控项，不写也可以（传 NULL）
	*/
	int len = WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, NULL, 0, NULL, NULL);
	std::string str1(len,0);
	WideCharToMultiByte(CP_ACP, 0, str.c_str(), -1, &str1[0], len, NULL, NULL);
	return str1;
}


std::wstring Tool::string_to_wstring(std::string str)
{
	/*
		🔧 函数原型：
		int MultiByteToWideChar(
		  UINT     CodePage,      // 代码页（编码方式）
		  DWORD    dwFlags,       // 转换选项
		  LPCCH    lpMultiByteStr,// 输入的多字节字符串
		  int      cbMultiByte,   // 输入字符串长度（字节数）
		  LPWSTR   lpWideCharStr, // 输出缓冲区（接收宽字符字符串）
		  int      cchWideChar    // 输出缓冲区大小（字符数，不是字节数）
		);
		🧩 参数详解：
		
		参数名	类型	作用
		CodePage	UINT	指定输入字符串的编码方式。常用：
		🔹CP_ACP：当前系统默认 ANSI 代码页（如 GBK）
		🔹CP_UTF8：UTF-8 编码
		dwFlags	DWORD	控制转换行为的标志位。一般设为 0 即可；也可使用：
		🔸 MB_PRECOMPOSED（默认值）
		🔸 MB_ERR_INVALID_CHARS：遇到非法字符时报错（配合 UTF-8 用）
		lpMultiByteStr	LPCCH	输入的多字节字符串（const char* 类型）
		cbMultiByte	int	输入字符串的字节数。如果是 -1，表示以 null 结尾，函数会自动计算长度（包括结尾的 \0）。
		lpWideCharStr	LPWSTR	用于存放输出的宽字符字符串（wchar_t*）。如果设为 NULL，函数只返回所需长度。
		cchWideChar	int	输出缓冲区的大小（单位是字符数，不是字节数）。如果为 0，表示你只想查询所需大小。
	*/
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
	std::wstring str1(len, 0);
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, &str1[0], len);
	return str1;
}