#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib,"winmm.lib")
#include"CArea.h"
#include"DrawBase.h"
#include"ShowMenu.h"
#include"MouseDraw.h"
#include"Welcome.h"

//��ͼ������
int Map[MAP_ROW][MAP_COL];

int main()
{
    //���ñ���
    system("title ����̰����");

    //�رչ��
    ShowCursor(false);

    //��ӭ����
    ShowWelcome();
    Sleep(1500);
    system("cls");

    PlaySoundA(MUSICPATH, NULL, SND_ASYNC | SND_NODEFAULT);
    //1.��ʼ��Ϸ
   // 2.��ȡ��Ϸ
   // 3.�༭��ͼ
   // 0.������Ϸ

    CArea c;

    //��ȡ���
    HANDLE hconsloeInput = GetStdHandle(STD_INPUT_HANDLE);
    //��ȡ����Ľṹ��
    INPUT_RECORD ir = { 0 };

    //�����ṹ������
    DWORD dwRealCourt = 0;

    //����̨�༭ģʽ
    DWORD dwMode = 0;

    //��ֹ��ѭ��
    int Flag = 1;
    while (1)
    {
        ShowMenu();
        //ѭ����ȡ����̨������Ϣ
        while (Flag)
        {
            //���ÿ���̨����ģʽ
            GetConsoleMode(hconsloeInput, &dwMode);
            SetConsoleMode(hconsloeInput, dwMode | ENABLE_MOUSE_INPUT);
            //��ȡ����̨����
            ReadConsoleInput
            (
                hconsloeInput,
                &ir,
                1,
                &dwRealCourt

            );
            //������в����������
            if (ir.EventType == MOUSE_EVENT)
            {
                //��MouseEv���������Ĳ���
                MOUSE_EVENT_RECORD MouseEv = ir.Event.MouseEvent;

                //�����������ʱ��
                if (MouseEv.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
                {
                    //����Ϸ
                    if (GAMESTART_CUS)
                    {
                        Flag = 0;
                        PlaySoundA(MUSICPATH, NULL, SND_ASYNC | SND_NODEFAULT);
                        system("cls");
                        //��ʼ����Ϸ
                        c.Restart_Game();
                        c.Init_Game();
                        //��Ϸ��ʼ
                        c.Game_Play();
                    }
                    //�Զ�����Ϸ
                    if (GAMESTART_ORG)
                    {
                        Flag = 0;
                        PlaySoundA(MUSICPATH, NULL, SND_ASYNC | SND_NODEFAULT);
                        system("cls");
                        c.Restart_Game();
                        c.Init_Game_Org();
                        c.Game_Play();
                    }
                    //��ȡ��Ϸ
                    else if (LOADGAME)
                    {
                        Flag = 0;
                        system("cls");
                        //��ȡ��Ϸ����
                        c.Load_Game();
                        //��ȡ��ĳ�ʼ������
                        c.Load_Init_Game();
                        //��ʼ��Ϸ
                        c.Game_Play();
                    }

                    //�༭��ͼ
                    else if (EDITGAME)
                    {
                        Flag = 0;
                   
                        system("cls");
                        //���Ƶ�ͼ
                        for (int i = 0; i < MAP_ROW; i++)
                        {
                            for (int j = 0; j < MAP_COL; j++)
                            {
                                if ((i == 0) || (j == 0) || (i == (MAP_ROW - 1)) || (j == (MAP_COL - 1)))
                                {
                                    Map[i][j] = OBSTACLES;
                                    Write_Char(i, j, "��");
                                }
                                else if (Map[i][j] == OBSTACLES)
                                    Write_Char(i, j, "��");
                               
                            }
                        }
                        //ui��Ϣ
                        Write_Char(35, 25, "����������");
                        Write_Char(35, 24, "����Ҽ��˳�");
                        Write_Char(35, 23, "���������ϰ�");
                        //�����ϰ�
                        MouseDraw();
                    }
                    else if (DOUBLEPLAY)
                    {
                        Flag = 0;
                        PlaySoundA(MUSICPATH, NULL, SND_ASYNC | SND_NODEFAULT);
                        system("cls");
                        //��ʼ����Ϸ
                        c.Restart_DoublePlayer_Game();
                        c.Init_Game_DoublePlayer();
                        //��Ϸ��ʼ
                        c.Game_Play_DoublePlayer();
                    }
                    else if (DOUBLCONTINUE)
                    {
                        Flag = 0;
                        PlaySoundA(MUSICPATH, NULL, SND_ASYNC | SND_NODEFAULT);
                        system("cls");
                        c.Load_Double_Game();
                        c.Load_Double_Init_Game();
                        c.Game_Play_DoublePlayer();
                    }
                    //�˳���Ϸ
                    else if (ENDGAME)
                    {
                        Flag = 0;
                        return 0;
                    }

                    
                }
            }
            //system("cls");
        }
        Flag = 1;
        system("cls");
    }
    //case LOADGAME:
    //    system("cls");
    //    //��ȡ��Ϸ
    //    c.Load_Game();
    //    //��ȡ��ĳ�ʼ������
    //    c.Load_Init_Game();
    //    //��ʼ��Ϸ
    //    c.Game_Play();
    //    break;
    //case EDITGAME:

    //    break;
    //case ENDGAME:

    //    break;
    //
    //system("cls");




//ShowWelcome();
//Sleep(400);
//system("cls");
//ShowMenu();
//system("pause");
//����CArea ����









//CSnake objsnake;
//objsnake.Draw_Snake();



 /*  objsnake.Move_Snack();*/
//objsnake.Remove_Snake();
//objsnake.Draw_Snake();

    return 0;
}