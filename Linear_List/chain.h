/*
头文件：
    线性列表，链表
*/
#ifndef chain_
#define chain_

#include <iostream>
#include <sstream>
#include <string>
#include "linearList.h"
#include "chainNode.h"
#include "myExceptions.h"

using namespace std;

class linkedDigraph;
template <class T> class linkedWDigraph;

template<class T>
class chain : public linearList<T>
{
    friend linkedDigraph;
    friend linkedWDigraph<int>;
    friend linkedWDigraph<float>;
    friend linkedWDigraph<double>;
public:
    // 构造（创建）
    chain(int initialCapacity = 10);
    // 构造（复制）
    chain(const chain<T>&);
    //析构
    ~chain();
    /*ADT方法*/
    // 空？
    bool empty() const { return listSize == 0; }
    // 位置
    int size() const { return listSize; }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;

protected:
    // 检查索引可行性
    void checkIndex(int theIndex) const;
    // 头结点
    chainNode<T>* firstNode;
    // 链表长度
    int listSize;
};

// 构造函数(创建)
template<class T>
chain<T>::chain(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "初始容量=" << initialCapacity << " 必须 > 0";
        throw illegalParameterValue(s.str());
    }
    firstNode = NULL;
    listSize = 0;
}
// 构造函数(复制)
template<class T>
chain<T>::chain(const chain<T>& theList)
{
    listSize = theList.listSize;
    // 如果是一张空表
    if (listSize == 0)
    {
        firstNode = NULL;
        return;
    }
    // 获取目标头节点
    chainNode<T>* sourceNode = theList.firstNode;
    // 复制头节点
    firstNode = new chainNode<T>(sourceNode->element);
    // 准备复制剩余元素
    sourceNode = sourceNode->next;
    chainNode<T>* targetNode = firstNode;
    // 复制剩余元素
    while (sourceNode != NULL)
    {
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    // 结束链表
    targetNode->next = NULL;
}
// 析构函数
template<class T>
chain<T>::~chain()
{
    chainNode<T>* nextNode;
    // 摧毁所有元素
    while (firstNode != NULL)
    {
        nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

// 检查索引可行性
template<class T>
void chain<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex >= listSize)
    {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

}
// 根据索引获取一个数
template<class T>
T& chain<T>::get(int theIndex) const
{
    //检查
    checkIndex(theIndex);

    // 顺着链表移动，直到该索引
    chainNode<T>* currentNode = firstNode;
    for (int i = 0; i < theIndex; i++)
        currentNode = currentNode->next;

    return currentNode->element;
}
// 元素首次出现的返回索引
template<class T>
int chain<T>::indexOf(const T& theElement) const
{
    chainNode<T>* currentNode = firstNode;
    int index = 0;
    while (currentNode != NULL && currentNode->element != theElement)
    {
        // 顺着链表移动，直到找到该数
        currentNode = currentNode->next;
        index++;
    }

    // 如果不存在，则返回-1。否则返回索引
    if (currentNode == NULL)
        return -1;
    else
        return index;
}
// 删除链表中的一个数
template<class T>
void chain<T>::erase(int theIndex)
{
    // 检查索引
    checkIndex(theIndex);

    // 寻找要删除的索引
    chainNode<T>* deleteNode;
    if (theIndex == 0)
    {
        // 删除头节点
        deleteNode = firstNode;
        firstNode = firstNode->next;
    }
    else
    {
        // 顺着链表移动，直到该索引的位置
        chainNode<T>* p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;

        deleteNode = p->next;
        // 注意这里是指向下下个节点，方便删除
        p->next = p->next->next;
    }
    listSize--;
    delete deleteNode;
}
// 插入
template<class T>
void chain<T>::insert(int theIndex, const T& theElement)
{
    if (theIndex < 0 || theIndex > listSize)
    {
        // 非法索引
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }

    if (theIndex == 0)
        // 直接插入
        firstNode = new chainNode<T>(theElement, firstNode);
    else
    {
        // 找到索引所在位置
        chainNode<T>* p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;

        // insert after p
        p->next = new chainNode<T>(theElement, p->next);
    }
    listSize++;
}
// 依旧是诡异的输出
template<class T>
void chain<T>::output(ostream& out) const
{
    for (chainNode<T>* currentNode = firstNode;
        currentNode != NULL;
        currentNode = currentNode->next)
        out << currentNode->element << "  ";
}

// 重载 <<
template <class T>
ostream& operator<<(ostream& out, const chain<T>& x)
{
    x.output(out);
    return out;
}

#endif
