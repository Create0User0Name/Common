/// @file	 StringOpt.h
/// @author  ʯ��
/// @version 1.0
/// @date	 2018/6/2 22:20
/// @brief	 �ַ�������

/**********************************************************************************
History:  //�޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ��
1.Date:	
Author:
Modification:
2.��������
**********************************************************************************/

#include <vector>
#include <string>
#include <stdarg.h>
#include <comm\common.h>

/// @brief	�ַ����ָ�
/// @param  str   [in]  Ҫ�ָ���ַ���
/// @param  strv  [out] �ָ����ַ�������
/// @param  delim [in]  �ָ��־�ַ�
void StringSplit(std::string const& str,	std::vector<std::string>& strv, std::string const& delim);

/// @brief	�ַ���ƴ��
/// @retval ����ƴ�Ӻ���ַ���
/// @note	�����б������Ҫ�Զ��������־ ��NULL, ������쳣
/// @param  str1 [in]  Ҫ���ӵ��ַ��� 
/// @param  str2 [in]  Ҫ���ӵ��ַ��� 
/// @param  ...	 [in]  �����б�
/// @param  [in]  ������־ NULL
std::string strcat(char const* str1, char const* str2, ...);

/// @brief  �ַ����޼�����ȡ�ַ�����β�Ŀո��Ʊ�����س������У�
/// @retval ���ر��޼�����ַ�������
/// @note	���Ҳ������Ϊ����
std::string& trim(
	std::string& str  /// < [in][out]  ���޼��ַ���
	);

/// @brief  �ַ����д�д�ַ�תСд
void StringLower(
	std::string& str  /// <  [in][out] �������ַ���  ������ַ���
	);

/// @brief  �ַ�����Сдת��д	
void StringUpper(
	std::string& str   /// < [in][out] �������ַ��� ������ַ���
	);

/// @brief  ȥ���ַ����з���ĸ�ַ�
/// @retval ���ش������ַ���
std::string DislodgeStringNotChar(
	std::string& str  ///  <  [in]	�������ַ���		
	);

/// @brief  ȥ���ַ��������пո�
/// @retval ���ش������ַ���
std::string DislodgeStringSpace(
	std::string& str  /// < [in]  �������ַ���
	);