/*
头文件；
    一条排序的链，用于实现字典
*/

#ifndef sortedChain_
#define sortedChain_



#include <iostream>
#include "dictionary.h"
#include "pairNode.h"

using namespace std;

template<class K, class E>
class sortedChain : public dictionary<K, E>
{
public:
    // 构造函数
    sortedChain() { firstNode = NULL; dSize = 0; }
    ~sortedChain();
    // 返回链表是否为空
    bool empty() const { return dSize == 0; }
    // 返回链表中的元素个数
    int size() const { return dSize; }
    pair<const K, E>* find(const K&) const;
    void erase(const K&);
    void insert(const pair<const K, E>&);
    void output(ostream& out) const;

protected:
    pairNode<K, E>* firstNode;      // 指向链表的第一个节点
    int dSize;                      // 排序链表中的元素个数
};
// 析构函数
template<class K, class E>
sortedChain<K, E>::~sortedChain()
{
    // 删除所有节点
    while (firstNode != NULL)
    {
        pairNode<K, E>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}
// 返回与键值匹配的指针
template<class K, class E>
pair<const K, E>* sortedChain<K, E>::find(const K& theKey) const
{
    pairNode<K, E>* currentNode = firstNode;

    // 用键值搜索匹配项，这个currentNode指向的东西有点多，但指向的还是键值
    while (currentNode != NULL && currentNode->element.first != theKey)
    {
        // 指向下一个节点
        currentNode = currentNode->next;
    }

    // 验证匹配
    if (currentNode != NULL && currentNode->element.first == theKey)
    {
        // 匹配成功，返回值
        return &currentNode->element;
    }

    // 没有匹配
    return NULL;
}
// 插入
template<class K, class E>
void sortedChain<K, E>::insert(const pair<const K, E>& thePair)
{
    // 将一组数插入字典，如果存在相同的键值则覆盖现有的
    pairNode<K, E>* p = firstNode;      // p节点
    pairNode<K, E>* tp = NULL;          // tp节点

    // 移动tp，到thePair可以在tp后面插入
    while (p != NULL && p->element.first < thePair.first)
    {
        tp = p;
        p = p->next;
    }

    // 检查是否有匹配的对
    if (p != NULL && p->element.first == thePair.first)
    {
        // 若存在，则替换掉原来的值
        p->element.second = thePair.second;
        return;
    }

    // 没有匹配，创建一个新的节点。
    pairNode<K, E>* newNode = new pairNode<K, E>(thePair, p);

    // 在tp后面插入新的节点
    if (tp == NULL)
    {
        // 若链表中没有值
        firstNode = newNode;
    }
    else
    {
        tp->next = newNode;
    }
    dSize++;
    return;
}
// 从字典中删除一个对
template<class K, class E>
void sortedChain<K, E>::erase(const K& theKey)
{
    pairNode<K, E>* p = firstNode;  // p节点
    pairNode<K, E>* tp = NULL;      // tp节点

    // 寻找是否有匹配的键
    while (p != NULL && p->element.first < theKey)
    {
        tp = p;
        p = p->next;
    }

    // 验证匹配
    if (p != NULL && p->element.first == theKey)
    {
        // 找到匹配项，将其从链表中移除
        if (tp == NULL) 
        {
            // p是头节点
            firstNode = p->next;
        }
        else
        {
            tp->next = p->next;
        }
        // 清理内存
        delete p;
        dSize--;
    }
}
// 输出
template<class K, class E>
void sortedChain<K, E>::output(ostream& out) const
{
    // 将链表中的元素加入输出流
    for (pairNode<K, E>* currentNode = firstNode; currentNode != NULL; currentNode = currentNode->next)
    {
        out << currentNode->element.first << " " << currentNode->element.second << "  ";
    }
}

// 重载<<，以便于输出
template <class K, class E>
ostream& operator<<(ostream& out, const sortedChain<K, E>& x)
{
    x.output(out); 
    return out;
}

#endif
