#include "CTank.h"
#include"CMap.h"
#include"CTankTool.h"
#include<windows.h>

CTank::CTank() :
    m_nTank_Mode{
           {{0,1,0},{1,1,1},{1,0,1}},
           {{1,0,1},{1,1,1},{0,1,0}},
           {{0,1,1},{1,1,0},{0,1,1}},
           {{1,1,0},{0,1,1} ,{1,1,0}}
}
{

    //坦克移动的时间差
    m_Tank_Move_Lasttime = clock();
    //坦克射击的时间差
    m_Tank_Shot_Lasttime = clock();
    m_Is_Tank_Player = false;
    m_Robo_Tank_Oper_Lasttime = clock();



}
CTank::CTank(DIR Dir, COORD Tank_Pos, LEVEL Tank_Level, bool Is_Tank_Player) :
    m_nTank_Mode{
                {{0,1,0},{1,1,1},{1,0,1}},
                {{1,0,1},{1,1,1},{0,1,0}},
                {{0,1,1},{1,1,0},{0,1,1}},
                {{1,1,0},{0,1,1} ,{1,1,0}}
}
{
    //坦克对象的方向
    m_Dir = Dir;
    //坦克对象中心的位置
    m_Tank_Pos = Tank_Pos;
    //坦克移动速度
    m_Tank_Move_Speed = CTankTool::Tank_Move_Speed[Tank_Level];
    //坦克后坐力
    m_Tank_Rocil = CTankTool::Tank_Rocil[Tank_Level];
    //坦克的生命
    m_Tank_Life = Tank_Level;
    //坦克的等级
    m_Tank_Level = Tank_Level;
    //坦克移动的时间差
    m_Tank_Move_Lasttime = clock();
    //坦克射击的时间差
    m_Tank_Shot_Lasttime = clock();
    m_Is_Tank_Player = Is_Tank_Player;
}
//检查前面是不是东西挡住，仅判断坦克头前面的三个点
//返回值为真代表前面没有东西（空地），返回值为假则代表有东西
bool CTank::Check_AHead()
{
    if (m_Dir == UP)
    {
        return (
            CMap::Is_Something_Here(m_Tank_Pos.X - 2, m_Tank_Pos.Y - 1, EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X - 2, m_Tank_Pos.Y, EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X - 2, m_Tank_Pos.Y + 1, EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X - 2, m_Tank_Pos.Y - 1, S_EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X - 2, m_Tank_Pos.Y, S_EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X - 2, m_Tank_Pos.Y + 1, S_EMPTY)) ||
            (
                CMap::Is_Something_Here(m_Tank_Pos.X - 2, m_Tank_Pos.Y - 1, S_GRASS) ||
                CMap::Is_Something_Here(m_Tank_Pos.X - 2, m_Tank_Pos.Y, S_GRASS) ||
                CMap::Is_Something_Here(m_Tank_Pos.X - 2, m_Tank_Pos.Y + 1, S_GRASS)); //||
            //(
            //    CMap::Is_Something_Here(m_Tank_Pos.X - 2, m_Tank_Pos.Y - 1, BULLET) ||
            //    CMap::Is_Something_Here(m_Tank_Pos.X - 2, m_Tank_Pos.Y, BULLET) ||
            //    CMap::Is_Something_Here(m_Tank_Pos.X - 2, m_Tank_Pos.Y + 1, BULLET));
    }



    else if (m_Dir == DOWN)
    {
        return (
            CMap::Is_Something_Here(m_Tank_Pos.X + 2, m_Tank_Pos.Y - 1, EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X + 2, m_Tank_Pos.Y, EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X + 2, m_Tank_Pos.Y + 1, EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X + 2, m_Tank_Pos.Y - 1, S_EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X + 2, m_Tank_Pos.Y, S_EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X + 2, m_Tank_Pos.Y + 1, S_EMPTY)) ||
            (
                CMap::Is_Something_Here(m_Tank_Pos.X + 2, m_Tank_Pos.Y - 1, S_GRASS) ||
                CMap::Is_Something_Here(m_Tank_Pos.X + 2, m_Tank_Pos.Y, S_GRASS) ||
                CMap::Is_Something_Here(m_Tank_Pos.X + 2, m_Tank_Pos.Y + 1, S_GRASS));
           // (
                //CMap::Is_Something_Here(m_Tank_Pos.X + 2, m_Tank_Pos.Y - 1, BULLET) ||
                //CMap::Is_Something_Here(m_Tank_Pos.X + 2, m_Tank_Pos.Y, BULLET) ||
                //CMap::Is_Something_Here(m_Tank_Pos.X + 2, m_Tank_Pos.Y + 1, BULLET));


    }
    else if (m_Dir == LEFT)
    {
        return (
            CMap::Is_Something_Here(m_Tank_Pos.X - 1, m_Tank_Pos.Y - 2, EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X, m_Tank_Pos.Y - 2, EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X + 1, m_Tank_Pos.Y - 2, EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X - 1, m_Tank_Pos.Y - 2, S_EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X, m_Tank_Pos.Y - 2, S_EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X + 1, m_Tank_Pos.Y - 2, S_EMPTY)) ||
            (
                CMap::Is_Something_Here(m_Tank_Pos.X - 1, m_Tank_Pos.Y - 2, S_GRASS) ||
                CMap::Is_Something_Here(m_Tank_Pos.X, m_Tank_Pos.Y - 2, S_GRASS) ||
                CMap::Is_Something_Here(m_Tank_Pos.X + 1, m_Tank_Pos.Y - 2, S_GRASS)); //||
           // (
                //CMap::Is_Something_Here(m_Tank_Pos.X - 1, m_Tank_Pos.Y - 2, BULLET) ||
                //CMap::Is_Something_Here(m_Tank_Pos.X, m_Tank_Pos.Y - 2, BULLET) ||
                //CMap::Is_Something_Here(m_Tank_Pos.X + 1, m_Tank_Pos.Y - 2, BULLET));

    }
    else
    {
        return (
            CMap::Is_Something_Here(m_Tank_Pos.X - 1, m_Tank_Pos.Y + 2, EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X, m_Tank_Pos.Y + 2, EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X + 1, m_Tank_Pos.Y + 2, EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X - 1, m_Tank_Pos.Y + 2, S_EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X, m_Tank_Pos.Y + 2, S_EMPTY) &&
            CMap::Is_Something_Here(m_Tank_Pos.X + 1, m_Tank_Pos.Y + 2, S_EMPTY)) ||
            (
                CMap::Is_Something_Here(m_Tank_Pos.X - 1, m_Tank_Pos.Y + 2, S_GRASS) ||
                CMap::Is_Something_Here(m_Tank_Pos.X, m_Tank_Pos.Y + 2, S_GRASS) ||
                CMap::Is_Something_Here(m_Tank_Pos.X + 1, m_Tank_Pos.Y + 2, S_GRASS)); //||
            //(
            //    CMap::Is_Something_Here(m_Tank_Pos.X - 1, m_Tank_Pos.Y + 2, BULLET) ||
            //    CMap::Is_Something_Here(m_Tank_Pos.X, m_Tank_Pos.Y + 2, BULLET) ||
            //    CMap::Is_Something_Here(m_Tank_Pos.X + 1, m_Tank_Pos.Y + 2, BULLET));
    }
}
//绘制坦克
void CTank::Draw_Tank(_In_ bool IsShow)
{

    switch (m_Dir)
    {
    case UP:
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (1 == m_nTank_Mode[UP][i][j])
                {
                    int Temp_Tank_Pos_X = m_Tank_Pos.X + i - 1;
                    int Temp_Tank_Pos_Y = m_Tank_Pos.Y + j - 1;
                    Draw_Tank_In_Class(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, IsShow);
                }
            }
        }
        break;
    case DOWN:
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (1 == m_nTank_Mode[DOWN][i][j])
                {
                    int Temp_Tank_Pos_X = m_Tank_Pos.X + i - 1;
                    int Temp_Tank_Pos_Y = m_Tank_Pos.Y + j - 1;
                    Draw_Tank_In_Class(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, IsShow);
                }
            }
        }
        break;
    case LEFT:
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (1 == m_nTank_Mode[LEFT][i][j])
                {
                    int Temp_Tank_Pos_X = m_Tank_Pos.X + i - 1;
                    int Temp_Tank_Pos_Y = m_Tank_Pos.Y + j - 1;
                    Draw_Tank_In_Class(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, IsShow);
                }
            }
        }
        break;
    case RIGHT:
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (1 == m_nTank_Mode[RIGHT][i][j])
                {
                    int Temp_Tank_Pos_X = m_Tank_Pos.X + i - 1;
                    int Temp_Tank_Pos_Y = m_Tank_Pos.Y + j - 1;
                    Draw_Tank_In_Class(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, IsShow);
                }
            }
        }
        break;
    }


}

//移动坦克
void CTank::Move_Tank(_In_ DIR Dir)
{
    if (clock() - m_Tank_Move_Lasttime > m_Tank_Move_Speed)
    {
        //擦除坦克
        Draw_Tank(false);
        //如果方向不一样则只进行转向
        if (Dir != m_Dir)
        {
            m_Dir = Dir;
        }
        //如果方向一样，则进行移动
        else
        {
            if (Check_AHead())
            {
                switch (m_Dir)
                {
                case UP:
                    m_Tank_Pos.X--;
                    break;
                case DOWN:
                    m_Tank_Pos.X++;
                    break;
                case LEFT:
                    m_Tank_Pos.Y--;
                    break;
                case RIGHT:
                    m_Tank_Pos.Y++;
                    break;
                }
            }
        }
        //绘制坦克
        Draw_Tank();
        m_Tank_Move_Lasttime = clock();
    }
}


void CTank::Draw_Robo_Tank(_In_ bool IsShow)
{
    switch (m_Dir)
    {
    case UP:
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (1 == m_nTank_Mode[UP][i][j])
                {
                    int Temp_Tank_Pos_X = m_Tank_Pos.X + i - 1;
                    int Temp_Tank_Pos_Y = m_Tank_Pos.Y + j - 1;
                    Draw_Robo_Tank_In_Class(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, IsShow);
                }
            }
        }
        break;
    case DOWN:
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (1 == m_nTank_Mode[DOWN][i][j])
                {
                    int Temp_Tank_Pos_X = m_Tank_Pos.X + i - 1;
                    int Temp_Tank_Pos_Y = m_Tank_Pos.Y + j - 1;
                    Draw_Robo_Tank_In_Class(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, IsShow);
                }
            }
        }
        break;
    case LEFT:
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (1 == m_nTank_Mode[LEFT][i][j])
                {
                    int Temp_Tank_Pos_X = m_Tank_Pos.X + i - 1;
                    int Temp_Tank_Pos_Y = m_Tank_Pos.Y + j - 1;
                    Draw_Robo_Tank_In_Class(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, IsShow);
                }
            }
        }
        break;
    case RIGHT:
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (1 == m_nTank_Mode[RIGHT][i][j])
                {
                    int Temp_Tank_Pos_X = m_Tank_Pos.X + i - 1;
                    int Temp_Tank_Pos_Y = m_Tank_Pos.Y + j - 1;
                    Draw_Robo_Tank_In_Class(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, IsShow);
                }
            }
        }
        break;
    }
}

void CTank::Move_Robo_Tank(_In_ DIR Dir)
{
    if (clock() - m_Tank_Move_Lasttime > m_Tank_Move_Speed)
    {
        //擦除坦克
        Draw_Robo_Tank(false);
        //如果方向不一样则只进行转向

        if (Dir != m_Dir && Dir!=Last_Dir)
        {

            m_Dir = Dir;
        }
        //如果方向一样，则进行移动
        else if(Dir ==Last_Dir ||Dir ==m_Dir)
        {
            if (Check_AHead())
            {
                switch (m_Dir)
                {
                case UP:
                    m_Tank_Pos.X--;
                    break;
                case DOWN:
                    m_Tank_Pos.X++;
                    break;
                case LEFT:
                    m_Tank_Pos.Y--;
                    break;
                case RIGHT:
                    m_Tank_Pos.Y++;
                    break;
                }
            }
        }
        //绘制坦克
        Draw_Robo_Tank();
        m_Tank_Move_Lasttime = clock();
    }
}

//在发射子弹时产生子弹坐标
COORD CTank::Tank_Shot_Bullet()
{
    switch (m_Dir)
    {
    case UP:
        return { short(m_Tank_Pos.X - 2),m_Tank_Pos.Y };
    case DOWN:
        return  { short(m_Tank_Pos.X + 2),m_Tank_Pos.Y };
    case LEFT:
        return { m_Tank_Pos.X,short(m_Tank_Pos.Y - 2) };
    case RIGHT:
        return{ m_Tank_Pos.X,short(m_Tank_Pos.Y + 2) };

    }


}
//获得坦克的方向
DIR CTank::Get_Tank_Dir()
{
    return m_Dir;
}

//确认是否能够射出子弹
bool CTank::Is_Tank_Can_Shot()
{
    if (clock() - m_Tank_Shot_Lasttime > m_Tank_Rocil)
    {
        m_Tank_Shot_Lasttime = clock();
        return true;
    }
    else
    {
        return false;
    }
}

void CTank::Creat_Robo_Tank(_Out_ std::vector<CTank>& Robo_Tank)
{
    //如果当前坦克数量大于或等于坦克数量最大值，则不再生成
    if (CTankTool::Robo_Tank_Count >= CTankTool::Robo_Tank_Max_Count)
    {
        return;
    }
    m_Tank_Level = (LEVEL)(rand() % 3 + 1);
    m_Dir = (DIR)(rand() % 4);
    m_Tank_Life = m_Tank_Level;
    m_Tank_Rocil = CTankTool::Tank_Rocil[m_Tank_Level];
    m_Tank_Move_Speed = CTankTool::Tank_Move_Speed[m_Tank_Level];
    m_Robo_Tank_Oper_Time = m_Tank_Level * 1000;


    while (1)
    {
        short X = rand() % 37 + 1;
        short Y = rand() % 37 + 1;
        if (CMap::Is_Something_Here(X, Y, EMPTY) && CMap::Is_Something_Here(X - 1, Y, EMPTY) &&
            CMap::Is_Something_Here(X + 1, Y, EMPTY) && CMap::Is_Something_Here(X, Y - 1, EMPTY) &&
            CMap::Is_Something_Here(X, Y + 1, EMPTY) && CMap::Is_Something_Here(X - 1, Y - 1, EMPTY) &&
            CMap::Is_Something_Here(X - 1, Y + 1, EMPTY) && CMap::Is_Something_Here(X + 1, Y - 1, EMPTY) &&
            CMap::Is_Something_Here(X + 1, Y + 1, EMPTY) &&
            CMap::Is_Something_Here(X, Y, S_EMPTY) && CMap::Is_Something_Here(X - 1, Y, S_EMPTY) &&
            CMap::Is_Something_Here(X + 1, Y, S_EMPTY) && CMap::Is_Something_Here(X, Y - 1, S_EMPTY) &&
            CMap::Is_Something_Here(X, Y + 1, S_EMPTY) && CMap::Is_Something_Here(X - 1, Y - 1, S_EMPTY) &&
            CMap::Is_Something_Here(X - 1, Y + 1, S_EMPTY) && CMap::Is_Something_Here(X + 1, Y - 1, S_EMPTY) &&
            CMap::Is_Something_Here(X + 1, Y + 1, S_EMPTY))
        {
            m_Tank_Pos.X = X;
            m_Tank_Pos.Y = Y;
            CTankTool::Robo_Tank_Count++;
            break;
        }
    }

    Robo_Tank.push_back(*this);
}


//获取坦克的等级（给子弹用）
LEVEL CTank::Get_Tank_Level()
{
    return m_Tank_Level;
}

bool CTank::Get_Is_Tank_Player()
{
    return m_Is_Tank_Player;
}
COORD CTank::Get_Tank_Pos()
{
    return m_Tank_Pos;
}

void CTank::Tank_Get_Dmg()
{
    m_Tank_Life--;
    PlaySoundA(HIT_SOUND, NULL, SND_ASYNC | SND_NODEFAULT);
}
//LEVEL CTank::Get_Tank_Level(CTank& This_Tank)
//{
//    return This_Tank.m_Tank_Level;
//}

void CTank::Draw_Tank_In_Class(_In_ int Temp_Tank_Pos_X, _In_ int Temp_Tank_Pos_Y, _In_ bool IsShow)
{
    //如果为真则绘制坦克，为假擦除坦克
    if (!CMap::Is_Something_Here(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, S_GRASS))
    {
        IsShow ? CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, CMap::Get_Str(PLAYER), CTankTool::Tank_Color[m_Tank_Level])
            : CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, CMap::Get_Str(PLAYER));
        //如果为真则将坦克信息写入地图，为假将地图信息编辑为空地
        IsShow ? CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, PLAYER) : CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, EMPTY);
    }
    else
    {
        //在草地中的坦克显示的是在草地中的颜色
        IsShow ? CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, CMap::Get_Str(PLAYER), CTankTool::Tank_In_Grass) :
            CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, CMap::Get_Str(PLAYER), CMap::SColor[S_GRASS]);

        IsShow ? CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, PLAYER) : CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, EMPTY);
    }
}

void CTank::Draw_Robo_Tank_In_Class(_In_ int Temp_Tank_Pos_X, _In_ int Temp_Tank_Pos_Y, _In_ bool IsShow)
{
    //如果为真则绘制坦克，为假擦除坦克
    if (!CMap::Is_Something_Here(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, S_GRASS))
    {
        IsShow ? CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, CMap::Get_Str(ROBO), CTankTool::Tank_Color[m_Tank_Level])
            : CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, CMap::Get_Str(ROBO));
        //如果为真则将坦克信息写入地图，为假将地图信息编辑为空地
        IsShow ? CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, ROBO) : CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, EMPTY);
    }
    else
    {
        //在草地中的坦克显示的是在草地中的颜色
        IsShow ? CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, CMap::Get_S_Str(S_GRASS), CTankTool::Tank_In_Grass) :
            CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, CMap::Get_S_Str(S_GRASS), CMap::SColor[S_GRASS]);

        IsShow ? CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, ROBO) : CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, EMPTY);
    }
}


int CTank::Get_Tank_Life()
{
    return m_Tank_Life;
}

void CTank::Reset_Player(_In_ COORD Reset_Pos)
{

    //位置
    m_Tank_Pos = Reset_Pos;
    //生命
    m_Tank_Life = m_Tank_Level;
    Draw_Tank();



}

unsigned short CTank::Get_Robo_Tank_Oper_Time()
{
    return m_Robo_Tank_Oper_Time;
}

bool CTank::Is_Robo_Tank_Can_Shot()
{

    if (clock() - m_Robo_Tank_Oper_Lasttime > m_Robo_Tank_Oper_Time)
    {
        m_Robo_Tank_Oper_Lasttime = clock();
        return true;
    }
    else
    {
        return false;
    }
}
void CTank::Set_Tank_Lasttime()
{
    //坦克移动时间差
    m_Tank_Move_Lasttime = clock();
    //坦克射击的时间差
    m_Tank_Shot_Lasttime = clock();

}

void CTank::Set_Robo_Lasttime()
{
    //坦克移动的时间差
    m_Tank_Move_Lasttime = clock();
    //坦克射击的时间差
    m_Tank_Shot_Lasttime = clock();
    //地方坦克操作的时间差
    m_Robo_Tank_Oper_Lasttime = clock();
}

//void CTank::Robo_Tank_Get_Path(_In_ CTank& Player1)
//{
//    //将起点放入oepn表
//    PNODE pNode = new NODE;
//    pNode->pFather = nullptr;
//    pNode->pos = m_Tank_Pos;
//    pNode->G = 0;
//    pNode->H = abs(pNode->pos.X - Player1.Get_Tank_Pos().X) + abs(pNode->pos.Y - Player1.Get_Tank_Pos().Y);
//    pNode->F = pNode->G + pNode->H;
//    //当待探测点表Open不为空，则应该在其中获取其预估损耗
//    while (m_Open.size() != 0)
//    {
//        //找open表中F最小的点
//        int MinF = m_Open[m_Open.size() - 1]->F;
//    }
//
//
//
//}