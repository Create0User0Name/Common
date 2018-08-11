/// @file:		common.h
/// @author:	ʯ��
/// @version:	1.0
/// @date:		2018/6/2 22:14
/// @brief:		����һЩ�궨��,�ͺ���

#include <comm\common.h>

// �ж�double�Ƿ���0
bool IsDoubleZero(const double& d){
	if (fabs(d) < 1e-15){
		return true;
	}
	return false;
}

//����ʱ���ַ���
std::string GetTime(std::string const& str /* = "" */){
	time_t t;
	t = time(NULL);
	tm *tt = NULL;
	localtime_s(tt, &t);

	char ctime[128] = {0};
	if(str.empty()){
		sprintf_s(ctime, 128, "%d/%02d%02d %02d:%02d:%02d", tt->tm_year - 1900, tt->tm_mon - 1, tt->tm_mday, 
			tt->tm_hour, tt->tm_min, tt->tm_sec);
	} else{
		//����ʾ
		sprintf_s(ctime, 128, "%s: %d/%02d%02d %02d:%02d:%02d", str.c_str(), tt->tm_year - 1900, tt->tm_mon - 1, tt->tm_mday, 
			tt->tm_hour, tt->tm_min, tt->tm_sec);
	}

	return std::string(ctime);
}