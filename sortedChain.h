/*
ͷ�ļ���
    һ���������������ʵ���ֵ�
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
    // ���캯��
    sortedChain() { firstNode = NULL; dSize = 0; }
    ~sortedChain();
    // ���������Ƿ�Ϊ��
    bool empty() const { return dSize == 0; }
    // ���������е�Ԫ�ظ���
    int size() const { return dSize; }
    pair<const K, E>* find(const K&) const;
    void erase(const K&);
    void insert(const pair<const K, E>&);
    void output(ostream& out) const;

protected:
    pairNode<K, E>* firstNode;      // ָ������ĵ�һ���ڵ�
    int dSize;                      // ���������е�Ԫ�ظ���
};
// ��������
template<class K, class E>
sortedChain<K, E>::~sortedChain()
{
    // ɾ�����нڵ�
    while (firstNode != NULL)
    {
        pairNode<K, E>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}
// �������ֵƥ���ָ��
template<class K, class E>
pair<const K, E>* sortedChain<K, E>::find(const K& theKey) const
{
    pairNode<K, E>* currentNode = firstNode;

    // �ü�ֵ����ƥ������currentNodeָ��Ķ����е�࣬��ָ��Ļ��Ǽ�ֵ
    while (currentNode != NULL && currentNode->element.first != theKey)
    {
        // ָ����һ���ڵ�
        currentNode = currentNode->next;
    }

    // ��֤ƥ��
    if (currentNode != NULL && currentNode->element.first == theKey)
    {
        // ƥ��ɹ�������ֵ
        return &currentNode->element;
    }

    // û��ƥ��
    return NULL;
}
// ����
template<class K, class E>
void sortedChain<K, E>::insert(const pair<const K, E>& thePair)
{
    // ��һ���������ֵ䣬���������ͬ�ļ�ֵ�򸲸����е�
    pairNode<K, E>* p = firstNode;      // p�ڵ�
    pairNode<K, E>* tp = NULL;          // tp�ڵ�

    // �ƶ�tp����thePair������tp�������
    while (p != NULL && p->element.first < thePair.first)
    {
        tp = p;
        p = p->next;
    }

    // ����Ƿ���ƥ��Ķ�
    if (p != NULL && p->element.first == thePair.first)
    {
        // �����ڣ����滻��ԭ����ֵ
        p->element.second = thePair.second;
        return;
    }

    // û��ƥ�䣬����һ���µĽڵ㡣
    pairNode<K, E>* newNode = new pairNode<K, E>(thePair, p);

    // ��tp��������µĽڵ�
    if (tp == NULL)
    {
        // ��������û��ֵ
        firstNode = newNode;
    }
    else
    {
        tp->next = newNode;
    }
    dSize++;
    return;
}
// ���ֵ���ɾ��һ����
template<class K, class E>
void sortedChain<K, E>::erase(const K& theKey)
{
    pairNode<K, E>* p = firstNode;  // p�ڵ�
    pairNode<K, E>* tp = NULL;      // tp�ڵ�

    // Ѱ���Ƿ���ƥ��ļ�
    while (p != NULL && p->element.first < theKey)
    {
        tp = p;
        p = p->next;
    }

    // ��֤ƥ��
    if (p != NULL && p->element.first == theKey)
    {
        // �ҵ�ƥ���������������Ƴ�
        if (tp == NULL) 
        {
            // p��ͷ�ڵ�
            firstNode = p->next;
        }
        else
        {
            tp->next = p->next;
        }
        // �����ڴ�
        delete p;
        dSize--;
    }
}
// ���
template<class K, class E>
void sortedChain<K, E>::output(ostream& out) const
{
    // �������е�Ԫ�ؼ��������
    for (pairNode<K, E>* currentNode = firstNode; currentNode != NULL; currentNode = currentNode->next)
    {
        out << currentNode->element.first << " " << currentNode->element.second << "  ";
    }
}

// ����<<���Ա������
template <class K, class E>
ostream& operator<<(ostream& out, const sortedChain<K, E>& x)
{
    x.output(out); 
    return out;
}

#endif
