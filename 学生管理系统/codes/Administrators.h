/*
ͷ�ļ���
	����Ա����
*/
#ifndef Administrators_
#define Administrators_

#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
�ࣺ����Ա
	��������Ա�ĸ�������
*/
class Administrators
{
public:
	// ���캯����һ���չ���Ա
	Administrators()
	{
		AccountNumber = "sf@#$fds";
		Password = "asdfsa324GDSD";
		Name = "sF#H:REDD@$34";
	}
	// ���캯��������һ������Ա
	Administrators(string AccountNumber, string Password, string Name)
	{
		this->AccountNumber = AccountNumber;
		this->Password = Password;
		this->Name = Name;
	}
	string AccountNumber;	// �˺�
	string Password;		// ����
	string Name;			// ����
};
/*�ࣺ����Ա�鼰�䷽����*/
class Administrators_Group
{
private:
	vector<Administrators> A;		// ����Ա��
public:
	Administrators_Group()
	{
		A.push_back(Administrators("root", "1!", "��߹���Ա��Ļ��"));
	}
	// �෽�������Ƿ�Ϊ��
	bool Empty()
	{
		return A.empty();
	}
	// �෽�����������Ա������
	int Size()
	{
		return int(A.size());
	}
	// �෽��������һ������Ա����������ĩβ
	void Create(string AccountNumber, string Password, string Name)
	{
		A.push_back(Administrators(AccountNumber, Password, Name));
		cout << "����Ա�����ɹ���" << endl;
	}
	// �෽������һ������Ա��������
	void Insert()
	{
		cout << "����" << endl;
	}
	// �෽������һ�����������ɾ��
	void Erase()
	{
		// Ѱ�ҹ���
		// ɾ��
	}
	// �෽�����ֶ�Ѱ��һ������Ա
	Administrators Find()
	{
		cout << "����" << endl;
	}
	// �෽����ͨ���˺�Ѱ��һ������Ա
	Administrators Find(string AccountNumber)
	{
		for (Administrators i : A)
		{
			if (i.AccountNumber == AccountNumber)
			{
				return i;
			}
		}
		// ������Ҫ���б������
		cout << "����ʧ�ܣ�û�иù���Ա��" << endl;
		return A[0];
	}
	/* �෽����ͨ������Ѱ��һ������Ա
	��������������Ǹ�ͨ���˺Ų��Ҳ����������ԣ�֮�������ʱ�����޸�
	Administrators Find(string Name)
	{
		for (Administrators i : A)
		{
			if (i.Name == Name)
			{
				return i;
			}
		}
		// ������Ҫ���б������
		cout << "����ʧ�ܣ�û�иù���Ա��" << endl;
		return A[0];
	}
	*/
	// �෽�����ж��˺������Ƿ���ȷ
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
	�෽����
		�����������˺��ж��Ƿ��ڱ���
		!!!!!!!!!!!!!!!!!!!
		Ŀǰ��һ�����⣬���ǽ��˺�����������һ��ͬʱ�жϣ�����Ժ�Ҫͨ������Ѱ�ҵĻ������һЩ��ֵ�bug
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