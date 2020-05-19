/*
Դ�ļ���
    ���Ծ���
*/
#include <iostream>
#include "matrix.h"

using namespace std;

int main(void)
{
    try
    {
        matrix<int> x(3, 2), y, z;
        int i, j;
        for (i = 1; i <= 3; i++)
            for (j = 1; j <= 2; j++)
                x(i, j) = 2 * i + j;
        cout << "��ʼ�� x(i,j) = 2*i + j" << endl;
        cout << "x(3,1) = " << x(3, 1) << endl;
        cout << "x=" << endl;;
        cout << x << endl;

        y = x;
        cout << "���� y = x" << endl;
        cout << "y=" << endl;
        cout << y << endl;

        x += 2;
        cout << "x ����2=" << endl;
        cout << x << endl;

        z = y + x;
        cout << "y + x=" << endl;
        cout << z << endl;

        cout << "-(y + x)=" << endl;
        cout << -z << endl;

        matrix<int> w(2, 3);
        for (i = 1; i <= 2; i++)
            for (j = 1; j <= 3; j++)
                w(i, j) = i + j;
        cout << "��ʼ��w(i,j) = i + j" << endl;
        cout << "w=" << endl;
        cout << w << endl;

        z = y * w;
        cout << "y * w=" << endl;
        cout << z << endl;
    }
    catch (...) 
    {
        cerr << "�����쳣��" << endl;
    }

    return 0;
}
