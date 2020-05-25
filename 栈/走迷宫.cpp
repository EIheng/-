/*
Դ�ļ���
    Ѱ���Թ���·
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
/*ȫ�ֱ���*/
int** maze;                 // �Թ�
int Size_A;                 // �Թ���С
stack<position> path;      // ָ��ջ��ָ��

void welcome() {};
// �����Թ�
void inputMaze()
{
    /*
    cout << "�����Թ���С��" << endl;
    cin >> Size_A;
    make2dArray(maze, Size_A + 2, Size_A + 2);
    cout << "����˳�������Թ���" << endl;
    for (int i = 1; i <= Size_A; i++)
        for (int j = 1; j <= Size_A; j++)
            cin >> maze[i][j];
    */
    Size_A = 10;
    make2dArray(maze, Size_A + 2, Size_A + 2);
    // ��1
    int a1[10] = { 0,1,1,1,1,1,0,0,0,0 };
    for (int i = 1; i <= Size_A; i++)
        maze[1][i] = a1[i - 1];
    // ��2
    int a2[10] = { 0,0,0,0,0,1,0,1,0,0 };
    for (int i = 1; i <= Size_A; i++)
        maze[2][i] = a2[i - 1];
    // ��3
    int a3[10] = { 0,0,0,1,0,1,0,0,0,0 };
    for (int i = 1; i <= Size_A; i++)
        maze[3][i] = a3[i - 1];
    // ��4
    int a4[10] = { 0,1,0,1,0,1,0,1,1,0 };
    for (int i = 1; i <= Size_A; i++)
        maze[4][i] = a4[i - 1];
    // ��5
    int a5[10] = { 0,1,0,1,0,1,0,1,0,0 };
    for (int i = 1; i <= Size_A; i++)
        maze[5][i] = a5[i - 1];
    // ��6
    int a6[10] = { 0,1,1,1,0,1,0,1,0,1 };
    for (int i = 1; i <= Size_A; i++)
        maze[6][i] = a6[i - 1];
    // ��7
    int a7[10] = { 0,1,0,0,0,1,0,1,0,1 };
    for (int i = 1; i <= Size_A; i++)
        maze[7][i] = a7[i - 1];
    // ��8
    int a8[10] = { 0,1,0,1,1,1,0,1,0,0 };
    for (int i = 1; i <= Size_A; i++)
        maze[8][i] = a8[i - 1];
    // ��9
    int a9[10] = { 1,0,0,0,0,0,0,1,0,0 };
    for (int i = 1; i <= Size_A; i++)
        maze[9][i] = a9[i - 1];
    // ��10
    int a10[10] = { 1,0,0,0,0,0,0,1,0,0 };
    for (int i = 1; i <= Size_A; i++)
        maze[10][i] = a10[i - 1];
}
// Ѱ�ҳ���
bool findPath()
{
    // �ҵ���(1, 1)�����ڵ�·��(Size_A, Size_A)
    // ����ɹ�����true����֮����false

    // ��ʼ��ƫ����
    position offset[4];
    offset[0].row = 0; offset[0].col = 1;   // ��
    offset[1].row = 1; offset[1].col = 0;   // ��
    offset[2].row = 0; offset[2].col = -1;  // ��
    offset[3].row = -1; offset[3].col = 0;  // ��

    // ��ʼ���Թ���Χ���ϰ�ǽ
    for (int i = 0; i <= Size_A + 1; i++)
    {
        maze[0][i] = maze[Size_A + 1][i] = 1; // ������ײ�
        maze[i][0] = maze[i][Size_A + 1] = 1; // �����
    }

    position here;      // ��ǰλ��
    here.row = 1;       // ��ǰλ�õ���
    here.col = 1;       // ��ǰλ�õ���
    maze[1][1] = 1;     // ��ֹ�ص����
    int option = 0;     // ��һ��
    int lastOption = 3; // ���Ĳ���

    // Ѱ��һ��·������������ǰλ�ò������Թ���С
    while (here.row != Size_A || here.col != Size_A)
    {
        // û�дﵽ����
        // �ҵ�Ҫ�ƶ������ڵ�һ��
        int r;  // Ѱ�ҵ���
        int c;  // Ѱ�ҵ���
        // Ѱ�Ҽ����ƶ��Ŀ�����
        while (option <= lastOption)
        {
            r = here.row + offset[option].row;
            c = here.col + offset[option].col;
            if (maze[r][c] == 0) 
                break;
            option++;   // ��һ��
        }
        // ���ڵ�һ���Ƿ��ҵ���
        if (option <= lastOption)
        {   
            // �ƶ���maze[r][c]
            path.push(here);
            here.row = r;
            here.col = c;
            maze[r][c] = 1; // ����1���Է�ֹ�ظ�����
            option = 0;
        }
        else
        {
            // ��·���ߣ�����
            if (path.empty())
                return false;   // û��λ�ÿ��Է���
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
    return true;  // �ﵽ����
}
// ���·��
void outputPath()
{
    cout << "·���ǣ�" << endl;
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
      cout << "û��·" << endl;
}
