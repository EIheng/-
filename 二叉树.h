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
// ��һ�α���
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
                    cout << "��ǰ�Ա���:" << nums[i] << "  " << nums[j] << endl;
                    cout << "�ɹ���" << endl;
                    return true;
                }
            }
        }
        cout << "ʧ�ܣ�" << endl;
        return false;
    }
};