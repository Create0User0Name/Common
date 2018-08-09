/*********************************************************************************
*Copyright(C),2010-2011
*FileName:		//StringDispose.h StringDispose.cpp
*Author:		//shijie
*Version:		//1.0
*Date:			//2018/6/2 22:20
*Description:	//�ַ����������ַ����ָ�ַ������ӣ��ַ����޼�

*History:  //�޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ��
1.Date:
Author:
Modification:
2.��������
**********************************************************************************/

#include <vector>
#include <string>
#include <stdarg.h>
#include <comm\common.h>

/*
���ܣ�		�ַ������
���������	str������ַ�����delim�ָ���
���������	�����ֺ���ַ���
����ֵ��	��
*/
void StringSplit(std::string const& str, std::vector<std::string>& strv, std::string const& delim);

/*
���ܣ�		�ַ���ƴ��
���������	�ַ���1�� �ַ���2�� ..., NULL
���������	��
����ֵ��	����ƴ�Ӻ���ַ���
*/
std::string strcat(char const* str1, char const* str2, ...);

/*
���ܣ�		�ַ����޼�����ȡ�ַ�����β�Ŀո��Ʊ�����س������У�
���������	���޼��ַ���
���������	��
����ֵ��	���ر��޼�����ַ�������
*/
std::string& trim(std::string& str);

/*
����:		�ַ����д�д�ַ�תСд
�������:	�������ַ���
�������:	������ַ���
����ֵ:		void
*/
void StringLower(std::string& str);

/*
����:		�ַ�����Сдת��д
�������:	�������ַ���
�������:	������ַ���
����ֵ:		void
*/
void StringUpper(std::string& str);

/*
����:		ȥ���ַ����з���ĸ�ַ�
�������:	�������ַ���
�������:	��
����ֵ:		���ش������ַ���
*/
std::string DislodgeStringNotChar(std::string& str);

/*
����:		ȥ���ַ����пո�
�������:	�������ַ���
�������:	��
����ֵ:		���ش������ַ���
*/
std::string DislodgeStringSpace(std::string& str);