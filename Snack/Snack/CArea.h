#pragma once
#include"CFood.h"
#include"CSnake.h"

class CArea
{   
  public:
    CArea();
    //��ʼ����Ϸ
    void Init_Game();
    void Init_Game_DoublePlayer();

    //��ʼ��Ϸ
    void Game_Play();
    void Game_Play_DoublePlayer();

    //�洢��Ϸ
    void Save_Game();
    void Save_Double_Game();

    //����
    void Load_Game();
    void Load_Double_Game();

    //�ؿ�
    void Restart_Game();
    //�ؿ�˫����Ϸ
    void Restart_DoublePlayer_Game();

    //��ȡ���ʼ����Ϸ
    void Load_Init_Game();
    void Load_Double_Init_Game();

    //��ʼ��ԭʼ��Ϸ
    void Init_Game_Org();

    

private:
    

    //ʳ�����
    CFood objFood;

    //�߶���
    CSnake objSnake;

    //�����������ʱ����
   vector <COORD> Temp_Snake;

   //����ʱ��Ԫ��
   COORD Temp_Ele;

   //����ʱ�ĳ���
   int Temp_Snake_Lenth;

   //�����ʱ�ķ���
   int Temp_Score;

   //��ʱ��ʳ���������
   int Temp_Food_Exist;

   //��ʱ���ٶ�
   int Temp_Speed;

   //��ʱ�ķ���
   int Temp_Dir;


    //��ʱ����ֵ
   int Temp_Life;
};

