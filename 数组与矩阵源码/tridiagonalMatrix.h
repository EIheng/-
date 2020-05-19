/*
ͷ�ļ���
    ���ԽǾ���
*/

#ifndef tridiagonal_
#define tridiagonal_


#include "myExceptions.h"

using namespace std;

template<class T>
class tridiagonalMatrix
{
public:
    tridiagonalMatrix(int theN = 10);
    ~tridiagonalMatrix() { delete[] element; }
    T get(int, int) const;
    void set(int, int, const T&);
private:
    int n;       // �����
    T* element;  // һά�ԽǾ���
};
// ���캯��(����)
template<class T>
tridiagonalMatrix<T>::tridiagonalMatrix(int theN)
{
    // ������Ч��
    if (theN < 1)
        throw illegalParameterValue("�����������>0");
    // ����
    n = theN;
    element = new T[3 * n - 2];
}

template <class T>
T tridiagonalMatrix<T>::get(int i, int j) const
{
    // ���ؾ����(i, j)λ�ô�����
    // ������Ч��
    if (i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();
    // ȷ��Ҫ���ص���
    switch (i - j)
    {
    case 1:     // ������
        return element[i - 2];
    case 0:     // �Խ�����
        return element[n + i - 2];
    case -1:    // ������
        return element[2 * n + i - 2];
    default: 
        return 0;
    }
}

template<class T>
void tridiagonalMatrix<T>::set(int i, int j, const T& newValue)
{
    // ��newValue�洢�������е�(i��j)��
    // ������Ч��
    if (i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();

    switch (i - j)
    {
    case 1:     // ������
        element[i - 2] = newValue;
        break;
    case 0:     // �Խ�����
        element[n + i - 2] = newValue;
        break;
    case -1:    // ������
        element[2 * n + i - 2] = newValue;
        break;
    default:
        if (newValue != 0)
            throw illegalParameterValue("�����Խ�Ԫ�ر���Ϊ��");
    }
}

#endif
