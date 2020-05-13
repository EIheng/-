/*
头文件：
    线性表的数组实现
    派生自抽象类linearList，以确保实现ADT的所有方法
    使用STL算法简化代码
*/

#ifndef arrayList_
#define arrayList_

#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>

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
      ~arrayList() {delete [] element;}

      /*ADT 方法*/
      // 空？
      bool empty() const {return listSize == 0;}
      // 数量
      int size() const {return listSize;}
      T& get(int theIndex) const;
      int indexOf(const T& theElement) const;
      void erase(int theIndex);
      void insert(int theIndex, const T& theElement);
      void output(ostream& out) const;

      /*额外的方法*/
      // 容量
      int capacity() const {return arrayLength;}

   protected:
      void checkIndex(int theIndex) const;
            // 抛出异常
      T* element;            // 顺序表中的元素
      int arrayLength;       // 顺序表的长度
      int listSize;          // 顺序表的元素个数
};

// 构造（创建）
template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
   if (initialCapacity < 1)
   {ostringstream s;
    s << "Initial capacity = " << initialCapacity << " Must be > 0";
    throw illegalParameterValue(s.str());
   }
   arrayLength = initialCapacity;
   element = new T[arrayLength];
   listSize = 0;
}
// 构造（复制）
template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
   arrayLength = theList.arrayLength;
   listSize = theList.listSize;
   element = new T[arrayLength];
   copy(theList.element, theList.element + listSize, element);
}
// 检查容量
template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{// Verify that theIndex is between 0 and listSize - 1.
   if (theIndex < 0 || theIndex >= listSize)
   {ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
   }

}
// 获取
template<class T>
T& arrayList<T>::get(int theIndex) const
{// Return element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   checkIndex(theIndex);
   return element[theIndex];
}
// 索引
template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{// Return index of first occurrence of theElement.
 // Return -1 if theElement not in list.

   // search for theElement
   int theIndex = (int) (find(element, element + listSize, theElement)
                         - element);

   // check if theElement was found
   if (theIndex == listSize)
     // not found
     return -1;
   else return theIndex;
 }
// 删除
template<class T>
void arrayList<T>::erase(int theIndex)
{// Delete the element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   checkIndex(theIndex);

   // valid index, shift elements with higher index
   copy(element + theIndex + 1, element + listSize,
                                element + theIndex);

   element[--listSize].~T(); // invoke destructor
}
// 插入
template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{// Insert theElement so that its index is theIndex.
   if (theIndex < 0 || theIndex > listSize)
   {// invalid index
      ostringstream s;
      s << "index = " << theIndex << " size = " << listSize;
      throw illegalIndex(s.str());
   }

   // valid index, make sure we have space
   if (listSize == arrayLength)
      {// no space, double capacity
         changeLength1D(element, arrayLength, 2 * arrayLength);
         arrayLength *= 2;
      }

   // shift elements right one position
   copy_backward(element + theIndex, element + listSize,
                 element + listSize + 1);

   element[theIndex] = theElement;

   listSize++;
}
// 输出
template<class T>
void arrayList<T>::output(ostream& out) const
{// Put the list into the stream out.
   copy(element, element + listSize, ostream_iterator<T>(cout, "  "));
}

// 重载 <<
template <class T>
ostream& operator<<(ostream& out, const arrayList<T>& x)
   {x.output(out); return out;}

#endif
