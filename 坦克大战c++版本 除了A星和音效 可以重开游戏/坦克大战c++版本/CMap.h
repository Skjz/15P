#pragma once
#include<stdio.h>
#include<windows.h>
//在内存上表示地图数据的枚举
enum THING
{
    //空地
    EMPTY = 0,
    //障碍物（边界）
    OBSTACLES = 1,
    //土墙
    WALL_I = 2,
    //铁墙
    WALL_II = 3,
    //钢墙
    WALL_III = 4,
    //玩家
    PLAYER = 5,
    //子弹
    BULLET = 6,
    //敌人
    ROBO = 7,
};
enum STHING
{
    S_EMPTY =0,
    S_GRASS = 1,
    S_RIVER = 2, 
};

enum COLOR
{
    FC_Red = FOREGROUND_INTENSITY | FOREGROUND_RED,
    FC_Green = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
    FC_Blue = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
    FC_Yellow = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
    FC_HighWhite = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    FC_White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    FC_Purple = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
    FC_Cyan = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
    FC_Gray = FOREGROUND_INTENSITY,
    FC_BLACK = 0,

    BC_Red = BACKGROUND_INTENSITY | BACKGROUND_RED,
    BC_Green = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
    BC_Blue = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
    BC_Yellow = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
    BC_Purple = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
    BC_Cyan = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
    BC_White = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
    BC_HighWhite = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
    BC_BLACK =0,
    
};


#define EDIT_WIDTH MouseEv.dwMousePosition.X < COLS* 2 - 2 && MouseEv.dwMousePosition.X > 1 && MouseEv.dwMousePosition.Y < ROWS - 1 && MouseEv.dwMousePosition.Y>0
#define HIT_SOUND "..\\Debug\\Hit.wav"
#define MUSic_SOUND "..\\Debug\\Game.wav"
//#define MouseEv.dwMousePosition.X < COLS * 2 - 2) && MouseEv.dwMousePosition.X >0 && MouseEv.dwMousePosition.Y < MAP_COL - 1 && MouseEv.dwMousePosition.Y>0
/*      
函数名:Write
函数作用：接口函数，在屏幕上给定的任意位置，以给定的颜色进行字符串输出
参数1 : short int 类型, 传入参数，坐标的x轴
参数2 : short int 类型, 传入参数，坐标的y轴
参数3：传入参数，想要打印的字符串常量
参数4：传入参数，想要显示的颜色，默认为黑色（亮白色是15）
返回值：
备注：该函数构成函数重载，由于默认颜色是黑色，所以想要进行擦除的时候不传入颜色即可


函数名：Write
函数作用：接口函数，用来在内存上写入该位置地图信息
参数1: short int 类型，传入参数，即坐标的X轴
参数2：short int 类型，传入参数，即坐标的Y轴
参数3:枚举常量，传入参数，表示地图上的是什么
返回值：
备注：该函数构成函数重载

函数名：Is_Something_Here
函数作用：确认地图的指定位置是不是那个东西，如果是则返回真，如果不是返回假
参数1：short int 类型，传入参数，即坐标的X轴
参数2：short int 类型，传入参数，即坐标的Y轴
参数3：枚举常量，传入参数，表示地图上的是什么
返回值：bool 类型，如果地图指定的位置上有指定的东西，返回真
备注：

函数名:InitMap
函数作用：初始化地图，绘制地图的边界，地形
参数1：
返回值：
备注：
*/
class CMap
{
private:
//地图宽和高

    
private:
//地图的数组
    //地图的宽和高

    static const char* Str[8];

    //静态地图
    //静态地图数组
    static const char* S_Str[3];
    static THING DrawThing[5];
    static STHING DrawSThing[3];
public:
    //普通地图
    static constexpr short ROWS{ 40 };
    static constexpr short COLS{ 40 };
    static THING Map[ROWS][COLS];
    //静态地图
    static STHING StaticMap[ROWS][COLS];

public:
    static void Clear_Map();

public:
    static COLOR  SColor[3];
    static COLOR OColor[5];
public:
    //显示用函数
    
    static void Write(_In_  const short X, _In_  const short Y, _In_ const char* Str, _In_ const int Color = 0);
    static void Write(_In_ const short X, _In_ const short Y,_In_ THING Something);
    static void Write(_In_ const short X, _In_ const short Y, _In_ STHING S_Something);
    static void Write(_In_ const short X, _In_ const short Y, _In_ int Int, _In_ const int Color = 0);

public:
    //告诉调用者这里在地图上是什么
    static bool Is_Something_Here(_In_ const short X,_In_ const short Y,_In_ THING Something);
    static bool Is_Something_Here(_In_ const short X,_In_ const short Y,_In_ STHING Something);

public:
    //初始化地图
    static void InitMap();
    static void MouseDraw();
    static void InitCusMap();

//间接访问静态成员变量的接口函数：
public:
    static const char* Get_Str(_In_ int Index);
    static const char* Get_S_Str(_In_ int Index);

public:
    static void ReloadMap(const char* Path_Map);

};

