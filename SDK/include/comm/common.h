/// @file:		common.h
/// @author:	ʯ��
/// @version:	1.0
/// @date:		2018/6/2 22:14
/// @brief:		����һЩ�궨��,�ͺ���

/**********************************************************************************
History:  //�޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ��
1.Date:
Author:
Modification:
2.��������
**********************************************************************************/

#ifndef _COMMON_H_
#define _COMMON_H_
#include <math.h>
#include <time.h>
#include <iostream>

/// @brief  �ַ�����󳤶�
const int STRING_MAX = 2048;

/// @brief  ���峣�ú�
#define MACRO_RETURN_IF(expr) if(expr){return;}
#define MACRO_RETURN_TRUE_IF(expr) if(expr){return true;}
#define MACRO_RETURN_NULLSTR_IF(expr) if(expr){return "";}
#define MACRO_RETURN_NULL_IF(expr) if(expr){return NULL;}
#define MACRO_RETURN_FALSE_IF(expr) if(expr){return false;}
#define MACRO_BREAK_IF(expr) if(expr){break;}
#define MACRO_CONTINUE_IF(expr) if(expr){continue;}

/// @brief �ж� double ֵ�Ƿ�Ϊ0
/// @retval false ��Ϊ0
/// @retval true  Ϊ0
bool IsDoubleZero(
	const double& d		/// < [in] ���
	);

/// @brief   ���ص�ǰʱ��
/// @retval  �����ַ���ʱ��(����˵���ַ���)
/// @note	 ����: ���ڵ�ʱ��: 2018/08/11 19:10:00
std::string GetTime(
	std::string const& str = ""   /// < [in] ʱ��ǰ�Ƿ��˵���ַ���
	);


#endif //_COMMON_H_