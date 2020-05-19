/*
头文件：
    对角矩阵
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
    int n;       // 矩阵阶
    T* element;  // 一维对角矩阵
};
// 构造函数(创建)
template<class T>
diagonalMatrix<T>::diagonalMatrix(int theN)
{
    // 输入有效性
    if (theN < 1)
        throw illegalParameterValue("矩阵阶数必须>0");
    // 创建
    n = theN;
    element = new T[n];
}
// 获取
template <class T>
T diagonalMatrix<T>::get(int i, int j) const
{
    // 返回矩阵的(i, j)位置处的数
    // 输入有效性
    if (i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();

    if (i == j)
        return element[i - 1];      // 对角线上的元素
    else
        return 0;                   // 非对角线上的元素
}
// 储存元素
template<class T>
void diagonalMatrix<T>::set(int i, int j, const T& newValue)
{
    // 将newValue存储到矩阵中的(i，j)。
    // 输入有效性
    if (i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();
    if (i == j)
        element[i - 1] = newValue;  // 保存对角数据
    else
        if (newValue != 0)          // 非对角值，输入必须为0
            throw illegalParameterValue("非对角元素必须为零");
}

#endif
