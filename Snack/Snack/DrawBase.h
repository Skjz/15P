#pragma once
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

//用作蛇方向的宏
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

//地图的宏

//地图的x轴
#define MAP_ROW 30
//地图的y轴
#define MAP_COL 30
//障碍物
#define OBSTACLES 1
//食物(普通)
#define FOOD 2
//食物（减速）
#define SPEEDDOWNFOOD 5
//蛇自己（玩家）
#define PLAYER 3
//蛇(敌方)
#define ENEMYPLAYER 6
//空地
#define EMPTYAREA 4

//菜单的宏

//自定义游戏开始
#define GAMESTART_CUS MouseEv.dwMousePosition.X >= 0 && MouseEv.dwMousePosition.X < 20 && MouseEv.dwMousePosition.Y < 1
//原始游戏开始
#define GAMESTART_ORG MouseEv.dwMousePosition.X >= 0 && MouseEv.dwMousePosition.X < 20 && MouseEv.dwMousePosition.Y == 1
//读取游戏
#define LOADGAME  MouseEv.dwMousePosition.X >= 0 && MouseEv.dwMousePosition.X < 20 && MouseEv.dwMousePosition.Y == 2
//编辑地图
#define EDITGAME  MouseEv.dwMousePosition.X >= 0 && MouseEv.dwMousePosition.X < 20 && MouseEv.dwMousePosition.Y == 3
//退出游戏
#define ENDGAME   MouseEv.dwMousePosition.X >= 0 && MouseEv.dwMousePosition.X < 20 && MouseEv.dwMousePosition.Y == 6
//双人游戏
#define DOUBLEPLAY  MouseEv.dwMousePosition.X >= 0 && MouseEv.dwMousePosition.X < 20 && MouseEv.dwMousePosition.Y == 4
//继续双人游戏
#define DOUBLCONTINUE  MouseEv.dwMousePosition.X >= 0 && MouseEv.dwMousePosition.X < 20 && MouseEv.dwMousePosition.Y == 5

//编辑模式的宏
#define EDITOBSTCALES MouseEv.dwMousePosition.X < MAP_ROW * 2 - 2) && MouseEv.dwMousePosition.X > 0 && MouseEv.dwMousePosition.Y < MAP_COL - 1 && MouseEv.dwMousePosition.Y>0
#define SETEMPTYAREA  MouseEv.dwMousePosition.X <( MAP_ROW * 2 - 2) && MouseEv.dwMousePosition.X >0 && MouseEv.dwMousePosition.Y < MAP_COL - 1 && MouseEv.dwMousePosition.Y>0
//文件夹路径
#define PATH   "..\\Save.txt"
//双人游戏文件夹路径
#define PATHDouble "..\\SnakeDouble.txt"

//音乐文件夹路径
#define MUSICPATH "..\\Sound\\Game.wav"

//地图信息管理数组
extern int Map[MAP_ROW][MAP_COL];


// 字体颜色
#define F_BLUE     FOREGROUND_BLUE      // 深蓝
#define F_H_BLUE   0x0001|0x0008        // 亮蓝
#define F_GREEN    0x0002               // 深绿
#define F_H_GREEN  0x0002|0x0008        // 亮绿
#define F_RED      0x0004               // 深红
#define F_H_RED    0x0004|0x0008        // 亮红
#define F_YELLOW   0x0002|0x0004        // 深黄
#define F_H_YELLOW 0x0002|0x0004|0x0008 // 亮黄
#define F_PURPLE   0x0001|0x0004        // 深紫
#define F_H_PURPLE 0x0001|0x0004|0x0008 // 亮紫
#define F_CYAN     0x0002|0x0004        // 深青
#define F_H_CYAN   0x0002|0x0004|0x0008 // 亮青
#define F_WHITE    0x0004|0x0002|0x0001
#define F_H_WHITE  0x0004|0x0002|0x0001|0x0008

 // 背景颜色
#define B_BLUE     BACKGROUND_BLUE      // 深蓝
#define B_H_BLUE   0x0010|0x0080        // 亮蓝
#define B_GREEN    0x0020               // 深绿
#define B_H_GREEN  0x0020|0x0080        // 亮绿
#define B_RED      0x0040               // 深红z
#define B_H_RED    0x0040|0x0080        // 亮红
#define B_YELLOW   0x0020|0x0040        // 深黄
#define B_H_YELLOW 0x0020|0x0040|0x0080 // 亮黄
#define B_PURPLE   0x0010|0x0040        // 深紫
#define B_H_PURPLE 0x0010|0x0040|0x0080 // 亮紫
#define B_CYAN     0x0020|0x0040        // 深青
#define B_H_CYAN   0x0020|0x0040|0x0080 // 亮青
#define B_WHITE    0x0010|0x0020|0x0040
#define B_H_WHITE  0x0010|0x0020|0x0040|0x0080

//鼠标宏
#define MOUSEPOS_X MouseEv.dwMousePosition.X / 2
#define MOUSEPOS_Y MouseEv.dwMousePosition.Y


//显示用函数
void Write_Char(int x, int y, const char* str, int Color = 15);
void Write_Int(int x, int y, int nNUm, int Color = 15);a
void ShowCursor(bool isShow);
//输入用函数
int WaitKey();
