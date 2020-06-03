/*
ͷ�ļ���
    ʹ�����򷨺ͳ����Ĺ�ϣ��
    ʵ�������ֵ䷽��
*/

#ifndef hashChains_
#define hashChains_



#include <iostream>
#include "hash.h"   // ��K���Ǹ�������ӳ�亯��
#include "dictionary.h"
#include "sortedChain.h"

using namespace std;

// �̳����ֵ�Ĺ�ϣ��
template<class K, class E>
class hashChains : public dictionary<K, E>
{
public:
    // ���캯��
    hashChains(int theDivisor = 11)
    {
        divisor = theDivisor;
        dSize = 0;

        // ����ͳ�ʼ����ϣ������
        table = new sortedChain<K, E>[divisor];
    }
    // ��������
    ~hashChains() { delete[] table; }
    // ���ر��Ƿ�Ϊ��
    bool empty() const { return dSize == 0; }
    // ���ر�Ĵ�С
    int size() const { return dSize; }
    // �������ֵƥ���ָ��
    pair<const K, E>* find(const K& theKey) const
    {
        return table[hash(theKey) % divisor].find(theKey);
    }
    // ����
    void insert(const pair<const K, E>& thePair)
    {
        int homeBucket = (int)hash(thePair.first) % divisor;
        int homeSize = table[homeBucket].size();
        table[homeBucket].insert(thePair);
        if (table[homeBucket].size() > homeSize)
            dSize++;
    }
    // ���ֵ���ɾ��һ����
    void erase(const K& theKey)
    {
        table[hash(theKey) % divisor].erase(theKey);
    }
    // ���
    void output(ostream& out) const
    {
        for (int i = 0; i < divisor; i++)
            if (table[i].size() == 0)
                cout << "NULL" << endl;
            else
                cout << table[i] << endl;
    }


protected:
    sortedChain<K, E>* table;  // ��ϣ��
    hash<K> hash;              // ������Kӳ�䵽�Ǹ����� 
    int dSize;                 // �б��е�Ԫ����
    int divisor;               // ɢ�к�������
};


// ����<<���Ա���ֱ�����
template <class K, class E>
ostream& operator<<(ostream& out, const hashChains<K, E>& x)
{
    x.output(out); return out;
}

#endif
