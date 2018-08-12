/// @file	 Dir.h
/// @author  ʯ��
/// @version 1.0
/// @date	 2018/6/2 22:20
/// @brief   ���ļ��еĲ���

/// @brief	���� FindFileName ��
/// @date	2018/8/12 13:08
/// @attention  FindFileName ����ֻ֧�ֲ���ָ��·���µ������ļ�,�������ļ����µ��ļ�

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
	static bool CreateDir(
		const std::string& path		/// < [in]  ������·��
		);

	/// @brief  ��õ�ǰ����·��
	/// @retval ���ص�ǰ�Ĺ���·��
	static std::string& GetWorkPath(
		std::string& path			/// < [out]  ��õ�·��
		);
};

/// @brief  ��ѯָ��Ŀ¼�µ��ļ����ļ���(�ݹ�)
class FindFileName
{
public:
	/// @brief	���캯��
	/// @note   ��ѯ�ļ��� *, *.text, a.*
	FindFileName(
		char const* fPath,			///   < [in] ��ѯ·��
		char const* fName /*"*"*/	///   < [in] ��ѯ�ļ���
		);

	/// @brief	���ز��Һ���
	void Find(
		char const* pPath,			///   < [in] ��ѯ·��
		char const* fName			///   < [in] ��ѯ�ļ���
		);

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
	void init(
		char const* fPath,			///   < [in] ��ѯ·��
		char const* fName/**.**/	///   < [in] ��ѯ�ļ���
		);

	/// @brief	ָ��·���²����ļ�
	void Find_Next(
		string &path    /// < [in] ��ѯ·��
		);

	/// @brief	���Ҵ�����
	void ErrorInfo(
		char *szBuf		/// < [out]  ���淵�صĴ�����Ϣ
		);

	/// @brief  �ȶ�ƥ���ļ���
	void FileCompare(
		string const& temp,		/// < [in]  ��ǰ�ļ�·��
		char const* str			/// < [in]  ��ǰ�ļ���(������׺)
		);
};

#endif _DIR_H_


