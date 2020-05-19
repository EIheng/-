#ifndef matrix_
#define matrix_

#include "myExceptions.h"

using namespace std;

template<class T>
class matrix
{
    friend ostream& operator<<(ostream&, const matrix<T>&);
public:
    matrix(int theRows = 0, int theColumns = 0);
    matrix(const matrix<T>&);
    ~matrix() { delete[] element; }
    int rows() const { return theRows; }
    int columns() const { return theColumns; }
    T& operator()(int i, int j) const;
    matrix<T>& operator=(const matrix<T>&);
    matrix<T> operator+(const matrix<T>&) const;// 一元加
    matrix<T> operator-() const; // 一元减
    matrix<T> operator-(const matrix<T>&) const;
    matrix<T> operator*(const matrix<T>&) const;
    matrix<T>& operator+=(const T&);
private:
    int theRows,    // 矩阵的行数
        theColumns; // 矩阵的列数
    T* element;     // 数组element
};
// 矩阵构造函数(创建)
template<class T>
matrix<T>::matrix(int theRows, int theColumns)
{
    // 检验行数与列数的有效性
    if (theRows < 0 || theColumns < 0)
        throw illegalParameterValue("行列数必须 >= 0");
    if ((theRows == 0 || theColumns == 0)
        && (theRows != 0 || theColumns != 0))
        throw illegalParameterValue("行和列都不应为零");

    // 创建矩阵
    this->theRows = theRows;
    this->theColumns = theColumns;
    element = new T[theRows * theColumns];
}
// 矩阵构造函数(复制)
template<class T>
matrix<T>::matrix(const matrix<T>& m)
{
    // 创建矩阵
    theRows = m.theRows;
    theColumns = m.theColumns;
    element = new T[theRows * theColumns];

    // 复制元素
    copy(m.element, m.element + theRows * theColumns, element);
}
// 重载=
template<class T>
matrix<T>& matrix<T>::operator=(const matrix<T>& m)
{
    // 赋值(*this) = m.
    if (this != &m)
    {
        // 不能自己复制自己
        delete[] element;
        theRows = m.theRows;
        theColumns = m.theColumns;
        element = new T[theRows * theColumns];
        // 复制每一个元素
        copy(m.element, m.element + theRows * theColumns, element);
    }
    return *this;
}
// 对()操作符重载
template<class T>
T& matrix<T>::operator()(int i, int j) const
{
    // 返回对元素element(i, j)的引用
    if (i < 1 || i > theRows
        || j < 1 || j > theColumns)
        throw matrixIndexOutOfBounds();
    return element[(i - 1) * theColumns + j - 1];
}
// 矩阵加法，重载+
template<class T>
matrix<T> matrix<T>::operator+(const matrix<T>& m) const
{
    // 返回本身矩阵+矩阵m
    // 行列可行性检测
    if (theRows != m.theRows || theColumns != m.theColumns)
        throw matrixSizeMismatch();

    // 创建结果矩阵
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i] + m.element[i];
    // 返回结果矩阵
    return w;
}
// 矩阵减法，重载-
template<class T>
matrix<T> matrix<T>::operator-(const matrix<T>& m) const
{
    // 返回本身矩阵-矩阵m
    // 行列可行性检测
    if (theRows != m.theRows || theColumns != m.theColumns)
        throw matrixSizeMismatch();

    // 创建结果矩阵
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i] - m.element[i];
    // 返回结果矩阵
    return w;
}
// 将矩阵变号，重载-
template<class T>
matrix<T> matrix<T>::operator-() const
{
    // 返回-矩阵
    // 创建结果矩阵
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = -element[i];
    // 返回结果矩阵
    return w;

}
// 矩阵乘法，重载*
template<class T>
matrix<T> matrix<T>::operator*(const matrix<T>& m) const
{
    // 返回本身*矩阵m
    // 行列可行性检测
    if (theColumns != m.theRows)
        throw matrixSizeMismatch();
    // 创建结果矩阵
    matrix<T> w(theRows, m.theColumns);

    // 为*this, m, w定义光标
    // 初始化位置到(1, 1)
    int ct = 0, cm = 0, cw = 0;

    // 为所有i与j计算所有 w(i,j)
    for (int i = 1; i <= theRows; i++)
    {
        // 计算行i的结果
        for (int j = 1; j <= m.theColumns; j++)
        { 
            // 计算w(i,j)的结果
            T sum = element[ct] * m.element[cm];

            // 添加剩余
            for (int k = 2; k <= theColumns; k++)
            {
                ct++;  // i的下一行
                cm += m.theColumns;  // m的j列的下一个
                sum += element[ct] * m.element[cm];
            }
            w.element[cw++] = sum;  // 保存w(i,j)

            // 重置行，开始下一列
            ct -= theColumns - 1;
            cm = j;
        }

        // 开始下一行，重置列
        ct += theColumns;
        cm = 0;
    }
    // 返回结果矩阵
    return w;
}
// 将矩阵中所有数增加x
template<class T>
matrix<T>& matrix<T>::operator+=(const T& x)
{
    for (int i = 0; i < theRows * theColumns; i++)
        element[i] += x;
    return *this;
}
// 将矩阵m放入流中
template<class T>
ostream& operator<<(ostream& out, const matrix<T>& m)
{
    int k = 0;  // 下标
    for (int i = 0; i < m.theRows; i++)
    {
        // 行
        for (int j = 0; j < m.theColumns; j++)
            out << m.element[k++] << "  ";

        // 一行结束
        out << endl;
    }

    return out;
}
// 由于某些原因，编译器不能自己创建（这段代码不能删！！报错也不能删！）
ostream& operator<<(ostream& out, const matrix<int>& m)
{
    int k = 0;
    for (int i = 0; i < m.theRows; i++)
    {
        for (int j = 0; j < m.theColumns; j++)
            out << m.element[k++] << "  ";
        out << endl;
    }
    return out;
}

#endif
