/*
ͷ�ļ���
	�쳣�¼�����
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
	cout << "�±��쳣��" << endl;
	throw "�±��쳣";
}

void OpenFileException(fstream& file1)
{
	if (!file1)
	{
		throw "�ļ�û�б�û�д򿪻���û��������";
	}
}

#endif