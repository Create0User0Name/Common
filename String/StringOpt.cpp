#include "StringOpt.h"

/*
功能：		字符串拆分
输入参数：	str待拆分字符串；delim分隔符
输出参数：	输出拆分后的字符串
返回值：	无
*/
void StringSplit(std::string const& str, std::vector<std::string>& strv, std::string const& delim) 
{
	char *temp = new char[str.size() + 1];
	strcpy_s(temp, str.size()+1, str.c_str());
	char *nextStr = NULL;
	for (char *token = strtok_s(temp, delim.c_str(), &nextStr); token; token = strtok_s(NULL, delim.c_str(), &nextStr)) {
		std::string part = token;
		strv.push_back(part);
		if ( ! ( (token += strlen(token)) - temp < (int)str.size()) ) {
			break;
		}
	}
	delete temp;
}

/*
功能：		字符串拼接
输入参数：	字符串1， 字符串2， ..., NULL
输出参数：	无
返回值：	返回拼接后的字符串
*/
std::string strcat(char const* str1, char const* str2, ...) {
	std::string str = str1;
	str += str2;

	//变长参数表
	va_list ap;
	//用str2以后的参数初始化变长参数表
	va_start(ap, str2);
	char const* strx = NULL;
	while (strx = va_arg(ap, char const*))
		str += strx;
	va_end(ap);
	return str;
}

/*
功能：		字符串修剪（截取字符串首尾的空格，制表符，回车，换行）
输入参数：	待修剪字符串
输出参数：	无
返回值：	返回被修剪后的字符串本身
*/
std::string& trim(std::string& str)
{
	std::string::size_type first = str.find_first_not_of(" \t\r\n");
	std::string::size_type last = str.find_last_not_of(" \t\r\n");

	if (first == std::string::npos || last == std::string::npos)
		str.clear();
	else
		str = str.substr(first, last - first + 1);
	return str;
}

/*
功能:		字符串中大写字符转小写
输入参数:	待处理字符串
输出参数:	处理后字符串
返回值:		void
*/
void StringLower(std::string& str)
{
	MACRO_RETURN_IF(str.empty());
	char* cpstr = new char[str.size()+1]();
	for(int i = 0; i < (int)str.size(); i++)
	{
		cpstr[i] = tolower(str.at(i));
	}
	str.clear();
	str = cpstr;
	delete cpstr;
	cpstr = NULL;
}

/*
功能:		字符串中小写转大写
输入参数:	待处理字符串
输出参数:	处理后字符串
返回值:		void
*/
void StringUpper(std::string& str)
{
	MACRO_RETURN_IF(str.empty());
	char* cpstr = new char[str.size()+1]();
	for(int i = 0; i < (int)str.size(); i++)
	{
		cpstr[i] = toupper(str.at(i));
	}
	str.clear();
	str = cpstr;
	delete cpstr;
	cpstr = NULL;
}

/*
功能:		去除字符串中非字母字符
输入参数:	待处理字符串
输出参数:	无
返回值:		返回处理后的字符串
*/
std::string DislodgeStringNotChar(std::string& str)
{
	MACRO_RETURN_NULLSTR_IF(str.empty());
	char* cpstr = new char[str.size()+1]();
	for(int i = 0, y = 0; i < (int)str.size(); i++)
	{
		if( isalpha(str.at(i)) ) //是字母字符时
		{
			cpstr[y++] = str.at(i);
		}
	}
	std::string retstr(cpstr);
	delete cpstr;
	cpstr = NULL;
	return retstr;
}

/*
功能:		去除字符串中空格
输入参数:	待处理字符串
输出参数:	无
返回值:		返回处理后的字符串
*/
std::string DislodgeStringSpace(std::string& str)
{
	MACRO_RETURN_NULLSTR_IF(str.empty());
	char* cpstr = new char[str.size()+1]();
	for(int i = 0, y = 0; i < (int)str.size(); i++)
	{
		if( !isspace(str.at(i)) ) //不是空格时
		{
			cpstr[y++] = str.at(i);
		}
	}
	std::string retstr(cpstr);
	delete cpstr;
	cpstr = NULL;
	return retstr;
}