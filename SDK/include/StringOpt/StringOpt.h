/// @file	 StringOpt.h
/// @author  石杰
/// @version 1.0
/// @date	 2018/6/2 22:20
/// @brief	 字符串操作

/**********************************************************************************
History:  //修改历史记录列表，每条修改记录应包含修改日期、修改者及修改内容简介
1.Date:	
Author:
Modification:
2.…………
**********************************************************************************/

#include <vector>
#include <string>
#include <stdarg.h>
#include <comm\common.h>

/// @brief	字符串分割
/// @param  str   [in]  要分割的字符串
/// @param  strv  [out] 分割后的字符串向量
/// @param  delim [in]  分割标志字符
void StringSplit(std::string const& str,	std::vector<std::string>& strv, std::string const& delim);

/// @brief	字符串拼接
/// @retval 返回拼接后的字符串
/// @note	参数列表最后需要自定义结束标志 如NULL, 否则会异常
/// @param  str1 [in]  要连接的字符串 
/// @param  str2 [in]  要连接的字符串 
/// @param  ...	 [in]  连接列表
/// @param  [in]  结束标志 NULL
std::string strcat(char const* str1, char const* str2, ...);

/// @brief  字符串修剪（截取字符串首尾的空格，制表符，回车，换行）
/// @retval 返回被修剪后的字符串本身
/// @note	入参也可以作为出参
std::string& trim(
	std::string& str  /// < [in][out]  待修剪字符串
	);

/// @brief  字符串中大写字符转小写
void StringLower(
	std::string& str  /// <  [in][out] 待处理字符串  处理后字符串
	);

/// @brief  字符串中小写转大写	
void StringUpper(
	std::string& str   /// < [in][out] 待处理字符串 处理后字符串
	);

/// @brief  去除字符串中非字母字符
/// @retval 返回处理后的字符串
std::string DislodgeStringNotChar(
	std::string& str  ///  <  [in]	待处理字符串		
	);

/// @brief  去除字符串中所有空格
/// @retval 返回处理后的字符串
std::string DislodgeStringSpace(
	std::string& str  /// < [in]  待处理字符串
	);