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

    //̹���ƶ���ʱ���
    m_Tank_Move_Lasttime = clock();
    //̹�������ʱ���
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
    //̹�˶���ķ���
    m_Dir = Dir;
    //̹�˶������ĵ�λ��
    m_Tank_Pos = Tank_Pos;
    //̹���ƶ��ٶ�
    m_Tank_Move_Speed = CTankTool::Tank_Move_Speed[Tank_Level];
    //̹�˺�����
    m_Tank_Rocil = CTankTool::Tank_Rocil[Tank_Level];
    //̹�˵�����
    m_Tank_Life = Tank_Level;
    //̹�˵ĵȼ�
    m_Tank_Level = Tank_Level;
    //̹���ƶ���ʱ���
    m_Tank_Move_Lasttime = clock();
    //̹�������ʱ���
    m_Tank_Shot_Lasttime = clock();
    m_Is_Tank_Player = Is_Tank_Player;
}
//���ǰ���ǲ��Ƕ�����ס�����ж�̹��ͷǰ���������
//����ֵΪ�����ǰ��û�ж������յأ�������ֵΪ��������ж���
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
//����̹��
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

//�ƶ�̹��
void CTank::Move_Tank(_In_ DIR Dir)
{
    if (clock() - m_Tank_Move_Lasttime > m_Tank_Move_Speed)
    {
        //����̹��
        Draw_Tank(false);
        //�������һ����ֻ����ת��
        if (Dir != m_Dir)
        {
            m_Dir = Dir;
        }
        //�������һ����������ƶ�
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
        //����̹��
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
        //����̹��
        Draw_Robo_Tank(false);
        //�������һ����ֻ����ת��

        if (Dir != m_Dir && Dir!=Last_Dir)
        {

            m_Dir = Dir;
        }
        //�������һ����������ƶ�
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
        //����̹��
        Draw_Robo_Tank();
        m_Tank_Move_Lasttime = clock();
    }
}

//�ڷ����ӵ�ʱ�����ӵ�����
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
//���̹�˵ķ���
DIR CTank::Get_Tank_Dir()
{
    return m_Dir;
}

//ȷ���Ƿ��ܹ�����ӵ�
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
    //�����ǰ̹���������ڻ����̹���������ֵ����������
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


//��ȡ̹�˵ĵȼ������ӵ��ã�
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
    //���Ϊ�������̹�ˣ�Ϊ�ٲ���̹��
    if (!CMap::Is_Something_Here(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, S_GRASS))
    {
        IsShow ? CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, CMap::Get_Str(PLAYER), CTankTool::Tank_Color[m_Tank_Level])
            : CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, CMap::Get_Str(PLAYER));
        //���Ϊ����̹����Ϣд���ͼ��Ϊ�ٽ���ͼ��Ϣ�༭Ϊ�յ�
        IsShow ? CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, PLAYER) : CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, EMPTY);
    }
    else
    {
        //�ڲݵ��е�̹����ʾ�����ڲݵ��е���ɫ
        IsShow ? CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, CMap::Get_Str(PLAYER), CTankTool::Tank_In_Grass) :
            CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, CMap::Get_Str(PLAYER), CMap::SColor[S_GRASS]);

        IsShow ? CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, PLAYER) : CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, EMPTY);
    }
}

void CTank::Draw_Robo_Tank_In_Class(_In_ int Temp_Tank_Pos_X, _In_ int Temp_Tank_Pos_Y, _In_ bool IsShow)
{
    //���Ϊ�������̹�ˣ�Ϊ�ٲ���̹��
    if (!CMap::Is_Something_Here(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, S_GRASS))
    {
        IsShow ? CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, CMap::Get_Str(ROBO), CTankTool::Tank_Color[m_Tank_Level])
            : CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, CMap::Get_Str(ROBO));
        //���Ϊ����̹����Ϣд���ͼ��Ϊ�ٽ���ͼ��Ϣ�༭Ϊ�յ�
        IsShow ? CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, ROBO) : CMap::Write(Temp_Tank_Pos_X, Temp_Tank_Pos_Y, EMPTY);
    }
    else
    {
        //�ڲݵ��е�̹����ʾ�����ڲݵ��е���ɫ
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

    //λ��
    m_Tank_Pos = Reset_Pos;
    //����
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
    //̹���ƶ�ʱ���
    m_Tank_Move_Lasttime = clock();
    //̹�������ʱ���
    m_Tank_Shot_Lasttime = clock();

}

void CTank::Set_Robo_Lasttime()
{
    //̹���ƶ���ʱ���
    m_Tank_Move_Lasttime = clock();
    //̹�������ʱ���
    m_Tank_Shot_Lasttime = clock();
    //�ط�̹�˲�����ʱ���
    m_Robo_Tank_Oper_Lasttime = clock();
}

//void CTank::Robo_Tank_Get_Path(_In_ CTank& Player1)
//{
//    //��������oepn��
//    PNODE pNode = new NODE;
//    pNode->pFather = nullptr;
//    pNode->pos = m_Tank_Pos;
//    pNode->G = 0;
//    pNode->H = abs(pNode->pos.X - Player1.Get_Tank_Pos().X) + abs(pNode->pos.Y - Player1.Get_Tank_Pos().Y);
//    pNode->F = pNode->G + pNode->H;
//    //����̽����Open��Ϊ�գ���Ӧ�������л�ȡ��Ԥ�����
//    while (m_Open.size() != 0)
//    {
//        //��open����F��С�ĵ�
//        int MinF = m_Open[m_Open.size() - 1]->F;
//    }
//
//
//
//}