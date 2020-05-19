/*
头文件：
    三对角矩阵
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
    int n;       // 矩阵阶
    T* element;  // 一维对角矩阵
};
// 构造函数(创建)
template<class T>
tridiagonalMatrix<T>::tridiagonalMatrix(int theN)
{
    // 输入有效性
    if (theN < 1)
        throw illegalParameterValue("矩阵阶数必须>0");
    // 创建
    n = theN;
    element = new T[3 * n - 2];
}

template <class T>
T tridiagonalMatrix<T>::get(int i, int j) const
{
    // 返回矩阵的(i, j)位置处的数
    // 输入有效性
    if (i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();
    // 确定要返回的数
    switch (i - j)
    {
    case 1:     // 下三角
        return element[i - 2];
    case 0:     // 对角线上
        return element[n + i - 2];
    case -1:    // 上三角
        return element[2 * n + i - 2];
    default: 
        return 0;
    }
}

template<class T>
void tridiagonalMatrix<T>::set(int i, int j, const T& newValue)
{
    // 将newValue存储到矩阵中的(i，j)。
    // 输入有效性
    if (i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();

    switch (i - j)
    {
    case 1:     // 下三角
        element[i - 2] = newValue;
        break;
    case 0:     // 对角线上
        element[n + i - 2] = newValue;
        break;
    case -1:    // 上三角
        element[2 * n + i - 2] = newValue;
        break;
    default:
        if (newValue != 0)
            throw illegalParameterValue("非三对角元素必须为零");
    }
}

#endif
