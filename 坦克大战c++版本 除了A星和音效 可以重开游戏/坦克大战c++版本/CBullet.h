#pragma once

#include<windows.h>
#include"CTank.h"
#include<ctime>
#include<vector>
/*
��������Draw_Bullet
�������ã������ӵ����߲����ӵ���ͬʱ�Ե�ͼ��Ϣ���б༭
����1��bool ���ͣ�������������Ϊ��������ӵ������Ϊ��������ӵ�
����ֵ��
��ע��

��������Set_Bullet_Dir
�������ã������ӵ��ķ��з��򣨳�ʼ���ӵ��ã�
����1��DIRö�����ͣ����������һ��ͨ��̹����ĺ�������ֵ����
����ֵ��
��ע��

��������Set_Bullet_Pos
�������ã������ӵ���λ�ã���ʼ���ӵ��ã�
����1�����������һ��ͨ��̹����ĺ�������ֵ����
����ֵ��
��ע��

��������Creat_Bullet
�������ã������ӵ������ӵ���ʼ����֮���ӵ���������������
����1��DIRö������,���������һ��ͨ��̹����ĺ��� Get_Tank_Dir() ����ֵ����
����2��COORD�ṹ�壬���������һ��ͨ��̹����ĺ��� Tank_Shot_Bullet() ����ֵ����
����3:vector ���������ã��������������ӵ��������г�ʼ���õ���Ϣ��������
����ֵ��
��ע��
*/


/*
/*
��������Draw_Bullet
�������ã������ӵ����߲����ӵ���ͬʱ�Ե�ͼ��Ϣ���б༭
����1��bool ���ͣ�������������Ϊ��������ӵ������Ϊ��������ӵ�
����ֵ��
��ע��

��������Move_Bullet
�������ã��ƶ��ӵ���ͬʱ�����ӵ�����Ч��m_Bullet_Life
����1��
����ֵ��
��ע��

��������Check_Bullet_Hit
�������ã�����ӵ�����ײ�����Ҵ�����Ӧ���߼�
����1��
����ֵ��int���ͣ���ӦTHINGö���еĶ��󣨼�����ײ����ʲô��
��ע��

*/


/*
��������Get_Bullet_Life
�������ã��ӿں������������ߵ����߸��ӵ������Ƿ���Ч
����1��
����ֵ��
��ע������ӵ�������Ч(false)��Ӧ������ɾ����

*/
class CBullet
{
//��ʼ���ӵ���
private:
    //�ӵ��ȼ�
    LEVEL m_Bullet_Level;
public:
    CBullet();
    //�����ӵ�����
    void Set_Bullet_Dir(_In_ DIR Dir);
    //�����ӵ�������
    void Set_Bullet_Pos(_In_ COORD Bullet_Pos);
    //�����ӵ�
    void Creat_Bullet(_In_ DIR Dir, _In_ COORD Bullet_Pos,_Out_ std::vector<CBullet>&Bullet);
    //���õȼ�
    void Set_Bullet_Level(_In_ LEVEL Tank_Level);
    //��ͬ�ӵ��ȼ�,��ͬ������
    void Bullet_Power(_Out_ std::vector<CBullet>& Bullet);
    void Set_Is_Bullet_Player(bool IS_Tank_Player);
    void Set_Bullet_Move_Lasttime();
private:
    //����ӵ��ǵо������Ѿ��ı�ʶ
    bool m_Is_Bullet_Player;
//�ƶ��ӵ�:
public:
    void Draw_Bullet(_In_ bool IsShow);
    void Move_Bullet(_Out_ std::vector<CBullet>& objBullet, _Out_ std::vector<CTank>& objRobo, _In_ CTank& Player1, _In_ CTank& Player2);
    //����ӵ�ײ����ʲô
    int Check_Bullet_Hit(_Out_ std::vector<CBullet>& objBullet, _Out_ std::vector<CTank>& objRobo, _In_ CTank& Player1, _In_ CTank& Player2);

    void Search_For_Robo( _Out_ std::vector<CTank>& objRobo);
    void Search_For_Player(_In_ CTank& Player1, _In_ CTank& Player2);
    //�����ӵ���λ��
    bool Bullet_Hit_Bullet;
private:
    void Draw_Bullet_In_Class();
    void Remove_Bullet_In_Class();
  
private:
    //�ӵ�������
    COORD m_Bullet_Pos;
    //�ӵ��ķ���
    DIR m_Bullet_Dir;
    //�ӵ��ƶ���ʱ���
    clock_t m_Bullet_Move_Lasttime;
    //�ٶ�
    int m_Bullet_Speed;

//ȷ���ӵ�����Ч�ԣ�
private:
    bool m_Bullet_Life;
public:
    bool Get_Bullet_Life();
public:
    LEVEL Get_Bullet_Level();
    COORD Get_Bullet_Pos();
    
};

