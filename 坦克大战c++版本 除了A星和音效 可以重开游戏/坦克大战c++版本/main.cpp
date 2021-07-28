#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"winmm.lib")
#include"CGame.h"
#include"CMap.h"
#include<ctime>
#include<stdio.h>
#include<windows.h>
#include"resource.h"
int main()
{
    CGame objGame;
    //…Ë÷√¥∞ø⁄
    objGame.Init_Console_Info_All(42, 42, "TankWar v0.01");

    objGame.Show_Welcome();
    Sleep(1000);
    system("cls");
    PlaySoundA(MUSic_SOUND, NULL, SND_ASYNC | SND_NODEFAULT);
    srand((unsigned int)time(0));


        while (1)
        {
            objGame.Show_Menu();
            if (KEYDOWN('1'))
            {
                system("cls");
                objGame.Game_Play_Adv();
            }
            if (KEYDOWN('2'))
            {
                system("cls");
                objGame.Game_Play();
            }

            if (KEYDOWN('3'))
            {
                system("cls");
                CMap::MouseDraw();
            }
            if (KEYDOWN('4'))
            {
                system("cls");
                objGame.Load_Game();
                objGame.Load_Game_Start();

            }
            Sleep(100);
            system("cls");
        }

   


    return 0;
}