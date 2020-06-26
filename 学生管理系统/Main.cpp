#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <stack>
#include <queue>

#include "codes/Meun.h"
#include "codes/Administrators.h"
#include "codes/Student.h"
#include "codes/MainMethod.h"

using namespace std;


int main()
{
    /*对象声明*/
    Meun Meun_OfMain;											// 主菜单
    Administrators_Group Administrators_Group_OfMain;			// 管理员组
    Students_Group Students_Group_OfMain;						// 学生组
    Administrators Land_OfMain;									// 登陆者
    MainMethod MainMethod_1
    (
        Meun_OfMain, 
        Administrators_Group_OfMain, 
        Students_Group_OfMain, 
        Land_OfMain
    );
    // 开始主循环
    while (true)
    {
        /*
        如果登陆成功进入管理员菜单
        注意登陆那个还有阅览者菜单等等没有完成，先暂时完成管理员
        */
        // 获取登陆者，登入系统或者注册
        if (MainMethod_1.Land())
        {
            // 进入管理员界面
            MainMethod_1.AdministratorsMain();
        }
        else
        {
            break;
        }
    }
    cout << "系统关闭！" << endl;
}
