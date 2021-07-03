#pragma once
#include<vector>
#include<windows.h>
#include"DrawBase.h"


using std::vector;
class CSnake
{
public:
    //初始化蛇
    CSnake();

    //显示蛇
    void Draw_Snake();
    void Draw_Enemy_Snake();

    //将蛇移除
    void Remove_Snake();
    void Remove_Enemy_Snake();

    //移动蛇
    void Move_Snack();
    void Move_Enemy_Snack();
    void Move_Double_Snake();
    void Move_Enemy_Snake_Head(COORD TempEnemy);

    //改变蛇的方向
    void Change_Snake_Dir();
    void Change_Enemy_Snake_Dir();

    //得到吃到食物数量的临时值
    int Get_Temp_Count_Food();
    int Get_Enemy_Temp_Count_Food();

    //得到吃到食物数量的值
    int Get_m_Count_Food();
    int Get_Enemy_m_Count_Food();

    //设置吃到食物的数量的值
    void Set_m_Count_Food(int Temp_Count_Food);
    void Set_Enemy_m_Count_Food(int Temp_Enemy_Count_Food);

    //得到分数的临时值
    int Get_Temp_Score();
    int Get_Enemy_Temp_Score();
    //得到分数的值
    int Get_Score();
    int Get_Enemy_Score();

    //设置分数的值
    void Set_Score(int Temp_Score);
    void Set_Enemy_Score(int Temp_Enemy_Score);

    //未关闭游戏时候生成蛇的图像
    void Draw_No_Player_Snake();
 
    //设置蛇的生命
    void Set_Snake_LIfe(int Temp_Life);
    void Set_Enemy_Snake_LIfe(int Temp_Enemy_Life);
    

    //得到游戏生命值
    int Get_Game_Life();

    int Get_Enemy_Game_Life();

   
    //获取蛇的长度
    int Get_Snake_Lenth();
    int Get_Enemy_Snake_Lenth();
    
    //获取蛇的元素
    COORD Get_Snake_Ele(int nLoc);
    COORD Get_Enemy_Snake_Ele(int nLoc);

    //读取文件push_back
    void Push_Back_Snake(COORD Temp_Snake);
    void Push_Back_Enemy_Snake(COORD Temp_Enemy_Snake);

    //返回一个操作
    int Get_Oper();
    int Get_Enemy_Oper();

    //重新创建蛇
    void RbuildSnake();
    void RbuildEnemySnake();

    //获得蛇的速度
    int Get_Speed();
    int Get_Enemy_Speed();

    //设置蛇的速度
    void Set_Speed(int nSpeed);
    void Set_Enemy_Speed(int nEnemySpeed);

    //获得蛇的方向
    int Get_Dir();
    int Get_Enemy_Dir();
    //设置蛇的方向
    void Set_Dir(int nDir);
    void Set_Enemy_Dir(int nDir);

    //void ClearVector();
    //删除蛇的元素
    void Dele_Snake_Ele();
    void Dele_Enemy_Snake_Ele();

private:
    //Player的容器
    vector<COORD> m_Snake;
    //player2的容器
    vector<COORD> m_Enemy_Snake;

    //Player的移动时间差
    int m_Move_Lasttime;
    //Player2的移动时间差
    int m_Enemy_Move_Lasttime;


    //蛇元素的临时坐标
    COORD Temp_Snake_Ele;
    COORD Temp_Enemy_Snake_Ele;
    
    //蛇的方向
    int m_Snake_Dir;
    int m_Enemy_Snake_Dir;

    //蛇的移动速度（难度）
    int m_Move_Speed;
    //蛇2的移动速度（难度）
    int m_Enemy_Move_Speed;

    //得分
    int m_Get_Score;
    //得分（player2）
    int m_Enemy_Get_Score;

    //得分的临时值
    int m_Get_Temp_Score;
    //敌方蛇的临时得分值
    int m_Enemy_Get_Temp_Score;

    //得到的食物数量的临时值
    int m_Temp_Count_Food;
    //敌方蛇的食物数量的临时值
    int m_Enemy_Temp_Count_Food;

    //食物的数量
    int m_Count_Food;
    //敌方蛇食物的数量
    int m_Enemy_Count_Food;
    
    //生命值
    int m_Game_Life;
    //敌方蛇的生命值
    int m_Enemy_Game_Life;

    //操作
    int Oper;
    //敌方操作
    int Enemy_Oper;
   
    
};

