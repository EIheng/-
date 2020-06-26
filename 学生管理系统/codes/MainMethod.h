/*
ͷ�ļ���
	��Ҫ������
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
�ࣺ
	��Ҫ������
*/
class MainMethod
{
private:
	/*��������*/
	Meun Meun_OfMain;										// ���˵�
	Administrators_Group Administrators_Group_OfMain;		// ����Ա��
	Students_Group Students_Group_OfMain;					// ѧ����
	Administrators Land_OfMain;								// ��½��
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
	�෽����
		��½����
		���������һ�����⣬����һ��Ҫͨ����½������˵�޷��˳�����Ӧ�ü�һ���˳�ѡ��
	*/
	bool Land()
	{
		/*��ֵ��ʼ��*/
		int Next;					// ��һ������
		string AccountNumber;		// �˺�
		string Password;			// ����
		/*�����½ѭ��*/
		while (true)
		{
			Meun_OfMain.Land();
			Meun_OfMain.Next();
			cin >> Next;
			if (Next == 1)			// ע��
			{
				Register();
			}
			else if (Next == 2)		// ��½
			{
				while (true)
				{
					cout << "�������˺ţ�";
					cin >> AccountNumber;
					cout << "���������룺";
					cin >> Password;
					if (AccountNumber == "������һ����")
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
						cout << "!!!�˺�����������������룬�����ص���һ�������������˺�ʱ���롰������һ������!!!" << endl;
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
	// �෽����ע�ᣨ��
	void Register()
	{
		/*��ֵ��ʼ��*/
		string AccountNumber;		// �˺�
		string Password;			// ����
		string PassWord_2;			// �������������
		string Name;				// ����
		/*����ע��ѭ��*/
		while (true)
		{
			Meun_OfMain.Register();
			cout << "�������˺ţ�";
			cin >> AccountNumber;
			cout << endl;		// ������
			if (Administrators_Group_OfMain.IsExist(AccountNumber) == false)
			{
				cout << "���������룺";
				cin >> Password;
				cout << endl;	// �ٻ�����
				cout << "���ٴ��������룺";
				cin >> PassWord_2;
				cout << endl;	// �һ�Ҫ������
				if (Password != PassWord_2)
				{
					cout << "�����������벻һ�£����������룡" << endl;
					continue;
				}
				cout << "���������ƣ�";
				cin >> Name;
				cout << endl;	// �����ٻ����У�
				break;
			}
		}
		cout << "ע��ɹ���" << endl;
		Administrators_Group_OfMain.Create(AccountNumber, Password, Name);
		cout << "��ã�" << Name << "���������������ʼ���档" << endl;
		// ����
	}
	// �෽��������Ա������
	void AdministratorsMain()
	{
		/*��ֵ��ʼ��*/
		int Next;					// ��һ������
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
				cout << "���������룡" << endl;
			}
		}
	}
};

#endif
