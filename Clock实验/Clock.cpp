#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include <time.h>

void Write_Char(int x, int y, const char* str, int n,int Color=15)
{
    //用来设置光标具体坐标的pos
    COORD pos = { 2 * x,y };
    //获取句柄
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置光标位置
    SetConsoleCursorPosition(hOut, pos);

    //设置文本颜色
    SetConsoleTextAttribute(hOut, Color);
    //输出字符
    printf("%s%d", str,n);
}

struct Snake
{
    Snake(int nId,int n,int Speed,int x,int y):m_n(n), m_nId(nId), m_nSpeed(Speed), m_x(x),m_y(y)
    {
        m_LastTime = clock();
    }

    void Move()
    {
        if (clock()- m_LastTime> m_nSpeed)
        {
            Write_Char(m_x, m_y, "移动", m_n);
            m_n++;
            m_LastTime = clock();

        }

    }
    int m_n;
    int m_nId ;
    int m_LastTime;
    int m_nSpeed;
    int m_x;
    int m_y;
};
int main()
{
    Snake obj1(1, 0, 100,10,10);
    Snake obj2(2, 0, 200,20,20);
    while (true)
    {
        obj1.Move();
        obj2.Move();
    }
}
