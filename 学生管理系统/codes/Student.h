/*
ͷ�ļ���
	ѧ������
	ѧ���鼰������
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
�ࣺ
	һ��ѧ�����࣬��������һλѧ��������
*/
class Student
{
public:
	// �෽��������һ����ѧ��
	Student()
	{
		Number = "01";
		Name = "01";
		College = "01";
		Class = "01";
	}
	// �෽��������һ��ѧ�����Զ���������
	Student(string Number, string Name, string College, string Class)
	{
		this->Number = Number;
		this->Name = Name;
		this->College = College;
		this->Class = Class;
	}
	string Number;				// ѧ��
	string Name;				// ����
	string College;				// ѧԺ
	string Class;				// �༶
};
/*
�ࣺ
	һ��ѧ������࣬����ѧ��������ع�����
*/
class Students_Group
{
private:
	// �����ԣ�ѧ����
	vector<Student> S;
public:
	Students_Group()
	{
		ReadFile();
	}
	/*
	�෽�����ϣ����ļ�����
		��ȡ�ļ��е������Ϣ���߽�ѧ��������������ļ�
	*/
	// �෽�������ļ�������ѧ��������
	void ReadFile()
	{
		string Number;				// �����ѧ��
		string Name;				// ���������
		string College;				// �����ѧԺ
		string Class;				// ����İ༶
		fstream Stu_File;			// �򿪵��ļ�
		Stu_File.open("codes/Resource/Students.group", ios::in | ios::out);
		OpenFileException(Stu_File);
		string data;
		while (data != "����")
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
	// �෽������ѧ�����浽�ļ���
	void OutToFile()
	{
		fstream Stu_File;			// �򿪵��ļ�
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
		Stu_File << "����" << endl;
		Stu_File.close();
	}
	/*
	�෽�����ϣ�������ط���
		����һ��ѧ�����ֶ������Զ�����һЩ���ݡ�
		�Ҿ�������Զ������е㡭��û�á���
	*/
	// �෽��������һ��ѧ�����ֶ���������
	void Create()
	{
		string Number;				// �����ѧ��
		string Name;				// ���������
		string College;				// �����ѧԺ
		string Class;				// ����İ༶
		cout << endl;	// ϲ���������е���
		cout << "���ڴ���ѧ��" << endl;
		cout << "������ѧ�ţ�";
		cin >> Number;
		cout << "������������";
		cin >> Name;
		cout << "������ѧԺ��";
		cin >> College;
		cout << "������༶��";
		cin >> Class;
		cout << endl;
		Create(Number, Name, College, Class);
	}
	// �෽��������һ��ѧ������������ĩβ
	void Create(string Number, string Name, string College, string Class)
	{
		S.push_back(Student(Number, Name, College, Class));
	}
	/*
	�෽����
		ͨ��������ֵ����һ��ѧ����������
		������������ܶ��࡭����������������ʱ������
	*/
	void Insert()
	{
		int Index;					// �����λ��
		string Number;				// �����ѧ��
		string Name;				// ���������
		string College;				// �����ѧԺ
		string Class;				// ����İ༶
		cout << "������Ҫ�����λ��" << endl;
		cin >> Index;
		cout << "������ѧ��" << endl;
		cin >> Number;
		cout << "����������" << endl;
		cin >> Name;
		cout << "������ѧԺ" << endl;
		cin >> College;
		cout << "������༶" << endl;
		cin >> Class;
	}
	// �෽������һ��ѧ��������ɾ��
	void Erase()
	{
		int Index;				// ѧ������
		int Next;				// ��һ������
		string Information;		// �����ѧ����Ϣ
		Index = Find();
		// ɾ��
		S.erase(S.begin() + Index);
		cout << "ɾ���ɹ���" << endl;
		cout << endl;
	}
	// �෽�����޸�һ��ѧ��������
	void ChangeInformation()
	{
		int Index;				// ѧ������
		int Next;				// ��һ������
		string Information;		// �����ѧ����Ϣ
		Index = Find();
		while (true)
		{
			cout
				<< "+-----------------------------------------------+" << endl
				<< "|            �����޸ĸ�ѧ����ʲô���ݣ�         |" << endl
				<< "+-----------------------------------------------+" << endl
				<< "|1.ѧ��                                         |" << endl
				<< "|2.����                                         |" << endl
				<< "|3.ѧԺ                                         |" << endl
				<< "|4.�༶                                         |" << endl
				<< "|0.������һ������                               |" << endl
				<< "+-----------------------------------------------+" << endl;
			cout << "��������һ������:";
			cin >> Next;
			if (Next == 1)
			{
				cout << "��ѧ���޸�Ϊ" << endl;
				cout << "�����룺";
				cin >> Information;
				S[Index].Number = Information;
				cout << "�޸�ѧ�ųɹ���" << endl;
				break;
			}
			else if (Next == 2)
			{
				cout << "�������޸�Ϊ" << endl;
				cout << "�����룺";
				cin >> Information;
				S[Index].Name = Information;
				cout << "�޸������ɹ���" << endl;
				break;
			}
			else if (Next == 3)
			{
				cout << "��ѧԺ�޸�Ϊ" << endl;
				cout << "�����룺";
				cin >> Information;
				S[Index].College = Information;
				cout << "�޸�ѧԺ�ɹ���" << endl;
				break;
			}
			else if (Next == 4)
			{
				cout << "���༶�޸�Ϊ" << endl;
				cout << "�����룺";
				cin >> Information;
				S[Index].Class = Information;
				cout << "�޸İ༶�ɹ���" << endl;
				break;
			}
			else if (Next == 0)
			{
				break;
			}
			else
			{
				cout << "���������룡" << endl;
			}
		}
		cout << endl;	// ��Ȼϲ�����е���
	}
	/*
	�෽�����ϣ�Ѱ����ط���
		�����ֶ�Ѱ�ң�Ѱ���±��
	*/
	// �෽�����ֶ�Ѱ��һ��ѧ��
	int Find()
	{
		string Information;			// �������Ϣ
		int Index;					// �±�
		while (true)
		{
			cout << "Ѱ��ѧ����" << endl;
			cout << "���������ѧ����ѧ�Ż���������";
			cin >> Information;
			cout << endl;
			Index = FindIndex(Information);
			if (Index >= S.size())
			{
				cout << "û�и�ѧ��������������ֵ��" << endl;
			}
			else
			{
				cout << "ѧ��" << Index << "��ѧ��Ϊ��" << S[Index].Number << endl;
				cout << "ѧ��" << Index << "������Ϊ��" << S[Index].Name << endl;
				cout << "ѧ��" << Index << "��ѧԺΪ��" << S[Index].College << endl;
				cout << "ѧ��" << Index << "�İ༶Ϊ��" << S[Index].Class << endl;
				cout << endl;
				return Index;
			}
		}
	}
	// �෽����ͨ��ѧ��Ѱ��һ��ѧ��
	Student Find(string Number)
	{
		for (Student i : S)
		{
			if (i.Number == Number)
			{
				return i;
			}
		}
		cout << "����ʧ�ܣ�û�и�ѧ����" << endl;
		return S[0];	// ���S[0]�������е����ԣ��ȴ��޸ġ���
	}
	// �෽����Ѱ��һ��ѧ�����±�
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
		// ���û���ҵ���ѧ�����򷵻���S.size()��ͬ��ֵ
		return j;
	}
	/* �෽����ͨ������Ѱ��һ��ѧ��
	��
	���ڵ�����
	��
	Student Find(string Name)
	{
		for (Student i : S)
		{
			if (i.Name == Name)
			{
				return i;
			}
		}
		cout << "����ʧ�ܣ�û�и�ѧ����" << endl;
		return S[0];
	}
	*/
	// �෽�������������ѧ����Ϣ
	void Output()
	{
		int Index = 0;
		cout << endl << "����ѧ�����ݣ�" << endl;
		for (Student i : S)
		{
			cout << "��" << Index << "λѧ��:" << endl;
			cout << "\t" << i.Number << endl;
			cout << "\t" << i.Name << endl;
			cout << "\t" << i.Class << endl;
			cout << "\t" << i.College << endl;
		}
		cout << endl;
	}
};
#endif
