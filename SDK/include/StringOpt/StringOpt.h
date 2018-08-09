/*********************************************************************************
*Copyright(C),2010-2011
*FileName:		//StringDispose.h StringDispose.cpp
*Author:		//shijie
*Version:		//1.0
*Date:			//2018/6/2 22:20
*Description:	//字符串操作，字符串分割，字符串连接，字符串修剪

*History:  //修改历史记录列表，每条修改记录应包含修改日期、修改者及修改内容简介
1.Date:
Author:
Modification:
2.…………
**********************************************************************************/

#include <vector>
#include <string>
#include <stdarg.h>
#include <comm\common.h>

/*
功能：		字符串拆分
输入参数：	str待拆分字符串；delim分隔符
输出参数：	输出拆分后的字符串
返回值：	无
*/
void StringSplit(std::string const& str, std::vector<std::string>& strv, std::string const& delim);

/*
功能：		字符串拼接
输入参数：	字符串1， 字符串2， ..., NULL
输出参数：	无
返回值：	返回拼接后的字符串
*/
std::string strcat(char const* str1, char const* str2, ...);

/*
功能：		字符串修剪（截取字符串首尾的空格，制表符，回车，换行）
输入参数：	待修剪字符串
输出参数：	无
返回值：	返回被修剪后的字符串本身
*/
std::string& trim(std::string& str);

/*
功能:		字符串中大写字符转小写
输入参数:	待处理字符串
输出参数:	处理后字符串
返回值:		void
*/
void StringLower(std::string& str);

/*
功能:		字符串中小写转大写
输入参数:	待处理字符串
输出参数:	处理后字符串
返回值:		void
*/
void StringUpper(std::string& str);

/*
功能:		去除字符串中非字母字符
输入参数:	待处理字符串
输出参数:	无
返回值:		返回处理后的字符串
*/
std::string DislodgeStringNotChar(std::string& str);

/*
功能:		去除字符串中空格
输入参数:	待处理字符串
输出参数:	无
返回值:		返回处理后的字符串
*/
std::string DislodgeStringSpace(std::string& str);