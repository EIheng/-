/*
头文件：
	资源路径
*/
#ifndef ResourcePath_
#define ResourcePath_

#include <sstream>
#include <iostream>
#include <map>
using namespace std;

class Resource_Path
{
public:
	Resource_Path()
	{
		Path.insert(pair<string, string>("Student", "Resource/Students.group"));
	}
	map<string, string> Path;
};
#endif