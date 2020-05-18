
/*
什么是异或？
　　0^0 = 0
　　1^0 = 1
　　0^1 = 1
1^1 = 0
两者不同则为1，两者相同为0。
在计算机中：
x: 0000 0001
0: 0000 0000
x^0=0000 0001
也就是等于自身。
x^x=0000 0000=0
*/
class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int a = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            a = a ^ nums[i];
        }
        return a;
    }
};
