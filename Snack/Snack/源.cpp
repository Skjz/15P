#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"winmm.lib")
#include"CArea.h"
#include"DrawBase.h"
#include"ShowMenu.h"
#include"MouseDraw.h"
#include"Welcome.h"

//地图的数组
int Map[MAP_ROW][MAP_COL];

int main()
{
    //设置标题
    system("title 欢乐贪吃蛇");

    //关闭光标
    ShowCursor(false);

    //欢迎界面
    ShowWelcome();
    Sleep(1500);
    system("cls");

    PlaySoundA(MUSICPATH, NULL, SND_ASYNC | SND_NODEFAULT);
    //1.开始游戏
   // 2.读取游戏
   // 3.编辑地图
   // 0.结束游戏

    CArea c;

    //获取句柄
    HANDLE hconsloeInput = GetStdHandle(STD_INPUT_HANDLE);
    //获取输入的结构体
    INPUT_RECORD ir = { 0 };

    //计数结构体数量
    DWORD dwRealCourt = 0;

    //控制台编辑模式
    DWORD dwMode = 0;

    //防止死循环
    int Flag = 1;
    while (1)
    {
        ShowMenu();
        //循环获取控制台输入信息
        while (Flag)
        {
            //设置控制台输入模式
            GetConsoleMode(hconsloeInput, &dwMode);
            SetConsoleMode(hconsloeInput, dwMode | ENABLE_MOUSE_INPUT);
            //读取控制台输入
            ReadConsoleInput
            (
                hconsloeInput,
                &ir,
                1,
                &dwRealCourt

            );
            //如果进行操作的是鼠标
            if (ir.EventType == MOUSE_EVENT)
            {
                //由MouseEv来接收鼠标的操作
                MOUSE_EVENT_RECORD MouseEv = ir.Event.MouseEvent;

                //当进行左击的时候
                if (MouseEv.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                {
                    //新游戏
                    if (GAMESTART_CUS)
                    {
                        Flag = 0;
                        PlaySoundA(MUSICPATH, NULL, SND_ASYNC | SND_NODEFAULT);
                        system("cls");
                        //初始化游戏
                        c.Restart_Game();
                        c.Init_Game();
                        //游戏开始
                        c.Game_Play();
                    }
                    //自定义游戏
                    if (GAMESTART_ORG)
                    {
                        Flag = 0;
                        PlaySoundA(MUSICPATH, NULL, SND_ASYNC | SND_NODEFAULT);
                        system("cls");
                        c.Restart_Game();
                        c.Init_Game_Org();
                        c.Game_Play();
                    }
                    //读取游戏
                    else if (LOADGAME)
                    {
                        Flag = 0;
                        system("cls");
                        //读取游戏函数
                        c.Load_Game();
                        //读取后的初始化函数
                        c.Load_Init_Game();
                        //开始游戏
                        c.Game_Play();
                    }

                    //编辑地图
                    else if (EDITGAME)
                    {
                        Flag = 0;
                   
                        system("cls");
                        //绘制地图
                        for (int i = 0; i < MAP_ROW; i++)
                        {
                            for (int j = 0; j < MAP_COL; j++)
                            {
                                if ((i == 0) || (j == 0) || (i == (MAP_ROW - 1)) || (j == (MAP_COL - 1)))
                                {
                                    Map[i][j] = OBSTACLES;
                                    Write_Char(i, j, "※");
                                }
                                else if (Map[i][j] == OBSTACLES)
                                    Write_Char(i, j, "□");
                               
                            }
                        }
                        //ui信息
                        Write_Char(35, 25, "鼠标左键绘制");
                        Write_Char(35, 24, "鼠标右键退出");
                        Write_Char(35, 23, "滚轮消除障碍");
                        //画出障碍
                        MouseDraw();
                    }
                    else if (DOUBLEPLAY)
                    {
                        Flag = 0;
                        PlaySoundA(MUSICPATH, NULL, SND_ASYNC | SND_NODEFAULT);
                        system("cls");
                        //初始化游戏
                        c.Restart_DoublePlayer_Game();
                        c.Init_Game_DoublePlayer();
                        //游戏开始
                        c.Game_Play_DoublePlayer();
                    }
                    else if (DOUBLCONTINUE)
                    {
                        Flag = 0;
                        PlaySoundA(MUSICPATH, NULL, SND_ASYNC | SND_NODEFAULT);
                        system("cls");
                        c.Load_Double_Game();
                        c.Load_Double_Init_Game();
                        c.Game_Play_DoublePlayer();
                    }
                    //退出游戏
                    else if (ENDGAME)
                    {
                        Flag = 0;
                        return 0;
                    }

                    
                }
            }
            //system("cls");
        }
        Flag = 1;
        system("cls");
    }
    //case LOADGAME:
    //    system("cls");
    //    //读取游戏
    //    c.Load_Game();
    //    //读取后的初始化函数
    //    c.Load_Init_Game();
    //    //开始游戏
    //    c.Game_Play();
    //    break;
    //case EDITGAME:

    //    break;
    //case ENDGAME:

    //    break;
    //
    //system("cls");




//ShowWelcome();
//Sleep(400);
//system("cls");
//ShowMenu();
//system("pause");
//创建CArea 对象









//CSnake objsnake;
//objsnake.Draw_Snake();



 /*  objsnake.Move_Snack();*/
//objsnake.Remove_Snake();
//objsnake.Draw_Snake();

    return 0;
}