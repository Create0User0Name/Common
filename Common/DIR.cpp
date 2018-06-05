#include "DIR.h"

DIR::DIR()
{
}

DIR::~DIR()
{
}

/*
功能：		创建目录，只能单级目录
输入参数：	路径
输出参数：	无
返回值：	成功返回true； 失败返回false
*/
bool DIR::CreateDir(const std::string& path) 
{
	MACRO_RETURN_FALSE_IF(path.empty());
	std::vector<std::string> vecStr;
	StringSplit(path, vecStr, "\\/");
	std::string temp = vecStr[0];
	MACRO_RETURN_FALSE_IF(vecStr.size() == 1);
	for (int i = 0; i < (int)vecStr.size()-1; i++)
	{
		temp += "\\";
		temp += vecStr.at(i + 1);
		_mkdir(temp.c_str());
	}
	return true;
}

/*
功能：		返回当前工作路径
输入参数：	无
输出参数：	当前工作目录
返回值：	void
*/
std::string& DIR::GetWorkPath(std::string& path)
{
	char cStrPath[MAXSTRING] = "";
	_getcwd(cStrPath, MAXSTRING-1);
	path = cStrPath;
	return path;
}