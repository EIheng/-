#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <math.h>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;
// 第一次备份
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