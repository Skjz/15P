#include"CMap.h"
#include<iostream>
#include "CGame.h"
#include<windows.h>
#include<conio.h>
#include"CTankTool.h"


using std::cout;
using std::endl;
CGame::CGame() :
    m_Tank_Kill_Count{ 0 }, m_Game_Win_Con{ 5 }, m_Temp_Tank_Kill_Count{ 0 }, m_Game_Lose_Con{ 5 }, m_Player_Dead_Count{ 0 }, Is_Game_Save{ false }


{
    Robo_Move_Lasttime = clock();
}

//�����ӵ��Ľӿ�
void CGame::Creat_Player1_Bullet()
{
    CBullet This_Bullet;
    This_Bullet.Set_Bullet_Level(Player1.Get_Tank_Level());
    This_Bullet.Set_Is_Bullet_Player(Player1.Get_Is_Tank_Player());
    //����һ���ӵ�
    This_Bullet.Creat_Bullet(Player1.Get_Tank_Dir(), Player1.Tank_Shot_Bullet(), objBullet);
    //���ӵ��ȼ��߹�1��ʱ�����ɵ��ӵ�������ͬ
    if (Player1.Get_Tank_Level() > 1)
    {
        This_Bullet.Bullet_Power(objBullet);
    }
}
void CGame::Creat_Player2_Bullet()
{
    CBullet This_Bullet;
    This_Bullet.Set_Bullet_Level(Player2.Get_Tank_Level());
    This_Bullet.Set_Is_Bullet_Player(Player2.Get_Is_Tank_Player());
    //����һ���ӵ�
    This_Bullet.Creat_Bullet(Player2.Get_Tank_Dir(), Player2.Tank_Shot_Bullet(), objBullet);
    //���ӵ��ȼ��߹�1��ʱ�����ɵ��ӵ�������ͬ
    if (Player2.Get_Tank_Level() > 1)
    {
        This_Bullet.Bullet_Power(objBullet);
    }
}
void CGame::Get_User_Oper()
{
    //�������w,����ֵΪ�棬���������ʽ������̹��1�����ƶ�
    if (KEYDOWN('W')) { Player1.Move_Tank(UP); }
    ///�������S,����ֵΪ�棬���������ʽ������̹��1�����ƶ�
    if (KEYDOWN('S')) { Player1.Move_Tank(DOWN); }
    ///�������A,����ֵΪ�棬���������ʽ������̹�������ƶ�
    if (KEYDOWN('A')) { Player1.Move_Tank(LEFT); }
    //�������D,����ֵΪ�棬���������ʽΪ�棬̹�������ƶ�
    if (KEYDOWN('D')) { Player1.Move_Tank(RIGHT); }
    if (KEYDOWN('J') && Player1.Is_Tank_Can_Shot())
    {
        Creat_Player1_Bullet();
    }
    if (KEYDOWN('L')) { Save_Game(); Is_Game_Save = true; }
    if (KEYDOWN('U')) {_getch();}
   

    if (KEYDOWN(VK_UP)) { Player2.Move_Tank(UP); }
    if (KEYDOWN(VK_DOWN)) { Player2.Move_Tank(DOWN); }
    if (KEYDOWN(VK_LEFT)) { Player2.Move_Tank(LEFT); }
    if (KEYDOWN(VK_RIGHT)) { Player2.Move_Tank(RIGHT); }
    if (KEYDOWN(' ') && Player2.Is_Tank_Can_Shot())
    {
        Creat_Player2_Bullet();
    }
}



////��ʾ�ú���
//void CGame::Write_Char(_In_ const short X, _In_ const  short Y, _In_ const  char* Str, _In_ const int Color )
//{
//    //���ù���������
//    COORD pos = { 2 * Y,X };
//    //��ȡ���
//    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//    //���ù��λ��
//    SetConsoleCursorPosition(hOut, pos);
//
//    //�����ı���ɫ
//    SetConsoleTextAttribute(hOut, Color);
//
//    //����ַ�
//    printf("%s", Str);
//
//
//}

//void CGame::Write_Int(_In_ const  short X, _In_ const short Y, _In_  const int Int, _In_ const int Color)
//{
//    COORD pos = { 2 * Y,X };
//    HANDLE hOUt = GetStdHandle(STD_OUTPUT_HANDLE);
//    SetConsoleCursorPosition(hOUt, pos);
//
//    SetConsoleTextAttribute(hOUt, Color);
//    printf("%d", Int);
//}

//�رչ���ú���
void CGame::Show_Cursor(_In_ const bool isShow)
{
    //��ȡ���
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //���ÿ���̨���Ľṹ��
    CONSOLE_CURSOR_INFO cci;
    //���ߴ�
    cci.dwSize = 1;
    //�رչ���򿪹��
    cci.bVisible = isShow;
    //���ÿ���̨����
    SetConsoleCursorInfo(hOut, &cci);

}

//��ʼ�����ڴ�С
void CGame::Init_Console_Size(_In_ const short X, _In_ const short Y)
{
    //1.��ȡ���
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);

    //2. ���ݵ�ǰ����̨�����ã���ȡ������ܹ����õĴ�С�����
    //    ��������Ĵ�С�������������õĴ�С���ͻ�����ʧ��
    COORD LargeSize = GetLargestConsoleWindowSize(Handle);
    if (LargeSize.X < X || LargeSize.Y < Y)
    {
        fprintf(stderr, "���õĳߴ��������������!\n");
        system("pause"); exit(0);
    }

    /*  3. ���ÿ���̨���ڵĴ�С�������С�����û������Ĵ�
          �ڴ�С������̨���ڵ� x y �ı����� 1 : 2*/
    SMALL_RECT Rect = { 0, 0, X * 2, Y };
    if (!SetConsoleWindowInfo(Handle, TRUE, &Rect))
    {
        printf("���ô��ڴ�С��������������!\n");
        system("pause"); exit(0);
    }

    //4. ���û�������С������ʾ�����������ݵĴ�С�������С
    //    ���ۻ�ȴ��ڴ�С�� 1��������������
    COORD Temp = { X * 2 + 1, Y + 1 };
    if (!SetConsoleScreenBufferSize(Handle, Temp))
    {
        printf("���û�������С��������������!\n");
        system("pause"); exit(0);
    }
}


//��ʼ��ȫ��������Ϣ
void CGame::Init_Console_Info_All(_In_ const short X, _In_ const short Y, _In_ const char* Title, _In_ const bool Isshow)
{
    //��ʼ�����ڴ�С
    Init_Console_Size(X, Y);

    //�����Ƿ�򿪹�꣨Ĭ�Ϲرգ�
    Show_Cursor(Isshow);

    //���ñ���
    SetConsoleTitleA(Title);


}
void CGame::Move_All_Bullet(_Out_ vector<CBullet>& objBullet, _Out_ vector<CTank>& objRobo, _In_ CTank& Player1, _In_ CTank& Player2)
{
    //��ȡ������
    vector<CBullet>::iterator begin = objBullet.begin();
    //������������ĩβ����һ��λ��ʱ
    while (begin != objBullet.end())
    {

        begin->Move_Bullet(objBullet, objRobo, Player1, Player2);
        //����ӵ�����Ч�ģ��������һ���ӵ�
        if (begin->Get_Bullet_Life())
        {
            begin++;
        }
        //����ӵ���Ч������ɾ��
        else
        {
            if (!(CMap::Is_Something_Here(begin->Get_Bullet_Pos().X, begin->Get_Bullet_Pos().Y, OBSTACLES) ||
                CMap::Is_Something_Here(begin->Get_Bullet_Pos().X, begin->Get_Bullet_Pos().Y, WALL_I) ||
                CMap::Is_Something_Here(begin->Get_Bullet_Pos().X, begin->Get_Bullet_Pos().Y, WALL_II) ||
                CMap::Is_Something_Here(begin->Get_Bullet_Pos().X, begin->Get_Bullet_Pos().Y, WALL_III) ||
                CMap::Is_Something_Here(begin->Get_Bullet_Pos().X, begin->Get_Bullet_Pos().Y, PLAYER) ||
                CMap::Is_Something_Here(begin->Get_Bullet_Pos().X, begin->Get_Bullet_Pos().Y, ROBO))
                )

            {
                begin->Draw_Bullet(false);
            }
            begin = objBullet.erase(begin);
        }


    }
}
//����������Ϸ�����߼��ĺ���
//�Զ�����Ϸ
void CGame::Game_Play()
{
    if (objBullet.size() != 0)
    {
        objBullet.clear();
    }
    //��ʼ����ͼ
   // CMap::InitMap();
    Refresh_Game();
    CMap::InitCusMap();
    //��ʼ���з�̹��
    Init_Robo_Tank();

    //�������̹��
    Player1.Draw_Tank();
    Player2.Draw_Tank();
    CMap::Write(41, 41, m_Tank_Kill_Count, 0xF);
    while (1)
    {
        //�����û�����
        Get_User_Oper();
        Move_All_Robo();
        //�ƶ������ӵ�
        Move_All_Bullet(objBullet, objRobo, Player1, Player2);
        //ȷ�ϵз�̹���Ƿ���
        Check_Robo_Alive();
        //ȷ������Ƿ���
        Check_Player_Is_Alive();
        //����з�̹��
        Refresh_Robo_Tank();
        //��Ϸ��������ѭ��
        if (m_Temp_Tank_Kill_Count > m_Tank_Kill_Count)
        {
            m_Tank_Kill_Count = m_Temp_Tank_Kill_Count;
            CMap::Write(41, 41, m_Tank_Kill_Count, 0xF);
        }
        if (KEYDOWN('K'))
        {
            //Refresh_Game();
            return;
        }
    }
}

//����ģʽ
void CGame::Game_Play_Adv()
{
    Is_Game_Save = false;

    if (objBullet.size() != 0)
    {
        objBullet.clear();
    }
    //if (objRobo.size() != 0)
    //{
    //    objRobo.clear();
    //}
    //��ʼ����ͼ
    CMap::InitMap();

    // CMap::InitCusMap();
         //�������̹��
    Player1.Reset_Player({ 10,10 });

    Player2.Reset_Player({ 5,5 });
    //��ʼ���з�̹��
    Init_Robo_Tank();

    CMap::Write(41, 41, m_Tank_Kill_Count, 0xF);
    while (1)
    {
        //�����û�����
        Get_User_Oper();
        //�ƶ����ез�̹��
        Move_All_Robo();
        //�ƶ������ӵ�
        Move_All_Bullet(objBullet, objRobo, Player1, Player2);
        //ȷ�ϵз�̹���Ƿ���
        Check_Robo_Alive();
        //ȷ������Ƿ���
        Check_Player_Is_Alive();

        //����з�̹��
        Refresh_Robo_Tank();
        //�Ʒ�
        if (m_Temp_Tank_Kill_Count > m_Tank_Kill_Count)
        {
            m_Tank_Kill_Count = m_Temp_Tank_Kill_Count;
            CMap::Write(41, 41, m_Tank_Kill_Count, 0xF);

        }
        //��Ϸ����
        if (m_Player_Dead_Count >= m_Game_Lose_Con)
        {
            return;
        }
        if (Is_Game_Save == true)
        {
            m_Player_Dead_Count = 0;
            CTankTool::Robo_Tank_Count = 0;
            m_Temp_Tank_Kill_Count = m_Tank_Kill_Count = 0;
            return;
        }
        //�����¹�
        Next_Stage();

    }


}
//��ʼ���з�̹��
void CGame::Init_Robo_Tank()
{
    for (int i = 0; i < objRobo.size(); i++)
    {
        objRobo[i].Draw_Robo_Tank(false);
    }
    if (objRobo.size() != 0)
    {
        objRobo.clear();
    }
    for (int i = 0; i < CTankTool::Robo_Tank_Max_Count; i++)
    {
        CTank This_Tank;
        This_Tank.Creat_Robo_Tank(objRobo);
        This_Tank.Draw_Robo_Tank();
    }

}
//����з�̹��
void CGame::Refresh_Robo_Tank()
{
    if (CTankTool::Robo_Tank_Count != CTankTool::Robo_Tank_Max_Count)
    {
        CTank This_Tank;
        This_Tank.Creat_Robo_Tank(objRobo);
        This_Tank.Draw_Robo_Tank(true);
    }
}
//���з�̹���Ƿ���
void CGame::Check_Robo_Alive()
{
    for (int i = 0; i < objRobo.size(); i++)
    {
        if (objRobo[i].Get_Tank_Life() <= 0)
        {
            objRobo[i].Draw_Tank(false);
            objRobo.erase(objRobo.begin() + i);
            CTankTool::Robo_Tank_Count--;
            m_Temp_Tank_Kill_Count++;
        }
    }
}
void CGame::Show_Menu()
{
    printf("******1.ð����Ϸ******\n");
    printf("******2.�༭��Ϸ******\n");
    printf("******3.�༭��ͼ******\n");
    printf("******4.��ȡ��Ϸ******\n");


}
//��һ��
void CGame::Next_Stage()
{

    Is_Game_Save = false;
    if (m_Game_Win_Con == m_Tank_Kill_Count)
    {
        if (objBullet.size() != 0)
        {
            objBullet.clear();
        }
        m_Player_Dead_Count = 0;
        CTankTool::Robo_Tank_Count = 0;
        m_Temp_Tank_Kill_Count = m_Tank_Kill_Count = 0;

        //�з�̹�˵��������
        CTankTool::Robo_Tank_Max_Count++;
        //��Ҫ��ɱ��̹����������
        m_Game_Win_Con++;
        // ��ȡ������ͼ
        CMap::Clear_Map();
        CMap::ReloadMap(CTankTool::Game_Stage[rand() % 5]);
        //��ʼ����ͼ��
        CMap::InitCusMap();
        Player1.Reset_Player({ 10,10 });
        Player2.Reset_Player({ 5,5 });
        //�ٴγ�ʼ����Ϸ,����̹�˵���Ϣ
        Init_Robo_Tank();
        CMap::Write(41, 41, m_Tank_Kill_Count, 0xF);

    }
}

void CGame::Move_All_Robo()
{
    for (int i = 0; i < objRobo.size(); i++)
    {
        int Flag{ 0 };
        Flag = rand() % 100;
        if (Flag < 40)
        {
            DIR Temp_Dir = DIR(rand() % 4);
            objRobo[i].Move_Robo_Tank(Temp_Dir);
        }
        else
        {
            objRobo[i].Move_Robo_Tank();
        }

    }
    for (int i = 0; i < objRobo.size(); i++)
    {
        if (objRobo[i].Is_Robo_Tank_Can_Shot())
        {
            Creat_Robo_Bullet(objRobo[i]);
        }
    }
}

void CGame::Creat_Robo_Bullet(CTank objRobo_Single)
{

    CBullet This_Bullet;
    This_Bullet.Set_Bullet_Level(objRobo_Single.Get_Tank_Level());
    This_Bullet.Set_Is_Bullet_Player(objRobo_Single.Get_Is_Tank_Player());
    //����һ���ӵ�
    This_Bullet.Creat_Bullet(objRobo_Single.Get_Tank_Dir(), objRobo_Single.Tank_Shot_Bullet(), objBullet);
    //���ӵ��ȼ��߹�1��ʱ�����ɵ��ӵ�������ͬ
    if (objRobo_Single.Get_Tank_Level() > 1)
    {
        This_Bullet.Bullet_Power(objBullet);
    }
}

void CGame::Check_Player_Is_Alive()
{
    if (Player1.Get_Tank_Life() <= 0)
    {
        m_Player_Dead_Count++;
        Player1.Draw_Tank(false);
        Player1.Reset_Player({ 10,10 });
    }
    if (Player2.Get_Tank_Life() <= 0)
    {
        m_Player_Dead_Count++;
        Player2.Draw_Tank(false);
        Player2.Reset_Player({ 5,5 });
    }

}


void CGame::Save_Game()
{
    FILE* pFile = nullptr;
    int Error = fopen_s(&pFile, PATH_SAVE_ADV, "wb+");
    if (Error != 0)
    {
        return;
    }
    //�泡�ϵ�̹����
    fwrite(&CTankTool::Robo_Tank_Count, 1, sizeof(unsigned short), pFile);
    //�浱ǰ�Ծֵ����̹����
    fwrite(&CTankTool::Robo_Tank_Max_Count, 1, sizeof(unsigned short), pFile);
    //����ͨ��ͼ
    for (int i = 0; i < CMap::ROWS; i++)
    {
        for (int j = 0; j < CMap::COLS; j++)
        {
            fwrite(&CMap::Map[i][j], 1, sizeof(THING), pFile);
        }
    }
    //�澲̬��ͼ
    for (int i = 0; i < CMap::ROWS; i++)
    {
        for (int j = 0; j < CMap::COLS; j++)
        {
            fwrite(&CMap::StaticMap[i][j], 1, sizeof(STHING), pFile);
        }
    }
    //��һ�����
    fwrite(&Player1, 1, sizeof(CTank), pFile);
    //��������
    fwrite(&Player2, 1, sizeof(CTank), pFile);
    //��з������С
    int Robo_Size = objRobo.size();
    fwrite(&Robo_Size, 1, 4, pFile);
    //��ʼ��з�̹��
    for (int i = 0; i < objRobo.size(); i++)
    {
        fwrite(&objRobo[i], 1, sizeof(CTank), pFile);
    }
    //���ӵ������С
    int Bullet_Size = objBullet.size();
    fwrite(&Bullet_Size, 1, 4, pFile);
    //���ӵ�
    for (int i = 0; i < objBullet.size(); i++)
    {
        fwrite(&objBullet[i], 1, sizeof(CBullet), pFile);
    }
    //m_Tank_Kill_Count{ 0 }, m_Game_Win_Con{ 5 }, m_Temp_Tank_Kill_Count{ 0 }, m_Game_Lose_Con{ 5 }, m_Player_Dead_Count{ 0 }
    //��̹�˻�ɱ��
    fwrite(&m_Tank_Kill_Count, 1, sizeof(unsigned int), pFile);
    //�浱ǰʤ������
    fwrite(&m_Game_Win_Con, 1, sizeof(unsigned int), pFile);
    //����ʱ��ɱ��
    fwrite(&m_Temp_Tank_Kill_Count, 1, sizeof(unsigned int), pFile);
    //�浱ǰ��Ϸʧ������
    fwrite(&m_Game_Lose_Con, 1, sizeof(unsigned int), pFile);
    //����Ϸ�����������
    fwrite(&m_Player_Dead_Count, 1, sizeof(unsigned int), pFile);
    fclose(pFile);
    pFile = nullptr;

}

void CGame::Load_Game()
{
    if (objRobo.size() != 0)
    {
        objRobo.clear();
    }
    if (objBullet.size() != 0)
    {
        objRobo.clear();
    }
    CMap::Clear_Map();
    FILE* pFile = nullptr;
    int Error = fopen_s(&pFile, PATH_SAVE_ADV, "rb");
    if (Error != 0)
    {
        return;
    }
    //�����ϵ�̹����
    fread(&CTankTool::Robo_Tank_Count, 1, sizeof(unsigned short), pFile);
    //����ǰ�Ծֵ����̹����
    fread(&CTankTool::Robo_Tank_Max_Count, 1, sizeof(unsigned short), pFile);
    //����ͨ��ͼ
    for (int i = 0; i < CMap::ROWS; i++)
    {
        for (int j = 0; j < CMap::COLS; j++)
        {
            fread(&CMap::Map[i][j], 1, sizeof(THING), pFile);
        }
    }
    //����̬��ͼ
    for (int i = 0; i < CMap::ROWS; i++)
    {
        for (int j = 0; j < CMap::COLS; j++)
        {
            fread(&CMap::StaticMap[i][j], 1, sizeof(STHING), pFile);
        }
    }
    //��һ�����
    fread(&Player1, 1, sizeof(CTank), pFile);
    Player1.Set_Tank_Lasttime();
    //���������
    fread(&Player2, 1, sizeof(CTank), pFile);
    Player1.Set_Tank_Lasttime();

    //���з������С
    int Robo_Size{ 0 };
    fread(&Robo_Size, 1, 4, pFile);
    //��ʼ��з�̹��
    for (int i = 0; i < Robo_Size; i++)
    {
        CTank objTempRobo;
        fread(&objTempRobo, 1, sizeof(CTank), pFile);
        objTempRobo.Set_Robo_Lasttime();

        objRobo.push_back(objTempRobo);
    }
    //���ӵ������С
    int Bullet_Size{ 0 };
    fread(&Bullet_Size, 1, 4, pFile);
    //���ӵ�
    for (int i = 0; i < Bullet_Size; i++)
    {
        CBullet objTempBullet;
        fread(&objTempBullet, 1, sizeof(CBullet), pFile);
        objTempBullet.Set_Bullet_Move_Lasttime();
        objBullet.push_back(objTempBullet);
    }
    //m_Tank_Kill_Count{ 0 }, m_Game_Win_Con{ 5 }, m_Temp_Tank_Kill_Count{ 0 }, m_Game_Lose_Con{ 5 }, m_Player_Dead_Count{ 0 }
    //��̹�˻�ɱ��
    fread(&m_Tank_Kill_Count, 1, sizeof(unsigned int), pFile);
    //����ǰʤ������
    fread(&m_Game_Win_Con, 1, sizeof(unsigned int), pFile);
    //����ʱ��ɱ��
    fread(&m_Temp_Tank_Kill_Count, 1, sizeof(unsigned int), pFile);
    //����ǰ��Ϸʧ������
    fread(&m_Game_Lose_Con, 1, sizeof(unsigned int), pFile);
    //����Ϸ�����������
    fread(&m_Player_Dead_Count, 1, sizeof(unsigned int), pFile);
    fclose(pFile);
    pFile = nullptr;
}
//��ȡ��Ϸ���߼�����
void CGame::Load_Game_Start()
{
    //���յ�ͼ��ʼ��
    CMap::InitCusMap();
    //��������̹��
    Player1.Draw_Tank(true);
    Player2.Draw_Tank(true);
    //���Ƶз�̹��
    for (int i = 0; i < objRobo.size(); i++)
    {
        if (objRobo[i].Get_Tank_Life() > 0)
        {
            objRobo[i].Draw_Robo_Tank(true);
        }
    }
    Is_Game_Save = false;
    while (1)
    {
        //�����û�����
        Get_User_Oper();
        //�ƶ����ез�̹��
        Move_All_Robo();
        //�ƶ������ӵ�
        Move_All_Bullet(objBullet, objRobo, Player1, Player2);
        //ȷ�ϵз�̹���Ƿ���
        Check_Robo_Alive();
        //ȷ������Ƿ���
        Check_Player_Is_Alive();

        //����з�̹��
        Refresh_Robo_Tank();
        //�Ʒ�
        if (m_Temp_Tank_Kill_Count > m_Tank_Kill_Count)
        {
            m_Tank_Kill_Count = m_Temp_Tank_Kill_Count;
        }
        //��Ϸ����
        if (m_Player_Dead_Count >= m_Game_Lose_Con)
        {
            system("cls");
            return;
        }
        if (Is_Game_Save == true)
        {
            system("cls");
            return;
        }
        //�����¹�
        Next_Stage();

    }

}

void CGame::Refresh_Game()
{
    Is_Game_Save = false;

        if (objBullet.size() != 0)
        {
            objBullet.clear();
        }
        m_Player_Dead_Count = 0;
        CTankTool::Robo_Tank_Count = 0;
        m_Temp_Tank_Kill_Count = m_Tank_Kill_Count = 0;

        //�з�̹�˵��������
       // CTankTool::Robo_Tank_Max_Count++;
        //��Ҫ��ɱ��̹����������
        //m_Game_Win_Con++;
  
        //��ʼ����ͼ��
        CMap::InitCusMap();
        Player1.Reset_Player({ 10,10 });
        Player2.Reset_Player({ 5,5 });
        //�ٴγ�ʼ����Ϸ,����̹�˵���Ϣ
        //Init_Robo_Tank();
        CMap::Write(41, 41, m_Tank_Kill_Count, 0xF);

    
}
void CGame::Show_Welcome()
{
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                         �����������������[ �����������[ �������[   �����[�����[  �����[�����[  �����[" << endl;
    cout << "                         �^�T�T�����X�T�T�a�����X�T�T�����[���������[  �����U�����U �����X�a�����U �����X�a" << endl;
    cout << "                            �����U   ���������������U�����X�����[ �����U�����������X�a �����������X�a" << endl;
    cout << "                            �����U   �����X�T�T�����U�����U�^�����[�����U�����X�T�����[ �����X�T�����[" << endl;
    cout << "                            �����U   �����U  �����U�����U �^���������U�����U  �����[�����U  �����[" << endl;
    cout << "                            �^�T�a   �^�T�a  �^�T�a�^�T�a  �^�T�T�T�a�^�T�a  �^�T�a�^�T�a  �^�T�a" << endl;

    cout << "                                �����[    �����[ �����������[ �������������[" << endl;
    cout << "                                �����U    �����U�����X�T�T�����[�����X�T�T�����[ " << endl;
    cout << "                                �����U ���[ �����U���������������U�������������X�a " << endl;
    cout << "                                �����U�������[�����U�����X�T�T�����U�����X�T�T�����[ " << endl;
    cout << "                                �^�������X�������X�a�����U  �����U�����U  �����U " << endl;
    cout << "                                �^�T�T�a�^�T�T�a �^�T�a  �^�T�a�^�T�a  �^�T�a  " << endl;








}