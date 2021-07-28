#include "CTankTool.h"
#include"CTank.h"

//初始化静态成员
unsigned short CTankTool::Tank_Move_Speed[4]{ 0,200,100,50 };
unsigned short CTankTool::Tank_Rocil[4]{ 0,300,200,150 };
COLOR CTankTool::Tank_Color[4]{ FC_BLACK,FC_HighWhite,FC_Green,FC_Blue };
COLOR CTankTool::Tank_In_Grass{ BC_Green };
COLOR CTankTool::Bullet_In_Grass{ BC_Green };
COLOR CTankTool::Bullet_In_River{ FC_HighWhite };
//敌方坦克的数量
unsigned short CTankTool::Robo_Tank_Count{ 0 };
unsigned short CTankTool::Robo_Tank_Max_Count{3};

DIR CTankTool::m_Robo_Move_Oper_Arr[4]{ UP,DOWN,LEFT,RIGHT };
//子弹相关
unsigned short CTankTool::Bullet_Move_Speed[4]{ 0,150,100,50 };
COLOR CTankTool::Bullet_Color[4]{ FC_BLACK,FC_Red,FC_Green,FC_Blue };

const char* CTankTool::Game_Stage[5]
{
    PATH_MAP1,PATH_MAP2,PATH_MAP3,PATH_MAP4,PATH_MAP5
};


//COORD CTankTool::Bullet_Hit_Bullet[100]{ 0 };