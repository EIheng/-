/*
源文件：
    寻找迷宫出路
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

#include "position.h"
#include "make2dArray.h"

using namespace std;
/*全局变量*/
int** maze;                 // 迷宫
int Size_A;                 // 迷宫大小
stack<position> path;      // 指向栈的指针

void welcome() {};
// 输入迷宫
void inputMaze()
{
    /*
    cout << "输入迷宫大小：" << endl;
    cin >> Size_A;
    make2dArray(maze, Size_A + 2, Size_A + 2);
    cout << "按行顺序输入迷宫：" << endl;
    for (int i = 1; i <= Size_A; i++)
        for (int j = 1; j <= Size_A; j++)
            cin >> maze[i][j];
    */
    Size_A = 10;
    make2dArray(maze, Size_A + 2, Size_A + 2);
    // 行1
    int a1[10] = { 0,1,1,1,1,1,0,0,0,0 };
    for (int i = 1; i <= Size_A; i++)
        maze[1][i] = a1[i - 1];
    // 行2
    int a2[10] = { 0,0,0,0,0,1,0,1,0,0 };
    for (int i = 1; i <= Size_A; i++)
        maze[2][i] = a2[i - 1];
    // 行3
    int a3[10] = { 0,0,0,1,0,1,0,0,0,0 };
    for (int i = 1; i <= Size_A; i++)
        maze[3][i] = a3[i - 1];
    // 行4
    int a4[10] = { 0,1,0,1,0,1,0,1,1,0 };
    for (int i = 1; i <= Size_A; i++)
        maze[4][i] = a4[i - 1];
    // 行5
    int a5[10] = { 0,1,0,1,0,1,0,1,0,0 };
    for (int i = 1; i <= Size_A; i++)
        maze[5][i] = a5[i - 1];
    // 行6
    int a6[10] = { 0,1,1,1,0,1,0,1,0,1 };
    for (int i = 1; i <= Size_A; i++)
        maze[6][i] = a6[i - 1];
    // 行7
    int a7[10] = { 0,1,0,0,0,1,0,1,0,1 };
    for (int i = 1; i <= Size_A; i++)
        maze[7][i] = a7[i - 1];
    // 行8
    int a8[10] = { 0,1,0,1,1,1,0,1,0,0 };
    for (int i = 1; i <= Size_A; i++)
        maze[8][i] = a8[i - 1];
    // 行9
    int a9[10] = { 1,0,0,0,0,0,0,1,0,0 };
    for (int i = 1; i <= Size_A; i++)
        maze[9][i] = a9[i - 1];
    // 行10
    int a10[10] = { 1,0,0,0,0,0,0,1,0,0 };
    for (int i = 1; i <= Size_A; i++)
        maze[10][i] = a10[i - 1];
}
// 寻找出口
bool findPath()
{
    // 找到从(1, 1)到出口的路径(Size_A, Size_A)
    // 如果成功返回true，反之返回false

    // 初始化偏移量
    position offset[4];
    offset[0].row = 0; offset[0].col = 1;   // 右
    offset[1].row = 1; offset[1].col = 0;   // 下
    offset[2].row = 0; offset[2].col = -1;  // 左
    offset[3].row = -1; offset[3].col = 0;  // 上

    // 初始化迷宫周围的障碍墙
    for (int i = 0; i <= Size_A + 1; i++)
    {
        maze[0][i] = maze[Size_A + 1][i] = 1; // 顶部与底部
        maze[i][0] = maze[i][Size_A + 1] = 1; // 左和右
    }

    position here;      // 当前位置
    here.row = 1;       // 当前位置的行
    here.col = 1;       // 当前位置的列
    maze[1][1] = 1;     // 防止回到入口
    int option = 0;     // 下一步
    int lastOption = 3; // 最多的步数

    // 寻找一条路径，条件：当前位置不等于迷宫大小
    while (here.row != Size_A || here.col != Size_A)
    {
        // 没有达到出口
        // 找到要移动的相邻的一步
        int r;  // 寻找的行
        int c;  // 寻找的列
        // 寻找继续移动的可行性
        while (option <= lastOption)
        {
            r = here.row + offset[option].row;
            c = here.col + offset[option].col;
            if (maze[r][c] == 0) 
                break;
            option++;   // 下一步
        }
        // 相邻的一步是否找到？
        if (option <= lastOption)
        {   
            // 移动到maze[r][c]
            path.push(here);
            here.row = r;
            here.col = c;
            maze[r][c] = 1; // 设置1，以防止重复访问
            option = 0;
        }
        else
        {
            // 无路可走，返回
            if (path.empty())
                return false;   // 没有位置可以返回
            position next = path.top();
            path.pop();
            /*
            if (next.row == here.row)
                option = 2 + next.col - here.col;
            else
                option = 3 + next.row - here.row;
            */
            option = 0;
            here = next;
        }
    }
    return true;  // 达到出口
}
// 输出路径
void outputPath()
{
    cout << "路径是：" << endl;
    position here;
    while (!path.empty())
    {
        here = path.top();
        path.pop();
        cout << here.row << ' ' << here.col << endl;
    }
}

int main()
{
   welcome();
   inputMaze();
   if (findPath()) 
      outputPath();
   else
      cout << "没有路" << endl;
}
