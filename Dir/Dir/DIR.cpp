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
	//ѭ������
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


/*FindFileName ��*/
FindFileName::FindFileName(char const* fPath, char const* fName = "*.*") 
{
	//��ʼ��
	init(fPath, fName);
}

//////////////////////////////////////Public Function////////////////////////////////////
//������
void FindFileName::Find(void){
	Find_Next(m_fPath);
}
//����������, �������¶������·�����ļ���
void FindFileName::Find(char const* fPath, char const* fName){
	init(fPath, fName);
	Find_Next(m_fPath);
}
//�����ļ�����
int FindFileName::GetFileCount(void) const{
	return mList_fName.size();
}
//���ز��ҵ����ļ��б�
const list<string>& FindFileName::GetResult(void)const{
	return mList_fName;
}
//������������
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
	std::string temp = path + "/*.*"; //���ò�ѯ·�� 
	HANDLE hFind = FindFirstFile(temp.c_str(), &wfd);
	if(INVALID_HANDLE_VALUE == hFind){
		char szBuf[128] = {0};
		ErrorInfo(szBuf);
		mList_fName.push_back("[" + path + "]" + szBuf);
		return;
	}
	BOOL goFind = TRUE;
	while(goFind){
		if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY){//Ŀ¼
			if(strcmp(wfd.cFileName, ".") && strcmp(wfd.cFileName, "..")){
				temp = path + '/' + wfd.cFileName;
				Find_Next( temp );	//�ݹ����
			}
		}
		else{ //�ļ�
			FileCompare(path, wfd.cFileName);  //�ȶ�ƥ���ļ�
		}
		goFind = FindNextFile(hFind, &wfd);
	}
	FindClose(hFind);
}

//�Բ�ѯ���������
void FindFileName::ErrorInfo(char *szBuf){
	DWORD err = GetLastError(); //��ȡ������
	LPVOID lpMsgBuf;
	//��ô�����Ϣ
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, err, 
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR) &lpMsgBuf, 0, NULL);
	sprintf_s(szBuf, 128, "������Ϣ (������=%d): %s", err, lpMsgBuf);
	//�ͷ��ڴ�
	LocalFree(lpMsgBuf);
}
//�ȶ��ļ�
void FindFileName::FileCompare(string const& path, char const* str){
	if( regex_match(str, re) )
		mList_fName.push_back(path + "/" + str);
}

//��ʼ��
void FindFileName::init(char const* fPath, char const* fName = "*.*")
{
	m_fPath = (fPath == NULL) ? "" : fPath;
	std::string::size_type pos1 = m_fPath.find_last_of('/');
	std::string::size_type pos2 = m_fPath.find_last_of('\\');
	if(pos1 != string::npos || pos2 != string::npos)
	{
		m_fPath = m_fPath.substr(0, pos1);
	}
	//�滻·���е�"\"
	for(auto &a : m_fPath){
		if(a == '\\')
			a = '/';
	}
	//�ָ��ļ���
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
	//����������ʽ
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