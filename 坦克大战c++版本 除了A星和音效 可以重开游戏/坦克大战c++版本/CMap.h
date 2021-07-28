#pragma once
#include<stdio.h>
#include<windows.h>
//���ڴ��ϱ�ʾ��ͼ���ݵ�ö��
enum THING
{
    //�յ�
    EMPTY = 0,
    //�ϰ���߽磩
    OBSTACLES = 1,
    //��ǽ
    WALL_I = 2,
    //��ǽ
    WALL_II = 3,
    //��ǽ
    WALL_III = 4,
    //���
    PLAYER = 5,
    //�ӵ�
    BULLET = 6,
    //����
    ROBO = 7,
};
enum STHING
{
    S_EMPTY =0,
    S_GRASS = 1,
    S_RIVER = 2, 
};

enum COLOR
{
    FC_Red = FOREGROUND_INTENSITY | FOREGROUND_RED,
    FC_Green = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
    FC_Blue = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
    FC_Yellow = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
    FC_HighWhite = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    FC_White = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    FC_Purple = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
    FC_Cyan = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
    FC_Gray = FOREGROUND_INTENSITY,
    FC_BLACK = 0,

    BC_Red = BACKGROUND_INTENSITY | BACKGROUND_RED,
    BC_Green = BACKGROUND_INTENSITY | BACKGROUND_GREEN,
    BC_Blue = BACKGROUND_INTENSITY | BACKGROUND_BLUE,
    BC_Yellow = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN,
    BC_Purple = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE,
    BC_Cyan = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE,
    BC_White = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
    BC_HighWhite = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE,
    BC_BLACK =0,
    
};


#define EDIT_WIDTH MouseEv.dwMousePosition.X < COLS* 2 - 2 && MouseEv.dwMousePosition.X > 1 && MouseEv.dwMousePosition.Y < ROWS - 1 && MouseEv.dwMousePosition.Y>0
#define HIT_SOUND "..\\Debug\\Hit.wav"
#define MUSic_SOUND "..\\Debug\\Game.wav"
//#define MouseEv.dwMousePosition.X < COLS * 2 - 2) && MouseEv.dwMousePosition.X >0 && MouseEv.dwMousePosition.Y < MAP_COL - 1 && MouseEv.dwMousePosition.Y>0
/*      
������:Write
�������ã��ӿں���������Ļ�ϸ���������λ�ã��Ը�������ɫ�����ַ������
����1 : short int ����, ��������������x��
����2 : short int ����, ��������������y��
����3�������������Ҫ��ӡ���ַ�������
����4�������������Ҫ��ʾ����ɫ��Ĭ��Ϊ��ɫ������ɫ��15��
����ֵ��
��ע���ú������ɺ������أ�����Ĭ����ɫ�Ǻ�ɫ��������Ҫ���в�����ʱ�򲻴�����ɫ����


��������Write
�������ã��ӿں������������ڴ���д���λ�õ�ͼ��Ϣ
����1: short int ���ͣ�����������������X��
����2��short int ���ͣ�����������������Y��
����3:ö�ٳ����������������ʾ��ͼ�ϵ���ʲô
����ֵ��
��ע���ú������ɺ�������

��������Is_Something_Here
�������ã�ȷ�ϵ�ͼ��ָ��λ���ǲ����Ǹ�������������򷵻��棬������Ƿ��ؼ�
����1��short int ���ͣ�����������������X��
����2��short int ���ͣ�����������������Y��
����3��ö�ٳ����������������ʾ��ͼ�ϵ���ʲô
����ֵ��bool ���ͣ������ͼָ����λ������ָ���Ķ�����������
��ע��

������:InitMap
�������ã���ʼ����ͼ�����Ƶ�ͼ�ı߽磬����
����1��
����ֵ��
��ע��
*/
class CMap
{
private:
//��ͼ��͸�

    
private:
//��ͼ������
    //��ͼ�Ŀ�͸�

    static const char* Str[8];

    //��̬��ͼ
    //��̬��ͼ����
    static const char* S_Str[3];
    static THING DrawThing[5];
    static STHING DrawSThing[3];
public:
    //��ͨ��ͼ
    static constexpr short ROWS{ 40 };
    static constexpr short COLS{ 40 };
    static THING Map[ROWS][COLS];
    //��̬��ͼ
    static STHING StaticMap[ROWS][COLS];

public:
    static void Clear_Map();

public:
    static COLOR  SColor[3];
    static COLOR OColor[5];
public:
    //��ʾ�ú���
    
    static void Write(_In_  const short X, _In_  const short Y, _In_ const char* Str, _In_ const int Color = 0);
    static void Write(_In_ const short X, _In_ const short Y,_In_ THING Something);
    static void Write(_In_ const short X, _In_ const short Y, _In_ STHING S_Something);
    static void Write(_In_ const short X, _In_ const short Y, _In_ int Int, _In_ const int Color = 0);

public:
    //���ߵ����������ڵ�ͼ����ʲô
    static bool Is_Something_Here(_In_ const short X,_In_ const short Y,_In_ THING Something);
    static bool Is_Something_Here(_In_ const short X,_In_ const short Y,_In_ STHING Something);

public:
    //��ʼ����ͼ
    static void InitMap();
    static void MouseDraw();
    static void InitCusMap();

//��ӷ��ʾ�̬��Ա�����Ľӿں�����
public:
    static const char* Get_Str(_In_ int Index);
    static const char* Get_S_Str(_In_ int Index);

public:
    static void ReloadMap(const char* Path_Map);

};

