#ifndef position_
#define position_

struct position
{
    int row;  // 位置行数
    int col;  // 位置列数

    operator int() const { return row; }
};

#endif
