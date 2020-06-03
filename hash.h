// functions to convert from type K to nonnegative integer
// derived from similar classes in SGI STL
/*
ͷ�ļ���
    ������ЩӢ���ǽ��ܣ����ҿ���������
    ��Kת��Ϊ�Ǹ�����
*/

#ifndef hash_
#define hash_

#include <iostream>
#include <string>

using namespace std;

template <class K> class hash;

template<>
class hash<string>
{
public:
    // ����ֵת��Ϊ�Ǹ�����
    size_t operator()(const string theKey) const
    {
        unsigned long hashValue = 0;
        int length = (int)theKey.length();
        for (int i = 0; i < length; i++)
            hashValue = 5 * hashValue + theKey.at(i);

        return size_t(hashValue);
    }
};

template<>
class hash<int>
{
public:
    size_t operator()(const int theKey) const
    {
        return size_t(theKey);
    }
};

template<>
class hash<long>
{
public:
    size_t operator()(const long theKey) const
    {
        return size_t(theKey);
    }
};

#endif
