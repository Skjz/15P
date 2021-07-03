#pragma once
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

//�����߷���ĺ�
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

//��ͼ�ĺ�

//��ͼ��x��
#define MAP_ROW 30
//��ͼ��y��
#define MAP_COL 30
//�ϰ���
#define OBSTACLES 1
//ʳ��(��ͨ)
#define FOOD 2
//ʳ����٣�
#define SPEEDDOWNFOOD 5
//���Լ�����ң�
#define PLAYER 3
//��(�з�)
#define ENEMYPLAYER 6
//�յ�
#define EMPTYAREA 4

//�˵��ĺ�

//�Զ�����Ϸ��ʼ
#define GAMESTART_CUS MouseEv.dwMousePosition.X >= 0 && MouseEv.dwMousePosition.X < 20 && MouseEv.dwMousePosition.Y < 1
//ԭʼ��Ϸ��ʼ
#define GAMESTART_ORG MouseEv.dwMousePosition.X >= 0 && MouseEv.dwMousePosition.X < 20 && MouseEv.dwMousePosition.Y == 1
//��ȡ��Ϸ
#define LOADGAME  MouseEv.dwMousePosition.X >= 0 && MouseEv.dwMousePosition.X < 20 && MouseEv.dwMousePosition.Y == 2
//�༭��ͼ
#define EDITGAME  MouseEv.dwMousePosition.X >= 0 && MouseEv.dwMousePosition.X < 20 && MouseEv.dwMousePosition.Y == 3
//�˳���Ϸ
#define ENDGAME   MouseEv.dwMousePosition.X >= 0 && MouseEv.dwMousePosition.X < 20 && MouseEv.dwMousePosition.Y == 6
//˫����Ϸ
#define DOUBLEPLAY  MouseEv.dwMousePosition.X >= 0 && MouseEv.dwMousePosition.X < 20 && MouseEv.dwMousePosition.Y == 4
//����˫����Ϸ
#define DOUBLCONTINUE  MouseEv.dwMousePosition.X >= 0 && MouseEv.dwMousePosition.X < 20 && MouseEv.dwMousePosition.Y == 5

//�༭ģʽ�ĺ�
#define EDITOBSTCALES MouseEv.dwMousePosition.X < MAP_ROW * 2 - 2) && MouseEv.dwMousePosition.X > 0 && MouseEv.dwMousePosition.Y < MAP_COL - 1 && MouseEv.dwMousePosition.Y>0
#define SETEMPTYAREA  MouseEv.dwMousePosition.X <( MAP_ROW * 2 - 2) && MouseEv.dwMousePosition.X >0 && MouseEv.dwMousePosition.Y < MAP_COL - 1 && MouseEv.dwMousePosition.Y>0
//�ļ���·��
#define PATH   "..\\Save.txt"
//˫����Ϸ�ļ���·��
#define PATHDouble "..\\SnakeDouble.txt"

//�����ļ���·��
#define MUSICPATH "..\\Sound\\Game.wav"

//��ͼ��Ϣ��������
extern int Map[MAP_ROW][MAP_COL];


// ������ɫ
#define F_BLUE     FOREGROUND_BLUE      // ����
#define F_H_BLUE   0x0001|0x0008        // ����
#define F_GREEN    0x0002               // ����
#define F_H_GREEN  0x0002|0x0008        // ����
#define F_RED      0x0004               // ���
#define F_H_RED    0x0004|0x0008        // ����
#define F_YELLOW   0x0002|0x0004        // ���
#define F_H_YELLOW 0x0002|0x0004|0x0008 // ����
#define F_PURPLE   0x0001|0x0004        // ����
#define F_H_PURPLE 0x0001|0x0004|0x0008 // ����
#define F_CYAN     0x0002|0x0004        // ����
#define F_H_CYAN   0x0002|0x0004|0x0008 // ����
#define F_WHITE    0x0004|0x0002|0x0001
#define F_H_WHITE  0x0004|0x0002|0x0001|0x0008

 // ������ɫ
#define B_BLUE     BACKGROUND_BLUE      // ����
#define B_H_BLUE   0x0010|0x0080        // ����
#define B_GREEN    0x0020               // ����
#define B_H_GREEN  0x0020|0x0080        // ����
#define B_RED      0x0040               // ���z
#define B_H_RED    0x0040|0x0080        // ����
#define B_YELLOW   0x0020|0x0040        // ���
#define B_H_YELLOW 0x0020|0x0040|0x0080 // ����
#define B_PURPLE   0x0010|0x0040        // ����
#define B_H_PURPLE 0x0010|0x0040|0x0080 // ����
#define B_CYAN     0x0020|0x0040        // ����
#define B_H_CYAN   0x0020|0x0040|0x0080 // ����
#define B_WHITE    0x0010|0x0020|0x0040
#define B_H_WHITE  0x0010|0x0020|0x0040|0x0080

//����
#define MOUSEPOS_X MouseEv.dwMousePosition.X / 2
#define MOUSEPOS_Y MouseEv.dwMousePosition.Y


//��ʾ�ú���
void Write_Char(int x, int y, const char* str, int Color = 15);
void Write_Int(int x, int y, int nNUm, int Color = 15);a
void ShowCursor(bool isShow);
//�����ú���
int WaitKey();
