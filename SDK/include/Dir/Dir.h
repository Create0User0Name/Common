/// @file	 Dir.h
/// @author  石杰
/// @version 1.0
/// @date	 2018/6/2 22:20
/// @brief   对文件夹的操作

/**
/// @brief	增加 FindFileName 类
/// @date	2018/8/12 13:08
/// @attention  FindFileName 现在只支持查找指定路径下的所有文件,包括子文件夹下的文件
**/

#ifndef _DIR_H_
#define _DIR_H_

#include <list>
#include <regex>
using namespace std;

/// @brief	对文件夹的操作
class DIR
{
public:
	/// @brief	构造函数
	DIR();

	/// @brief  创建文件夹，可创建多级
	/// @retval true 创建成功
	/// @retval false 创建失败
	/// @param  path [in]  创建的路径
	static bool CreateDir(const std::string& path);

	/// @brief  获得当前工作路径
	/// @retval 返回当前的工作路径
	/// @param  path [out]  获得的路径
	static std::string& GetWorkPath(std::string& path);
};

/// @brief  查询指定目录下的文件或文件夹(递归)
class FindFileName
{
public:
	/// @brief	构造函数
	/// @note   查询文件名 *, *.text, a.*
	/// @param  fPath [in] 查询路径
	/// @param  fName [in] 查询文件名
	FindFileName(char const* fPath,	char const* fName /*"*"*/);

	/// @brief	重载查找函数
	/// @param  fPath [in] 查询路径
	/// @param  fName [in] 查询文件名
	void Find(char const* pPath, char const* fName);

	/// @brief  查找开始
	void Find(void);

	/// @brief  获得查找到的文件数量
	int GetFileCount(void)const;

	/// @brief  返回查询到的结果集
	/// @return list<string>& 返回查找到的文件列表引用
	const list<string>& GetResult(void)const;		

	/// @brief  重载输出运算符
	friend ostream& operator <<(ostream& os, list<string> const& fn);
	friend ostream& operator <<(ostream& os, FindFileName const& fn);

private:
	/// @brief	待查找根路径
	string m_fPath;		
	/// @brief  待查找的文件名
	string m_fName;		
	/// @brief  文件后缀
	string m_fsuffix;		
	/// @brief  正则表达式
	regex re;	
	/// @brief	查找后的文件名链表
	list<string> mList_fName;	

private:
	/// @brief	初始化
	/// @note   查询文件名 *, *.text, a.*
	/// @param  fPath [in] 查询路径
	/// @param  fName [in] 查询文件名
	void init(char const* fPath, char const* fName/**.**/);

	/// @brief	指定路径下查找文件
	/// @param  path [in] 查询路径
	void Find_Next(string &path);

	/// @brief	查找错误处理
	/// @param  szBuf [out]  保存返回的错误信息
	void ErrorInfo(char *szBuf);

	/// @brief  比对匹配文件名
	/// @param  temp [in]  当前文件路径
	/// @param  str  [in]  当前文件名(包含后缀)
	void FileCompare(string const& temp, char const* str);
};

#endif _DIR_H_


