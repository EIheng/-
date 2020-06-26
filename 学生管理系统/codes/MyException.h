/*
头文件：
	异常事件管理
*/
#ifndef MyException_
#define MyException_

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void IndexException()
{
	cout << "下标异常！" << endl;
	throw "下标异常";
}

void OpenFileException(fstream& file1)
{
	if (!file1)
	{
		throw "文件没有被没有打开或者没有正常打开";
	}
}

#endif