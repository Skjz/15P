#pragma once
#include"CFood.h"
#include"CSnake.h"

class CArea
{   
  public:
    CArea();
    //初始化游戏
    void Init_Game();
    void Init_Game_DoublePlayer();

    //开始游戏
    void Game_Play();
    void Game_Play_DoublePlayer();

    //存储游戏
    void Save_Game();
    void Save_Double_Game();

    //读档
    void Load_Game();
    void Load_Double_Game();

    //重开
    void Restart_Game();
    //重开双人游戏
    void Restart_DoublePlayer_Game();

    //读取后初始化游戏
    void Load_Init_Game();
    void Load_Double_Init_Game();

    //初始化原始游戏
    void Init_Game_Org();

    

private:
    

    //食物对象
    CFood objFood;

    //蛇对象
    CSnake objSnake;

    //存放蛇身体临时数组
   vector <COORD> Temp_Snake;

   //蛇临时的元素
   COORD Temp_Ele;

   //蛇临时的长度
   int Temp_Snake_Lenth;

   //玩家临时的分数
   int Temp_Score;

   //临时的食物存在数据
   int Temp_Food_Exist;

   //临时的速度
   int Temp_Speed;

   //临时的方向
   int Temp_Dir;


    //临时生命值
   int Temp_Life;
};

