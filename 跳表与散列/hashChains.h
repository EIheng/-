/*
头文件：
    使用排序法和除法的哈希表
    实现所有字典方法
*/

#ifndef hashChains_
#define hashChains_



#include <iostream>
#include "hash.h"   // 从K到非负整数的映射函数
#include "dictionary.h"
#include "sortedChain.h"

using namespace std;

// 继承于字典的哈希表
template<class K, class E>
class hashChains : public dictionary<K, E>
{
public:
    // 构造函数
    hashChains(int theDivisor = 11)
    {
        divisor = theDivisor;
        dSize = 0;

        // 分配和初始化哈希表数组
        table = new sortedChain<K, E>[divisor];
    }
    // 析构函数
    ~hashChains() { delete[] table; }
    // 返回表是否为空
    bool empty() const { return dSize == 0; }
    // 返回表的大小
    int size() const { return dSize; }
    // 返回与键值匹配的指针
    pair<const K, E>* find(const K& theKey) const
    {
        return table[hash(theKey) % divisor].find(theKey);
    }
    // 插入
    void insert(const pair<const K, E>& thePair)
    {
        int homeBucket = (int)hash(thePair.first) % divisor;
        int homeSize = table[homeBucket].size();
        table[homeBucket].insert(thePair);
        if (table[homeBucket].size() > homeSize)
            dSize++;
    }
    // 从字典中删除一个对
    void erase(const K& theKey)
    {
        table[hash(theKey) % divisor].erase(theKey);
    }
    // 输出
    void output(ostream& out) const
    {
        for (int i = 0; i < divisor; i++)
            if (table[i].size() == 0)
                cout << "NULL" << endl;
            else
                cout << table[i] << endl;
    }


protected:
    sortedChain<K, E>* table;  // 哈希表
    hash<K> hash;              // 将类型K映射到非负整数 
    int dSize;                 // 列表中的元素数
    int divisor;               // 散列函数除数
};


// 重载<<，以便于直接输出
template <class K, class E>
ostream& operator<<(ostream& out, const hashChains<K, E>& x)
{
    x.output(out); return out;
}

#endif
