#include "CArea.h"
#include"DrawBase.h"
#include<stdio.h>

CArea::CArea() 
{

}

//初始化游戏
void CArea::Init_Game()
{
    //绘制地图并且在数组中存放障碍物信息
    //障碍物信息用来判断是否撞到障碍物
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
            {
                Write_Char(i, j, "□");
            }
            else
            {
                Map[i][j] = EMPTYAREA;
            }
        }

    }
    //创建蛇的图像
    objSnake.Draw_Snake();


    //初始化食物
    objFood.Creat_Food();

    //ui信息
    Write_Char(35, 25, "按e存档",15);
    Write_Char(35, 24, "按q暂停",15);
    Write_Char(35, 23, "分数:",15);
    Write_Char(35, 26, "1p操作 上:w 下:s 左:a 右:d ");
}
//初始化游戏
void CArea::Init_Game_DoublePlayer()
{
    //绘制地图并且在数组中存放障碍物信息
    //障碍物信息用来判断是否撞到障碍物
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
            {
                Write_Char(i, j, "□");
            }
            else
            {
                Map[i][j] = EMPTYAREA;
            }
        }

    }
    //创建蛇的图像
    objSnake.Draw_Snake();
    objSnake.Draw_Enemy_Snake();


    //初始化食物
    objFood.Creat_Food();

    //ui信息
    Write_Char(35, 25, "按e存档",15);
    Write_Char(35, 24, "按q暂停",15);
    Write_Char(35, 23, "1p分数:",15);
    Write_Char(35, 22, "2p分数:",15);
    Write_Char(35, 26, "2p操作 上:i 下:k 左:j 右:l");
    Write_Char(35, 27, "1p操作 上:w 下:s 左:a 右:d ");

}
void CArea::Init_Game_Org()
{
    //绘制地图并且在数组中存放障碍物信息
   //障碍物信息用来判断是否撞到障碍物
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
            {
                Map[i][j] = EMPTYAREA;
            }
            else
            {
                Map[i][j] = EMPTYAREA;
            }
        }

    }
    //创建蛇的图像
    objSnake.Draw_Snake();


    //初始化食物
    objFood.Creat_Food();

    //ui信息
    Write_Char(35, 25, "按e存档",15);
    Write_Char(35, 24, "按q暂停",15);
    Write_Char(35, 23, "分数:",15);
    Write_Char(35, 26, "1p操作 上:w 下:s 左:a 右:d ");
}

//读取游戏的再初始化
void CArea::Load_Init_Game()
{
    //地图初始化
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
            {
                Write_Char(i, j, "□");
            }
            else if (Map[i][j] == PLAYER)
            {
                ;
            }
            else if (Map[i][j] == FOOD)
            {
                Write_Char(i, j, "★");
            }
            else if (Map[i][j] == SPEEDDOWNFOOD)
            {
                Write_Char(i, j, "☆");
            }
            else
            {
                Map[i][j] = EMPTYAREA;
            }
        }

    }
    //创建蛇的图像

    objSnake.Draw_Snake();



    //ui信息
    Write_Char(35, 25, "按e存档");
    Write_Char(35, 24, "按q暂停");
    Write_Char(35, 23, "分数:");
    Write_Char(35, 26, "2p操作 上:i 下:k 左:j 右:l");
    Write_Char(35, 27, "1p操作 上:w 下:s 左:a 右:d ");


}

void CArea::Load_Double_Init_Game()
{
    //地图初始化
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
            {
                Write_Char(i, j, "□");
            }
            else if (Map[i][j] == PLAYER)
            {
                ;
            }
            else if (Map[i][j] == ENEMYPLAYER)
            {
                ;
            }
            else if (Map[i][j] == FOOD)
            {
                Write_Char(i, j, "★");
            }
            else if (Map[i][j] == SPEEDDOWNFOOD)
            {
                Write_Char(i, j, "☆");
            }
            else
            {
                Map[i][j] = EMPTYAREA;
            }
        }

    }
    //创建蛇的图像

    objSnake.Draw_Snake();
    objSnake.Draw_Enemy_Snake();



    //ui信息
    Write_Char(35, 25, "按e存档");
    Write_Char(35, 24, "按q暂停");
    Write_Char(35, 23, "1p分数:");
    Write_Char(35, 22, "2p分数:");
    Write_Char(35, 26, "2p操作 上:i 下:k 左:j 右:l");
    Write_Char(35, 27, "1p操作 上:w 下:s 左:a 右:d");





}

//重开游戏
void CArea::Restart_Game()
{
    //让食物的状态再次变为不存在
    objFood.Set_Food_Exist(0);
    //重新创建蛇相关的数据
    objSnake.RbuildSnake();
}
//重开游戏
void CArea::Restart_DoublePlayer_Game()
{
    //让食物的状态再次变为不存在
    objFood.Set_Food_Exist(0);
    //重新创建蛇相关的数据
    objSnake.RbuildSnake();
    objSnake.RbuildEnemySnake();
}



//游戏开始
void CArea::Game_Play()
{


    while (1)
    {
        //显示分数
        Write_Int(76, 23, objSnake.Get_Score());

        //接收存档的输入
        int Select = 0;

        //创建食物
        objFood.Creat_Food();

        //蛇的移动
        objSnake.Move_Snack();

        //如果接收到e则直接存档并且return掉函数
        Select = objSnake.Get_Oper();
        if (Select == 'e')
        {
            Save_Game();
            return;
        }
        
        //如果生命值归0则直接return 
        if (objSnake.Get_Game_Life() == 0)
        {

            return;
        }
        //刷新食物的状况
        if (objSnake.Get_Temp_Count_Food() > objSnake.Get_m_Count_Food())
        {
            objFood.Set_Food_Exist(0);
            objSnake.Set_m_Count_Food(objSnake.Get_Temp_Count_Food());
        }

        //刷新分数
        if (objSnake.Get_Temp_Score() > objSnake.Get_Score())
        {
            objSnake.Set_Score(objSnake.Get_Temp_Score());
            Write_Char(38, 23, "                                    ");
            Write_Int(76, 23, objSnake.Get_Score());
        }
    }



}
//双人游戏开始
void CArea::Game_Play_DoublePlayer()
{


    while (1)
    {
        //显示分数
        Write_Int(76, 23, objSnake.Get_Score(), F_H_GREEN);
        Write_Int(76, 22, objSnake.Get_Enemy_Score(), F_H_GREEN);

        //接收存档的输入
        int Select = 0;

        //创建食物
        objFood.Creat_Food();

        //蛇的移动
        objSnake.Move_Double_Snake();
        //objSnake.Move_Enemy_Snack();

        //如果接收到e则直接存档并且return掉函数
        Select = objSnake.Get_Oper();
        if (Select == 'e')
        {
            Save_Double_Game();
            return;
        }
        
        //如果生命值归0则直接return 
        if (objSnake.Get_Game_Life() == 0)
        {
            Write_Char(10,15,"2p玩家赢");
            Sleep(1500);
            return;
        }
        if (objSnake.Get_Enemy_Game_Life() == 0)
        {
            Write_Char(10, 15, "1p玩家赢");
            Sleep(1500);
            return;
        }
        //刷新食物的状况
        if (objSnake.Get_Temp_Count_Food() > objSnake.Get_m_Count_Food())
        {
            objFood.Set_Food_Exist(0);
            objSnake.Set_m_Count_Food(objSnake.Get_Temp_Count_Food());
        }
        if (objSnake.Get_Enemy_Temp_Count_Food() > objSnake.Get_Enemy_m_Count_Food())
        {
            objFood.Set_Food_Exist(0);
            objSnake.Set_Enemy_m_Count_Food(objSnake.Get_Enemy_Temp_Count_Food());
        }
        //刷新分数
        if (objSnake.Get_Temp_Score() > objSnake.Get_Score())
        {
            objSnake.Set_Score(objSnake.Get_Temp_Score());
            Write_Char(38, 23, "                                    ");
            Write_Int(76, 23, objSnake.Get_Score(), F_H_GREEN);
        }        
        if (objSnake.Get_Enemy_Temp_Score() > objSnake.Get_Enemy_Score())
        {
            objSnake.Set_Enemy_Score(objSnake.Get_Enemy_Temp_Score());
            Write_Char(38, 22, "                                    ");
            Write_Int(76, 22, objSnake.Get_Enemy_Score(), F_H_GREEN);
        }
    }



}

//存档
void CArea::Save_Game()
{
    FILE* pFile = NULL;
    int nError = fopen_s(&pFile, PATH, "wb+");
    if (nError != NULL)
    {
        printf("存储失败!\n");
        system("pause");

        return;
    }
    //1 存储地图信息
    for (int i = 0; i < MAP_ROW; i++)
    {
        for (int j = 0; j < MAP_COL; j++)
        {
            if (pFile != 0)
            {
                fwrite(&Map[i][j], 1, sizeof(int), pFile);
            }
        }
    }

    //存储蛇信息

    //2.1 获取蛇的长度
    Temp_Snake_Lenth = objSnake.Get_Snake_Lenth();
    fwrite(&Temp_Snake_Lenth, 1, sizeof(int), pFile);
    //2.2 将获得的蛇的元素放入临时的结构体中
    for (int i = 0; i < Temp_Snake_Lenth; i++)
    {
        Temp_Ele = objSnake.Get_Snake_Ele(i);


        //2.3 将临时的元素push_back进临时的结构体数组中
        //Temp_Snake.push_back(Temp_Ele);

         //2.4 将获得的临时结构体数组写入文件
          fwrite(&Temp_Ele, 1, sizeof(COORD), pFile);
      
    }



    //3 存储分数
    Temp_Score = objSnake.Get_Score();
    fwrite(&Temp_Score, 1, sizeof(int), pFile);

    //4 存储食物的状况
    Temp_Food_Exist = objFood.Get_Food_Exist();
    fwrite(&Temp_Food_Exist, 1, sizeof(int), pFile);


    //5 存储速度
    Temp_Speed = objSnake.Get_Speed();
    fwrite(&Temp_Speed, 1, sizeof(int), pFile);

    //6 存储蛇的方向
    Temp_Dir = objSnake.Get_Dir();
    fwrite(&Temp_Dir, 1, sizeof(int), pFile);

    //7 存储生命
    Temp_Life = objSnake.Get_Game_Life();
    fwrite(&Temp_Life, 1, sizeof(int), pFile);
    fclose(pFile);

}
//读档
void CArea::Load_Game()
{
    FILE* pFile = NULL;
    int Error = fopen_s(&pFile, PATH, "rb+");
    if (Error != 0)
    {
        return;
    }
    //1 读取地图
    for (int i = 0; i < MAP_ROW; i++)
    {
        for (int j = 0; j < MAP_COL; j++)
        {
            if (pFile != 0)
            {
                fread(&Map[i][j], 1, sizeof(int), pFile);
            }
        }
    }

    //2.1 读取长度
    if (pFile != 0)
    {
        fread(&Temp_Snake_Lenth, 1, sizeof(int), pFile);
    }

    //2.2 读取蛇的身体

  

    objSnake.Dele_Snake_Ele();
    
    for (int i = 0; i < Temp_Snake_Lenth; i++)
    {
        fread(&Temp_Ele, 1, sizeof(COORD), pFile);
        objSnake.Push_Back_Snake(Temp_Ele);
    }



    //3 读取分数
    fread(&Temp_Score, 1, sizeof(int), pFile);
    objSnake.Set_Score(Temp_Score);

    //4 读取食物的状况
    fread(&Temp_Food_Exist, 1, sizeof(int), pFile);
    objFood.Set_Food_Exist(Temp_Food_Exist);

    //5 读取速度
    fread(&Temp_Speed, 1, sizeof(int), pFile);
    objSnake.Set_Speed(Temp_Speed);

    //6 读取蛇的方向
    fread(&Temp_Dir, 1, sizeof(int), pFile);
    objSnake.Set_Dir(Temp_Dir);

    //7 读取生命
    fread(&Temp_Life, 1, sizeof(int), pFile);
    objSnake.Set_Snake_LIfe(Temp_Life);
    fclose(pFile);

}
//存储双人游戏
void CArea::Save_Double_Game()
{
    FILE* pFile = NULL;
    int nError = fopen_s(&pFile, PATHDouble, "wb+");
    if (nError != NULL)
    {
        return;
    }
    //1 存储地图信息
    for (int i = 0; i < MAP_ROW; i++)
    {
        for (int j = 0; j < MAP_COL; j++)
        {
            if (pFile != 0)
            {
                fwrite(&Map[i][j], 1, sizeof(int), pFile);
            }
        }
    }

    //存储蛇信息

    //2.1 获取蛇的长度
    Temp_Snake_Lenth = objSnake.Get_Snake_Lenth();
    fwrite(&Temp_Snake_Lenth, 1, sizeof(int), pFile);
    //2.2 将获得的蛇的元素放入临时的结构体中
    for (int i = 0; i < Temp_Snake_Lenth; i++)
    {
        Temp_Ele = objSnake.Get_Snake_Ele(i);


        //2.3 将临时的元素push_back进临时的结构体数组中
        //Temp_Snake.push_back(Temp_Ele);

         //2.4 将获得的临时结构体数组写入文件
        fwrite(&Temp_Ele, 1, sizeof(COORD), pFile);

    }

    //2.1.1 存储敌方蛇的长度
    Temp_Snake_Lenth = objSnake.Get_Enemy_Snake_Lenth();
    fwrite(&Temp_Snake_Lenth, 1, sizeof(int), pFile);

    //2.2.1 将获得的蛇的元素放入临时的结构体中
    for (int i = 0; i < Temp_Snake_Lenth; i++)
    {
        Temp_Ele = objSnake.Get_Enemy_Snake_Ele(i);


         //2.4.1 将获得的临时结构体数组写入文件
        fwrite(&Temp_Ele, 1, sizeof(COORD), pFile);

    }

    //3 存储分数
    Temp_Score = objSnake.Get_Score();
    fwrite(&Temp_Score, 1, sizeof(int), pFile);  


    //3.1 存储敌方分数
    Temp_Score = objSnake.Get_Enemy_Score();
    fwrite(&Temp_Score, 1, sizeof(int), pFile);

    //4 存储食物的状况
    Temp_Food_Exist = objFood.Get_Food_Exist();
    fwrite(&Temp_Food_Exist, 1, sizeof(int), pFile);


    //5 存储速度
    Temp_Speed = objSnake.Get_Speed();
    fwrite(&Temp_Speed, 1, sizeof(int), pFile);  
    
    //5.1 存储敌方蛇的速度
    Temp_Speed = objSnake.Get_Enemy_Speed();
    fwrite(&Temp_Speed, 1, sizeof(int), pFile);

    //6 存储蛇的方向
    Temp_Dir = objSnake.Get_Dir();
    fwrite(&Temp_Dir, 1, sizeof(int), pFile);    
    
    //6.1 存储敌方蛇的方向
    Temp_Dir = objSnake.Get_Enemy_Dir();
    fwrite(&Temp_Dir, 1, sizeof(int), pFile);

    //7 存储生命
    Temp_Life = objSnake.Get_Game_Life();
    fwrite(&Temp_Life, 1, sizeof(int), pFile);   
    
    //7.1 存储敌方蛇的生命
    Temp_Life = objSnake.Get_Enemy_Game_Life();
    fwrite(&Temp_Life, 1, sizeof(int), pFile);
    fclose(pFile);


}

//读档双人游戏
void CArea::Load_Double_Game()
{
    FILE* pFile = NULL;
    int Error = fopen_s(&pFile, PATHDouble, "rb+");
    if (Error != 0)
    {
        return;
    }
    //1 读取地图
    for (int i = 0; i < MAP_ROW; i++)
    {
        for (int j = 0; j < MAP_COL; j++)
        {
            if (pFile != 0)
            {
                fread(&Map[i][j], 1, sizeof(int), pFile);
            }
        }
    }

    //2.1 读取长度
    if (pFile != 0)
    {
        fread(&Temp_Snake_Lenth, 1, sizeof(int), pFile);
    }

   
    //2.2 读取蛇的身体

    objSnake.Dele_Snake_Ele();

    for (int i = 0; i < Temp_Snake_Lenth; i++)
    {
        fread(&Temp_Ele, 1, sizeof(COORD), pFile);
        objSnake.Push_Back_Snake(Temp_Ele);
    }

    //2.2.1读取敌方蛇的长度
    fread(&Temp_Snake_Lenth, 1, sizeof(int), pFile);

   

    //2.2.2 读取敌方蛇的身体

    objSnake.Dele_Enemy_Snake_Ele();

    for (int i = 0; i < Temp_Snake_Lenth; i++)
    {
        fread(&Temp_Ele, 1, sizeof(COORD), pFile);
        objSnake.Push_Back_Enemy_Snake(Temp_Ele);
    }

    //3 读取分数
    fread(&Temp_Score, 1, sizeof(int), pFile);
    objSnake.Set_Score(Temp_Score);    
    
    //3.1 读取敌方蛇分数
    fread(&Temp_Score, 1, sizeof(int), pFile);
    objSnake.Set_Enemy_Score(Temp_Score);

    //4 读取食物的状况
    fread(&Temp_Food_Exist, 1, sizeof(int), pFile);
    objFood.Set_Food_Exist(Temp_Food_Exist);   

    //5 读取速度
    fread(&Temp_Speed, 1, sizeof(int), pFile);
    objSnake.Set_Speed(Temp_Speed);    
    //5.1 读取敌方速度
    fread(&Temp_Speed, 1, sizeof(int), pFile);
    objSnake.Set_Enemy_Speed(Temp_Speed);

    //6 读取蛇的方向
    fread(&Temp_Dir, 1, sizeof(int), pFile);
    objSnake.Set_Dir(Temp_Dir); 
    //6.1 读取敌方蛇的方向
    fread(&Temp_Dir, 1, sizeof(int), pFile);
    objSnake.Set_Enemy_Dir(Temp_Dir);

    //7 读取生命
    fread(&Temp_Life, 1, sizeof(int), pFile);
    objSnake.Set_Snake_LIfe(Temp_Life);    
    //7.1 读取生命
    fread(&Temp_Life, 1, sizeof(int), pFile);
    objSnake.Set_Enemy_Snake_LIfe(Temp_Life);
    fclose(pFile);

}
