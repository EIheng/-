/*
头文件：
	管理员数据
*/
#ifndef Administrators_
#define Administrators_

#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
类：管理员
	包含管理员的各项属性
*/
class Administrators
{
public:
	// 构造函数：一个空管理员
	Administrators()
	{
		AccountNumber = "sf@#$fds";
		Password = "asdfsa324GDSD";
		Name = "sF#H:REDD@$34";
	}
	// 构造函数：创建一个管理员
	Administrators(string AccountNumber, string Password, string Name)
	{
		this->AccountNumber = AccountNumber;
		this->Password = Password;
		this->Name = Name;
	}
	string AccountNumber;	// 账号
	string Password;		// 密码
	string Name;			// 姓名
};
/*类：管理员组及其方法组*/
class Administrators_Group
{
private:
	vector<Administrators> A;		// 管理员组
public:
	Administrators_Group()
	{
		A.push_back(Administrators("root", "1!", "最高管理员：幕冬"));
	}
	// 类方法：组是否为空
	bool Empty()
	{
		return A.empty();
	}
	// 类方法：组里管理员的数量
	int Size()
	{
		return int(A.size());
	}
	// 类方法：创建一个管理员，并加入组末尾
	void Create(string AccountNumber, string Password, string Name)
	{
		A.push_back(Administrators(AccountNumber, Password, Name));
		cout << "管理员创建成功！" << endl;
	}
	// 类方法：将一个管理员插入组中
	void Insert()
	{
		cout << "待定" << endl;
	}
	// 类方法：将一个管理从组中删除
	void Erase()
	{
		// 寻找管理
		// 删除
	}
	// 类方法：手动寻找一个管理员
	Administrators Find()
	{
		cout << "待定" << endl;
	}
	// 类方法：通过账号寻找一个管理员
	Administrators Find(string AccountNumber)
	{
		for (Administrators i : A)
		{
			if (i.AccountNumber == AccountNumber)
			{
				return i;
			}
		}
		// 这里需要进行报错操作
		cout << "查找失败，没有该管理员！" << endl;
		return A[0];
	}
	/* 类方法：通过姓名寻找一个管理员
	这个方法与上面那个通过账号查找产生了两义性，之后如果有时间再修改
	Administrators Find(string Name)
	{
		for (Administrators i : A)
		{
			if (i.Name == Name)
			{
				return i;
			}
		}
		// 这里需要进行报错操作
		cout << "查找失败，没有该管理员！" << endl;
		return A[0];
	}
	*/
	// 类方法：判断账号密码是否正确
	bool IsCorrect(string AccountNumber, string Password)
	{
		for (Administrators i : A)
		{
			if (i.AccountNumber == AccountNumber)
			{
				if (i.Password == Password)
				{
					return true;
				}
				return false;
			}
		}
		return false;
	}
	/*
	类方法：
		该姓名或者账号判断是否在表中
		!!!!!!!!!!!!!!!!!!!
		目前有一个问题，就是将账号与姓名放在一起同时判断，如果以后还要通过姓名寻找的话会出现一些奇怪的bug
		!!!!!!!!!!!!!!!!!!!
	*/
	bool IsExist(string AccountNumberOrName)
	{
		for (Administrators i : A)
		{
			if ((i.AccountNumber == AccountNumberOrName) or (i.Name == AccountNumberOrName))
			{
				return true;
			}
		}
		return false;
	}
};
#endif