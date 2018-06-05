#include "DIR.h"

DIR::DIR()
{
}

DIR::~DIR()
{
}

/*
���ܣ�		����Ŀ¼��ֻ�ܵ���Ŀ¼
���������	·��
���������	��
����ֵ��	�ɹ�����true�� ʧ�ܷ���false
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
���ܣ�		���ص�ǰ����·��
���������	��
���������	��ǰ����Ŀ¼
����ֵ��	void
*/
std::string& DIR::GetWorkPath(std::string& path)
{
	char cStrPath[MAXSTRING] = "";
	_getcwd(cStrPath, MAXSTRING-1);
	path = cStrPath;
	return path;
}