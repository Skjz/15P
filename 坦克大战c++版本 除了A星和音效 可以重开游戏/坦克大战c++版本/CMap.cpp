#include "CMap.h"
#include"CTankTool.h"
#include<windows.h>


//初始化静态成员
THING CMap::Map[ROWS][COLS]{ EMPTY };
STHING CMap::StaticMap[ROWS][COLS]{ S_EMPTY };
const char* CMap::Str[8]{ "  ","□","~~","☆","※","■","●","xx" };
COLOR CMap::OColor[5]{ FC_BLACK , FC_Yellow ,FC_Gray,FC_Cyan ,FC_HighWhite };
const char* CMap::S_Str[3]{ "  ","■","||" };
COLOR  CMap::SColor[3]{ FC_BLACK,FC_Green,BC_HighWhite };

THING CMap::DrawThing[5]{  //空地
                          EMPTY,
                          //障碍物（边界）
                          OBSTACLES,
                          //土墙
                          WALL_I,
                          //铁墙
                          WALL_II,
                          //钢墙
                          WALL_III
};
STHING CMap::DrawSThing[3]
{
    //空地
    S_EMPTY ,
    //草地
    S_GRASS ,
    //河流
    S_RIVER
};
//将内容显示在屏幕上
void CMap::Write(_In_  const short X, _In_  const short Y, _In_ const char* Str, _In_ const int Color)
{
    //设置光标具体坐标
    COORD pos = { 2 * Y,X };
    //获取句柄
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置光标位置
    SetConsoleCursorPosition(hOut, pos);

    //设置文本颜色
    SetConsoleTextAttribute(hOut, Color);

    //输出字符
    printf("%s", Str);
}

//在内存上写入地图数据
void CMap::Write(_In_ const short X, _In_ const short Y, _In_ THING Something)
{
    Map[X][Y] = Something;


}

//告诉调用者这里在地图上是什么
bool CMap::Is_Something_Here(_In_ const short X, _In_ const short Y, _In_ THING Something)
{
    //如果返回为真，代表这里的东西确实是我传入的东西，为假说明不是
    return Map[X][Y] == Something;
}
bool CMap::Is_Something_Here(_In_ const short X, _In_ const short Y, _In_ STHING Something)
{
    return StaticMap[X][Y] == Something;
}

//初始化地图(初始地图化)
void CMap::InitMap()
{
    for (short i = 0; i < ROWS; i++)
    {
        for (short j = 0; j < COLS; j++)
        {
            //当是地图边界的时候，设置边界并绘制边界
            if ((i == 0) || (j == 0) || (i == ROWS - 1) || (j == COLS - 1))
            {
                CMap::Write(i, j, OBSTACLES);
                CMap::Write(i, j, Str[OBSTACLES], OColor[OBSTACLES]);
            }
            else
            {
                CMap::Write(i, j, EMPTY);
                CMap::Write(i, j, S_EMPTY);
            }
        }
    }
    //设置并绘制土墙
    for (short j = 15; j < 30; j++)
    {
        CMap::Write(10, j, WALL_I);
        CMap::Write(10, j, Str[WALL_I], OColor[WALL_I]);
    }
    //设置并绘制铁强
    for (short j = 15; j < 30; j++)
    {
        CMap::Write(12, j, WALL_II);
        CMap::Write(12, j, Str[WALL_II], OColor[WALL_II]);
    }
    //设置并绘制钢墙
    for (short j = 15; j < 30; j++)
    {
        CMap::Write(14, j, WALL_III);
        CMap::Write(14, j, Str[WALL_III], OColor[WALL_III]);
    }
    //设置并绘制草
    for (int i = 16; i < 20; i++)
    {
        for (short j = 15; j < 30; j++)
        {
            CMap::Write(i, j, S_GRASS);
            CMap::Write(i, j, S_Str[S_GRASS], SColor[S_GRASS]);
        }
    }
    for (short j = 15; j < 30; j++)
    {
        CMap::Write(30, j, S_RIVER);
        CMap::Write(30, j, S_Str[S_RIVER], SColor[S_RIVER]);
    }
}

//初始化非默认地图
void CMap::InitCusMap()
{

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if ((i == 0) || (j == 0) || (i == ROWS - 1) || (j == COLS - 1))
            {
                CMap::Write(i, j, OBSTACLES);
                CMap::Write(i, j, Str[OBSTACLES], OColor[OBSTACLES]);
            }
            else if (Map[i][j] == OBSTACLES)
            {
                CMap::Write(i, j, Str[OBSTACLES], OColor[OBSTACLES]);
            }
            else if (Map[i][j] == WALL_I)
            {
                CMap::Write(i, j, Str[WALL_I], OColor[WALL_I]);
            }
            else if (Map[i][j] == WALL_II)
            {
                CMap::Write(i, j, Str[WALL_II], OColor[WALL_II]);
            }
            else if (Map[i][j] == WALL_III)
            {
                CMap::Write(i, j, Str[WALL_III], OColor[WALL_III]);
            }
            else if (StaticMap[i][j] == S_GRASS)
            {
                CMap::Write(i, j, S_Str[S_GRASS], SColor[S_GRASS]);
            }
            else if (StaticMap[i][j] == S_RIVER)
            {
                CMap::Write(i, j, S_Str[S_RIVER], SColor[S_RIVER]);
            }
        }
    }
}
//获得地图上显示的对应图案
const char* CMap::Get_Str(_In_ int Index)
{
    return CMap::Str[Index];
}
void CMap::Write(_In_ const short X, _In_ const short Y, _In_ STHING S_Something)
{
    StaticMap[X][Y] = S_Something;
}

const char* CMap::Get_S_Str(_In_ int Index)
{
    return S_Str[Index];
}


void CMap::MouseDraw()
{
   
    Clear_Map();
    for (short i = 0; i < ROWS; i++)
    {
        for (short j = 0; j < COLS; j++)
        {
            //当是地图边界的时候，设置边界并绘制边界
            if ((i == 0) || (j == 0) || (i == ROWS - 1) || (j == COLS - 1))
            {
                CMap::Write(i, j, OBSTACLES);
                CMap::Write(i, j, Str[OBSTACLES], OColor[OBSTACLES]);
            }
        }
    }
    int Index1 = 0;
    int Index2 = 0;
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
            1,            //缓冲区INPUT_RECORD的数量
            &dwRealCourt  //传出，读取完毕的时候，究竟读取了几个结构体信息
        );
        //是一个鼠标信息
        if (ir.EventType == MOUSE_EVENT)
        {
            //如果是鼠标信息，那么就是联合体中的这个字段起作用
            MOUSE_EVENT_RECORD MouseEv = ir.Event.MouseEvent;

            //当使用滚轮的时候，那么就切换画的图像
            if (MouseEv.dwEventFlags == MOUSE_WHEELED )
            {
                Index1++;
                if (Index1 >= 5)
                {
                    Index1 = 0;
                }
            }
            else if (MouseEv.dwEventFlags == DOUBLE_CLICK)
            {
                Index2++;
                if (Index2 >= 3)
                {
                    Index2 = 0;
                }
            }
            //画当前的图像图像（动态）
            if (MouseEv.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED && EDIT_WIDTH)
            {
                //在图形上显示该内容
                int y = MouseEv.dwMousePosition.X / 2;
                int x = MouseEv.dwMousePosition.Y;
                CMap::Write(x, y, DrawThing[Index1]);
                CMap::Write(x, y, Str[DrawThing[Index1]], OColor[DrawThing[Index1]]);
                //将该内容写入相对应的数组中

            }
            //画当前图像（静态）
            if (MouseEv.dwButtonState == RIGHTMOST_BUTTON_PRESSED &&EDIT_WIDTH)
            {
                int y = MouseEv.dwMousePosition.X / 2;
                int x = MouseEv.dwMousePosition.Y;
                CMap::Write(x, y, DrawSThing[Index2]);
                CMap::Write(x, y, S_Str[DrawThing[Index2]], SColor[DrawThing[Index2]]);

            }

            //退出
            if (MouseEv.dwButtonState == FROM_LEFT_2ND_BUTTON_PRESSED)
            {
                return;

            }

        }

    }
}

void CMap::ReloadMap(const char* Path_Map)
{
    //读取地图进入静态数组和动态数组
    FILE* pFile = nullptr;
    int Error = fopen_s(&pFile, Path_Map, "rb");

    if (Error != 0)
    {

        return;
    }
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            fread(&Map[i][j], 1, sizeof(THING), pFile);
        }
    }
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            fread(&StaticMap[i][j], 1, sizeof(STHING), pFile);
        }
    }
    fclose(pFile);
    pFile = nullptr;

}

void CMap::Clear_Map()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            Map[i][j] = EMPTY;
            Write(i, j, EMPTY);
            Write(i, j, Str[EMPTY], OColor[EMPTY]);
            StaticMap[i][j] = S_EMPTY;
            Write(i, j, S_EMPTY);
            Write(i, j, S_Str[S_EMPTY], SColor[S_EMPTY]);

        }
    }


}
void CMap::Write(_In_ const short X, _In_ const short Y, _In_ int Int, _In_ const int Color)
{
    //设置光标具体坐标
    COORD pos = { 2 * Y,X };
    //获取句柄
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置光标位置
    SetConsoleCursorPosition(hOut, pos);

    //设置文本颜色
    SetConsoleTextAttribute(hOut, Color);

    //输出字符
    printf("%d", Int);
}
