#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <windows.h>
#include <direct.h>
//#include <unistd.h> //UNIX

#include <Dir\Dir.h>
#include <comm\common.h>
#include <StringOpt\StringOpt.h>
DIR::DIR()
{
}

bool DIR::CreateDir(const std::string& path) 
{
	MACRO_RETURN_FALSE_IF(path.empty());
	std::vector<std::string> vecStr;
	StringSplit(path, vecStr, "\\/");
	std::string temp = vecStr[0];
	MACRO_RETURN_FALSE_IF(vecStr.size() == 1);
	//循环创建
	for (int i = 0; i < (int)vecStr.size()-1; i++)
	{
		temp += "\\";
		temp += vecStr.at(i + 1);
		_mkdir(temp.c_str());
	}
	return true;
}

std::string& DIR::GetWorkPath(std::string& path)
{
	char cStrPath[STRING_MAX] = "";
	_getcwd(cStrPath, STRING_MAX-1);
	path = cStrPath;
	return path;
}


/*FindFileName 类*/
FindFileName::FindFileName(char const* fPath, char const* fName = "*.*") 
{
	//初始化
	init(fPath, fName);
}

//////////////////////////////////////Public Function////////////////////////////////////
//主函数
void FindFileName::Find(void){
	Find_Next(m_fPath);
}
//重载主函数, 可以重新定义查找路径和文件名
void FindFileName::Find(char const* fPath, char const* fName){
	init(fPath, fName);
	Find_Next(m_fPath);
}
//返回文件数量
int FindFileName::GetFileCount(void) const{
	return mList_fName.size();
}
//返回查找到的文件列表
const list<string>& FindFileName::GetResult(void)const{
	return mList_fName;
}
//重载输出运算符
ostream& operator <<(ostream& os, list<string> const& fn){
	for(list<string>::const_iterator it = fn.begin(); it != fn.end(); it++)
		os << *it << endl;
	return os;
}
ostream& operator <<(ostream& os, FindFileName const& fn)
{
	const list<string>& ls = fn.GetResult();
	os << ls;
	return os;
}

/////////////////////////////////////Private Function///////////////////////////////////
void FindFileName::Find_Next(string &path){
	WIN32_FIND_DATA wfd = {0};
	std::string temp = path + "/*.*"; //设置查询路径 
	HANDLE hFind = FindFirstFile(temp.c_str(), &wfd);
	if(INVALID_HANDLE_VALUE == hFind){
		char szBuf[128] = {0};
		ErrorInfo(szBuf);
		mList_fName.push_back("[" + path + "]" + szBuf);
		return;
	}
	BOOL goFind = TRUE;
	while(goFind){
		if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){//目录
			if(strcmp(wfd.cFileName, ".") && strcmp(wfd.cFileName, "..")){
				temp = path + '/' + wfd.cFileName;
				Find_Next( temp );	//递归查找
			}
		}
		else{ //文件
			FileCompare(path, wfd.cFileName);  //比对匹配文件
		}
		goFind = FindNextFile(hFind, &wfd);
	}
	FindClose(hFind);
}

//对查询结果错误处理
void FindFileName::ErrorInfo(char *szBuf){
	DWORD err = GetLastError(); //获取错误码
	LPVOID lpMsgBuf;
	//获得错误信息
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, err, 
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR) &lpMsgBuf, 0, NULL);
	sprintf_s(szBuf, 128, "出错信息 (出错码=%d): %s", err, lpMsgBuf);
	//释放内存
	LocalFree(lpMsgBuf);
}
//比对文件
void FindFileName::FileCompare(string const& path, char const* str){
	if( regex_match(str, re) )
		mList_fName.push_back(path + "/" + str);
}

//初始化
void FindFileName::init(char const* fPath, char const* fName = "*.*")
{
	m_fPath = (fPath == NULL) ? "" : fPath;
	std::string::size_type pos1 = m_fPath.find_last_of('/');
	std::string::size_type pos2 = m_fPath.find_last_of('\\');
	if(pos1 != string::npos || pos2 != string::npos)
	{
		m_fPath = m_fPath.substr(0, pos1);
	}
	//替换路径中的"\"
	for(auto &a : m_fPath){
		if(a == '\\')
			a = '/';
	}
	//分割文件名
	if(fName != NULL)
	{
		string temp = fName;
		size_t found = temp.find_last_of('.');
		m_fName = temp.substr(0, found);
		m_fsuffix = temp.substr(found+1);
	}
	else
	{
		m_fName = "*";
		m_fsuffix = "*";
	}
	//构建正则表达式
	if(m_fName == "*" && m_fsuffix == "*")
		re = "[^ ]*.[^ ]*";
	else if(m_fName != "*" && m_fsuffix != "*")
		re = m_fName + "." + m_fsuffix;
	else if(m_fName == "*" && m_fsuffix != "*")
		re = "[^ ]*." + m_fsuffix;
	else if(m_fsuffix == "*" && m_fName != "*")
		re = m_fName + ".[^ ]*";
	else{}
}