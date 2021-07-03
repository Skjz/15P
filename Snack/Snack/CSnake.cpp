#include "CSnake.h"
#include"DrawBase.h"
#include"CArea.h"
#include<time.h>

//初始化蛇的坐标和信息

CSnake::CSnake() :
    //Player1初始化
    m_Snake_Dir(RIGHT), m_Move_Speed(200), m_Count_Food(0), m_Get_Score(0),
    m_Temp_Count_Food(0), m_Get_Temp_Score(0), m_Game_Life(1),
    //player2初始化
    m_Enemy_Snake_Dir(RIGHT), m_Enemy_Move_Speed(200), m_Enemy_Count_Food(0), m_Enemy_Get_Score(0),
    m_Enemy_Temp_Count_Food(0), m_Enemy_Get_Temp_Score(0), m_Enemy_Game_Life(1)
{
    m_Move_Lasttime = clock();
    m_Enemy_Move_Lasttime = clock();
    //COORD temp = { 10,3 };
    //for ( temp; temp.Y < 7; temp.Y++)
    //{
    //    m_Snake.push_back(temp);
    //}
    //for (unsigned int i = 0; i < m_Snake.size(); i++)
    //{

    //    //设定蛇的身体是PLAYER
    //    Map[m_Snake[i].X][m_Snake[i].Y] = PLAYER;
    //}

}

//初始化蛇
void CSnake::RbuildSnake()
{
    //将所有数据初始化
    m_Snake_Dir = RIGHT;
    m_Move_Speed = 200;
    m_Count_Food = 0;
    m_Get_Score = 0;

    m_Temp_Count_Food = 0;
    m_Get_Temp_Score = 0;
    m_Game_Life = 1;
    //如果容器尺寸不为0，则直接将容器清空
    if (m_Snake.size() != 0)
    {
        m_Snake.clear();
    }
    //生成蛇的身体元素
    COORD temp = { 10,3 };
    for (temp; temp.Y < 7; temp.Y++)
    {
        m_Snake.push_back(temp);
    }
    for (unsigned int i = 0; i < m_Snake.size(); i++)
    {
        //设定蛇的身体是PLAYER
        Map[m_Snake[i].X][m_Snake[i].Y] = PLAYER;
    }

}

//初始化敌方蛇
void CSnake::RbuildEnemySnake()
{
    //将所有数据初始化
    m_Enemy_Snake_Dir = RIGHT;
    m_Enemy_Move_Speed = 200;
    m_Enemy_Count_Food = 0;
    m_Enemy_Get_Score = 0;

    m_Enemy_Temp_Count_Food = 0;
    m_Enemy_Get_Temp_Score = 0;
    m_Enemy_Game_Life = 1;
    //如果容器尺寸不为0，则直接将容器清空
    if (m_Enemy_Snake.size() != 0)
    {
        m_Enemy_Snake.clear();
    }
    //生成蛇的身体元素
    COORD temp = { 5,20 };
    for (temp; temp.Y < 24; temp.Y++)
    {
        m_Enemy_Snake.push_back(temp);
    }
    for (unsigned int i = 0; i < m_Enemy_Snake.size(); i++)
    {

        //设定蛇的身体是ENEMYPLAYErPLAYER
        Map[m_Enemy_Snake[i].X][m_Enemy_Snake[i].Y] = ENEMYPLAYER;
    }


}
//获取蛇的方向
int CSnake::Get_Oper()
{
    return Oper;
}
int CSnake::Get_Enemy_Oper()
{
    return Enemy_Oper;
}

//显示蛇
void CSnake::Draw_Snake()
{
    for (unsigned int i = 0; i < m_Snake.size(); i++)
    {
        Write_Char(m_Snake[i].X, m_Snake[i].Y, "■");
        Map[m_Snake[i].X][m_Snake[i].Y] = PLAYER;
    }
}

//显示敌方蛇
void CSnake::Draw_Enemy_Snake()
{
    for (unsigned int i = 0; i < m_Enemy_Snake.size(); i++)
    {
        Write_Char(m_Enemy_Snake[i].X, m_Enemy_Snake[i].Y, "■", F_H_GREEN);
        Map[m_Enemy_Snake[i].X][m_Enemy_Snake[i].Y] = ENEMYPLAYER;
    }
}

//将蛇移除
void CSnake::Remove_Snake()
{
    for (unsigned int i = 0; i < m_Snake.size(); i++)
    {
        Write_Char(m_Snake[i].X, m_Snake[i].Y, "  ");
    }
}

//将敌方蛇移除
void CSnake::Remove_Enemy_Snake()
{
    for (unsigned int i = 0; i < m_Enemy_Snake.size(); i++)
    {
        Write_Char(m_Enemy_Snake[i].X, m_Enemy_Snake[i].Y, "  ");
    }
}


//移动蛇
void CSnake::Move_Snack()
{




    //用来接收操作的变量
    Oper = 0;

    //存放蛇头坐标
    COORD Temp = { m_Snake[0].X,m_Snake[0].Y };
    Oper = WaitKey();
    //如果输入e，则保存
    if (Oper == 101)
    {
        Get_Oper();
        return;
    }
    //如果输入q，则暂停
    if (Oper == 'q')
    {
        system("pause");
        Write_Char(38, 23, "                                    ");
        Write_Int(76, 23, Get_Score());
    }
    //防止蛇能180度转弯，进行输入的操作检查
    if ((m_Snake_Dir == UP && Oper == 's') || (m_Snake_Dir == DOWN && Oper == 'w'))
    {
        Oper = 0;
    }
    else if ((m_Snake_Dir == LEFT && Oper == 'd') || (m_Snake_Dir == RIGHT && Oper == 'a'))
    {
        Oper = 0;

    }



    //改变蛇的方向
    switch (Oper)
    {
    case 'w':
        m_Snake_Dir = UP;
        break;
    case 'a':
        m_Snake_Dir = LEFT;
        break;
    case 's':
        m_Snake_Dir = DOWN;
        break;
    case'd':
        m_Snake_Dir = RIGHT;
        break;
    default:
        break;
    }

    //消除蛇

    if (clock() - m_Move_Lasttime > m_Move_Speed)
    {
        Remove_Snake();


        //改变蛇头的坐标
        switch (m_Snake_Dir)
        {
        case UP:
            Temp.Y--;
            break;
        case LEFT:
            Temp.X--;
            break;
        case DOWN:
            Temp.Y++;
            break;
        case RIGHT:
            Temp.X++;
            break;
        }

        //坐标移动后，蛇可能遇到的情况
        // 1.撞到自己
        if (Map[Temp.X][Temp.Y] == PLAYER)
        {
            m_Game_Life = 0;
            m_Snake.clear();
            return;
        }

        // 2.撞到食物
        else if (Map[Temp.X][Temp.Y] == FOOD)
        {

            //计数吃到的食物
            m_Temp_Count_Food = m_Count_Food + 1;

            //加分
            m_Get_Temp_Score = m_Get_Score + 100;

            //蛇变长
            m_Snake.insert(m_Snake.begin(), Temp);

            //显示蛇
            Draw_Snake();

            //加速
            if (m_Move_Speed != 0)
            {
                m_Move_Speed -= 10;
            }

            //将食物的地图信息编辑为空地
            Map[Temp.X][Temp.Y] = EMPTYAREA;
            return;
        }
        //2.1减速食物
        else if (Map[Temp.X][Temp.Y] == SPEEDDOWNFOOD)
        {
            //计数吃到的食物
            m_Temp_Count_Food = m_Count_Food + 1;

            //加分
            m_Get_Temp_Score = m_Get_Score + 100;

            //蛇变长
            m_Snake.insert(m_Snake.begin(), Temp);

             Draw_Snake();

            //减速
            if (m_Move_Speed < 200)
            {
                m_Move_Speed += 10;
            }

            //将食物的地图信息编辑为空地
            Map[Temp.X][Temp.Y] = EMPTYAREA;
            return;
        }

        // 3.撞到障碍物
        else if (Map[Temp.X][Temp.Y] == OBSTACLES)
        {
            m_Game_Life = 0;
            m_Snake.clear();
            return;
        }

        // 4.撞到空地:无事发生

        //5.撞到敌方蛇
        else if (Map[Temp.X][Temp.Y] == ENEMYPLAYER)
        {
            m_Enemy_Game_Life = 0;
            m_Enemy_Snake.clear();


            return;
        }
        //在蛇头处插入新坐标
        m_Snake.insert(m_Snake.begin(), Temp);

        //将蛇尾去掉
        Map[m_Snake.back().X][m_Snake.back().Y] = EMPTYAREA;
        m_Snake.erase(m_Snake.end() - 1);

        //画出蛇
        Draw_Snake();
        m_Move_Lasttime = clock();
    }
}



//移动敌方蛇
void CSnake::Move_Enemy_Snack()
{


    //用来接收操作的变量
    //Enemy_Oper = 0;

    //存放蛇头坐标
    COORD TempEnemy = { m_Enemy_Snake[0].X,m_Enemy_Snake[0].Y };
    //Enemy_Oper = WaitKey();
    ////如果输入e，则保存
    //if (Oper == 101)
    //{
    //    Get_Oper();
    //    return;
    //}
    ////如果输入q，则暂停
    //if (Oper == 'q')
    //{
    //    system("pause");
    //    Write_Char(38, 23, "                                    ");
    //    Write_Int(76, 23, Get_Score());
    //}
    //防止蛇能180度转弯，进行输入的操作检查
    if ((m_Enemy_Snake_Dir == UP && Oper == 'k') || (m_Enemy_Snake_Dir == DOWN && Oper == 'i'))
    {
        Oper = 0;
    }
    else if ((m_Enemy_Snake_Dir == LEFT && Oper == 'j') || (m_Enemy_Snake_Dir == RIGHT && Oper == 'l'))
    {
        Oper = 0;
    }

    //改变蛇的方向
 /*   switch (Enemy_Oper)
    {
    case 'i':
        m_Enemy_Snake_Dir = UP;
        break;
    case 'j':
        m_Enemy_Snake_Dir = LEFT;
        break;
    case 'k':
        m_Enemy_Snake_Dir = DOWN;
        break;
    case 'l':
        m_Enemy_Snake_Dir = RIGHT;
        break;
    default:
        break;
    }*/
    if (clock() - m_Enemy_Move_Lasttime > m_Enemy_Move_Speed)
    {
        //消除蛇
        Remove_Enemy_Snake();


        //改变蛇头的坐标
        switch (m_Enemy_Snake_Dir)
        {
        case UP:
            TempEnemy.Y--;
            break;
        case LEFT:
            TempEnemy.X--;
            break;
        case DOWN:
            TempEnemy.Y++;
            break;
        case RIGHT:
            TempEnemy.X++;
            break;
        }

        //坐标移动后，蛇可能遇到的情况
        // 1.撞到自己
        if (Map[TempEnemy.X][TempEnemy.Y] == ENEMYPLAYER)
        {
            m_Game_Life = 0;
            m_Enemy_Snake.clear();
            //可能需要一个其他变量来判断
            Write_Char(7, 15, "1号玩家赢");
            Sleep(1500);
            return;
        }

        // 2.撞到食物
        else if (Map[TempEnemy.X][TempEnemy.Y] == FOOD)
        {

            //计数吃到的食物
            m_Enemy_Temp_Count_Food = m_Enemy_Count_Food + 1;

            //加分
            m_Enemy_Get_Temp_Score = m_Enemy_Get_Score + 100;

            //蛇变长
            m_Enemy_Snake.insert(m_Enemy_Snake.begin(), TempEnemy);

            Draw_Enemy_Snake();


            //加速
            if (m_Enemy_Move_Speed != 0)
            {
                m_Enemy_Move_Speed -= 10;
            }

            //将食物的地图信息编辑为空地
            Map[TempEnemy.X][TempEnemy.Y] = EMPTYAREA;
            return;
        }
        //2.1减速食物
        else if (Map[TempEnemy.X][TempEnemy.Y] == SPEEDDOWNFOOD)
        {
            //计数吃到的食物
            m_Enemy_Temp_Count_Food = m_Enemy_Count_Food + 1;

            //加分
            m_Enemy_Get_Temp_Score = m_Enemy_Get_Score + 100;

            //蛇变长
            m_Enemy_Snake.insert(m_Enemy_Snake.begin(), TempEnemy);

            //画蛇
            Draw_Enemy_Snake();


            //减速
            if (m_Enemy_Move_Speed < 200)
            {
                m_Enemy_Move_Speed += 10;
            }

            //将食物的地图信息编辑为空地
            Map[TempEnemy.X][TempEnemy.Y] = EMPTYAREA;
            return;
        }

        // 3.撞到障碍物
        else if (Map[TempEnemy.X][TempEnemy.Y] == OBSTACLES)
        {
            m_Enemy_Game_Life = 0;
            m_Enemy_Snake.clear();
            return;
        }

        // 4.撞到空地:无事发生

        //5.撞到1号玩家
        else if (Map[TempEnemy.X][TempEnemy.Y] == PLAYER)
        {
            m_Game_Life = 0;
        }
        //在蛇头处插入新坐标
        m_Enemy_Snake.insert(m_Enemy_Snake.begin(), TempEnemy);


        //将蛇尾去掉
        Map[m_Enemy_Snake.back().X][m_Enemy_Snake.back().Y] = EMPTYAREA;
        m_Enemy_Snake.erase(m_Enemy_Snake.end() - 1);

        //画出蛇

        Draw_Enemy_Snake();
        m_Enemy_Move_Lasttime = clock();
    }

}

void CSnake::Move_Double_Snake()
{

    //用来接收操作的变量
    Oper = 0;

    //存放蛇头坐标
    COORD Temp = { m_Snake[0].X,m_Snake[0].Y };
    COORD TempEnemy = { m_Enemy_Snake[0].X,m_Enemy_Snake[0].Y };
    Oper = WaitKey();
    //如果输入e，则保存
    if (Oper == 101)
    {
        Get_Oper();
        return;
    }
    //如果输入q，则暂停
    if (Oper == 'q')
    {
        _getch();
    }
    //防止蛇能180度转弯，进行输入的操作检查
    if ((m_Snake_Dir == UP && Oper == 's') || (m_Snake_Dir == DOWN && Oper == 'w'))
    {
        Oper = 0;
    }
    else if ((m_Snake_Dir == LEFT && Oper == 'd') || (m_Snake_Dir == RIGHT && Oper == 'a'))
    {
        Oper = 0;

    }

    if ((m_Enemy_Snake_Dir == UP && Oper == 'k') || (m_Enemy_Snake_Dir == DOWN && Oper == 'i'))
    {
        Oper = 0;
    }
    else if ((m_Enemy_Snake_Dir == LEFT && Oper == 'l') || (m_Enemy_Snake_Dir == RIGHT && Oper == 'j'))
    {
        Oper = 0;
    }

    //改变蛇的方向
    Change_Snake_Dir();
    Change_Enemy_Snake_Dir();

    //移动敌方蛇
    Move_Enemy_Snake_Head(TempEnemy);

    if (clock() - m_Move_Lasttime > m_Move_Speed)
    {
        //消除蛇
        Remove_Snake();


        //改变蛇头的坐标
        switch (m_Snake_Dir)
        {
        case UP:
            Temp.Y--;
            break;
        case LEFT:
            Temp.X--;
            break;
        case DOWN:
            Temp.Y++;
            break;
        case RIGHT:
            Temp.X++;
            break;
        }

        //坐标移动后，蛇可能遇到的情况
        // 1.撞到自己
        if (Map[Temp.X][Temp.Y] == PLAYER)
        {
            m_Game_Life = 0;
            m_Snake.clear();
            return;
        }

        // 2.撞到食物
        else if (Map[Temp.X][Temp.Y] == FOOD)
        {

            //计数吃到的食物
            m_Temp_Count_Food = m_Count_Food + 1;

            //加分
            m_Get_Temp_Score = m_Get_Score + 100;

            //蛇变长
            m_Snake.insert(m_Snake.begin(), Temp);

            //显示蛇
            Draw_Snake();

            //加速
            if (m_Move_Speed != 0)
            {
                m_Move_Speed -= 10;
            }

            //将食物的地图信息编辑为空地
            Map[Temp.X][Temp.Y] = EMPTYAREA;
            return;
        }
        //2.1减速食物
        else if (Map[Temp.X][Temp.Y] == SPEEDDOWNFOOD)
        {
            //计数吃到的食物
            m_Temp_Count_Food = m_Count_Food + 1;

            //加分
            m_Get_Temp_Score = m_Get_Score + 100;

            //蛇变长
            m_Snake.insert(m_Snake.begin(), Temp);

            //显示蛇
            Draw_Snake();

            //减速
            if (m_Move_Speed < 200)
            {
                m_Move_Speed += 10;
            }

            //将食物的地图信息编辑为空地
  /*          Map[Temp.X][Temp.Y] = EMPTYAREA;*/
            return;
        }

        // 3.撞到障碍物
        else if (Map[Temp.X][Temp.Y] == OBSTACLES)
        {
            m_Game_Life = 0;
            m_Snake.clear();
            return;
        }

        // 4.撞到空地:无事发生

        //5.撞到敌方蛇
        else if (Map[Temp.X][Temp.Y] == ENEMYPLAYER)
        {
            m_Enemy_Game_Life = 0;
            m_Enemy_Snake.clear();

            //1号玩家赢
            return;
        }
        //在蛇头处插入新坐标
        m_Snake.insert(m_Snake.begin(), Temp);

        //将蛇尾去掉
        Map[m_Snake.back().X][m_Snake.back().Y] = EMPTYAREA;
        m_Snake.erase(m_Snake.end() - 1);

        //画出蛇
        Draw_Snake();
        m_Move_Lasttime = clock();
    }
}

//得到吃到食物数量的临时值
int CSnake::Get_Temp_Count_Food()
{
    return m_Temp_Count_Food;
}

//得到敌方吃到食物数量的临时值
int CSnake::Get_Enemy_Temp_Count_Food()
{
    return m_Enemy_Temp_Count_Food;
}

//得到吃到食物数量的值
int CSnake::Get_m_Count_Food()
{
    return m_Count_Food;
}

//得到敌方吃到食物数量的值
int CSnake::Get_Enemy_m_Count_Food()
{
    return m_Enemy_Count_Food;
}

//设置吃到食物的数量的值
void CSnake::Set_m_Count_Food(int Temp_Count_Food)
{
    m_Count_Food = Temp_Count_Food;
}
//设置敌方吃到食物的数量的值
void CSnake::Set_Enemy_m_Count_Food(int Temp_Enemy_Count_Food)
{
    m_Enemy_Count_Food = Temp_Enemy_Count_Food;
}


//得到分数的临时值
int CSnake::Get_Temp_Score()
{
    return m_Get_Temp_Score;
}

//得到敌方分数的临时值
int CSnake::Get_Enemy_Temp_Score()
{
    return m_Enemy_Get_Temp_Score;
}

//得到分数的值
int CSnake::Get_Score()
{
    return m_Get_Score;
}

int CSnake::Get_Enemy_Score()
{
    return m_Enemy_Get_Score;
}

//设置分数的值
void CSnake::Set_Enemy_Score(int Temp_Enemy_Score)
{
    m_Enemy_Get_Score = Temp_Enemy_Score;
}
void CSnake::Set_Score(int Temp_Score)
{
    m_Get_Score = Temp_Score;
}

//获取蛇的长度
int CSnake::Get_Snake_Lenth()
{
    return m_Snake.size();
}
//获取敌方蛇的长度
int CSnake::Get_Enemy_Snake_Lenth()
{
    return m_Enemy_Snake.size();
}


//获取蛇的元素
COORD CSnake::Get_Snake_Ele(int nLoc)
{
    Temp_Snake_Ele.X = m_Snake[nLoc].X;
    Temp_Snake_Ele.Y = m_Snake[nLoc].Y;
    return Temp_Snake_Ele;

}
//获取敌方蛇的元素
COORD CSnake::Get_Enemy_Snake_Ele(int nLoc)
{
    Temp_Enemy_Snake_Ele.X = m_Enemy_Snake[nLoc].X;
    Temp_Enemy_Snake_Ele.Y = m_Enemy_Snake[nLoc].Y;
    return Temp_Enemy_Snake_Ele;

}
//将元素放入容器
void CSnake::Push_Back_Snake(COORD Temp_Snake)
{

    m_Snake.push_back(Temp_Snake);
}
//将敌方元素放入容器
void CSnake::Push_Back_Enemy_Snake(COORD Temp_Snake)
{

    m_Enemy_Snake.push_back(Temp_Snake);
}

//获得蛇的速度
int CSnake::Get_Speed()
{
    return  m_Move_Speed;
}
//获得敌方蛇的速度
int CSnake::Get_Enemy_Speed()
{
    return  m_Enemy_Move_Speed;
}

//设置蛇的速度
void CSnake::Set_Speed(int nSpeed)
{
    m_Move_Speed = nSpeed;
}
//设置敌方蛇的速度
void CSnake::Set_Enemy_Speed(int nEnemy_Speed)
{
    m_Enemy_Move_Speed = nEnemy_Speed;
}

//获得蛇的方向
int CSnake::Get_Dir()
{
    return m_Snake_Dir;
}

//获得敌方蛇的方向
int CSnake::Get_Enemy_Dir()
{
    return m_Enemy_Snake_Dir;
}

//设置蛇的方向
void CSnake::Set_Dir(int nDir)
{
    m_Snake_Dir = nDir;
}
//设置敌方蛇的方向
void CSnake::Set_Enemy_Dir(int nEnemy_Dir)
{
    m_Enemy_Snake_Dir = nEnemy_Dir;
}

//未关闭游戏时候生成蛇的图像
void CSnake::Draw_No_Player_Snake()
{
    for (unsigned int i = 0; i < m_Snake.size(); i++)
    {
        Write_Char(m_Snake[i].X, m_Snake[i].Y, "■");
        Map[m_Snake[i].X][m_Snake[i].Y] = EMPTYAREA;
    }
}
//void CSnake::ClearVector()
//{
//    if (m_Snake.size() > 0)
//    {
//        m_Snake.clear();
//    }
//}

//删除蛇的元素
void CSnake::Dele_Snake_Ele()
{
    m_Snake.clear();
}

//删除敌方蛇的元素
void CSnake::Dele_Enemy_Snake_Ele()
{
    m_Enemy_Snake.clear();
}

//设置蛇的生命
void CSnake::Set_Snake_LIfe(int Temp_Life)
{
    m_Game_Life = Temp_Life;

}
//设置敌方蛇的生命
void CSnake::Set_Enemy_Snake_LIfe(int Temp_Enemy_Life)
{
    m_Enemy_Game_Life = Temp_Enemy_Life;

}

//获得蛇的生命
int CSnake::Get_Game_Life()
{
    return m_Game_Life;
}

//获得对方蛇的生命
int CSnake::Get_Enemy_Game_Life()
{
    return m_Enemy_Game_Life;
}

//改变敌方蛇的方向
void CSnake::Change_Snake_Dir()
{
    switch (Oper)
    {
    case 'w':
        m_Snake_Dir = UP;
        break;
    case 'a':
        m_Snake_Dir = LEFT;
        break;
    case 's':
        m_Snake_Dir = DOWN;
        break;
    case 'd':
        m_Snake_Dir = RIGHT;
        break;
    default:
        break;
    }

}

//改变对方的蛇的方向
void CSnake::Change_Enemy_Snake_Dir()
{
    switch (Oper)
    {
    case 'i':
        m_Enemy_Snake_Dir = UP;
        break;
    case 'j':
        m_Enemy_Snake_Dir = LEFT;
        break;
    case 'k':
        m_Enemy_Snake_Dir = DOWN;
        break;
    case 'l':
        m_Enemy_Snake_Dir = RIGHT;
        break;
    default:
        break;
    }
}
//移动敌方的蛇
void CSnake::Move_Enemy_Snake_Head(COORD TempEnemy)
{
    if (clock() - m_Enemy_Move_Lasttime > m_Enemy_Move_Speed)
    {
        //消除蛇
        Remove_Enemy_Snake();


        //改变蛇头的坐标
        switch (m_Enemy_Snake_Dir)
        {
        case UP:
            TempEnemy.Y--;
            break;
        case LEFT:
            TempEnemy.X--;
            break;
        case DOWN:
            TempEnemy.Y++;
            break;
        case RIGHT:
            TempEnemy.X++;
            break;
        }

        //坐标移动后，蛇可能遇到的情况
        // 1.撞到自己
        if (Map[TempEnemy.X][TempEnemy.Y] == ENEMYPLAYER)
        {
            m_Game_Life = 0;
            m_Enemy_Snake.clear();
            //可能需要一个其他变量来判断
            Write_Char(7, 15, "1号玩家赢");
            Sleep(1500);
            return;
        }

        // 2.撞到食物
        else if (Map[TempEnemy.X][TempEnemy.Y] == FOOD)
        {

            //计数吃到的食物
            m_Enemy_Temp_Count_Food = m_Enemy_Count_Food + 1;

            //加分
            m_Enemy_Get_Temp_Score = m_Enemy_Get_Score + 100;

            //蛇变长
            m_Enemy_Snake.insert(m_Enemy_Snake.begin(), TempEnemy);

            Draw_Enemy_Snake();


            //加速
            if (m_Enemy_Move_Speed != 0)
            {
                m_Enemy_Move_Speed -= 10;
            }

            //将食物的地图信息编辑为空地
      /*      Map[TempEnemy.X][TempEnemy.Y] = EMPTYAREA;*/
            return;
        }
        //2.1减速食物
        else if (Map[TempEnemy.X][TempEnemy.Y] == SPEEDDOWNFOOD)
        {
            //计数吃到的食物
            m_Enemy_Temp_Count_Food = m_Enemy_Count_Food + 1;

            //加分
            m_Enemy_Get_Temp_Score = m_Enemy_Get_Score + 100;

            //蛇变长
            m_Enemy_Snake.insert(m_Enemy_Snake.begin(), TempEnemy);

            //画蛇
            Draw_Enemy_Snake();


            //减速
            if (m_Enemy_Move_Speed < 200)
            {
                m_Enemy_Move_Speed += 10;
            }

            //将食物的地图信息编辑为空地
      /*      Map[TempEnemy.X][TempEnemy.Y] = EMPTYAREA;*/
            return;
        }

        // 3.撞到障碍物
        else if (Map[TempEnemy.X][TempEnemy.Y] == OBSTACLES)
        {
            m_Enemy_Game_Life = 0;
            m_Enemy_Snake.clear();
            return;
        }

        // 4.撞到空地:无事发生

        //5.撞到1号玩家
        else if (Map[TempEnemy.X][TempEnemy.Y] == PLAYER)
        {
            m_Game_Life = 0;
        }
        //在蛇头处插入新坐标
        m_Enemy_Snake.insert(m_Enemy_Snake.begin(), TempEnemy);


        //将蛇尾去掉
        Map[m_Enemy_Snake.back().X][m_Enemy_Snake.back().Y] = EMPTYAREA;
        m_Enemy_Snake.erase(m_Enemy_Snake.end() - 1);

        //画出蛇

        Draw_Enemy_Snake();
        m_Enemy_Move_Lasttime = clock();
    }
}