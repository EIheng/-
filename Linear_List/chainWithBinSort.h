/*
ͷ�ļ���
    ����������������
*/

#ifndef chain_
#define chain_

#include<iostream>
#include<sstream>
#include<string>
#include "linearList.h"
#include "chainNode.h"
#include "myExceptions.h"
#include "studentRecord2.h"

using namespace std;

template<class T>
class chain : public linearList<T> 
{
public:
    // ���죨������
    chain(int initialCapacity = 10);
    // ���죨���ƣ�
    chain(const chain<T>&);
    //����
    ~chain();
    /*ADT����*/
    // �գ�
    bool empty() const { return listSize == 0; }
    // λ��
    int size() const { return listSize; }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;

    // ���ⷽ��
    void binSort(int range);
    void binSort(int range, int(*value)(T& x));

protected:
    // �������������
    void checkIndex(int theIndex) const;
    // ͷ���
    chainNode<T>* firstNode;
    // ������
    int listSize;
};

// ���캯��(����)
template<class T>
chain<T>::chain(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        ostringstream s;
        s << "��ʼ����=" << initialCapacity << " ���� > 0";
        throw illegalParameterValue(s.str());
    }
    firstNode = NULL;
    listSize = 0;
}
// ���캯��(����)
template<class T>
chain<T>::chain(const chain<T>& theList)
{
    listSize = theList.listSize;
    // �����һ�ſձ�
    if (listSize == 0)
    {
        firstNode = NULL;
        return;
    }
    // ��ȡĿ��ͷ�ڵ�
    chainNode<T>* sourceNode = theList.firstNode;
    // ����ͷ�ڵ�
    firstNode = new chainNode<T>(sourceNode->element);
    // ׼������ʣ��Ԫ��
    sourceNode = sourceNode->next;
    chainNode<T>* targetNode = firstNode;
    // ����ʣ��Ԫ��
    while (sourceNode != NULL)
    {
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
    // ��������
    targetNode->next = NULL;
}
// ��������
template<class T>
chain<T>::~chain()
{
   chainNode<T> *nextNode;
   // �ݻ�����Ԫ��
   while (firstNode != NULL)
   {
      nextNode = firstNode->next;
      delete firstNode;
      firstNode = nextNode;
   }
}
// �������������
template<class T>
void chain<T>::checkIndex(int theIndex) const
{
   if (theIndex < 0 || theIndex >= listSize)
   {ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
   }

}
// ����������ȡһ����
template<class T>
T& chain<T>::get(int theIndex) const
{
    //���
    checkIndex(theIndex);

    // ˳�������ƶ���ֱ��������
    chainNode<T>* currentNode = firstNode;
    for (int i = 0; i < theIndex; i++)
        currentNode = currentNode->next;

    return currentNode->element;
}
// Ԫ���״γ��ֵķ�������
template<class T>
int chain<T>::indexOf(const T& theElement) const
{
    chainNode<T>* currentNode = firstNode;
    int index = 0;
    while (currentNode != NULL && currentNode->element != theElement)
    {
        // ˳�������ƶ���ֱ���ҵ�����
        currentNode = currentNode->next;
        index++;
    }

    // ��������ڣ��򷵻�-1�����򷵻�����
    if (currentNode == NULL)
        return -1;
    else
        return index;
}
// ɾ�������е�һ����
template<class T>
void chain<T>::erase(int theIndex)
{
    // �������
    checkIndex(theIndex);

    // Ѱ��Ҫɾ��������
    chainNode<T>* deleteNode;
    if (theIndex == 0)
    {
        // ɾ��ͷ�ڵ�
        deleteNode = firstNode;
        firstNode = firstNode->next;
    }
    else
    {
        // ˳�������ƶ���ֱ����������λ��
        chainNode<T>* p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;

        deleteNode = p->next;
        // ע��������ָ�����¸��ڵ㣬����ɾ��
        p->next = p->next->next;
    }
    listSize--;
    delete deleteNode;
}
// ����
template<class T>
void chain<T>::insert(int theIndex, const T& theElement)
{
    if (theIndex < 0 || theIndex > listSize)
    {
        // �Ƿ�����
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }
    
    if (theIndex == 0)
        // ֱ�Ӳ���
        firstNode = new chainNode<T>(theElement, firstNode);
    else
    {
        // �ҵ���������λ��
        chainNode<T>* p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;

        // insert after p
        p->next = new chainNode<T>(theElement, p->next);
    }
    listSize++;
}
// �����ǹ�������
template<class T>
void chain<T>::output(ostream& out) const
{
    for (chainNode<T>* currentNode = firstNode;
        currentNode != NULL;
        currentNode = currentNode->next)
        out << currentNode->element << "  ";
}

// ���� <<
template <class T>
ostream& operator<<(ostream& out, const chain<T>& x)
   {x.output(out); return out;}


template<class T>
void chain<T>::binSort(int range)
{// Sort the nodes in the chain.
   // create and initialize the bins
   chainNode<T> **bottom, **top;
   bottom = new chainNode<T>* [range + 1];
   top = new chainNode<T>* [range + 1];
   for (int b = 0; b <= range; b++)
      bottom[b] = NULL;
   
   // distribute to bins
   for (; firstNode != NULL; firstNode = firstNode->next)
   {// add firstNode to proper bin
      int theBin = firstNode->element; // type conversion to int
      if (bottom[theBin] == NULL) // bin is empty
        bottom[theBin] = top[theBin] = firstNode;
      else
      {// bin not empty
        top[theBin]->next = firstNode;
        top[theBin] = firstNode;
      }
   }
   
   // collect from bins into sorted chain
   chainNode<T> *y = NULL;
   for (int theBin = 0; theBin <= range; theBin++)
      if (bottom[theBin] != NULL)
      {// bin not empty
         if (y == NULL) // first nonempty bin
            firstNode = bottom[theBin];
         else // not first nonempty bin
            y->next = bottom[theBin];
         y = top[theBin];
      }  
   if (y != NULL)
      y->next = NULL;
   
   delete [] bottom;
   delete [] top;
}

template<class T>
void chain<T>::binSort(int range, int(*value)(T& x))
{// Sort the nodes in the chain. The sort key is value(theElement).
   // create and initialize the bins
   chainNode<T> **bottom, **top;
   bottom = new chainNode<T>* [range + 1];
   top = new chainNode<T>* [range + 1];
   for (int b = 0; b <= range; b++)
      bottom[b] = NULL;
   
   // distribute to bins
   for (; firstNode != NULL; firstNode = firstNode->next)
   {// add firstNode to proper bin
      int theBin = value(firstNode->element);
                         // type conversion to int
      if (bottom[theBin] == NULL) // bin is empty
        bottom[theBin] = top[theBin] = firstNode;
      else
      {// bin not empty
        top[theBin]->next = firstNode;
        top[theBin] = firstNode;
      }
   }
   
   // collect from bins into sorted chain
   chainNode<T> *y = NULL;
   for (int theBin = 0; theBin <= range; theBin++)
      if (bottom[theBin] != NULL)
      {// bin not empty
         if (y == NULL) // first nonempty bin
            firstNode = bottom[theBin];
         else // not first nonempty bin
            y->next = bottom[theBin];
         y = top[theBin];
      }  
   if (y != NULL)
      y->next = NULL;
   
   delete [] bottom;
   delete [] top;
}
#endif
