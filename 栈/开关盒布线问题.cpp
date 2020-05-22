/*
源文件：
    开关盒布线
*/

#include <iostream>
#include <stack>

using namespace std;
// 确定开关盒是否可布线(net[]"管脚网组，其中1与1对应，2与2对应", n"管脚个数")
bool checkBox(int net[], int n)
{
    stack<int>* s = new stack<int>(n);

    // 顺时针扫描网组
    for (int i = 0; i < n; i++)
    {
        // 处理管脚i
        if (!s->empty())                     // 若栈不为空
            if (net[i] == net[s->top()])     // 将数与栈顶比较
                s->pop();                    // 若相同，弹栈
            else
                s->push(i);                  // 若不相同，将i压栈
        else                                 // 若栈空
            s->push(i);                      // 将i压栈
    }

    // 是否有剩余不可布线的管脚，检查是否栈空
    if (s->empty())
    {
        cout << "这个开关盒是可以布线的" << endl;
        return true;
    }
    cout << "这个开关盒不可以布线" << endl;
    return false;
}

void main()
{
    // 输入管脚及其分配问题
    cout << "输入管脚个数" << endl;
    int n;
    cin >> n;

    // 创造管脚网组
    int* net = new int[n];
    // 输入管脚网组
    cout << "依次输入管脚的，数量：" << n << endl;
    for (int i = 0; i < n; i++)
        cin >> net[i];

    // 看是否可行
    checkBox(net, n);
}
