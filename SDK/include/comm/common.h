/// @file:		common.h
/// @author:	石杰
/// @version:	1.0
/// @date:		2018/6/2 22:14
/// @brief:		常用一些宏定义,和函数

/**********************************************************************************
History:  //修改历史记录列表，每条修改记录应包含修改日期、修改者及修改内容简介
1.Date:
Author:
Modification:
2.…………
**********************************************************************************/

#ifndef _COMMON_H_
#define _COMMON_H_
#include <math.h>
#include <time.h>
#include <iostream>

/// @brief  字符串最大长度
const int STRING_MAX = 2048;

/// @brief  定义常用宏
#define MACRO_RETURN_IF(expr) if(expr){return;}
#define MACRO_RETURN_TRUE_IF(expr) if(expr){return true;}
#define MACRO_RETURN_NULLSTR_IF(expr) if(expr){return "";}
#define MACRO_RETURN_NULL_IF(expr) if(expr){return NULL;}
#define MACRO_RETURN_FALSE_IF(expr) if(expr){return false;}
#define MACRO_BREAK_IF(expr) if(expr){break;}
#define MACRO_CONTINUE_IF(expr) if(expr){continue;}

/// @brief 判断 double 值是否为0
/// @retval false 不为0
/// @retval true  为0
bool IsDoubleZero(
	const double& d		/// < [in] 入参
	);

/// @brief   返回当前时间
/// @retval  返回字符串时间(包括说明字符串)
/// @note	 例如: 现在的时间: 2018/08/11 19:10:00
std::string GetTime(
	std::string const& str = ""   /// < [in] 时间前是否带说明字符串
	);


#endif //_COMMON_H_