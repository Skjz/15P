#define _CRT_SECURE_NO_WARNINGS
#include"DrawBase.h"

void Write_Char(int x, int y,  const char* str, int Color)
{
    //用来设置光标具体坐标的pos
    COORD pos = { 2*x,y };
    //获取句柄
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置光标位置
    SetConsoleCursorPosition(hOut,pos);

    //设置文本颜色
    SetConsoleTextAttribute(hOut, Color);
    //输出字符
    printf("%s", str);
}

void Write_Int(int x, int y, int nNum, int Color)
{
    //用来设置光标具体坐标的pos
    COORD pos = { x,y };
    //获取句柄
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置光标位置
    SetConsoleCursorPosition(hOut, pos);
    //设置文本颜色
    SetConsoleTextAttribute(hOut, Color);
    printf("%d", nNum);
}

//关闭光标函数
void ShowCursor(bool isShow)
{
    HANDLE hOUtStd = GetStdHandle(STD_OUTPUT_HANDLE);

    //设置控制台光标的结构体
    CONSOLE_CURSOR_INFO cci;
    //光标尺寸
    cci.dwSize = 1;
    //关闭光标或打开光标
    cci.bVisible = isShow;

    //设置控制台函数
    SetConsoleCursorInfo(hOUtStd, &cci);
}


int WaitKey()
{
    if (_kbhit())
    {
        return _getch();
    }
    return 0;
}
