#pragma once
#include<stdio.h>
#include<windows.h>
#include<ctime>
#include<vector>

/*
��������Draw_Tank
�������ã���ʾ̹�˻��ǲ���̹�˵�ͼ��ͬʱ�ܹ��ڵ�ͼ��Ϣ�б༭������Ϊ̹�˻�������
����1��bool ���ͣ����������true��ʾ̹���ҽ�̹�˵���Ϣд���ͼ��flase��̹�˲����ҽ���ͼ�༭Ϊ�յ�
����ֵ��
��ע������1��Ĭ�ϲ�����true��Ҳ����˵�������������Ĭ���ǻ���̹���ҽ���ͼ��Ϣ�༭Ϊ̹��


��������Move_Tank
�������ã���̹���ڵ�ͼ���ƶ�
����1��ö�ٳ����������������̹�˵ķ���
����ֵ:
��ע������1��CGame���Get_User_Oper����



��������Check_AHead
�������ã�ȷ��̹��ǰ����������Ƿ����ϰ���
����1��
����ֵ��bool ���ͣ����Ϊ�棬����ǰ���ǿյأ����Ϊ����˵�����ϰ���
��ע��



��������Tank_Shot_Bullet
�������ã�����һ���ӵ�������
����1��
����ֵ��COORD���ͣ��ӵ������ĳ�ʼ����
��ע��



������:Get_Tank_Dir
�������ã�����̹�˷����ӵ�ʱ�ķ���
����1��
����ֵ:DIR��ö�����ͣ�̹�˵ķ���������ʼ���ӵ��ķ���
��ע��

��������Is_Tank_Can_Shot
�������ã������ж�̹�˵�ǰ�Ƿ��ܹ��������
����1��
����ֵ��bool���ͣ�����ܹ��������ֵΪ�棬������ܣ�����ֵΪ��
��ע��

 ��������Get_Tank_Level
 �������ã������ӵ�ʱ���ӵ����̹�˵ĵȼ�
 ����1��
 ����ֵ��LEVELö�����ͣ�̹�˵ĵȼ�
 ��ע��

��������Creat_Robo_Tank
�������ã����������з�̹��
����1��vector<CTank> ���飬��������������������õĵз�̹�˷���������
����ֵ��
��ע��Ŀǰ��ͼ��󴴽�̹����Ϊ3
*/



//�ܵȼ�Ӱ���̹�����ԣ�
//1. �ƶ��ٶ�
//2. ������ٶ�
//3. ����
//4. ����

//��Ϊ�±�������
enum LEVEL
{
    LV_0,//��Ч����
    LV_1,
    LV_2,
    LV_3,
};

//̹�˷���
enum DIR
{
    Last_Dir=-1,
    UP=0,
    DOWN,
    LEFT,
    RIGHT
};

//����·�ߵĽṹ�壬ÿһ���ṹ��ʵ�����Ķ��󶼱�����Щ��Ϣ
typedef struct _NODE
{
    _NODE* pFather;		//����㣬��һ��λ��
    COORD pos;			//��ǰλ��
    int G;				//�ߵĲ���
    int H;				//Ԥ�����յ�Ĳ���
    int F;				//��ġ���G+H
}NODE,*PNODE;


class CTank
{
public:
    CTank();
    CTank(DIR Dir, COORD Tank_Pos, LEVEL Tank_Level = LV_1, bool Is_Tank_Player = true);


    //�ƶ�̹���ýӿ�
public:
    void Draw_Tank(_In_ bool IsShow = true);
    //�ƶ�̹��
    void Move_Tank(_In_ DIR Dir);
    bool Check_AHead();
    //�ƶ���̹��֮���ڻ���ʱ��ľ����߼�
private:
    void Draw_Tank_In_Class(_In_ int Temp_Tank_Pos_X, _In_ int Temp_Tank_Pos_Y, _In_ bool IsShow);
    void Draw_Robo_Tank_In_Class(_In_ int Temp_Tank_Pos_X, _In_ int Temp_Tank_Pos_Y, _In_ bool IsShow);
    //�ƶ��з�̹���ýӿ�
public:
    void Draw_Robo_Tank(_In_ bool IsShow = true);
    void Move_Robo_Tank(_In_ DIR Dir=Last_Dir);
    bool Is_Robo_Tank_Can_Shot();

    //��ʼ���ӵ��ýӿڣ�
public:
    //�ڷ����ӵ�ʱ�����ӵ�����
    COORD Tank_Shot_Bullet();
    //���̹�˵ķ���
    DIR Get_Tank_Dir();
    //��ȡ̹�˵ĵȼ������ӵ��ã�
    LEVEL Get_Tank_Level();
private:
    //̹�˵�ģ��
    int m_nTank_Mode[4][3][3];
private:
    //̹���ƶ����
private:
    //̹�˵ķ���
    DIR m_Dir;
    //̹�˵�λ��
    COORD m_Tank_Pos;
    //̹���ƶ���ʱ���
    clock_t m_Tank_Move_Lasttime;
    //̹���ƶ����ٶ�
    unsigned short m_Tank_Move_Speed;

public:
    //����̹���ƶ�ʱ���
    void Set_Tank_Lasttime();
    void Set_Robo_Lasttime();
public:
    //ȷ��̹���Ƿ��ܹ������ӵ�:
    bool Is_Tank_Can_Shot();

 //̹�˵ĺ�����
private:
    clock_t m_Tank_Shot_Lasttime;
    unsigned short m_Tank_Rocil;
public:
    int Get_Tank_Life();

private:
    //��ҵ�����ֵ
    int m_Tank_Life;
    //���̹�˵ĵȼ�
    LEVEL m_Tank_Level;
public:
    //̹������
    void Tank_Get_Dmg();
public:
    //���ɻ�����
    void Creat_Robo_Tank(_Out_ std::vector<CTank>& Robo_Tank);
private:
    //�ط�̹�˲�����ʱ���
    unsigned short m_Robo_Tank_Oper_Time;
    //�ط�̹�˿���ʱ���
    clock_t m_Robo_Tank_Oper_Lasttime;
public:
    //�ط�̹�˿�����ٶ�
    unsigned short Get_Robo_Tank_Oper_Time();
private:
    //����̹������һ��ǵ���
    bool m_Is_Tank_Player;
public:
    //����������ҵ���������������Ҳ���֮ǰ��̹��
    void Reset_Player(_In_ COORD Reset_Pos);

public:
    //ȷ��̹���Ƿ������
    bool Get_Is_Tank_Player();
    //���̹������
    COORD Get_Tank_Pos();
    
public:
    //�з�̹��Ѱ·
    //�ҵ���·����Ŵ�
    //std::vector<COORD> m_Robo_Tank_Move_Path;
    //std::vector<PNODE> m_Open;
    //std::vector<PNODE> m_Close;
    ////�з�̹�˻�ȡ·�����㷨
    //void Robo_Tank_Get_Path(_In_ CTank &Player1)
    
    

};

