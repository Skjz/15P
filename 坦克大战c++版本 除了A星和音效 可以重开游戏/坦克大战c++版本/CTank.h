#pragma once
#include<stdio.h>
#include<windows.h>
#include<ctime>
#include<vector>

/*
函数名：Draw_Tank
函数作用：显示坦克或是擦除坦克的图像，同时能够在地图信息中编辑该坐标为坦克或是坐标
参数1：bool 类型，传入参数，true显示坦克且将坦克的信息写入地图，flase则将坦克擦除且将地图编辑为空地
返回值：
备注：参数1的默认参数是true，也就是说，如果不传参数默认是绘制坦克且将地图信息编辑为坦克


函数名：Move_Tank
函数作用：让坦克在地图上移动
参数1：枚举常量，传入参数，即坦克的方向
返回值:
备注：参数1从CGame里的Get_User_Oper接收



函数名：Check_AHead
函数作用：确认坦克前面的三个点是否有障碍物
参数1：
返回值：bool 类型，如果为真，代表前方是空地，如果为假则说明有障碍物
备注：



函数名：Tank_Shot_Bullet
函数作用：返回一个子弹的坐标
参数1：
返回值：COORD类型，子弹产生的初始坐标
备注：



函数名:Get_Tank_Dir
函数作用：返回坦克发射子弹时的方向
参数1：
返回值:DIR，枚举类型，坦克的方向，用来初始化子弹的方向
备注：

函数名：Is_Tank_Can_Shot
函数作用：用来判断坦克当前是否能够进行射击
参数1：
返回值，bool类型，如果能够射击返回值为真，如果不能，返回值为假
备注：

 函数名：Get_Tank_Level
 函数作用：创建子弹时让子弹获得坦克的等级
 参数1：
 返回值：LEVEL枚举类型，坦克的等级
 备注：

函数名：Creat_Robo_Tank
函数作用：用来创建敌方坦克
参数1：vector<CTank> 数组，传出参数，将随机创建好的敌方坦克放入容器中
返回值：
备注：目前地图最大创建坦克数为3
*/



//受等级影响的坦克属性：
//1. 移动速度
//2. 开火的速度
//3. 外形
//4. 生命

//作为下标来索引
enum LEVEL
{
    LV_0,//无效索引
    LV_1,
    LV_2,
    LV_3,
};

//坦克方向
enum DIR
{
    Last_Dir=-1,
    UP=0,
    DOWN,
    LEFT,
    RIGHT
};

//计算路线的结构体，每一个结构体实例化的对象都保存这些信息
typedef struct _NODE
{
    _NODE* pFather;		//父结点，上一个位置
    COORD pos;			//当前位置
    int G;				//走的步数
    int H;				//预估到终点的步数
    int F;				//损耗、即G+H
}NODE,*PNODE;


class CTank
{
public:
    CTank();
    CTank(DIR Dir, COORD Tank_Pos, LEVEL Tank_Level = LV_1, bool Is_Tank_Player = true);


    //移动坦克用接口
public:
    void Draw_Tank(_In_ bool IsShow = true);
    //移动坦克
    void Move_Tank(_In_ DIR Dir);
    bool Check_AHead();
    //移动了坦克之后在画的时候的具体逻辑
private:
    void Draw_Tank_In_Class(_In_ int Temp_Tank_Pos_X, _In_ int Temp_Tank_Pos_Y, _In_ bool IsShow);
    void Draw_Robo_Tank_In_Class(_In_ int Temp_Tank_Pos_X, _In_ int Temp_Tank_Pos_Y, _In_ bool IsShow);
    //移动敌方坦克用接口
public:
    void Draw_Robo_Tank(_In_ bool IsShow = true);
    void Move_Robo_Tank(_In_ DIR Dir=Last_Dir);
    bool Is_Robo_Tank_Can_Shot();

    //初始化子弹用接口：
public:
    //在发射子弹时产生子弹坐标
    COORD Tank_Shot_Bullet();
    //获得坦克的方向
    DIR Get_Tank_Dir();
    //获取坦克的等级（给子弹用）
    LEVEL Get_Tank_Level();
private:
    //坦克的模型
    int m_nTank_Mode[4][3][3];
private:
    //坦克移动相关
private:
    //坦克的方向
    DIR m_Dir;
    //坦克的位置
    COORD m_Tank_Pos;
    //坦克移动的时间差
    clock_t m_Tank_Move_Lasttime;
    //坦克移动的速度
    unsigned short m_Tank_Move_Speed;

public:
    //设置坦克移动时间差
    void Set_Tank_Lasttime();
    void Set_Robo_Lasttime();
public:
    //确认坦克是否能够发射子弹:
    bool Is_Tank_Can_Shot();

 //坦克的后坐力
private:
    clock_t m_Tank_Shot_Lasttime;
    unsigned short m_Tank_Rocil;
public:
    int Get_Tank_Life();

private:
    //玩家的生命值
    int m_Tank_Life;
    //玩家坦克的等级
    LEVEL m_Tank_Level;
public:
    //坦克受伤
    void Tank_Get_Dmg();
public:
    //生成机器人
    void Creat_Robo_Tank(_Out_ std::vector<CTank>& Robo_Tank);
private:
    //地方坦克操作的时间差
    unsigned short m_Robo_Tank_Oper_Time;
    //地方坦克开火时间差
    clock_t m_Robo_Tank_Oper_Lasttime;
public:
    //地方坦克开火的速度
    unsigned short Get_Robo_Tank_Oper_Time();
private:
    //决定坦克是玩家还是敌人
    bool m_Is_Tank_Player;
public:
    //重新设置玩家的坐标和生命，并且擦除之前的坦克
    void Reset_Player(_In_ COORD Reset_Pos);

public:
    //确认坦克是否是玩家
    bool Get_Is_Tank_Player();
    //获得坦克坐标
    COORD Get_Tank_Pos();
    
public:
    //敌方坦克寻路
    //找到的路径存放处
    //std::vector<COORD> m_Robo_Tank_Move_Path;
    //std::vector<PNODE> m_Open;
    //std::vector<PNODE> m_Close;
    ////敌方坦克获取路径的算法
    //void Robo_Tank_Get_Path(_In_ CTank &Player1)
    
    

};

