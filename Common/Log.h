/*********************************************************************************
*Copyright(C),2010-2011
*FileName:		//Log.h Log.cpp
*Author:		//shijie
*Version:		//1.0
*Date:			//2018/6/2 22:20
*Description:	//通用日志类，可以用在调试和运行记录（单利模式）

//使用到了common.h & DIR.h

*Others:		//使用日志类，不推荐适用类中的静态成员函数，而使用宏定义，根据不同的需要使用不同的宏定义，简化不必要的参数
*Function List:
1.static void printf(bool flag, int level, char const* file, int line, char const* format, ...);
	功能：  打印日志到文件中
	参数：  falg： 日志类型（开发日志，运行日志）
			level：日志级别（调试，信息，警告，一般错误，致命错误）
			file： 文件
			line： 行
			format：格式化字符串
	返回值  无
2.static Log& GetInstance(void);
	功能：  获得单利模式中的唯一对象引用

*History:  //修改历史记录列表，每条修改记录应包含修改日期、修改者及修改内容简介
1.Date:
Author:
Modification:
2.…………
**********************************************************************************/

#ifndef _LOG_H_
#define _LOG_H_

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdarg.h>
#include "DIR.h"

//调试
#define OUT_LOG_BUG(_file, _line, _outtext) \
	Log::printf(false, Log::LEVEL_BUG, _file, _line, _outtext)
#define OUT_LOG_BUG_FMT(_file, _line, _format, ...)\
	Log::printf(false, Log::LEVEL_BUG, _file, _line, _format, __VA_ARGS__)
//信息
#define OUT_LOG_INF(_file, _line, _outtext) \
	Log::printf(false, Log::LEVEL_INF, _file, _line, _outtext)
#define OUT_LOG_INF_FMT(_file, _line, _format, ...) \
	Log::printf(false, Log::LEVEL_INF, _file, _line, _format, __VA_ARGS__)
//警告
#define OUT_LOG_WAR(_file, _line, _outtext) \
	Log::printf(false, Log::LEVEL_WAR, _file, _line, _outtext)
#define OUT_LOG_WAR_FMT(_file, _line, _format, ...) \
	Log::printf(false, Log::LEVEL_WAR, _file, _line, _format, __VA_ARGS__)
//一般错误
#define OUT_LOG_ERR(_file, _line, _outtext) \
	Log::printf(false, Log::LEVEL_ERR, _file, _line, _outtext)
#define OUT_LOG_ERR_FMT(_file, _line, _format, ...) \
	Log::printf(false, Log::LEVEL_ERR, _file, _line, _format, __VA_ARGS__)
//致命错误
#define OUT_LOG_CRT(_file, _line, _outtext) \
	Log::printf(false, Log::LEVEL_CRT, _file, _line, _outtext)
#define OUT_LOG_CRT_FMT(_file, _line, _format, ...) \
	Log::printf(false, Log::LEVEL_CRT, _file, _line, _format, __VA_ARGS__)

//正常运行时，输出运行日志
#define RUN_LOG_INF(_outtext) \
	Log::printf(true, Log::LEVEL_RUN, __FILE__, __LINE__, _outtext)
#define RUN_LOG_INF_FMT(_format, ...) \
	Log::printf(true, Log::LEVEL_RUN, __FILE__, __LINE__, _format, __VA_ARGS__)

class Log
{
private:
	Log();
	Log(const Log&){}
public:
	~Log();
	std::ofstream m_ofsRunLog;   //运行输出文件
	std::ofstream m_ofsBugLog;   //开发调试输出文件
	std::ofstream* m_ofsTempLog; //临时输出文件
private:
	//日志等级标签数组
	static char const* m_levels[];
	//单利模式
	static Log m_log;			
public:
	//日志等级 调试 - 信息 - 警告 - 一般错误 - 致命错误 - 运行
	static int const LEVEL_BUG = 0;
	static int const LEVEL_INF = 1;
	static int const LEVEL_WAR = 2;
	static int const LEVEL_ERR = 3;
	static int const LEVEL_CRT = 4;
	static int const LEVEL_RUN = 5;
	static void printf(bool flag, int level, char const* file, int line, char const* format, ...);
	static Log& GetInstance(void) {
		return m_log;
	}
};
#endif // !_LOG_H_