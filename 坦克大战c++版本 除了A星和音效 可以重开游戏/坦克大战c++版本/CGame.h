#pragma once
#include<stdio.h>
#include"CTank.h"
#include"CBullet.h"
#include<vector>

using std::vector;
//����ʶ�𰸼��Ƿ��µĺ�
#define KEYDOWN(key) ((GetAsyncKeyState(key)& 0x8000) ? (1) :(0) )

/*
��������Get_User_Oper 
�������ã�ʵ�ֺ�������ȡ�û��Ĳ���������̹���ƶ�����ͣ�ʹ洢
����:
����ֵ��
��ע���ú�������ʵʱ��ȡ�û����������




��������Show_Cursor
�������ã�ʵ�ֺ����������򿪻�رտ���̨�����ʾ
����1�����������true\false
����ֵ��
��ע��trueΪ�򿪿���̨��꣬falseΪ�رտ���̨���


��������Init_Console_Size
�������ã�ʵ�ֺ�����������������̨���ڵĴ�С
����1����������� short int �Ͳ���������x
����2���������,  short int �Ͳ���������y
����ֵ��
��ע��

��������Init_Console_Info_All
�������ã��ӿں�������ʼ�����д�����Ϣ���������ڳߴ磬��������С�����ڱ��⣬�Լ��Ƿ���ʾ����̨���
����1�����������short ���͵Ĳ��������ڵĿ��
����2�����������short ���͵Ĳ��������ڵĸ߶�
����3������������ַ������������ڵı���
����4�����������bool���ͣ��Ƿ���ʾ���ڹ�꣬Ĭ���ǹرչ�ꡣ
����ֵ��
��ע��Ҫ�򿪹����Ҫ�ڲ���4������true����


��������Game_Play
�������ã��ӿں���������������Ϸ�������̵��߼�
����1��
����ֵ��
��ע��

��������Move_All_bullet
�������ã��ƶ����е��ӵ����Ҹ���ɾȥ�ӵ�
����1��
����ֵ��
��ע��
*/

class CGame
{

public:
    //��ʼ��ȫ��������Ϣ
    void Init_Console_Info_All(_In_ const short X, _In_ const short Y, _In_ const char* Title, _In_ const bool Isshow = false);
    CGame();

public:
    //����������Ϸ�����߼��ĺ���(�Զ���)
    void Game_Play();
    //����ģʽ
    void Game_Play_Adv();

    //��ʼ����Ϸ�ã�
private:
    //�رչ���ú���
    void Show_Cursor(_In_ const bool isShow = false);
    //��ʼ�����ڴ�С
    void Init_Console_Size(_In_ const short X, _In_ const short Y);


    //�����û������ã�
private:
    //��ȡ�û�����
    void Get_User_Oper();

    //�����Ķ���
private:
    CTank Player1{ RIGHT, {10,10},LV_3,true };
    CTank Player2{ LEFT,{5,5,},LV_3 ,true};
private:
    vector<CBullet> objBullet;
    vector<CTank> objRobo;

private:
    //ȷ���ѷ��Ƿ���
    void Check_Player_Is_Alive();

//���ɵз�̹����أ�
private:
    //��ʼ���з�̹��
    void Init_Robo_Tank();
    //����з�̹��
    void Refresh_Robo_Tank();

    //ȷ��̹��
    void Check_Robo_Alive();

private:
    //������һ��
    void Next_Stage();
    void Refresh_Game();
private:
    clock_t Robo_Move_Lasttime;
    
private:
    //��һ�ɱ�ļ���
    unsigned short m_Tank_Kill_Count;
    unsigned short m_Temp_Tank_Kill_Count;
    //���ʤ������  
    unsigned short m_Game_Win_Con;
    
private:
    //���ʧ�ܵ�����
    unsigned short m_Game_Lose_Con;
    unsigned short m_Player_Dead_Count;
    bool Is_Game_Save;
private:
    //�ƶ����е�ͼ�ϵ��ӵ�
    void Move_All_Bullet(_Out_ vector<CBullet> &objBullet,_Out_ vector<CTank> &objRobo,_In_ CTank &Player1,_In_ CTank &Player2);

private:
    void Move_All_Robo();
    void Creat_Robo_Bullet(CTank objRobo_Single);
    
private:
    //����һ������ӵ��Ľӿ�
    void Creat_Player1_Bullet();
    //������������ӵ��Ľӿ�
    void Creat_Player2_Bullet();

public:
    void Show_Menu();
    void Show_Welcome();

private:
    void Save_Game();
public:
    void Load_Game();
public:
    void Load_Game_Start();

    
};



