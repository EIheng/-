/*
ͷ�ļ���
    �ԽǾ���
*/
#ifndef diagonalMatrix_
#define diagonalMatrix_


#include "myExceptions.h"

using namespace std;

template<class T>
class diagonalMatrix
{
public:
    diagonalMatrix(int theN = 10);
    ~diagonalMatrix() { delete[] element; }
    T get(int, int) const;
    void set(int, int, const T&);
private:
    int n;       // �����
    T* element;  // һά�ԽǾ���
};
// ���캯��(����)
template<class T>
diagonalMatrix<T>::diagonalMatrix(int theN)
{
    // ������Ч��
    if (theN < 1)
        throw illegalParameterValue("�����������>0");
    // ����
    n = theN;
    element = new T[n];
}
// ��ȡ
template <class T>
T diagonalMatrix<T>::get(int i, int j) const
{
    // ���ؾ����(i, j)λ�ô�����
    // ������Ч��
    if (i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();

    if (i == j)
        return element[i - 1];      // �Խ����ϵ�Ԫ��
    else
        return 0;                   // �ǶԽ����ϵ�Ԫ��
}
// ����Ԫ��
template<class T>
void diagonalMatrix<T>::set(int i, int j, const T& newValue)
{
    // ��newValue�洢�������е�(i��j)��
    // ������Ч��
    if (i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();
    if (i == j)
        element[i - 1] = newValue;  // ����Խ�����
    else
        if (newValue != 0)          // �ǶԽ�ֵ���������Ϊ0
            throw illegalParameterValue("�ǶԽ�Ԫ�ر���Ϊ��");
}

#endif
