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
void StringSplit(
	std::string const& str,			/// < [in]  Ҫ�ָ���ַ���
	std::vector<std::string>& strv, /// < [out] �ָ����ַ�������
	std::string const& delim		/// < [in]  �ָ��־�ַ�
	);

/// @brief	�ַ���ƴ��
/// @retval ����ƴ�Ӻ���ַ���
std::string strcat(
	char const* str1,	/// < [in]  Ҫ���ӵ��ַ��� 
	char const* str2,   /// < [in]
	...					/// < [in]  �����б�
	);

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
/// @note	
std::string DislodgeStringNotChar(
	std::string& str  ///  <  [in]	�������ַ���		
	);

/// @brief  ȥ���ַ��������пո�
/// @retval ���ش������ַ���
/// @note	
std::string DislodgeStringSpace(
	std::string& str  /// < [in]  �������ַ���
	);