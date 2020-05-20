/*
源文件：
    存在重复元素
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

// 第一反应当然是暴力，不过写完就发现，超时了…………
class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        if (nums.size() == 0)
            return false;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] == nums[j])
                {
                    cout << "当前对比数:" << nums[i] << "  " << nums[j] << endl;
                    cout << "成功！" << endl;
                    return true;
                }
            }
        }
        cout << "失败！" << endl;
        return false;
    }
};
/*
哈希表
就是遍历整个数组，每找到一个数，就把它加入表，如果遍历的过程中又找到了这个元素，那么就说明出现重复元素。
*/
class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        // 进行一次排序
        sort(nums.begin(), nums.end());
        // 遍历一次数组
        for (int i = 1; i < nums.size(); i++)
        {
            // 若存在相同的数，则返回true
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};
/*
集合
就是遍历整个数组，每找到一个数，就把它加入表，如果遍历的过程中又找到了

将数组加入集合，再将原数组的元素个数与集合的元素个数进行比较，因为不能出现相同元素，所以如果不相同，则存在相同元素；如果相同，则不存在相同元素
*/
class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_map <int, int>map_1;
        // 遍历数组
        for (int i : nums)
        {
            // 若存在相同数字，映射的数+1
            map_1[i]++;
            if (map_1[i] > 1)
                return true;
        }
        return false;
    }
};
/*
排序
将数组排序后，再遍历数组，两两对比，如果到最后两两还是不相同，则不存在相同元素。
*/
class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set <int>set_1(nums.begin(), nums.end());
        // 若原数组大于集合，则存在
        return nums.size() > set_1.size();
    }
};

void main()
{
    Solution A;
    vector<int> nums = { 1,2,3,1 };
    vector<int> nums_1 = { 1,2,3,4 };
    vector<int> nums_2 = { 1,1,1,3,3,4,3,2,4,2 };

    A.containsDuplicate(nums);
    A.containsDuplicate(nums_1);
    A.containsDuplicate(nums_2);
}