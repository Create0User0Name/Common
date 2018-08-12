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
#include <stdarg.h>

//调试
#define LOG_BUG(_file, _line, _outtext) \
	Log::printf(Log::LEVEL_BUG, _file, _line, _outtext)
#define LOG_BUG_F(_file, _line, _format, ...)\
	Log::printf(Log::LEVEL_BUG, _file, _line, _format, __VA_ARGS__)
//信息
#define LOG_INFO(_file, _line, _outtext) \
	Log::printf(Log::LEVEL_INFO, _file, _line, _outtext)
#define LOG_INFO_F(_file, _line, _format, ...) \
	Log::printf(Log::LEVEL_INFO, _file, _line, _format, __VA_ARGS__)
//警告
#define LOG_WAR(_file, _line, _outtext) \
	Log::printf(Log::LEVEL_WARN, _file, _line, _outtext)
#define LOG_WARN_F(_file, _line, _format, ...) \
	Log::printf(Log::LEVEL_WARN, _file, _line, _format, __VA_ARGS__)
//一般错误
#define LOG_ERROR(_file, _line, _outtext) \
	Log::printf(Log::LEVEL_ERROR, _file, _line, _outtext)
#define LOG_ERROR_F(_file, _line, _format, ...) \
	Log::printf(Log::LEVEL_ERROR, _file, _line, _format, __VA_ARGS__)
//致命错误
#define LOG_CRT(_file, _line, _outtext) \
	Log::printf(Log::LEVEL_CRT, _file, _line, _outtext)
#define LOG_CRT_F(_file, _line, _format, ...) \
	Log::printf(Log::LEVEL_CRT, _file, _line, _format, __VA_ARGS__)

class Log
{
public:
	Log();
	Log(const Log&){}
	~Log();
	
private:
	//日志等级标签数组
	static char const* m_levels[];
	static std::ofstream m_ofsRunLog;   //输出LOG

public:
	//日志等级 调试 - 信息 - 警告 - 一般错误 - 致命错误 - 运行
	static enum LEVEL {LEVEL_BUG, LEVEL_INFO, LEVEL_WARN, LEVEL_ERROR, LEVEL_CRT};
	static void printf(LEVEL level, char const* file, int line, char const* format, ...);
};
#endif // !_LOG_H_