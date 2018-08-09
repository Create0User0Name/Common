/*********************************************************************************
*Copyright(C),2010-2011
*FileName:		//StringDispose.h StringDispose.cpp
*Author:		//shijie
*Version:		//1.0
*Date:			//2018/6/2 22:20
*Description:	//�ַ����������ַ����ָ�ַ������ӣ��ַ����޼�

*Others:		//��
*Function List:
1.void StringSplit(std::string const& str, std::vector<std::string>& strv, std::string const& delim);
	���ܣ�  �ַ����ָ�
	������  1�����ָ��ַ���
			2���ָ�󱣴�����
			3���ָ��
	����ֵ��void
2.std::string strcat(char const* str1, char const* str2, ...);
	���ܣ�  �ַ�������
	������  �������ַ���
	����ֵ���������Ӻ���ַ���
3.std::string& trim(std::string& str);
	���ܣ�  �ַ����޼�����ȡ�ַ�����β�Ŀո��Ʊ�����س������У�
	������  ���޼��ַ���
	����ֵ�������޼�����ַ���
4.void StringLower(std::string& str);
	���ܣ�  �ַ����д�д�ַ�תСд
	������  �������ַ���
	����ֵ��void
5.void StringUpper(std::string& str)
    ���ܣ�  �ַ�����Сдת��д
    ������  �������ַ���
    ����ֵ��void
6.std::string DislodgeStringNotChar(std::string& str)
	���ܣ�  ȥ���ַ����з���ĸ�ַ�
	������  �������ַ���
	����ֵ�����ش������ַ���
7.std::string DislodgeStringSpace(std::string& str);
	���ܣ�  ȥ���ַ����пո�
	������  �������ַ���
	����ֵ�����ش������ַ���

*History:  //�޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ��
1.Date:
Author:
Modification:
2.��������
**********************************************************************************/

#include <vector>
#include <string>
#include <stdarg.h>
#include "common.h"
void StringSplit(std::string const& str, std::vector<std::string>& strv, std::string const& delim);
std::string strcat(char const* str1, char const* str2, ...);
std::string& trim(std::string& str);
void StringLower(std::string& str);
void StringUpper(std::string& str);
std::string DislodgeStringNotChar(std::string& str);
std::string DislodgeStringSpace(std::string& str);