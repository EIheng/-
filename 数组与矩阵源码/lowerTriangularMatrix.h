/*
头文件：
    三角矩阵
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
    int n;       // 矩阵阶
    T* element;  // 一维对角矩阵
};

// 构造函数(创建)
template<class T>
lowerTriangularMatrix<T>::lowerTriangularMatrix(int theN)
{
    // 输入有效性
    if (theN < 1)
        throw illegalParameterValue("矩阵阶数必须>0");
    // 创建
    n = theN;
    element = new T[n * (n + 1) / 2];
}
// 获取
template <class T>
T lowerTriangularMatrix<T>::get(int i, int j) const
{
    // 返回矩阵的(i, j)位置处的数
    // 输入有效性
    if (i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();

    // 若i >= j，则(i,j)在下三角形中
    if (i >= j)
        return element[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}
// 储存元素
template<class T>
void lowerTriangularMatrix<T>::set(int i, int j, const T& newValue)
{
    // 将newValue存储到矩阵中的(i，j)
    // 输入有效性
    if (i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();
    // 若i >= j，则(i,j)在下三角形中
    if (i >= j)
        element[i * (i - 1) / 2 + j - 1] = newValue;
    else
        if (newValue != 0)
            throw illegalParameterValue("不在下三角中的元素必须为零");
}

#endif
