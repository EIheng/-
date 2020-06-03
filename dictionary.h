/*
头文件：
    抽象类字典，K代表键，E代表值
*/

#ifndef dictionary_
#define dictionary_

using namespace std;
// 字典
template<class K, class E>
class dictionary
{
public:
    virtual ~dictionary() {}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual pair<const K, E>* find(const K&) const = 0;
    virtual void erase(const K&) = 0;
    virtual void insert(const pair<const K, E>&) = 0;
};
#endif

