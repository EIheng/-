/*
ͷ�ļ���
    ���Ǿ���
*/
#ifndef lowerTriangularMatrix_
#define lowerTriangularMatrix_


#include "myExceptions.h"

using namespace std;

template<class T>
class lowerTriangularMatrix
{
public:
    lowerTriangularMatrix(int theN = 10);
    ~lowerTriangularMatrix() { delete[] element; }
    T get(int, int) const;
    void set(int, int, const T&);
private:
    int n;       // �����
    T* element;  // һά�ԽǾ���
};

// ���캯��(����)
template<class T>
lowerTriangularMatrix<T>::lowerTriangularMatrix(int theN)
{
    // ������Ч��
    if (theN < 1)
        throw illegalParameterValue("�����������>0");
    // ����
    n = theN;
    element = new T[n * (n + 1) / 2];
}
// ��ȡ
template <class T>
T lowerTriangularMatrix<T>::get(int i, int j) const
{
    // ���ؾ����(i, j)λ�ô�����
    // ������Ч��
    if (i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();

    // ��i >= j����(i,j)������������
    if (i >= j)
        return element[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}
// ����Ԫ��
template<class T>
void lowerTriangularMatrix<T>::set(int i, int j, const T& newValue)
{
    // ��newValue�洢�������е�(i��j)
    // ������Ч��
    if (i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();
    // ��i >= j����(i,j)������������
    if (i >= j)
        element[i * (i - 1) / 2 + j - 1] = newValue;
    else
        if (newValue != 0)
            throw illegalParameterValue("�����������е�Ԫ�ر���Ϊ��");
}

#endif
