/*
源文件：
    使用栈重新安排火车车厢
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

// 全局变量
stack<int>* track;  // 缓冲轨道数组
int numberOfCars;   // 车厢的数量
int numberOfTracks; // 缓冲轨道的数量
int smallestCar;    // 在缓冲轨道中编号最小的车厢
int itsTrack;       // 停靠着最小编号的车厢的缓冲轨道
// 将编号最小的车厢从缓冲轨道移出轨道
void outputFromHoldingTrack()
{
    // 从栈
    track[itsTrack].pop();
    cout << "从缓冲轨道" << itsTrack << "移出车厢" << smallestCar << endl;

    // 检查所有栈的栈顶，寻找编号最小额度车厢和它所属的栈itsTrack
    smallestCar = numberOfCars + 2;
    for (int i = 1; i <= numberOfTracks; i++)
    {
        // 如果栈非空，而且栈顶的车厢小于在缓冲轨道中编号最小的车厢
        if (!track[i].empty() && (track[i].top() < smallestCar))
        {
            // 修改最小
            smallestCar = track[i].top();
            itsTrack = i;
        }
    }
}
// 将车厢c移到一个缓冲轨道。当且仅当没有可用的缓冲轨道时返回false
bool putInHoldingTrack(int c)
{
    // 为车厢c寻找合适的缓冲轨道
    // 初始化
    int bestTrack = 0;                  // 目前最合适的缓冲轨道
    int bestTop = numberOfCars + 1;     // 最合适的缓冲轨道中的最顶部的车厢

    // 遍历缓冲轨道
    for (int i = 1; i <= numberOfTracks; i++)
    {
        if (!track[i].empty())      // 若缓冲轨道不为空
        {
            // 获取顶部
            int topCar = track[i].top();    // 缓冲轨道i的顶部车厢
            // 寻找最优缓冲车道顶上的车厢
            if (c < topCar && topCar < bestTop)
            {
                // 修改最优
                bestTop = topCar;
                bestTrack = i;
            }
        }
        else if (bestTrack == 0)    // 若当前栈空，则最优栈就是遍历的数
            bestTrack = i;
    }
    // 遍历完成，若没有可行的轨道
    if (bestTrack == 0)
        return false;

    // 将车厢c加入到最优轨道
    track[bestTrack].push(c);
    cout << "移动车厢" << c << "到" << bestTrack << "轨道" << endl;

    // 如果需要，更新smallestCar与itsTrack
    if (c < smallestCar)
    {
        smallestCar = c;
        itsTrack = bestTrack;
    }

    return true;
}
// 从初始顺序开始重排车厢(车厢组，车厢的数量， 缓冲轨道的数量)
bool railroad(int inputOrder[], int theNumberOfCars, int theNumberOfTracks)
{
    // 如果重排成功，返回true，否侧返回false
    numberOfCars = theNumberOfCars;
    numberOfTracks = theNumberOfTracks;

    // 创建用于缓冲轨道的栈
    track = new stack<int>[numberOfTracks + 1];

    int nextCarToOutput = 1;            //下一辆需要被输出的车厢
    smallestCar = numberOfCars + 1;     // 初始化缓冲轨道中最小的车厢

    // 遍历车厢
    for (int i = 1; i <= numberOfCars; i++)
    {
        if (inputOrder[i] == nextCarToOutput)
        {
            // 将车厢inputOrder[i]移出轨道
            cout << "移动车厢" << inputOrder[i] << "从缓冲轨道到输出轨道" << endl;
            nextCarToOutput++;

            // 从缓冲轨道移到输出轨道
            while (smallestCar == nextCarToOutput)
            {
                outputFromHoldingTrack();
                nextCarToOutput++;
            }
        }
        else if (!putInHoldingTrack(inputOrder[i]))  // 尝试将车厢inputOrder[i]移动到一个缓冲轨道
            return false;
    }
    return true;
}

int main()
{
    int p[] = { 0, 5, 8, 1, 7, 4, 2, 9, 6, 3 };
    cout << "输入车厢组合：581742963" << endl;
    cout << railroad(p, 9, 3) << endl;
    int q[] = { 0, 3, 6, 9, 2, 4, 7, 1, 8, 5 };
    cout << "输入车厢组合：369247185" << endl;
    cout << railroad(q, 9, 3) << endl;
    return 0;
}
