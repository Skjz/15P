#pragma once
#include"CMap.h"
#include"CBullet.h"
#include<vector>
using std::vector;
//#include<windows.h>

//地图1
#define PATH_MAP1  "..\\Debug\\1.map"
//地图2                 D
#define PATH_MAP2  "..\\Debug\\2.map"
//地图3                 D
#define PATH_MAP3  "..\\Debug\\3.map"
//地图4                 D
#define PATH_MAP4  "..\\Debug\\4.map"
//地图5                 D
#define PATH_MAP5  "..\\Debug\\5.map"
//保存冒险模式
#define PATH_SAVE_ADV   "..\\Debug\\Adv.sav"
//保存编辑模式
#define PATH_SAVE_CUS  "..\\Debug\\Cus.sav"

//坦克大战工具类，以LEVEL来作为索引使用
class CTankTool
{
public:
    //坦克相关
    //初始化静态成员
    static unsigned short Tank_Move_Speed[4];       //坦克移动速度数组
    static unsigned short Tank_Rocil[4];            //坦克后坐力数组，影响坦克射击的间隔时间
    static COLOR Tank_Color[4];                     //坦克外观的数组，不同等级的坦克有不同的外观
    static COLOR Tank_In_Grass;                     //坦克在草里的颜色
    static COLOR Bullet_In_Grass;                   //子弹在草里的颜色
    static COLOR Bullet_In_River;                   
    //敌方坦克的数量
    static unsigned short Robo_Tank_Count;            //敌方坦克的数量
    static unsigned short Robo_Tank_Max_Count;        //敌方坦克同时在场最大数量
    static DIR m_Robo_Move_Oper_Arr[4];

   
    //地图数组
    static const char* Game_Stage[5];

    //子弹相关
    static unsigned short Bullet_Move_Speed[4];     //子弹的移动速度数组，不同等级的子弹有不同的移动速度
    static COLOR Bullet_Color[4];                   //子弹的外观数组，不同等级的子弹有不同外观
    ////子弹数组
    //static vector<CBullet> objBullet;
    ////坦克数组
    //static vector<CTank> objRobo;
};

