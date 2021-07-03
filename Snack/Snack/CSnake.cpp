#include "CSnake.h"
#include"DrawBase.h"
#include"CArea.h"
#include<time.h>

//��ʼ���ߵ��������Ϣ

CSnake::CSnake() :
    //Player1��ʼ��
    m_Snake_Dir(RIGHT), m_Move_Speed(200), m_Count_Food(0), m_Get_Score(0),
    m_Temp_Count_Food(0), m_Get_Temp_Score(0), m_Game_Life(1),
    //player2��ʼ��
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

    //    //�趨�ߵ�������PLAYER
    //    Map[m_Snake[i].X][m_Snake[i].Y] = PLAYER;
    //}

}

//��ʼ����
void CSnake::RbuildSnake()
{
    //���������ݳ�ʼ��
    m_Snake_Dir = RIGHT;
    m_Move_Speed = 200;
    m_Count_Food = 0;
    m_Get_Score = 0;

    m_Temp_Count_Food = 0;
    m_Get_Temp_Score = 0;
    m_Game_Life = 1;
    //��������ߴ粻Ϊ0����ֱ�ӽ��������
    if (m_Snake.size() != 0)
    {
        m_Snake.clear();
    }
    //�����ߵ�����Ԫ��
    COORD temp = { 10,3 };
    for (temp; temp.Y < 7; temp.Y++)
    {
        m_Snake.push_back(temp);
    }
    for (unsigned int i = 0; i < m_Snake.size(); i++)
    {
        //�趨�ߵ�������PLAYER
        Map[m_Snake[i].X][m_Snake[i].Y] = PLAYER;
    }

}

//��ʼ���з���
void CSnake::RbuildEnemySnake()
{
    //���������ݳ�ʼ��
    m_Enemy_Snake_Dir = RIGHT;
    m_Enemy_Move_Speed = 200;
    m_Enemy_Count_Food = 0;
    m_Enemy_Get_Score = 0;

    m_Enemy_Temp_Count_Food = 0;
    m_Enemy_Get_Temp_Score = 0;
    m_Enemy_Game_Life = 1;
    //��������ߴ粻Ϊ0����ֱ�ӽ��������
    if (m_Enemy_Snake.size() != 0)
    {
        m_Enemy_Snake.clear();
    }
    //�����ߵ�����Ԫ��
    COORD temp = { 5,20 };
    for (temp; temp.Y < 24; temp.Y++)
    {
        m_Enemy_Snake.push_back(temp);
    }
    for (unsigned int i = 0; i < m_Enemy_Snake.size(); i++)
    {

        //�趨�ߵ�������ENEMYPLAYErPLAYER
        Map[m_Enemy_Snake[i].X][m_Enemy_Snake[i].Y] = ENEMYPLAYER;
    }


}
//��ȡ�ߵķ���
int CSnake::Get_Oper()
{
    return Oper;
}
int CSnake::Get_Enemy_Oper()
{
    return Enemy_Oper;
}

//��ʾ��
void CSnake::Draw_Snake()
{
    for (unsigned int i = 0; i < m_Snake.size(); i++)
    {
        Write_Char(m_Snake[i].X, m_Snake[i].Y, "��");
        Map[m_Snake[i].X][m_Snake[i].Y] = PLAYER;
    }
}

//��ʾ�з���
void CSnake::Draw_Enemy_Snake()
{
    for (unsigned int i = 0; i < m_Enemy_Snake.size(); i++)
    {
        Write_Char(m_Enemy_Snake[i].X, m_Enemy_Snake[i].Y, "��", F_H_GREEN);
        Map[m_Enemy_Snake[i].X][m_Enemy_Snake[i].Y] = ENEMYPLAYER;
    }
}

//�����Ƴ�
void CSnake::Remove_Snake()
{
    for (unsigned int i = 0; i < m_Snake.size(); i++)
    {
        Write_Char(m_Snake[i].X, m_Snake[i].Y, "  ");
    }
}

//���з����Ƴ�
void CSnake::Remove_Enemy_Snake()
{
    for (unsigned int i = 0; i < m_Enemy_Snake.size(); i++)
    {
        Write_Char(m_Enemy_Snake[i].X, m_Enemy_Snake[i].Y, "  ");
    }
}


//�ƶ���
void CSnake::Move_Snack()
{




    //�������ղ����ı���
    Oper = 0;

    //�����ͷ����
    COORD Temp = { m_Snake[0].X,m_Snake[0].Y };
    Oper = WaitKey();
    //�������e���򱣴�
    if (Oper == 101)
    {
        Get_Oper();
        return;
    }
    //�������q������ͣ
    if (Oper == 'q')
    {
        system("pause");
        Write_Char(38, 23, "                                    ");
        Write_Int(76, 23, Get_Score());
    }
    //��ֹ����180��ת�䣬��������Ĳ������
    if ((m_Snake_Dir == UP && Oper == 's') || (m_Snake_Dir == DOWN && Oper == 'w'))
    {
        Oper = 0;
    }
    else if ((m_Snake_Dir == LEFT && Oper == 'd') || (m_Snake_Dir == RIGHT && Oper == 'a'))
    {
        Oper = 0;

    }



    //�ı��ߵķ���
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

    //������

    if (clock() - m_Move_Lasttime > m_Move_Speed)
    {
        Remove_Snake();


        //�ı���ͷ������
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

        //�����ƶ����߿������������
        // 1.ײ���Լ�
        if (Map[Temp.X][Temp.Y] == PLAYER)
        {
            m_Game_Life = 0;
            m_Snake.clear();
            return;
        }

        // 2.ײ��ʳ��
        else if (Map[Temp.X][Temp.Y] == FOOD)
        {

            //�����Ե���ʳ��
            m_Temp_Count_Food = m_Count_Food + 1;

            //�ӷ�
            m_Get_Temp_Score = m_Get_Score + 100;

            //�߱䳤
            m_Snake.insert(m_Snake.begin(), Temp);

            //��ʾ��
            Draw_Snake();

            //����
            if (m_Move_Speed != 0)
            {
                m_Move_Speed -= 10;
            }

            //��ʳ��ĵ�ͼ��Ϣ�༭Ϊ�յ�
            Map[Temp.X][Temp.Y] = EMPTYAREA;
            return;
        }
        //2.1����ʳ��
        else if (Map[Temp.X][Temp.Y] == SPEEDDOWNFOOD)
        {
            //�����Ե���ʳ��
            m_Temp_Count_Food = m_Count_Food + 1;

            //�ӷ�
            m_Get_Temp_Score = m_Get_Score + 100;

            //�߱䳤
            m_Snake.insert(m_Snake.begin(), Temp);

             Draw_Snake();

            //����
            if (m_Move_Speed < 200)
            {
                m_Move_Speed += 10;
            }

            //��ʳ��ĵ�ͼ��Ϣ�༭Ϊ�յ�
            Map[Temp.X][Temp.Y] = EMPTYAREA;
            return;
        }

        // 3.ײ���ϰ���
        else if (Map[Temp.X][Temp.Y] == OBSTACLES)
        {
            m_Game_Life = 0;
            m_Snake.clear();
            return;
        }

        // 4.ײ���յ�:���·���

        //5.ײ���з���
        else if (Map[Temp.X][Temp.Y] == ENEMYPLAYER)
        {
            m_Enemy_Game_Life = 0;
            m_Enemy_Snake.clear();


            return;
        }
        //����ͷ������������
        m_Snake.insert(m_Snake.begin(), Temp);

        //����βȥ��
        Map[m_Snake.back().X][m_Snake.back().Y] = EMPTYAREA;
        m_Snake.erase(m_Snake.end() - 1);

        //������
        Draw_Snake();
        m_Move_Lasttime = clock();
    }
}



//�ƶ��з���
void CSnake::Move_Enemy_Snack()
{


    //�������ղ����ı���
    //Enemy_Oper = 0;

    //�����ͷ����
    COORD TempEnemy = { m_Enemy_Snake[0].X,m_Enemy_Snake[0].Y };
    //Enemy_Oper = WaitKey();
    ////�������e���򱣴�
    //if (Oper == 101)
    //{
    //    Get_Oper();
    //    return;
    //}
    ////�������q������ͣ
    //if (Oper == 'q')
    //{
    //    system("pause");
    //    Write_Char(38, 23, "                                    ");
    //    Write_Int(76, 23, Get_Score());
    //}
    //��ֹ����180��ת�䣬��������Ĳ������
    if ((m_Enemy_Snake_Dir == UP && Oper == 'k') || (m_Enemy_Snake_Dir == DOWN && Oper == 'i'))
    {
        Oper = 0;
    }
    else if ((m_Enemy_Snake_Dir == LEFT && Oper == 'j') || (m_Enemy_Snake_Dir == RIGHT && Oper == 'l'))
    {
        Oper = 0;
    }

    //�ı��ߵķ���
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
        //������
        Remove_Enemy_Snake();


        //�ı���ͷ������
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

        //�����ƶ����߿������������
        // 1.ײ���Լ�
        if (Map[TempEnemy.X][TempEnemy.Y] == ENEMYPLAYER)
        {
            m_Game_Life = 0;
            m_Enemy_Snake.clear();
            //������Ҫһ�������������ж�
            Write_Char(7, 15, "1�����Ӯ");
            Sleep(1500);
            return;
        }

        // 2.ײ��ʳ��
        else if (Map[TempEnemy.X][TempEnemy.Y] == FOOD)
        {

            //�����Ե���ʳ��
            m_Enemy_Temp_Count_Food = m_Enemy_Count_Food + 1;

            //�ӷ�
            m_Enemy_Get_Temp_Score = m_Enemy_Get_Score + 100;

            //�߱䳤
            m_Enemy_Snake.insert(m_Enemy_Snake.begin(), TempEnemy);

            Draw_Enemy_Snake();


            //����
            if (m_Enemy_Move_Speed != 0)
            {
                m_Enemy_Move_Speed -= 10;
            }

            //��ʳ��ĵ�ͼ��Ϣ�༭Ϊ�յ�
            Map[TempEnemy.X][TempEnemy.Y] = EMPTYAREA;
            return;
        }
        //2.1����ʳ��
        else if (Map[TempEnemy.X][TempEnemy.Y] == SPEEDDOWNFOOD)
        {
            //�����Ե���ʳ��
            m_Enemy_Temp_Count_Food = m_Enemy_Count_Food + 1;

            //�ӷ�
            m_Enemy_Get_Temp_Score = m_Enemy_Get_Score + 100;

            //�߱䳤
            m_Enemy_Snake.insert(m_Enemy_Snake.begin(), TempEnemy);

            //����
            Draw_Enemy_Snake();


            //����
            if (m_Enemy_Move_Speed < 200)
            {
                m_Enemy_Move_Speed += 10;
            }

            //��ʳ��ĵ�ͼ��Ϣ�༭Ϊ�յ�
            Map[TempEnemy.X][TempEnemy.Y] = EMPTYAREA;
            return;
        }

        // 3.ײ���ϰ���
        else if (Map[TempEnemy.X][TempEnemy.Y] == OBSTACLES)
        {
            m_Enemy_Game_Life = 0;
            m_Enemy_Snake.clear();
            return;
        }

        // 4.ײ���յ�:���·���

        //5.ײ��1�����
        else if (Map[TempEnemy.X][TempEnemy.Y] == PLAYER)
        {
            m_Game_Life = 0;
        }
        //����ͷ������������
        m_Enemy_Snake.insert(m_Enemy_Snake.begin(), TempEnemy);


        //����βȥ��
        Map[m_Enemy_Snake.back().X][m_Enemy_Snake.back().Y] = EMPTYAREA;
        m_Enemy_Snake.erase(m_Enemy_Snake.end() - 1);

        //������

        Draw_Enemy_Snake();
        m_Enemy_Move_Lasttime = clock();
    }

}

void CSnake::Move_Double_Snake()
{

    //�������ղ����ı���
    Oper = 0;

    //�����ͷ����
    COORD Temp = { m_Snake[0].X,m_Snake[0].Y };
    COORD TempEnemy = { m_Enemy_Snake[0].X,m_Enemy_Snake[0].Y };
    Oper = WaitKey();
    //�������e���򱣴�
    if (Oper == 101)
    {
        Get_Oper();
        return;
    }
    //�������q������ͣ
    if (Oper == 'q')
    {
        _getch();
    }
    //��ֹ����180��ת�䣬��������Ĳ������
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

    //�ı��ߵķ���
    Change_Snake_Dir();
    Change_Enemy_Snake_Dir();

    //�ƶ��з���
    Move_Enemy_Snake_Head(TempEnemy);

    if (clock() - m_Move_Lasttime > m_Move_Speed)
    {
        //������
        Remove_Snake();


        //�ı���ͷ������
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

        //�����ƶ����߿������������
        // 1.ײ���Լ�
        if (Map[Temp.X][Temp.Y] == PLAYER)
        {
            m_Game_Life = 0;
            m_Snake.clear();
            return;
        }

        // 2.ײ��ʳ��
        else if (Map[Temp.X][Temp.Y] == FOOD)
        {

            //�����Ե���ʳ��
            m_Temp_Count_Food = m_Count_Food + 1;

            //�ӷ�
            m_Get_Temp_Score = m_Get_Score + 100;

            //�߱䳤
            m_Snake.insert(m_Snake.begin(), Temp);

            //��ʾ��
            Draw_Snake();

            //����
            if (m_Move_Speed != 0)
            {
                m_Move_Speed -= 10;
            }

            //��ʳ��ĵ�ͼ��Ϣ�༭Ϊ�յ�
            Map[Temp.X][Temp.Y] = EMPTYAREA;
            return;
        }
        //2.1����ʳ��
        else if (Map[Temp.X][Temp.Y] == SPEEDDOWNFOOD)
        {
            //�����Ե���ʳ��
            m_Temp_Count_Food = m_Count_Food + 1;

            //�ӷ�
            m_Get_Temp_Score = m_Get_Score + 100;

            //�߱䳤
            m_Snake.insert(m_Snake.begin(), Temp);

            //��ʾ��
            Draw_Snake();

            //����
            if (m_Move_Speed < 200)
            {
                m_Move_Speed += 10;
            }

            //��ʳ��ĵ�ͼ��Ϣ�༭Ϊ�յ�
  /*          Map[Temp.X][Temp.Y] = EMPTYAREA;*/
            return;
        }

        // 3.ײ���ϰ���
        else if (Map[Temp.X][Temp.Y] == OBSTACLES)
        {
            m_Game_Life = 0;
            m_Snake.clear();
            return;
        }

        // 4.ײ���յ�:���·���

        //5.ײ���з���
        else if (Map[Temp.X][Temp.Y] == ENEMYPLAYER)
        {
            m_Enemy_Game_Life = 0;
            m_Enemy_Snake.clear();

            //1�����Ӯ
            return;
        }
        //����ͷ������������
        m_Snake.insert(m_Snake.begin(), Temp);

        //����βȥ��
        Map[m_Snake.back().X][m_Snake.back().Y] = EMPTYAREA;
        m_Snake.erase(m_Snake.end() - 1);

        //������
        Draw_Snake();
        m_Move_Lasttime = clock();
    }
}

//�õ��Ե�ʳ����������ʱֵ
int CSnake::Get_Temp_Count_Food()
{
    return m_Temp_Count_Food;
}

//�õ��з��Ե�ʳ����������ʱֵ
int CSnake::Get_Enemy_Temp_Count_Food()
{
    return m_Enemy_Temp_Count_Food;
}

//�õ��Ե�ʳ��������ֵ
int CSnake::Get_m_Count_Food()
{
    return m_Count_Food;
}

//�õ��з��Ե�ʳ��������ֵ
int CSnake::Get_Enemy_m_Count_Food()
{
    return m_Enemy_Count_Food;
}

//���óԵ�ʳ���������ֵ
void CSnake::Set_m_Count_Food(int Temp_Count_Food)
{
    m_Count_Food = Temp_Count_Food;
}
//���õз��Ե�ʳ���������ֵ
void CSnake::Set_Enemy_m_Count_Food(int Temp_Enemy_Count_Food)
{
    m_Enemy_Count_Food = Temp_Enemy_Count_Food;
}


//�õ���������ʱֵ
int CSnake::Get_Temp_Score()
{
    return m_Get_Temp_Score;
}

//�õ��з���������ʱֵ
int CSnake::Get_Enemy_Temp_Score()
{
    return m_Enemy_Get_Temp_Score;
}

//�õ�������ֵ
int CSnake::Get_Score()
{
    return m_Get_Score;
}

int CSnake::Get_Enemy_Score()
{
    return m_Enemy_Get_Score;
}

//���÷�����ֵ
void CSnake::Set_Enemy_Score(int Temp_Enemy_Score)
{
    m_Enemy_Get_Score = Temp_Enemy_Score;
}
void CSnake::Set_Score(int Temp_Score)
{
    m_Get_Score = Temp_Score;
}

//��ȡ�ߵĳ���
int CSnake::Get_Snake_Lenth()
{
    return m_Snake.size();
}
//��ȡ�з��ߵĳ���
int CSnake::Get_Enemy_Snake_Lenth()
{
    return m_Enemy_Snake.size();
}


//��ȡ�ߵ�Ԫ��
COORD CSnake::Get_Snake_Ele(int nLoc)
{
    Temp_Snake_Ele.X = m_Snake[nLoc].X;
    Temp_Snake_Ele.Y = m_Snake[nLoc].Y;
    return Temp_Snake_Ele;

}
//��ȡ�з��ߵ�Ԫ��
COORD CSnake::Get_Enemy_Snake_Ele(int nLoc)
{
    Temp_Enemy_Snake_Ele.X = m_Enemy_Snake[nLoc].X;
    Temp_Enemy_Snake_Ele.Y = m_Enemy_Snake[nLoc].Y;
    return Temp_Enemy_Snake_Ele;

}
//��Ԫ�ط�������
void CSnake::Push_Back_Snake(COORD Temp_Snake)
{

    m_Snake.push_back(Temp_Snake);
}
//���з�Ԫ�ط�������
void CSnake::Push_Back_Enemy_Snake(COORD Temp_Snake)
{

    m_Enemy_Snake.push_back(Temp_Snake);
}

//����ߵ��ٶ�
int CSnake::Get_Speed()
{
    return  m_Move_Speed;
}
//��õз��ߵ��ٶ�
int CSnake::Get_Enemy_Speed()
{
    return  m_Enemy_Move_Speed;
}

//�����ߵ��ٶ�
void CSnake::Set_Speed(int nSpeed)
{
    m_Move_Speed = nSpeed;
}
//���õз��ߵ��ٶ�
void CSnake::Set_Enemy_Speed(int nEnemy_Speed)
{
    m_Enemy_Move_Speed = nEnemy_Speed;
}

//����ߵķ���
int CSnake::Get_Dir()
{
    return m_Snake_Dir;
}

//��õз��ߵķ���
int CSnake::Get_Enemy_Dir()
{
    return m_Enemy_Snake_Dir;
}

//�����ߵķ���
void CSnake::Set_Dir(int nDir)
{
    m_Snake_Dir = nDir;
}
//���õз��ߵķ���
void CSnake::Set_Enemy_Dir(int nEnemy_Dir)
{
    m_Enemy_Snake_Dir = nEnemy_Dir;
}

//δ�ر���Ϸʱ�������ߵ�ͼ��
void CSnake::Draw_No_Player_Snake()
{
    for (unsigned int i = 0; i < m_Snake.size(); i++)
    {
        Write_Char(m_Snake[i].X, m_Snake[i].Y, "��");
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

//ɾ���ߵ�Ԫ��
void CSnake::Dele_Snake_Ele()
{
    m_Snake.clear();
}

//ɾ���з��ߵ�Ԫ��
void CSnake::Dele_Enemy_Snake_Ele()
{
    m_Enemy_Snake.clear();
}

//�����ߵ�����
void CSnake::Set_Snake_LIfe(int Temp_Life)
{
    m_Game_Life = Temp_Life;

}
//���õз��ߵ�����
void CSnake::Set_Enemy_Snake_LIfe(int Temp_Enemy_Life)
{
    m_Enemy_Game_Life = Temp_Enemy_Life;

}

//����ߵ�����
int CSnake::Get_Game_Life()
{
    return m_Game_Life;
}

//��öԷ��ߵ�����
int CSnake::Get_Enemy_Game_Life()
{
    return m_Enemy_Game_Life;
}

//�ı�з��ߵķ���
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

//�ı�Է����ߵķ���
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
//�ƶ��з�����
void CSnake::Move_Enemy_Snake_Head(COORD TempEnemy)
{
    if (clock() - m_Enemy_Move_Lasttime > m_Enemy_Move_Speed)
    {
        //������
        Remove_Enemy_Snake();


        //�ı���ͷ������
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

        //�����ƶ����߿������������
        // 1.ײ���Լ�
        if (Map[TempEnemy.X][TempEnemy.Y] == ENEMYPLAYER)
        {
            m_Game_Life = 0;
            m_Enemy_Snake.clear();
            //������Ҫһ�������������ж�
            Write_Char(7, 15, "1�����Ӯ");
            Sleep(1500);
            return;
        }

        // 2.ײ��ʳ��
        else if (Map[TempEnemy.X][TempEnemy.Y] == FOOD)
        {

            //�����Ե���ʳ��
            m_Enemy_Temp_Count_Food = m_Enemy_Count_Food + 1;

            //�ӷ�
            m_Enemy_Get_Temp_Score = m_Enemy_Get_Score + 100;

            //�߱䳤
            m_Enemy_Snake.insert(m_Enemy_Snake.begin(), TempEnemy);

            Draw_Enemy_Snake();


            //����
            if (m_Enemy_Move_Speed != 0)
            {
                m_Enemy_Move_Speed -= 10;
            }

            //��ʳ��ĵ�ͼ��Ϣ�༭Ϊ�յ�
      /*      Map[TempEnemy.X][TempEnemy.Y] = EMPTYAREA;*/
            return;
        }
        //2.1����ʳ��
        else if (Map[TempEnemy.X][TempEnemy.Y] == SPEEDDOWNFOOD)
        {
            //�����Ե���ʳ��
            m_Enemy_Temp_Count_Food = m_Enemy_Count_Food + 1;

            //�ӷ�
            m_Enemy_Get_Temp_Score = m_Enemy_Get_Score + 100;

            //�߱䳤
            m_Enemy_Snake.insert(m_Enemy_Snake.begin(), TempEnemy);

            //����
            Draw_Enemy_Snake();


            //����
            if (m_Enemy_Move_Speed < 200)
            {
                m_Enemy_Move_Speed += 10;
            }

            //��ʳ��ĵ�ͼ��Ϣ�༭Ϊ�յ�
      /*      Map[TempEnemy.X][TempEnemy.Y] = EMPTYAREA;*/
            return;
        }

        // 3.ײ���ϰ���
        else if (Map[TempEnemy.X][TempEnemy.Y] == OBSTACLES)
        {
            m_Enemy_Game_Life = 0;
            m_Enemy_Snake.clear();
            return;
        }

        // 4.ײ���յ�:���·���

        //5.ײ��1�����
        else if (Map[TempEnemy.X][TempEnemy.Y] == PLAYER)
        {
            m_Game_Life = 0;
        }
        //����ͷ������������
        m_Enemy_Snake.insert(m_Enemy_Snake.begin(), TempEnemy);


        //����βȥ��
        Map[m_Enemy_Snake.back().X][m_Enemy_Snake.back().Y] = EMPTYAREA;
        m_Enemy_Snake.erase(m_Enemy_Snake.end() - 1);

        //������

        Draw_Enemy_Snake();
        m_Enemy_Move_Lasttime = clock();
    }
}