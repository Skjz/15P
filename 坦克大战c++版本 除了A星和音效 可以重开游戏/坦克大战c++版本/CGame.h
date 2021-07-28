#pragma once
#include<stdio.h>
#include"CTank.h"
#include"CBullet.h"
#include<vector>

using std::vector;
//用来识别案件是否按下的宏
#define KEYDOWN(key) ((GetAsyncKeyState(key)& 0x8000) ? (1) :(0) )

/*
函数名：Get_User_Oper 
函数作用：实现函数，获取用户的操作，比如坦克移动，暂停和存储
参数:
返回值：
备注：该函数用来实时获取用户的输入操作




函数名：Show_Cursor
函数作用：实现函数，用来打开或关闭控制台光标显示
参数1：传入参数，true\false
返回值：
备注：true为打开控制台光标，false为关闭控制台光标


函数名：Init_Console_Size
函数作用：实现函数，设置整个控制台窗口的大小
参数1：传入参数， short int 型参数，坐标x
参数2：传入参数,  short int 型参数，坐标y
返回值：
备注：

函数名：Init_Console_Info_All
函数作用：接口函数，初始化所有窗口信息，包括窗口尺寸，缓冲区大小，窗口标题，以及是否显示控制台光标
参数1：传入参数，short 类型的参数，窗口的宽度
参数2：传入参数，short 类型的参数，窗口的高度
参数3：传入参数，字符串常量，窗口的标题
参数4：传入参数，bool类型，是否显示窗口光标，默认是关闭光标。
返回值：
备注：要打开光标需要在参数4处传入true参数


函数名：Game_Play
函数作用：接口函数，用来处理游戏运行流程的逻辑
参数1：
返回值：
备注：

函数名：Move_All_bullet
函数作用：移动所有的子弹。且负责删去子弹
参数1：
返回值：
备注：
*/

class CGame
{

public:
    //初始化全部窗口信息
    void Init_Console_Info_All(_In_ const short X, _In_ const short Y, _In_ const char* Title, _In_ const bool Isshow = false);
    CGame();

public:
    //控制整个游戏游玩逻辑的函数(自定义)
    void Game_Play();
    //闯关模式
    void Game_Play_Adv();

    //初始化游戏用：
private:
    //关闭光标用函数
    void Show_Cursor(_In_ const bool isShow = false);
    //初始化窗口大小
    void Init_Console_Size(_In_ const short X, _In_ const short Y);


    //接收用户操作用：
private:
    //获取用户输入
    void Get_User_Oper();

    //包含的对象：
private:
    CTank Player1{ RIGHT, {10,10},LV_3,true };
    CTank Player2{ LEFT,{5,5,},LV_3 ,true};
private:
    vector<CBullet> objBullet;
    vector<CTank> objRobo;

private:
    //确认友方是否存活
    void Check_Player_Is_Alive();

//生成敌方坦克相关：
private:
    //初始化敌方坦克
    void Init_Robo_Tank();
    //复活敌方坦克
    void Refresh_Robo_Tank();

    //确认坦克
    void Check_Robo_Alive();

private:
    //进入下一关
    void Next_Stage();
    void Refresh_Game();
private:
    clock_t Robo_Move_Lasttime;
    
private:
    //玩家击杀的计数
    unsigned short m_Tank_Kill_Count;
    unsigned short m_Temp_Tank_Kill_Count;
    //玩家胜利条件  
    unsigned short m_Game_Win_Con;
    
private:
    //玩家失败的条件
    unsigned short m_Game_Lose_Con;
    unsigned short m_Player_Dead_Count;
    bool Is_Game_Save;
private:
    //移动所有地图上的子弹
    void Move_All_Bullet(_Out_ vector<CBullet> &objBullet,_Out_ vector<CTank> &objRobo,_In_ CTank &Player1,_In_ CTank &Player2);

private:
    void Move_All_Robo();
    void Creat_Robo_Bullet(CTank objRobo_Single);
    
private:
    //创建一号玩家子弹的接口
    void Creat_Player1_Bullet();
    //创建二号玩家子弹的接口
    void Creat_Player2_Bullet();

public:
    void Show_Menu();
    void Show_Welcome();

private:
    void Save_Game();
public:
    void Load_Game();
public:
    void Load_Game_Start();

    
};



