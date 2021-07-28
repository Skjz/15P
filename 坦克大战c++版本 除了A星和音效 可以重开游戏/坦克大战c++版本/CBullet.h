#pragma once

#include<windows.h>
#include"CTank.h"
#include<ctime>
#include<vector>
/*
函数名：Draw_Bullet
函数作用：绘制子弹或者擦除子弹，同时对地图信息进行编辑
参数1：bool 类型，传入参数，如果为真则绘制子弹，如果为假则擦除子弹
返回值：
备注：

函数名：Set_Bullet_Dir
函数作用：设置子弹的飞行方向（初始化子弹用）
参数1：DIR枚举类型，传入参数，一般通过坦克类的函数返回值传入
返回值：
备注：

函数名：Set_Bullet_Pos
函数作用：设置子弹的位置（初始化子弹用）
参数1：传入参数，一般通过坦克类的函数返回值传入
返回值：
备注：

函数名：Creat_Bullet
函数作用：产生子弹，将子弹初始化，之后将子弹对象置入容器中
参数1：DIR枚举类型,传入参数，一般通过坦克类的函数 Get_Tank_Dir() 返回值传入
参数2：COORD结构体，传入参数，一般通过坦克类的函数 Tank_Shot_Bullet() 返回值传入
参数3:vector 容器的引用，传出参数，将子弹对象所有初始化好的信息置入容器
返回值：
备注：
*/


/*
/*
函数名：Draw_Bullet
函数作用：绘制子弹或者擦除子弹，同时对地图信息进行编辑
参数1：bool 类型，传入参数，如果为真则绘制子弹，如果为假则擦除子弹
返回值：
备注：

函数名：Move_Bullet
函数作用：移动子弹，同时设置子弹的有效性m_Bullet_Life
参数1：
返回值：
备注：

函数名：Check_Bullet_Hit
函数作用：检查子弹的碰撞，并且处理相应的逻辑
参数1：
返回值：int类型，对应THING枚举中的对象（即反馈撞上了什么）
备注：

*/


/*
函数名：Get_Bullet_Life
函数作用：接口函数，用来告诉调用者该子弹对象是否有效
参数1：
返回值：
备注：如果子弹对象无效(false)，应当进行删除。

*/
class CBullet
{
//初始化子弹：
private:
    //子弹等级
    LEVEL m_Bullet_Level;
public:
    CBullet();
    //设置子弹方向
    void Set_Bullet_Dir(_In_ DIR Dir);
    //设置子弹的坐标
    void Set_Bullet_Pos(_In_ COORD Bullet_Pos);
    //产生子弹
    void Creat_Bullet(_In_ DIR Dir, _In_ COORD Bullet_Pos,_Out_ std::vector<CBullet>&Bullet);
    //设置等级
    void Set_Bullet_Level(_In_ LEVEL Tank_Level);
    //不同子弹等级,不同的生成
    void Bullet_Power(_Out_ std::vector<CBullet>& Bullet);
    void Set_Is_Bullet_Player(bool IS_Tank_Player);
    void Set_Bullet_Move_Lasttime();
private:
    //这个子弹是敌军还是友军的标识
    bool m_Is_Bullet_Player;
//移动子弹:
public:
    void Draw_Bullet(_In_ bool IsShow);
    void Move_Bullet(_Out_ std::vector<CBullet>& objBullet, _Out_ std::vector<CTank>& objRobo, _In_ CTank& Player1, _In_ CTank& Player2);
    //检查子弹撞上了什么
    int Check_Bullet_Hit(_Out_ std::vector<CBullet>& objBullet, _Out_ std::vector<CTank>& objRobo, _In_ CTank& Player1, _In_ CTank& Player2);

    void Search_For_Robo( _Out_ std::vector<CTank>& objRobo);
    void Search_For_Player(_In_ CTank& Player1, _In_ CTank& Player2);
    //返回子弹的位置
    bool Bullet_Hit_Bullet;
private:
    void Draw_Bullet_In_Class();
    void Remove_Bullet_In_Class();
  
private:
    //子弹的坐标
    COORD m_Bullet_Pos;
    //子弹的方向
    DIR m_Bullet_Dir;
    //子弹移动的时间差
    clock_t m_Bullet_Move_Lasttime;
    //速度
    int m_Bullet_Speed;

//确认子弹的有效性：
private:
    bool m_Bullet_Life;
public:
    bool Get_Bullet_Life();
public:
    LEVEL Get_Bullet_Level();
    COORD Get_Bullet_Pos();
    
};

