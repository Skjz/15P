#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"ShowMenu.h"
#include"DrawBase.h"
void ShowMenu()
{

    //printf("********1.重新游戏********\n");
    //printf("********2.读取游戏********\n");
    //printf("********3.编辑地图********\n");
    //printf("********0.结束游戏********\n");
    Write_Char(0, 0, "********1.自定游戏********");
    Write_Char(0, 1, "********2.重新游戏********");
    Write_Char(0, 2, "********3.读取游戏********");
    Write_Char(0, 3, "********4.编辑地图********");
    Write_Char(0, 4, "********5.双人游戏********");
    Write_Char(0, 5, "********6.继续双人********");
    Write_Char(0, 6, "********7.结束游戏********");
    Write_Char(0, 7, "      鼠标左键进行选择     ");




}