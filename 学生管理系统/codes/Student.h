/*
头文件：
	学生数据
	学生组及方法组
*/
#ifndef Student_
#define Student_

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "MyException.h"

using namespace std;

/*
类：
	一个学生的类，包含各种一位学生的数据
*/
class Student
{
public:
	// 类方法：创建一个空学生
	Student()
	{
		Number = "01";
		Name = "01";
		College = "01";
		Class = "01";
	}
	// 类方法：创建一个学生，自动输入数据
	Student(string Number, string Name, string College, string Class)
	{
		this->Number = Number;
		this->Name = Name;
		this->College = College;
		this->Class = Class;
	}
	string Number;				// 学号
	string Name;				// 姓名
	string College;				// 学院
	string Class;				// 班级
};
/*
类：
	一个学生组的类，包含学生组与相关管理方法
*/
class Students_Group
{
private:
	// 类属性：学生组
	vector<Student> S;
public:
	Students_Group()
	{
		ReadFile();
	}
	/*
	类方法集合：对文件处理
		读取文件中的相关信息或者将学生的数据输出到文件
	*/
	// 类方法：从文件中载入学生的数据
	void ReadFile()
	{
		string Number;				// 输入的学号
		string Name;				// 输入的姓名
		string College;				// 输入的学院
		string Class;				// 输入的班级
		fstream Stu_File;			// 打开的文件
		Stu_File.open("codes/Resource/Students.group", ios::in | ios::out);
		OpenFileException(Stu_File);
		string data;
		while (data != "结束")
		{
			Stu_File >> data;
			if (data == "{")
			{
				Stu_File >> Number;
				Stu_File >> Name;
				Stu_File >> College;
				Stu_File >> Class;
				S.push_back(Student(Number, Name, College, Class));
			}
		}
		Stu_File.close();
	}
	// 类方法：将学生表保存到文件中
	void OutToFile()
	{
		fstream Stu_File;			// 打开的文件
		Stu_File.open("codes/Resource/Students.group", ios::in | ios::out);
		OpenFileException(Stu_File);
		int Index = 0;
		for (Student i : S)
		{
			Stu_File << Index << endl;
			Stu_File << "{" << endl;
			Stu_File << "\t" << i.Number << endl;
			Stu_File << "\t" << i.Name << endl;
			Stu_File << "\t" << i.College << endl;
			Stu_File << "\t" << i.Class << endl;
			Stu_File << "}" << endl;
			Index += 1;
		}
		Stu_File << "结束" << endl;
		Stu_File.close();
	}
	/*
	类方法集合：创建相关方法
		创建一个学生，手动或者自动输入一些数据。
		我觉得这个自动输入有点……没用……
	*/
	// 类方法：创建一个学生，手动输入数据
	void Create()
	{
		string Number;				// 输入的学号
		string Name;				// 输入的姓名
		string College;				// 输入的学院
		string Class;				// 输入的班级
		cout << endl;	// 喜欢到处换行的我
		cout << "正在创建学生" << endl;
		cout << "请输入学号：";
		cin >> Number;
		cout << "请输入姓名：";
		cin >> Name;
		cout << "请输入学院：";
		cin >> College;
		cout << "请输入班级：";
		cin >> Class;
		cout << endl;
		Create(Number, Name, College, Class);
	}
	// 类方法：创建一个学生，并加入组末尾
	void Create(string Number, string Name, string College, string Class)
	{
		S.push_back(Student(Number, Name, College, Class));
	}
	/*
	类方法：
		通过输入数值来将一个学生插入组中
		但是这个方法很多余………………所以暂时保留了
	*/
	void Insert()
	{
		int Index;					// 输入的位置
		string Number;				// 输入的学号
		string Name;				// 输入的姓名
		string College;				// 输入的学院
		string Class;				// 输入的班级
		cout << "请输入要插入的位置" << endl;
		cin >> Index;
		cout << "请输入学号" << endl;
		cin >> Number;
		cout << "请输入姓名" << endl;
		cin >> Name;
		cout << "请输入学院" << endl;
		cin >> College;
		cout << "请输入班级" << endl;
		cin >> Class;
	}
	// 类方法：将一个学生从组中删除
	void Erase()
	{
		int Index;				// 学生索引
		int Next;				// 下一步操作
		string Information;		// 输入的学生信息
		Index = Find();
		// 删除
		S.erase(S.begin() + Index);
		cout << "删除成功！" << endl;
		cout << endl;
	}
	// 类方法：修改一个学生的数据
	void ChangeInformation()
	{
		int Index;				// 学生索引
		int Next;				// 下一步操作
		string Information;		// 输入的学生信息
		Index = Find();
		while (true)
		{
			cout
				<< "+-----------------------------------------------+" << endl
				<< "|            你想修改该学生的什么数据？         |" << endl
				<< "+-----------------------------------------------+" << endl
				<< "|1.学号                                         |" << endl
				<< "|2.姓名                                         |" << endl
				<< "|3.学院                                         |" << endl
				<< "|4.班级                                         |" << endl
				<< "|0.返回上一步操作                               |" << endl
				<< "+-----------------------------------------------+" << endl;
			cout << "请输入下一步操作:";
			cin >> Next;
			if (Next == 1)
			{
				cout << "将学号修改为" << endl;
				cout << "请输入：";
				cin >> Information;
				S[Index].Number = Information;
				cout << "修改学号成功！" << endl;
				break;
			}
			else if (Next == 2)
			{
				cout << "将姓名修改为" << endl;
				cout << "请输入：";
				cin >> Information;
				S[Index].Name = Information;
				cout << "修改姓名成功！" << endl;
				break;
			}
			else if (Next == 3)
			{
				cout << "将学院修改为" << endl;
				cout << "请输入：";
				cin >> Information;
				S[Index].College = Information;
				cout << "修改学院成功！" << endl;
				break;
			}
			else if (Next == 4)
			{
				cout << "将班级修改为" << endl;
				cout << "请输入：";
				cin >> Information;
				S[Index].Class = Information;
				cout << "修改班级成功！" << endl;
				break;
			}
			else if (Next == 0)
			{
				break;
			}
			else
			{
				cout << "请重新输入！" << endl;
			}
		}
		cout << endl;	// 依然喜欢空行的我
	}
	/*
	类方法集合：寻找相关方法
		包括手动寻找，寻找下标等
	*/
	// 类方法：手动寻找一个学生
	int Find()
	{
		string Information;			// 输入的信息
		int Index;					// 下标
		while (true)
		{
			cout << "寻找学生中" << endl;
			cout << "请输入这个学生的学号或者姓名：";
			cin >> Information;
			cout << endl;
			Index = FindIndex(Information);
			if (Index >= S.size())
			{
				cout << "没有该学生，请重新输入值！" << endl;
			}
			else
			{
				cout << "学生" << Index << "的学号为：" << S[Index].Number << endl;
				cout << "学生" << Index << "的姓名为：" << S[Index].Name << endl;
				cout << "学生" << Index << "的学院为：" << S[Index].College << endl;
				cout << "学生" << Index << "的班级为：" << S[Index].Class << endl;
				cout << endl;
				return Index;
			}
		}
	}
	// 类方法：通过学号寻找一个学生
	Student Find(string Number)
	{
		for (Student i : S)
		{
			if (i.Number == Number)
			{
				return i;
			}
		}
		cout << "查找失败，没有该学生！" << endl;
		return S[0];	// 这个S[0]的问题有点明显，等待修改……
	}
	// 类方法：寻找一个学生的下标
	int FindIndex(string Information)
	{
		int j = 0;
		for (Student i : S)
		{
			if (i.Number == Information or i.Name == Information)
			{
				return j;
			}
			j += 1;
		}
		// 如果没有找到该学生，则返回与S.size()相同的值
		return j;
	}
	/* 类方法：通过姓名寻找一个学生
	！
	存在的问题
	！
	Student Find(string Name)
	{
		for (Student i : S)
		{
			if (i.Name == Name)
			{
				return i;
			}
		}
		cout << "查找失败，没有该学生！" << endl;
		return S[0];
	}
	*/
	// 类方法：遍历并输出学生信息
	void Output()
	{
		int Index = 0;
		cout << endl << "所有学生数据：" << endl;
		for (Student i : S)
		{
			cout << "第" << Index << "位学生:" << endl;
			cout << "\t" << i.Number << endl;
			cout << "\t" << i.Name << endl;
			cout << "\t" << i.Class << endl;
			cout << "\t" << i.College << endl;
		}
		cout << endl;
	}
};
#endif
