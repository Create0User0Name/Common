/*********************************************************************************
*Copyright(C),2010-2011
*FileName:		//DIR.h DIR.cpp
*Author:		//shijie
*Version:		//1.0
*Date:			//2018/6/2 22:20
*Description:	//���ļ��еĲ���

//ʹ�õ���StringDispose.cpp�еĺ���StringSplit

*Others:		//��
*Function List: 
1.static bool CreateDir(const std::string& path);
	���ܣ�  �����ļ��У��ɴ����༶
	������  �����ļ�·��
	����ֵ���ɹ� true�� ʧ��false
2.static std::string& GetWorkPath(std::string& path);
	���ܣ�  ��õ�ǰ����·��
	������  ����·���ַ���
	����ֵ���� 

*History:  //�޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ��
1.Date:
Author:
Modification:
2.��������
**********************************************************************************/

#ifndef _DIR_H_
#define _DIR_H_
#include <iostream>
#include <string>
#include "StringDispose.h"
#include "common.h"
#include <direct.h>
//#include <unistd.h> //UNIX

class DIR
{
public:
	DIR();
	~DIR();
	static bool CreateDir(const std::string& path);
	static std::string& GetWorkPath(std::string& path);
};

#endif _DIR_H_


