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

//创造子弹的接口
void CGame::Creat_Player1_Bullet()
{
    CBullet This_Bullet;
    This_Bullet.Set_Bullet_Level(Player1.Get_Tank_Level());
    This_Bullet.Set_Is_Bullet_Player(Player1.Get_Is_Tank_Player());
    //创建一颗子弹
    This_Bullet.Creat_Bullet(Player1.Get_Tank_Dir(), Player1.Tank_Shot_Bullet(), objBullet);
    //当子弹等级高过1级时，生成的子弹有所不同
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
    //创建一颗子弹
    This_Bullet.Creat_Bullet(Player2.Get_Tank_Dir(), Player2.Tank_Shot_Bullet(), objBullet);
    //当子弹等级高过1级时，生成的子弹有所不同
    if (Player2.Get_Tank_Level() > 1)
    {
        This_Bullet.Bullet_Power(objBullet);
    }
}
void CGame::Get_User_Oper()
{
    //如果按下w,返回值为真，则条件表达式成立，坦克1向上移动
    if (KEYDOWN('W')) { Player1.Move_Tank(UP); }
    ///如果按下S,返回值为真，则条件表达式成立，坦克1向下移动
    if (KEYDOWN('S')) { Player1.Move_Tank(DOWN); }
    ///如果按下A,返回值为真，则条件表达式成立，坦克向左移动
    if (KEYDOWN('A')) { Player1.Move_Tank(LEFT); }
    //如果按下D,返回值为真，则条件表达式为真，坦克向右移动
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



////显示用函数
//void CGame::Write_Char(_In_ const short X, _In_ const  short Y, _In_ const  char* Str, _In_ const int Color )
//{
//    //设置光标具体坐标
//    COORD pos = { 2 * Y,X };
//    //获取句柄
//    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//    //设置光标位置
//    SetConsoleCursorPosition(hOut, pos);
//
//    //设置文本颜色
//    SetConsoleTextAttribute(hOut, Color);
//
//    //输出字符
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

//关闭光标用函数
void CGame::Show_Cursor(_In_ const bool isShow)
{
    //获取句柄
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //设置控制台光标的结构体
    CONSOLE_CURSOR_INFO cci;
    //光标尺寸
    cci.dwSize = 1;
    //关闭光标或打开光标
    cci.bVisible = isShow;
    //设置控制台函数
    SetConsoleCursorInfo(hOut, &cci);

}

//初始化窗口大小
void CGame::Init_Console_Size(_In_ const short X, _In_ const short Y)
{
    //1.获取句柄
    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);

    //2. 根据当前控制台的设置，获取它最大能够设置的大小，如果
    //    我们请求的大小超过了它能设置的大小，就会设置失败
    COORD LargeSize = GetLargestConsoleWindowSize(Handle);
    if (LargeSize.X < X || LargeSize.Y < Y)
    {
        fprintf(stderr, "设置的尺寸过大，请重新设置!\n");
        system("pause"); exit(0);
    }

    /*  3. 设置控制台窗口的大小，这个大小就是用户看到的窗
          口大小，控制台窗口的 x y 的比例是 1 : 2*/
    SMALL_RECT Rect = { 0, 0, X * 2, Y };
    if (!SetConsoleWindowInfo(Handle, TRUE, &Rect))
    {
        printf("设置窗口大小错误，请重新设置!\n");
        system("pause"); exit(0);
    }

    //4. 设置缓冲区大小，它表示的是容纳内容的大小，这个大小
    //    理论会比窗口大小大 1，否则会出现问题
    COORD Temp = { X * 2 + 1, Y + 1 };
    if (!SetConsoleScreenBufferSize(Handle, Temp))
    {
        printf("设置缓冲区大小错误，请重新设置!\n");
        system("pause"); exit(0);
    }
}


//初始化全部窗口信息
void CGame::Init_Console_Info_All(_In_ const short X, _In_ const short Y, _In_ const char* Title, _In_ const bool Isshow)
{
    //初始化窗口大小
    Init_Console_Size(X, Y);

    //设置是否打开光标（默认关闭）
    Show_Cursor(Isshow);

    //设置标题
    SetConsoleTitleA(Title);


}
void CGame::Move_All_Bullet(_Out_ vector<CBullet>& objBullet, _Out_ vector<CTank>& objRobo, _In_ CTank& Player1, _In_ CTank& Player2)
{
    //获取迭代器
    vector<CBullet>::iterator begin = objBullet.begin();
    //当迭代器不在末尾的下一个位置时
    while (begin != objBullet.end())
    {

        begin->Move_Bullet(objBullet, objRobo, Player1, Player2);
        //如果子弹是有效的，则访问下一个子弹
        if (begin->Get_Bullet_Life())
        {
            begin++;
        }
        //如果子弹无效，则将其删除
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
//控制整个游戏游玩逻辑的函数
//自定义游戏
void CGame::Game_Play()
{
    if (objBullet.size() != 0)
    {
        objBullet.clear();
    }
    //初始化地图
   // CMap::InitMap();
    Refresh_Game();
    CMap::InitCusMap();
    //初始化敌方坦克
    Init_Robo_Tank();

    //绘制玩家坦克
    Player1.Draw_Tank();
    Player2.Draw_Tank();
    CMap::Write(41, 41, m_Tank_Kill_Count, 0xF);
    while (1)
    {
        //接收用户操作
        Get_User_Oper();
        Move_All_Robo();
        //移动所有子弹
        Move_All_Bullet(objBullet, objRobo, Player1, Player2);
        //确认敌方坦克是否存活
        Check_Robo_Alive();
        //确认玩家是否存活
        Check_Player_Is_Alive();
        //复活敌方坦克
        Refresh_Robo_Tank();
        //游戏结束跳出循环
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

//闯关模式
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
    //初始化地图
    CMap::InitMap();

    // CMap::InitCusMap();
         //绘制玩家坦克
    Player1.Reset_Player({ 10,10 });

    Player2.Reset_Player({ 5,5 });
    //初始化敌方坦克
    Init_Robo_Tank();

    CMap::Write(41, 41, m_Tank_Kill_Count, 0xF);
    while (1)
    {
        //接收用户操作
        Get_User_Oper();
        //移动所有敌方坦克
        Move_All_Robo();
        //移动所有子弹
        Move_All_Bullet(objBullet, objRobo, Player1, Player2);
        //确认敌方坦克是否存活
        Check_Robo_Alive();
        //确认玩家是否存活
        Check_Player_Is_Alive();

        //复活敌方坦克
        Refresh_Robo_Tank();
        //计分
        if (m_Temp_Tank_Kill_Count > m_Tank_Kill_Count)
        {
            m_Tank_Kill_Count = m_Temp_Tank_Kill_Count;
            CMap::Write(41, 41, m_Tank_Kill_Count, 0xF);

        }
        //游戏结束
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
        //进入下关
        Next_Stage();

    }


}
//初始化敌方坦克
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
//复活敌方坦克
void CGame::Refresh_Robo_Tank()
{
    if (CTankTool::Robo_Tank_Count != CTankTool::Robo_Tank_Max_Count)
    {
        CTank This_Tank;
        This_Tank.Creat_Robo_Tank(objRobo);
        This_Tank.Draw_Robo_Tank(true);
    }
}
//检查敌方坦克是否存活
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
    printf("******1.冒险游戏******\n");
    printf("******2.编辑游戏******\n");
    printf("******3.编辑地图******\n");
    printf("******4.读取游戏******\n");


}
//下一关
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

        //敌方坦克的数量提高
        CTankTool::Robo_Tank_Max_Count++;
        //需要击杀的坦克数量增加
        m_Game_Win_Con++;
        // 获取其他地图
        CMap::Clear_Map();
        CMap::ReloadMap(CTankTool::Game_Stage[rand() % 5]);
        //初始化地图了
        CMap::InitCusMap();
        Player1.Reset_Player({ 10,10 });
        Player2.Reset_Player({ 5,5 });
        //再次初始化游戏,包括坦克的信息
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
    //创建一颗子弹
    This_Bullet.Creat_Bullet(objRobo_Single.Get_Tank_Dir(), objRobo_Single.Tank_Shot_Bullet(), objBullet);
    //当子弹等级高过1级时，生成的子弹有所不同
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
    //存场上的坦克数
    fwrite(&CTankTool::Robo_Tank_Count, 1, sizeof(unsigned short), pFile);
    //存当前对局的最大坦克数
    fwrite(&CTankTool::Robo_Tank_Max_Count, 1, sizeof(unsigned short), pFile);
    //存普通地图
    for (int i = 0; i < CMap::ROWS; i++)
    {
        for (int j = 0; j < CMap::COLS; j++)
        {
            fwrite(&CMap::Map[i][j], 1, sizeof(THING), pFile);
        }
    }
    //存静态地图
    for (int i = 0; i < CMap::ROWS; i++)
    {
        for (int j = 0; j < CMap::COLS; j++)
        {
            fwrite(&CMap::StaticMap[i][j], 1, sizeof(STHING), pFile);
        }
    }
    //存一号玩家
    fwrite(&Player1, 1, sizeof(CTank), pFile);
    //存二号玩家
    fwrite(&Player2, 1, sizeof(CTank), pFile);
    //存敌方数组大小
    int Robo_Size = objRobo.size();
    fwrite(&Robo_Size, 1, 4, pFile);
    //开始存敌方坦克
    for (int i = 0; i < objRobo.size(); i++)
    {
        fwrite(&objRobo[i], 1, sizeof(CTank), pFile);
    }
    //存子弹数组大小
    int Bullet_Size = objBullet.size();
    fwrite(&Bullet_Size, 1, 4, pFile);
    //存子弹
    for (int i = 0; i < objBullet.size(); i++)
    {
        fwrite(&objBullet[i], 1, sizeof(CBullet), pFile);
    }
    //m_Tank_Kill_Count{ 0 }, m_Game_Win_Con{ 5 }, m_Temp_Tank_Kill_Count{ 0 }, m_Game_Lose_Con{ 5 }, m_Player_Dead_Count{ 0 }
    //存坦克击杀数
    fwrite(&m_Tank_Kill_Count, 1, sizeof(unsigned int), pFile);
    //存当前胜利条件
    fwrite(&m_Game_Win_Con, 1, sizeof(unsigned int), pFile);
    //存临时击杀数
    fwrite(&m_Temp_Tank_Kill_Count, 1, sizeof(unsigned int), pFile);
    //存当前游戏失败条件
    fwrite(&m_Game_Lose_Con, 1, sizeof(unsigned int), pFile);
    //存游戏玩家死亡次数
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
    //读场上的坦克数
    fread(&CTankTool::Robo_Tank_Count, 1, sizeof(unsigned short), pFile);
    //读当前对局的最大坦克数
    fread(&CTankTool::Robo_Tank_Max_Count, 1, sizeof(unsigned short), pFile);
    //读普通地图
    for (int i = 0; i < CMap::ROWS; i++)
    {
        for (int j = 0; j < CMap::COLS; j++)
        {
            fread(&CMap::Map[i][j], 1, sizeof(THING), pFile);
        }
    }
    //读静态地图
    for (int i = 0; i < CMap::ROWS; i++)
    {
        for (int j = 0; j < CMap::COLS; j++)
        {
            fread(&CMap::StaticMap[i][j], 1, sizeof(STHING), pFile);
        }
    }
    //读一号玩家
    fread(&Player1, 1, sizeof(CTank), pFile);
    Player1.Set_Tank_Lasttime();
    //读二号玩家
    fread(&Player2, 1, sizeof(CTank), pFile);
    Player1.Set_Tank_Lasttime();

    //读敌方数组大小
    int Robo_Size{ 0 };
    fread(&Robo_Size, 1, 4, pFile);
    //读始存敌方坦克
    for (int i = 0; i < Robo_Size; i++)
    {
        CTank objTempRobo;
        fread(&objTempRobo, 1, sizeof(CTank), pFile);
        objTempRobo.Set_Robo_Lasttime();

        objRobo.push_back(objTempRobo);
    }
    //读子弹数组大小
    int Bullet_Size{ 0 };
    fread(&Bullet_Size, 1, 4, pFile);
    //读子弹
    for (int i = 0; i < Bullet_Size; i++)
    {
        CBullet objTempBullet;
        fread(&objTempBullet, 1, sizeof(CBullet), pFile);
        objTempBullet.Set_Bullet_Move_Lasttime();
        objBullet.push_back(objTempBullet);
    }
    //m_Tank_Kill_Count{ 0 }, m_Game_Win_Con{ 5 }, m_Temp_Tank_Kill_Count{ 0 }, m_Game_Lose_Con{ 5 }, m_Player_Dead_Count{ 0 }
    //读坦克击杀数
    fread(&m_Tank_Kill_Count, 1, sizeof(unsigned int), pFile);
    //读当前胜利条件
    fread(&m_Game_Win_Con, 1, sizeof(unsigned int), pFile);
    //读临时击杀数
    fread(&m_Temp_Tank_Kill_Count, 1, sizeof(unsigned int), pFile);
    //读当前游戏失败条件
    fread(&m_Game_Lose_Con, 1, sizeof(unsigned int), pFile);
    //读游戏玩家死亡次数
    fread(&m_Player_Dead_Count, 1, sizeof(unsigned int), pFile);
    fclose(pFile);
    pFile = nullptr;
}
//读取游戏的逻辑处理
void CGame::Load_Game_Start()
{
    //按照地图初始化
    CMap::InitCusMap();
    //绘制两个坦克
    Player1.Draw_Tank(true);
    Player2.Draw_Tank(true);
    //绘制敌方坦克
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
        //接收用户操作
        Get_User_Oper();
        //移动所有敌方坦克
        Move_All_Robo();
        //移动所有子弹
        Move_All_Bullet(objBullet, objRobo, Player1, Player2);
        //确认敌方坦克是否存活
        Check_Robo_Alive();
        //确认玩家是否存活
        Check_Player_Is_Alive();

        //复活敌方坦克
        Refresh_Robo_Tank();
        //计分
        if (m_Temp_Tank_Kill_Count > m_Tank_Kill_Count)
        {
            m_Tank_Kill_Count = m_Temp_Tank_Kill_Count;
        }
        //游戏结束
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
        //进入下关
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

        //敌方坦克的数量提高
       // CTankTool::Robo_Tank_Max_Count++;
        //需要击杀的坦克数量增加
        //m_Game_Win_Con++;
  
        //初始化地图了
        CMap::InitCusMap();
        Player1.Reset_Player({ 10,10 });
        Player2.Reset_Player({ 5,5 });
        //再次初始化游戏,包括坦克的信息
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
    cout << "                         ████████╗ █████╗ ███╗   ██╗██╗  ██╗██╗  ██╗" << endl;
    cout << "                         ╚══██╔══╝██╔══██╗████╗  ██║██║ ██╔╝██║ ██╔╝" << endl;
    cout << "                            ██║   ███████║██╔██╗ ██║█████╔╝ █████╔╝" << endl;
    cout << "                            ██║   ██╔══██║██║╚██╗██║██╔═██╗ ██╔═██╗" << endl;
    cout << "                            ██║   ██║  ██║██║ ╚████║██║  ██╗██║  ██╗" << endl;
    cout << "                            ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝  ╚═╝" << endl;

    cout << "                                ██╗    ██╗ █████╗ ██████╗" << endl;
    cout << "                                ██║    ██║██╔══██╗██╔══██╗ " << endl;
    cout << "                                ██║ █╗ ██║███████║██████╔╝ " << endl;
    cout << "                                ██║███╗██║██╔══██║██╔══██╗ " << endl;
    cout << "                                ╚███╔███╔╝██║  ██║██║  ██║ " << endl;
    cout << "                                ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝  ╚═╝  " << endl;








}