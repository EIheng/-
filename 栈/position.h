#ifndef position_
#define position_

struct position
{
    int row;  // λ������
    int col;  // λ������

    operator int() const { return row; }
};

#endif
