/*
头文件：
	主要方法组
*/
#ifndef MainMethod_
#define MainMethod_

#include <sstream>
#include <iostream>
#include <string>
#include <vector>

#include "Meun.h"
#include "Administrators.h"
#include "Student.h"
using namespace std;

/*
类：
	主要方法组
*/
class MainMethod
{
private:
	/*对象声明*/
	Meun Meun_OfMain;										// 主菜单
	Administrators_Group Administrators_Group_OfMain;		// 管理员组
	Students_Group Students_Group_OfMain;					// 学生组
	Administrators Land_OfMain;								// 登陆者
public:
	MainMethod
	(
		Meun Meun_OfMain, 
		Administrators_Group Administrators_Group_OfMain, 
		Students_Group Students_Group_OfMain, 
		Administrators Land_OfMain
	)
	{
		this->Meun_OfMain = Meun_OfMain;
		this->Administrators_Group_OfMain = Administrators_Group_OfMain;
		this->Students_Group_OfMain = Students_Group_OfMain;
		this->Land_OfMain = Land_OfMain;
	}
	/*
	类方法：
		登陆（）
		这个方法有一个问题，就是一定要通过登陆，就是说无法退出……应该加一个退出选项
	*/
	bool Land()
	{
		/*数值初始化*/
		int Next;					// 下一步操作
		string AccountNumber;		// 账号
		string Password;			// 密码
		/*进入登陆循环*/
		while (true)
		{
			Meun_OfMain.Land();
			Meun_OfMain.Next();
			cin >> Next;
			if (Next == 1)			// 注册
			{
				Register();
			}
			else if (Next == 2)		// 登陆
			{
				while (true)
				{
					cout << "请输入账号：";
					cin >> AccountNumber;
					cout << "请输入密码：";
					cin >> Password;
					if (AccountNumber == "返回上一步！")
					{
						continue;
					}
					if (Administrators_Group_OfMain.IsCorrect(AccountNumber, Password))
					{
						Land_OfMain = Administrators_Group_OfMain.Find(AccountNumber);
						return true;
					}
					else
					{
						cout << "!!!账号密码错误，请重新输入，如果想回到上一步，请在输入账号时输入“返回上一步！”!!!" << endl;
					}
				}
			}
			else if (Next == 0)
			{
				break;
			}
		}
		return false;
	}
	// 类方法：注册（）
	void Register()
	{
		/*数值初始化*/
		string AccountNumber;		// 账号
		string Password;			// 密码
		string PassWord_2;			// 二次输入的密码
		string Name;				// 名称
		/*进入注册循环*/
		while (true)
		{
			Meun_OfMain.Register();
			cout << "请输入账号：";
			cin >> AccountNumber;
			cout << endl;		// 换个行
			if (Administrators_Group_OfMain.IsExist(AccountNumber) == false)
			{
				cout << "请输入密码：";
				cin >> Password;
				cout << endl;	// 再换个行
				cout << "请再次输入密码：";
				cin >> PassWord_2;
				cout << endl;	// 我还要换个行
				if (Password != PassWord_2)
				{
					cout << "两次输入密码不一致，请重新输入！" << endl;
					continue;
				}
				cout << "请输入名称：";
				cin >> Name;
				cout << endl;	// 再再再换个行！
				break;
			}
		}
		cout << "注册成功！" << endl;
		Administrators_Group_OfMain.Create(AccountNumber, Password, Name);
		cout << "你好，" << Name << "，接下来将进入初始界面。" << endl;
		// 创建
	}
	// 类方法：管理员主界面
	void AdministratorsMain()
	{
		/*数值初始化*/
		int Next;					// 下一步操作
		while (true)
		{
			Meun_OfMain.MainOfAdministrators(Land_OfMain.Name);
			Meun_OfMain.Next();
			cin >> Next;
			if (Next == 1)
			{
				Students_Group_OfMain.Output();
			}
			else if (Next == 2)
			{
				Students_Group_OfMain.Create();
			}
			else if (Next == 3)
			{
				Students_Group_OfMain.Find();
			}
			else if (Next == 4)
			{
				Students_Group_OfMain.ChangeInformation();
			}
			else if (Next == 5)
			{
				Students_Group_OfMain.Erase();
			}
			else if (Next == 6)
			{
				Students_Group_OfMain.OutToFile();
			}
			else
			{
				cout << "请重新输入！" << endl;
			}
		}
	}
};

#endif
