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
    matrix<T> operator+(const matrix<T>&) const;// һԪ��
    matrix<T> operator-() const; // һԪ��
    matrix<T> operator-(const matrix<T>&) const;
    matrix<T> operator*(const matrix<T>&) const;
    matrix<T>& operator+=(const T&);
private:
    int theRows,    // ���������
        theColumns; // ���������
    T* element;     // ����element
};
// �����캯��(����)
template<class T>
matrix<T>::matrix(int theRows, int theColumns)
{
    // ������������������Ч��
    if (theRows < 0 || theColumns < 0)
        throw illegalParameterValue("���������� >= 0");
    if ((theRows == 0 || theColumns == 0)
        && (theRows != 0 || theColumns != 0))
        throw illegalParameterValue("�к��ж���ӦΪ��");

    // ��������
    this->theRows = theRows;
    this->theColumns = theColumns;
    element = new T[theRows * theColumns];
}
// �����캯��(����)
template<class T>
matrix<T>::matrix(const matrix<T>& m)
{
    // ��������
    theRows = m.theRows;
    theColumns = m.theColumns;
    element = new T[theRows * theColumns];

    // ����Ԫ��
    copy(m.element, m.element + theRows * theColumns, element);
}
// ����=
template<class T>
matrix<T>& matrix<T>::operator=(const matrix<T>& m)
{
    // ��ֵ(*this) = m.
    if (this != &m)
    {
        // �����Լ������Լ�
        delete[] element;
        theRows = m.theRows;
        theColumns = m.theColumns;
        element = new T[theRows * theColumns];
        // ����ÿһ��Ԫ��
        copy(m.element, m.element + theRows * theColumns, element);
    }
    return *this;
}
// ��()����������
template<class T>
T& matrix<T>::operator()(int i, int j) const
{
    // ���ض�Ԫ��element(i, j)������
    if (i < 1 || i > theRows
        || j < 1 || j > theColumns)
        throw matrixIndexOutOfBounds();
    return element[(i - 1) * theColumns + j - 1];
}
// ����ӷ�������+
template<class T>
matrix<T> matrix<T>::operator+(const matrix<T>& m) const
{
    // ���ر������+����m
    // ���п����Լ��
    if (theRows != m.theRows || theColumns != m.theColumns)
        throw matrixSizeMismatch();

    // �����������
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i] + m.element[i];
    // ���ؽ������
    return w;
}
// �������������-
template<class T>
matrix<T> matrix<T>::operator-(const matrix<T>& m) const
{
    // ���ر������-����m
    // ���п����Լ��
    if (theRows != m.theRows || theColumns != m.theColumns)
        throw matrixSizeMismatch();

    // �����������
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i] - m.element[i];
    // ���ؽ������
    return w;
}
// �������ţ�����-
template<class T>
matrix<T> matrix<T>::operator-() const
{
    // ����-����
    // �����������
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = -element[i];
    // ���ؽ������
    return w;

}
// ����˷�������*
template<class T>
matrix<T> matrix<T>::operator*(const matrix<T>& m) const
{
    // ���ر���*����m
    // ���п����Լ��
    if (theColumns != m.theRows)
        throw matrixSizeMismatch();
    // �����������
    matrix<T> w(theRows, m.theColumns);

    // Ϊ*this, m, w������
    // ��ʼ��λ�õ�(1, 1)
    int ct = 0, cm = 0, cw = 0;

    // Ϊ����i��j�������� w(i,j)
    for (int i = 1; i <= theRows; i++)
    {
        // ������i�Ľ��
        for (int j = 1; j <= m.theColumns; j++)
        { 
            // ����w(i,j)�Ľ��
            T sum = element[ct] * m.element[cm];

            // ���ʣ��
            for (int k = 2; k <= theColumns; k++)
            {
                ct++;  // i����һ��
                cm += m.theColumns;  // m��j�е���һ��
                sum += element[ct] * m.element[cm];
            }
            w.element[cw++] = sum;  // ����w(i,j)

            // �����У���ʼ��һ��
            ct -= theColumns - 1;
            cm = j;
        }

        // ��ʼ��һ�У�������
        ct += theColumns;
        cm = 0;
    }
    // ���ؽ������
    return w;
}
// ������������������x
template<class T>
matrix<T>& matrix<T>::operator+=(const T& x)
{
    for (int i = 0; i < theRows * theColumns; i++)
        element[i] += x;
    return *this;
}
// ������m��������
template<class T>
ostream& operator<<(ostream& out, const matrix<T>& m)
{
    int k = 0;  // �±�
    for (int i = 0; i < m.theRows; i++)
    {
        // ��
        for (int j = 0; j < m.theColumns; j++)
            out << m.element[k++] << "  ";

        // һ�н���
        out << endl;
    }

    return out;
}
// ����ĳЩԭ�򣬱����������Լ���������δ��벻��ɾ��������Ҳ����ɾ����
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
