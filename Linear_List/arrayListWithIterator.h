/*
头文件：
    线性表的数组实现
    派生自抽象类linearList，以确保实现ADT的所有方法
    使用STL算法简化代码
    包含迭代器
*/
#ifndef arrayList_
#define arrayList_

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iterator>
#include "linearList.h"
#include "myExceptions.h"
#include "changeLength1D.h"

using namespace std;

template<class T>
class arrayList : public linearList<T>
{
public:
    // 构造（创建）
    arrayList(int initialCapacity = 10);
    // 构造（复制）
    arrayList(const arrayList<T>&);
    // 析构（删除）
    ~arrayList() { delete[] element; }

    /*ADT 方法*/
    // 空？
    bool empty() const { return listSize == 0; }
    // 数量
    int size() const { return listSize; }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;

    /*额外的方法*/
    // 容量
    int capacity() const { return arrayLength; }

    // 迭代器
    class iterator;
    iterator begin() { return iterator(element); }
    iterator end() { return iterator(element + listSize); }

    // 顺序表的迭代器，没学过迭代器的我看得我一脸懵逼
    class iterator
    {
    public:
        // 双向迭代器
        typedef bidirectional_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;

        // 构造
        iterator(T* thePosition = 0) { position = thePosition; }

        // 析构
        T& operator*() const { return *position; }
        T* operator->() const { return &*position; }

        // 前增
        iterator& operator++()
        {
            ++position;
            return *this;
        }
        // 后增
        iterator operator++(int)
        {
            iterator old = *this;
            ++position;
            return old;
        }

        // 前减
        iterator& operator--()
        {
            --position; return *this;
        }
        // 后减
        iterator operator--(int)
        {
            iterator old = *this;
            --position;
            return old;
        }
        // 相等检测
        bool operator!=(const iterator right) const
        {
            return position != right.position;
        }
        bool operator==(const iterator right) const
        {
            return position == right.position;
        }
    protected:
        T* position;
    };
protected:
    /*arrayList的其他成员*/
    // 检查索引
    void checkIndex(int theIndex) const;
    T* element;           // 顺序表中的元素
    int arrayLength;      // 顺序表的长度
    int listSize;         // 顺序表的元素个数
};
// 构造(创建)
template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
    // 检测大小可行性
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    // 开始创建
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}
// 构造（复制）
template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
    // 先复制容量
    arrayLength = theList.arrayLength;
    // 再复制长度
    listSize = theList.listSize;
    // 再分配空间
    element = new T[arrayLength];
    // 再拷贝
    copy(theList.element, theList.element + listSize, element);
}
// 检查索引可行性
template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex >= listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

}
// 获取
template<class T>
T& arrayList<T>::get(int theIndex) const
{
    // 检查
    checkIndex(theIndex);
    // 返回
    return element[theIndex];
}
// 索引
template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{
    int theIndex = (int)(find(element, element + listSize, theElement) - element);
    // 查找
    if (theIndex == listSize)
        // 没有找到则返回-1
        return -1;
    else
        return theIndex;
}
// 删除
template<class T>
void arrayList<T>::erase(int theIndex)
{
    // 检查索引
    checkIndex(theIndex);
    // 将后面的数全部向前移动一位
    copy(element + theIndex + 1, element + listSize, element + theIndex);
    // 这个地方的调用析构函数我觉得很诡异……不是很明白
    element[--listSize].~T();
}
// 插入
template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
    // 检查索引可行性
    if (theIndex < 0 || theIndex > listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }
   // 检查空间是否充足
   if (listSize == arrayLength)
      {
        // 扩容
        changeLength1D(element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
      }

   // 全部向后移动一格
   copy_backward(element + theIndex, element + listSize, element + listSize + 1);
   element[theIndex] = theElement;
   listSize++;
}

// 输出，他的输出的意思大概就是将数字导入输入流，然后……用迭代器输出？
template<class T>
void arrayList<T>::output(ostream& out) const
{
   copy(element, element + listSize, ostream_iterator<T>(cout, "  "));
}

// 重载 <<
template <class T>
ostream& operator<<(ostream& out, const arrayList<T>& x)
{
    x.output(out); return out;
}

#endif
