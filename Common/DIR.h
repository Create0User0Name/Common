/*********************************************************************************
*Copyright(C),2010-2011
*FileName:		//DIR.h DIR.cpp
*Author:		//shijie
*Version:		//1.0
*Date:			//2018/6/2 22:20
*Description:	//对文件夹的操作

//使用到了StringDispose.cpp中的函数StringSplit

*Others:		//无
*Function List: 
1.static bool CreateDir(const std::string& path);
	功能：  创建文件夹，可创建多级
	参数：  创建文件路径
	返回值：成功 true， 失败false
2.static std::string& GetWorkPath(std::string& path);
	功能：  获得当前工作路径
	参数：  保存路径字符串
	返回值：无 

*History:  //修改历史记录列表，每条修改记录应包含修改日期、修改者及修改内容简介
1.Date:
Author:
Modification:
2.…………
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


