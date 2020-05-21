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
// 栈的测试
void Stack_A()
{
    stack<int> A;
    // 判断栈是否为空
    cout << A.empty() << endl;
    for (int i = 1; i <= 10; i++)
    {
        cout << "压栈，数：" << i << endl;
        A.push(i);
    }
    // 输出栈的空间数量
    cout << A.size() << endl;
    for (int i = 1; i <= 10; i++)
    {
        cout << "弹栈，数：" << A.top() << endl;
        A.pop();
    }
}
// 匹配括号
void Match_Brackets(string strs)
{
    stack<int> s;
    int length = (int)strs.size();

    // 扫描strs寻找左括号和有括号
    for (int i = 0; i < length; i++)
    {
        // 左括号，压栈
        if (strs.at(i) == '(')
            s.push(i);
        // 为右括号
        else if (strs.at(i) == ')')
        {
            // 如果为右括号同时栈不为空
            if (!s.empty())
            {
                s.pop();
            }
            else
            {
                cout << "括号不匹配！" << endl;
                return;
            }
        }
    }
    // 遍历结束，栈不为空
    if (!s.empty())
    {
        cout << "括号不匹配！" << endl;
    }
}
// 递归解决汉若塔问题
void Towers_Of_Hanoi(int n, int x, int y, int z)
{
    if (n > 0)
    {
        Towers_Of_Hanoi(n - 1, x, z, y);
        cout << "移动顶端的盘子从" << x
            << "到" << y << endl;
        Towers_Of_Hanoi(n - 1, z, y, x);
    }
}

// 全局变量
stack<int> tower[4];

void moveAndShow(int, int, int, int);

// 使用栈解决汉诺塔问题
void towersOfHanoi(int n)
{
    for (int d = n; d > 0; d--)     // 塔的空间
        tower[1].push(d);           // 加入盘子

    // 开始移动，将盘子由1，依赖3移动到2
    moveAndShow(n, 1, 2, 3);
}

// 此处注意是将x移动到y塔上，而不是z塔上
void moveAndShow(int n, int x, int y, int z)
{
    // 将n个盘子从x塔依赖z塔移动到y塔，并且显示状态
    if (n > 0)
    {
        moveAndShow(n - 1, x, z, y);
        int d = tower[x].top();   // 移动顶端
        tower[x].pop();           // 弹栈
        tower[y].push(d);         // 压栈
        // showState();              // 展示
        // 展示移动过程
        cout << "移动盘子" << d << "从塔" << x << "到塔" << y << endl;
        moveAndShow(n - 1, z, y, x);
    }
}

int main()
{
    // 括号测试
    string strs_1 = "(((()))))";
    string strs_2 = "((0)-(-)";
    string strs_3 = "((0)";
    Match_Brackets(strs_1);
    Match_Brackets(strs_2);
    Match_Brackets(strs_3);
    //汉诺塔测试
    Towers_Of_Hanoi(2, 1, 3, 2);
    towersOfHanoi(3);

    cout << "嘿嘿！" << endl;
}

