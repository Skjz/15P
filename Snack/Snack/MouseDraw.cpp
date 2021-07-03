#define _CRT_SECURE_NO_WARNINGS
#include"DrawBase.h"
#include"MouseDraw.h"

void MouseDraw()
{
    //1 获取控制台输入句柄
    HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
    //2 循环获取控制台输入信息
    INPUT_RECORD ir = { 0 };
    DWORD dwRealCourt = 0;
    DWORD dwMode = 0;
    int Return = 0;

    while (true)
    {
        GetConsoleMode(hConsoleInput, &dwMode);
        SetConsoleMode(hConsoleInput, dwMode | ENABLE_MOUSE_INPUT);
        ReadConsoleInput(
            hConsoleInput,//控制台输入数据
            &ir,          //获取到的控制台信息就传到这个结构体中
            3,            //缓冲区INPUT_RECORD的数量
            &dwRealCourt  //传出，读取完毕的时候，究竟读取了几个结构体信息
        );
        //是一个鼠标信息
        if (ir.EventType == MOUSE_EVENT)
        {
            //如果是鼠标信息，那么就是联合体中的这个字段起作用
            MOUSE_EVENT_RECORD MouseEv = ir.Event.MouseEvent;
            if (MouseEv.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                //画障碍物
                if ((EDITOBSTCALES)
                {
                    int x = MOUSEPOS_X;
                    int y = MOUSEPOS_Y;
                    Write_Char(x, y, "□");
                    Map[x][y] = OBSTACLES;
                }
            }
            //退出编辑模式
            if (MouseEv.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
            {
                return;
            }

            //消除障碍物
            if (MouseEv.dwButtonState == FROM_LEFT_2ND_BUTTON_PRESSED)
            {
                if (SETEMPTYAREA)
                {
                    int x = MOUSEPOS_X;
                    int y = MOUSEPOS_Y;
                    Write_Char(x, y, "  ");
                    Map[x][y] = EMPTYAREA;
                }
            }

        }

    }
}