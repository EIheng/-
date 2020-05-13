/*
头文件：
    顺序表的一个抽象类
    所有方法都是纯虚函数
*/
#ifndef linearList_
#define linearList_
#include <iostream>

using namespace std;

template<class T>
class linearList
{
public:
    // 析构函数
    virtual ~linearList() {};
    // 是否为空
    virtual bool empty() const = 0;
    // 返回表的元素个数
    virtual int size() const = 0;
    // 返回索引位置的数
    virtual T& get(int theIndex) const = 0;
    // 返回该数在表中第一次出现的位置
    virtual int indexOf(const T& theElement) const = 0;
    // 删除索引位置处的数
    virtual void erase(int theIndex) = 0;
    // 在索引中插入一个数
    virtual void insert(int theIndex, const T& theElement) = 0;
    // 输出表
    virtual void output(ostream& out) const = 0;
};
#endif