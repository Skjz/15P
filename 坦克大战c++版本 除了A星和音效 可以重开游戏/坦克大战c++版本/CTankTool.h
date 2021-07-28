#pragma once
#include"CMap.h"
#include"CBullet.h"
#include<vector>
using std::vector;
//#include<windows.h>

//��ͼ1
#define PATH_MAP1  "..\\Debug\\1.map"
//��ͼ2                 D
#define PATH_MAP2  "..\\Debug\\2.map"
//��ͼ3                 D
#define PATH_MAP3  "..\\Debug\\3.map"
//��ͼ4                 D
#define PATH_MAP4  "..\\Debug\\4.map"
//��ͼ5                 D
#define PATH_MAP5  "..\\Debug\\5.map"
//����ð��ģʽ
#define PATH_SAVE_ADV   "..\\Debug\\Adv.sav"
//����༭ģʽ
#define PATH_SAVE_CUS  "..\\Debug\\Cus.sav"

//̹�˴�ս�����࣬��LEVEL����Ϊ����ʹ��
class CTankTool
{
public:
    //̹�����
    //��ʼ����̬��Ա
    static unsigned short Tank_Move_Speed[4];       //̹���ƶ��ٶ�����
    static unsigned short Tank_Rocil[4];            //̹�˺��������飬Ӱ��̹������ļ��ʱ��
    static COLOR Tank_Color[4];                     //̹����۵����飬��ͬ�ȼ���̹���в�ͬ�����
    static COLOR Tank_In_Grass;                     //̹���ڲ������ɫ
    static COLOR Bullet_In_Grass;                   //�ӵ��ڲ������ɫ
    static COLOR Bullet_In_River;                   
    //�з�̹�˵�����
    static unsigned short Robo_Tank_Count;            //�з�̹�˵�����
    static unsigned short Robo_Tank_Max_Count;        //�з�̹��ͬʱ�ڳ��������
    static DIR m_Robo_Move_Oper_Arr[4];

   
    //��ͼ����
    static const char* Game_Stage[5];

    //�ӵ����
    static unsigned short Bullet_Move_Speed[4];     //�ӵ����ƶ��ٶ����飬��ͬ�ȼ����ӵ��в�ͬ���ƶ��ٶ�
    static COLOR Bullet_Color[4];                   //�ӵ���������飬��ͬ�ȼ����ӵ��в�ͬ���
    ////�ӵ�����
    //static vector<CBullet> objBullet;
    ////̹������
    //static vector<CTank> objRobo;
};

