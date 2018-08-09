/*********************************************************************************
*Copyright(C),2010-2011
*FileName:		//Log.h Log.cpp
*Author:		//shijie
*Version:		//1.0
*Date:			//2018/6/2 22:20
*Description:	//ͨ����־�࣬�������ڵ��Ժ����м�¼������ģʽ��

//ʹ�õ���common.h & DIR.h

*Others:		//ʹ����־�࣬���Ƽ��������еľ�̬��Ա��������ʹ�ú궨�壬���ݲ�ͬ����Ҫʹ�ò�ͬ�ĺ궨�壬�򻯲���Ҫ�Ĳ���
*Function List:
1.static void printf(bool flag, int level, char const* file, int line, char const* format, ...);
	���ܣ�  ��ӡ��־���ļ���
	������  falg�� ��־���ͣ�������־��������־��
			level����־���𣨵��ԣ���Ϣ�����棬һ�������������
			file�� �ļ�
			line�� ��
			format����ʽ���ַ���
	����ֵ  ��
2.static Log& GetInstance(void);
	���ܣ�  ��õ���ģʽ�е�Ψһ��������

*History:  //�޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ��
1.Date:
Author:
Modification:
2.��������
**********************************************************************************/

#ifndef _LOG_H_
#define _LOG_H_

#include <iostream>
#include <fstream>
#include <time.h>
#include <stdarg.h>
#include "DIR.h"

//����
#define OUT_LOG_BUG(_file, _line, _outtext) \
	Log::printf(false, Log::LEVEL_BUG, _file, _line, _outtext)
#define OUT_LOG_BUG_FMT(_file, _line, _format, ...)\
	Log::printf(false, Log::LEVEL_BUG, _file, _line, _format, __VA_ARGS__)
//��Ϣ
#define OUT_LOG_INF(_file, _line, _outtext) \
	Log::printf(false, Log::LEVEL_INF, _file, _line, _outtext)
#define OUT_LOG_INF_FMT(_file, _line, _format, ...) \
	Log::printf(false, Log::LEVEL_INF, _file, _line, _format, __VA_ARGS__)
//����
#define OUT_LOG_WAR(_file, _line, _outtext) \
	Log::printf(false, Log::LEVEL_WAR, _file, _line, _outtext)
#define OUT_LOG_WAR_FMT(_file, _line, _format, ...) \
	Log::printf(false, Log::LEVEL_WAR, _file, _line, _format, __VA_ARGS__)
//һ�����
#define OUT_LOG_ERR(_file, _line, _outtext) \
	Log::printf(false, Log::LEVEL_ERR, _file, _line, _outtext)
#define OUT_LOG_ERR_FMT(_file, _line, _format, ...) \
	Log::printf(false, Log::LEVEL_ERR, _file, _line, _format, __VA_ARGS__)
//��������
#define OUT_LOG_CRT(_file, _line, _outtext) \
	Log::printf(false, Log::LEVEL_CRT, _file, _line, _outtext)
#define OUT_LOG_CRT_FMT(_file, _line, _format, ...) \
	Log::printf(false, Log::LEVEL_CRT, _file, _line, _format, __VA_ARGS__)

//��������ʱ�����������־
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
	std::ofstream m_ofsRunLog;   //��������ļ�
	std::ofstream m_ofsBugLog;   //������������ļ�
	std::ofstream* m_ofsTempLog; //��ʱ����ļ�
private:
	//��־�ȼ���ǩ����
	static char const* m_levels[];
	//����ģʽ
	static Log m_log;			
public:
	//��־�ȼ� ���� - ��Ϣ - ���� - һ����� - �������� - ����
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