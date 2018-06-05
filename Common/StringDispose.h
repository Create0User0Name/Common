/*********************************************************************************
*Copyright(C),2010-2011
*FileName:		//StringDispose.h StringDispose.cpp
*Author:		//shijie
*Version:		//1.0
*Date:			//2018/6/2 22:20
*Description:	//字符串操作，字符串分割，字符串连接，字符串修剪

*Others:		//无
*Function List:
1.void StringSplit(std::string const& str, std::vector<std::string>& strv, std::string const& delim);
	功能：  字符串分割
	参数：  1）待分割字符串
			2）分割后保存向量
			3）分割符
	返回值：void
2.std::string strcat(char const* str1, char const* str2, ...);
	功能：  字符串连接
	参数：  待连接字符串
	返回值：返回连接后的字符串
3.std::string& trim(std::string& str);
	功能：  字符串修剪（截取字符串首尾的空格，制表符，回车，换行）
	参数：  待修剪字符串
	返回值：返回修剪后的字符串

*History:  //修改历史记录列表，每条修改记录应包含修改日期、修改者及修改内容简介
1.Date:
Author:
Modification:
2.…………
**********************************************************************************/

#include <vector>
#include <string>
#include <stdarg.h>
void StringSplit(std::string const& str, std::vector<std::string>& strv, std::string const& delim);
std::string strcat(char const* str1, char const* str2, ...);
std::string& trim(std::string& str);