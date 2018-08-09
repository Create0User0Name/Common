#include "Log.h"
Log Log::m_log;
Log::Log()
{
	std::string cStrPath;
	DIR::CreateDir(DIR::GetWorkPath(cStrPath) + "\\LOG");
	m_ofsRunLog.open(cStrPath + "\\LOG\\RunLog.log", std::ios::app);
	m_ofsBugLog.open(cStrPath + "\\LOG\\BugLog.log");
}

Log::~Log()
{
	m_ofsBugLog.close();
	m_ofsRunLog.close();
	m_ofsTempLog = NULL;
}

/*
���ܣ�		����ʽ��ӡ��־
���������	flag�� ���л򿪷��� level����־�ȼ��� file��Դ���ļ��� lineԴ���кţ� format����ʽ���ַ���
���������	��
����ֵ��	void
*/
void Log::printf(bool flag, int level, char const* file, int line, char const* format, ...)
{
	//ʱ��
	char dateTime[32] = "";
	time_t now = time(NULL);
	tm t;   //tm�ṹָ��
	localtime_s(&t, &now);
	strftime(dateTime, sizeof(dateTime), "%Y/%m/%d %H:%M:%S", &t);
	Log& log = Log::GetInstance();
	char string[MAXSTRING] = "";
	//��ӡ��־
	if (flag){
		MACRO_RETURN_IF(log.m_ofsRunLog.fail());
		//����ʱ��־
		sprintf_s(string, MAXSTRING, "[%s]", dateTime);
		log.m_ofsRunLog << string;
		log.m_ofsTempLog = &log.m_ofsRunLog;
	}
	else{
		MACRO_RETURN_IF(log.m_ofsBugLog.fail());
		//����ʱ��־
		sprintf_s(string, MAXSTRING, "[%s][%s][%s : %d]", dateTime, m_levels[level], file, line);
		log.m_ofsBugLog << string;
		log.m_ofsTempLog = &log.m_ofsBugLog;
	}
	//��ӡ��ʽ���ַ���
	va_list ap;
	char fmt[MAXSTRING] = "";
	va_start(ap, format);
	vsprintf_s(fmt, format, ap);
	va_end(ap);
	*log.m_ofsTempLog << fmt << std::endl;
}

char const* Log::m_levels[] = { "LEVEL_BUG", "LEVEL_INF", "LEVEL_WAR", "LEVEL_ERR", "LEVEL_CRT" };