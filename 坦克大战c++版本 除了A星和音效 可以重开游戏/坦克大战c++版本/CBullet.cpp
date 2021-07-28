#include "CBullet.h"
#include"CGame.h"
#include"CTankTool.h"

CBullet::CBullet() :
    Bullet_Hit_Bullet(false),
    m_Bullet_Speed(150)
{
    m_Bullet_Move_Lasttime = clock();

}
//�����ӵ�����
void CBullet::Set_Bullet_Dir(_In_ DIR Dir)
{
    m_Bullet_Dir = Dir;
}
void CBullet::Set_Bullet_Pos(_In_ COORD Bullet_Pos)
{
    m_Bullet_Pos = Bullet_Pos;
}
//�����ӵ�
void CBullet::Creat_Bullet(_In_ DIR Dir, _In_ COORD Bullet_Pos,_Out_ std::vector<CBullet>& Bullet)
{

    //��ʼ������ķ���
    Set_Bullet_Dir(Dir);
    //��ʼ�������λ��
    Set_Bullet_Pos(Bullet_Pos);
    //����������������
    if (!CMap::Is_Something_Here(Bullet_Pos.X, Bullet_Pos.Y, OBSTACLES))
    {
        Bullet.push_back(*this);
        Draw_Bullet(true);
    }

}

//��ͬ�ӵ��ȼ���ͬ������
void CBullet::Bullet_Power(_Out_ std::vector<CBullet>& Bullet)
{
    //���ӵ��ȼ�Ϊ2ʱ�����������ӵ�
    if (m_Bullet_Level == 2)
    {
        switch (m_Bullet_Dir)
        {
        case UP:
        {
            short Temp_Bullet_Pos_Y = m_Bullet_Pos.Y - 1;
            short Temp_Bullet_Pos_X = m_Bullet_Pos.X;
            Creat_Bullet(m_Bullet_Dir, { Temp_Bullet_Pos_X,Temp_Bullet_Pos_Y },Bullet);
        }
        break;
        case DOWN:
        {
            short Temp_Bullet_Pos_Y = m_Bullet_Pos.Y + 1;
            short Temp_Bullet_Pos_X = m_Bullet_Pos.X;
            Creat_Bullet(m_Bullet_Dir, { Temp_Bullet_Pos_X,Temp_Bullet_Pos_Y }, Bullet);
        }
        break;
        case LEFT:
        {
            short Temp_Bullet_Pos_Y = m_Bullet_Pos.Y;
            short Temp_Bullet_Pos_X = m_Bullet_Pos.X - 1;
            Creat_Bullet(m_Bullet_Dir, { Temp_Bullet_Pos_X,Temp_Bullet_Pos_Y }, Bullet);
        }
        break;
        case RIGHT:
        {
            short Temp_Bullet_Pos_Y = m_Bullet_Pos.Y;
            short Temp_Bullet_Pos_X = m_Bullet_Pos.X + 1;
            Creat_Bullet(m_Bullet_Dir, { Temp_Bullet_Pos_X,Temp_Bullet_Pos_Y }, Bullet);
        }
        break;
        }
    }
    //���ӵ��ȼ�Ϊ3ʱ��������3���ӵ�
    else if (m_Bullet_Level == 3)
    {
        switch (m_Bullet_Dir)
        {
        case UP:
        {
            short Temp_Bullet_Pos_Y = m_Bullet_Pos.Y - 1;
            short Temp_Bullet_Pos_X = m_Bullet_Pos.X;
            Creat_Bullet(m_Bullet_Dir, { Temp_Bullet_Pos_X,Temp_Bullet_Pos_Y }, Bullet);
            Temp_Bullet_Pos_Y = m_Bullet_Pos.Y + 2;
            Temp_Bullet_Pos_X = m_Bullet_Pos.X;
            Creat_Bullet(m_Bullet_Dir, { Temp_Bullet_Pos_X,Temp_Bullet_Pos_Y }, Bullet);
        }
        break;
        case DOWN:
        {
            short Temp_Bullet_Pos_Y = m_Bullet_Pos.Y - 1;
            short Temp_Bullet_Pos_X = m_Bullet_Pos.X;
            Creat_Bullet(m_Bullet_Dir, { Temp_Bullet_Pos_X,Temp_Bullet_Pos_Y }, Bullet);
            Temp_Bullet_Pos_Y = m_Bullet_Pos.Y + 2;
            Temp_Bullet_Pos_X = m_Bullet_Pos.X;
            Creat_Bullet(m_Bullet_Dir, { Temp_Bullet_Pos_X,Temp_Bullet_Pos_Y }, Bullet);
        }
        break;
        case LEFT:
        {
            short Temp_Bullet_Pos_Y = m_Bullet_Pos.Y;
            short Temp_Bullet_Pos_X = m_Bullet_Pos.X - 1;
            Creat_Bullet(m_Bullet_Dir, { Temp_Bullet_Pos_X,Temp_Bullet_Pos_Y }, Bullet);
            Temp_Bullet_Pos_Y = m_Bullet_Pos.Y;
            Temp_Bullet_Pos_X = m_Bullet_Pos.X + 2;
            Creat_Bullet(m_Bullet_Dir, { Temp_Bullet_Pos_X,Temp_Bullet_Pos_Y }, Bullet);
        }
        break;

        case RIGHT:
        {
            short Temp_Bullet_Pos_Y = m_Bullet_Pos.Y;
            short Temp_Bullet_Pos_X = m_Bullet_Pos.X - 1;
            Creat_Bullet(m_Bullet_Dir, { Temp_Bullet_Pos_X,Temp_Bullet_Pos_Y }, Bullet);
            Temp_Bullet_Pos_Y = m_Bullet_Pos.Y;
            Temp_Bullet_Pos_X = m_Bullet_Pos.X + 2;
            Creat_Bullet(m_Bullet_Dir, { Temp_Bullet_Pos_X,Temp_Bullet_Pos_Y }, Bullet);
        }
        break;
        }
    }

}
//���ӵ�
//�����������������ӵ�
//����Ǽ�������ӵ�
void CBullet::Draw_Bullet(_In_ bool IsShow)
{
    //���ӵ�
    if (IsShow)
    {
        Draw_Bullet_In_Class();
    }
    //�����ӵ�
    else
    {
        Remove_Bullet_In_Class();
    }


}

//ȷ��ײ����ʲô
int  CBullet::Check_Bullet_Hit(_Out_ vector<CBullet>& objBullet, _Out_ vector<CTank>& objRobo, _In_ CTank& Player1, _In_ CTank& Player2)
{
    //���ײ�����ϰ��������
    if (CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, OBSTACLES))
    {
        return OBSTACLES;
    }
    //���ûײ���ϰ����򷵻ؼ�
    else if (CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, EMPTY))
    {
        return EMPTY;
    }
    //���ײ��һ��ǽ�������ǽ��ɿյ�
    else if (CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, WALL_I))
    {
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, CMap::Get_Str(EMPTY));
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, EMPTY);
        return WALL_I;
    }
    //���ײ�϶���ǽ�������ǽ���һ��ǽ
    else if (CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, WALL_II))
    {
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, CMap::Get_Str(WALL_I), CMap::OColor[WALL_I]);
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, WALL_I);
        return WALL_II;
    }
    //���ײ������ǽ�������ǽ��ɶ���ǽ
    else if (CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, WALL_III))
    {
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, CMap::Get_Str(WALL_II), CMap::OColor[WALL_II]);
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, WALL_II);
        return WALL_III;
    }
    //���ײ�����ӵ�����������
    else if (CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, BULLET))
    {
        //Bullet_Hit_Bullet = true;
        auto it = objBullet.begin();
        while (it != objBullet.end())
        {
            if (it->m_Bullet_Pos.X == m_Bullet_Pos.X && it->m_Bullet_Pos.Y == m_Bullet_Pos.Y)
            {
                it->m_Bullet_Life = false;
                //break;
            }
            it++;
        }

        return BULLET;
    }
    //�������ҵ��ӵ��������
    else if (CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, PLAYER) && m_Is_Bullet_Player == true)
    {
        return OBSTACLES;
    }
    //�������ҵ��ӵ����˵���
    else if (CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, ROBO) && m_Is_Bullet_Player == true)
    {
        Search_For_Robo(objRobo);
        return OBSTACLES;
    }
    //����ǵ��˵��ӵ����˵���
    else if (CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, ROBO) && m_Is_Bullet_Player == false)
    {
        return OBSTACLES;
    }
    //����ǵ��˵��ӵ������
    else if (CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, PLAYER) && m_Is_Bullet_Player == false)
    {
        Search_For_Player(Player1,Player2);
        return OBSTACLES;
    }

}

//�ƶ��ӵ�
void CBullet::Move_Bullet(_Out_ vector<CBullet>& objBullet, _Out_ vector<CTank>& objRobo, _In_ CTank& Player1, _In_ CTank& Player2)
{
    if (clock() - m_Bullet_Move_Lasttime > CTankTool::Bullet_Move_Speed[m_Bullet_Level])
    {
        m_Bullet_Life = false;
        Draw_Bullet(false);
        switch (m_Bullet_Dir)
        {
        case UP:
            m_Bullet_Pos.X--;
            break;
        case DOWN:
            m_Bullet_Pos.X++;
            break;
        case LEFT:
            m_Bullet_Pos.Y--;
            break;
        case RIGHT:
            m_Bullet_Pos.Y++;
            break;
        }
        m_Bullet_Life = !(Check_Bullet_Hit(objBullet,objRobo, Player1,Player2));
        if (m_Bullet_Life)
        {
            Draw_Bullet(true);
        }
        else
        {
            return;
        }
        m_Bullet_Move_Lasttime = clock();
    }
}
//�����ӵ��Ƿ���Ч
bool CBullet::Get_Bullet_Life()
{
    return m_Bullet_Life;
}

//���õȼ�
void CBullet::Set_Bullet_Level(_In_ LEVEL Tank_Level)
{
    m_Bullet_Level = Tank_Level;
}

//COORD CBullet::Get_Bullet_Pos()
//{
//    return m_Bullet_Pos;
//}

//void CBullet::Bullet_Power_Hit(THING thing)
//{
//    
//}

//�����ӵ��ĵȼ�
LEVEL CBullet::Get_Bullet_Level()
{
    return m_Bullet_Level;
}
//�����ӵ���λ��
COORD CBullet::Get_Bullet_Pos()
{
    return m_Bullet_Pos;
}
//�����ӵ����Ѿ����ǵо��ı�ʶ��
void CBullet::Set_Is_Bullet_Player(bool Is_Tank_Player)
{
    m_Is_Bullet_Player = Is_Tank_Player;
}

//��������
void CBullet::Search_For_Robo(_Out_ vector<CTank>& objRobo)
{
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            auto Begin = objRobo.begin();
            while (Begin != objRobo.end())
            {
                if (m_Bullet_Pos.X+i == Begin->Get_Tank_Pos().X && m_Bullet_Pos.Y+j == Begin->Get_Tank_Pos().Y)
                {
                    Begin->Tank_Get_Dmg();
                    break;
                }
                else
                {
                    Begin++;
                }
            }
        }
    }
}
//�������
void CBullet::Search_For_Player(_In_ CTank& Player1, _In_ CTank& Player2)
{
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (m_Bullet_Pos.X + i == Player1.Get_Tank_Pos().X && m_Bullet_Pos.Y + j == Player1.Get_Tank_Pos().Y)
            {
                Player1.Tank_Get_Dmg();
                return;
            }
            else if (m_Bullet_Pos.X + i == Player2.Get_Tank_Pos().X && m_Bullet_Pos.Y + j == Player2.Get_Tank_Pos().Y)
            {
                Player2.Tank_Get_Dmg();
                return;
            }
        }
    }
}
void CBullet::Draw_Bullet_In_Class()
{
    if (!(CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, S_GRASS) || CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, S_RIVER)))
    {
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, CMap::Get_Str(BULLET), CTankTool::Bullet_Color[m_Bullet_Level]);
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, BULLET);
    }
    else if (CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, S_GRASS))
    {
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, CMap::Get_S_Str(S_GRASS), CTankTool::Bullet_In_Grass);
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, BULLET);
    }
    else if (CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, S_RIVER))
    {
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, CMap::Get_Str(BULLET), CTankTool::Bullet_Color[m_Bullet_Level]);
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, BULLET);
    }
}
void CBullet::Remove_Bullet_In_Class()
{
    if (!(CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, S_GRASS) || CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, S_RIVER)))
    {
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, CMap::Get_Str(BULLET));
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, EMPTY);
    }
    else if (CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, S_GRASS))
    {
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, CMap::Get_S_Str(S_GRASS), CMap::SColor[S_GRASS]);
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, EMPTY);
    }
    else if (CMap::Is_Something_Here(m_Bullet_Pos.X, m_Bullet_Pos.Y, S_RIVER))
    {
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, CMap::Get_S_Str(S_RIVER), CMap::SColor[S_RIVER]);
        CMap::Write(m_Bullet_Pos.X, m_Bullet_Pos.Y, EMPTY);
    }
}

void CBullet::Set_Bullet_Move_Lasttime()
{
    m_Bullet_Move_Lasttime = clock();
}