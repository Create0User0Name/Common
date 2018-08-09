#include "StringOpt.h"

/*
���ܣ�		�ַ������
���������	str������ַ�����delim�ָ���
���������	�����ֺ���ַ���
����ֵ��	��
*/
void StringSplit(std::string const& str, std::vector<std::string>& strv, std::string const& delim) 
{
	char *temp = new char[str.size() + 1];
	strcpy_s(temp, str.size()+1, str.c_str());
	char *nextStr = NULL;
	for (char *token = strtok_s(temp, delim.c_str(), &nextStr); token; token = strtok_s(NULL, delim.c_str(), &nextStr)) {
		std::string part = token;
		strv.push_back(part);
		if ( ! ( (token += strlen(token)) - temp < (int)str.size()) ) {
			break;
		}
	}
	delete temp;
}

/*
���ܣ�		�ַ���ƴ��
���������	�ַ���1�� �ַ���2�� ..., NULL
���������	��
����ֵ��	����ƴ�Ӻ���ַ���
*/
std::string strcat(char const* str1, char const* str2, ...) {
	std::string str = str1;
	str += str2;

	//�䳤������
	va_list ap;
	//��str2�Ժ�Ĳ�����ʼ���䳤������
	va_start(ap, str2);
	char const* strx = NULL;
	while (strx = va_arg(ap, char const*))
		str += strx;
	va_end(ap);
	return str;
}

/*
���ܣ�		�ַ����޼�����ȡ�ַ�����β�Ŀո��Ʊ�����س������У�
���������	���޼��ַ���
���������	��
����ֵ��	���ر��޼�����ַ�������
*/
std::string& trim(std::string& str)
{
	std::string::size_type first = str.find_first_not_of(" \t\r\n");
	std::string::size_type last = str.find_last_not_of(" \t\r\n");

	if (first == std::string::npos || last == std::string::npos)
		str.clear();
	else
		str = str.substr(first, last - first + 1);
	return str;
}

/*
����:		�ַ����д�д�ַ�תСд
�������:	�������ַ���
�������:	������ַ���
����ֵ:		void
*/
void StringLower(std::string& str)
{
	MACRO_RETURN_IF(str.empty());
	char* cpstr = new char[str.size()+1]();
	for(int i = 0; i < (int)str.size(); i++)
	{
		cpstr[i] = tolower(str.at(i));
	}
	str.clear();
	str = cpstr;
	delete cpstr;
	cpstr = NULL;
}

/*
����:		�ַ�����Сдת��д
�������:	�������ַ���
�������:	������ַ���
����ֵ:		void
*/
void StringUpper(std::string& str)
{
	MACRO_RETURN_IF(str.empty());
	char* cpstr = new char[str.size()+1]();
	for(int i = 0; i < (int)str.size(); i++)
	{
		cpstr[i] = toupper(str.at(i));
	}
	str.clear();
	str = cpstr;
	delete cpstr;
	cpstr = NULL;
}

/*
����:		ȥ���ַ����з���ĸ�ַ�
�������:	�������ַ���
�������:	��
����ֵ:		���ش������ַ���
*/
std::string DislodgeStringNotChar(std::string& str)
{
	MACRO_RETURN_NULLSTR_IF(str.empty());
	char* cpstr = new char[str.size()+1]();
	for(int i = 0, y = 0; i < (int)str.size(); i++)
	{
		if( isalpha(str.at(i)) ) //����ĸ�ַ�ʱ
		{
			cpstr[y++] = str.at(i);
		}
	}
	std::string retstr(cpstr);
	delete cpstr;
	cpstr = NULL;
	return retstr;
}

/*
����:		ȥ���ַ����пո�
�������:	�������ַ���
�������:	��
����ֵ:		���ش������ַ���
*/
std::string DislodgeStringSpace(std::string& str)
{
	MACRO_RETURN_NULLSTR_IF(str.empty());
	char* cpstr = new char[str.size()+1]();
	for(int i = 0, y = 0; i < (int)str.size(); i++)
	{
		if( !isspace(str.at(i)) ) //���ǿո�ʱ
		{
			cpstr[y++] = str.at(i);
		}
	}
	std::string retstr(cpstr);
	delete cpstr;
	cpstr = NULL;
	return retstr;
}