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
#include <stdarg.h>

//����
#define LOG_BUG(_file, _line, _outtext) \
	Log::printf(Log::LEVEL_BUG, _file, _line, _outtext)
#define LOG_BUG_F(_file, _line, _format, ...)\
	Log::printf(Log::LEVEL_BUG, _file, _line, _format, __VA_ARGS__)
//��Ϣ
#define LOG_INFO(_file, _line, _outtext) \
	Log::printf(Log::LEVEL_INFO, _file, _line, _outtext)
#define LOG_INFO_F(_file, _line, _format, ...) \
	Log::printf(Log::LEVEL_INFO, _file, _line, _format, __VA_ARGS__)
//����
#define LOG_WAR(_file, _line, _outtext) \
	Log::printf(Log::LEVEL_WARN, _file, _line, _outtext)
#define LOG_WARN_F(_file, _line, _format, ...) \
	Log::printf(Log::LEVEL_WARN, _file, _line, _format, __VA_ARGS__)
//һ�����
#define LOG_ERROR(_file, _line, _outtext) \
	Log::printf(Log::LEVEL_ERROR, _file, _line, _outtext)
#define LOG_ERROR_F(_file, _line, _format, ...) \
	Log::printf(Log::LEVEL_ERROR, _file, _line, _format, __VA_ARGS__)
//��������
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
	//��־�ȼ���ǩ����
	static char const* m_levels[];
	static std::ofstream m_ofsRunLog;   //���LOG

public:
	//��־�ȼ� ���� - ��Ϣ - ���� - һ����� - �������� - ����
	static enum LEVEL {LEVEL_BUG, LEVEL_INFO, LEVEL_WARN, LEVEL_ERROR, LEVEL_CRT};
	static void printf(LEVEL level, char const* file, int line, char const* format, ...);
};
#endif // !_LOG_H_