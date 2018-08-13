/// @file	 Dir.h
/// @author  ʯ��
/// @version 1.0
/// @date	 2018/6/2 22:20
/// @brief   ���ļ��еĲ���

/**
/// @brief	���� FindFileName ��
/// @date	2018/8/12 13:08
/// @attention  FindFileName ����ֻ֧�ֲ���ָ��·���µ������ļ�,�������ļ����µ��ļ�
**/

#ifndef _DIR_H_
#define _DIR_H_

#include <list>
#include <regex>
using namespace std;

/// @brief	���ļ��еĲ���
class DIR
{
public:
	/// @brief	���캯��
	DIR();

	/// @brief  �����ļ��У��ɴ����༶
	/// @retval true �����ɹ�
	/// @retval false ����ʧ��
	/// @param  path [in]  ������·��
	static bool CreateDir(const std::string& path);

	/// @brief  ��õ�ǰ����·��
	/// @retval ���ص�ǰ�Ĺ���·��
	/// @param  path [out]  ��õ�·��
	static std::string& GetWorkPath(std::string& path);
};

/// @brief  ��ѯָ��Ŀ¼�µ��ļ����ļ���(�ݹ�)
class FindFileName
{
public:
	/// @brief	���캯��
	/// @note   ��ѯ�ļ��� *, *.text, a.*
	/// @param  fPath [in] ��ѯ·��
	/// @param  fName [in] ��ѯ�ļ���
	FindFileName(char const* fPath,	char const* fName /*"*"*/);

	/// @brief	���ز��Һ���
	/// @param  fPath [in] ��ѯ·��
	/// @param  fName [in] ��ѯ�ļ���
	void Find(char const* pPath, char const* fName);

	/// @brief  ���ҿ�ʼ
	void Find(void);

	/// @brief  ��ò��ҵ����ļ�����
	int GetFileCount(void)const;

	/// @brief  ���ز�ѯ���Ľ����
	/// @return list<string>& ���ز��ҵ����ļ��б�����
	const list<string>& GetResult(void)const;		

	/// @brief  ������������
	friend ostream& operator <<(ostream& os, list<string> const& fn);
	friend ostream& operator <<(ostream& os, FindFileName const& fn);

private:
	/// @brief	�����Ҹ�·��
	string m_fPath;		
	/// @brief  �����ҵ��ļ���
	string m_fName;		
	/// @brief  �ļ���׺
	string m_fsuffix;		
	/// @brief  ������ʽ
	regex re;	
	/// @brief	���Һ���ļ�������
	list<string> mList_fName;	

private:
	/// @brief	��ʼ��
	/// @note   ��ѯ�ļ��� *, *.text, a.*
	/// @param  fPath [in] ��ѯ·��
	/// @param  fName [in] ��ѯ�ļ���
	void init(char const* fPath, char const* fName/**.**/);

	/// @brief	ָ��·���²����ļ�
	/// @param  path [in] ��ѯ·��
	void Find_Next(string &path);

	/// @brief	���Ҵ�����
	/// @param  szBuf [out]  ���淵�صĴ�����Ϣ
	void ErrorInfo(char *szBuf);

	/// @brief  �ȶ�ƥ���ļ���
	/// @param  temp [in]  ��ǰ�ļ�·��
	/// @param  str  [in]  ��ǰ�ļ���(������׺)
	void FileCompare(string const& temp, char const* str);
};

#endif _DIR_H_


