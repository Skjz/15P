#include "CArea.h"
#include"DrawBase.h"
#include<stdio.h>

CArea::CArea() 
{

}

//��ʼ����Ϸ
void CArea::Init_Game()
{
    //���Ƶ�ͼ�����������д���ϰ�����Ϣ
    //�ϰ�����Ϣ�����ж��Ƿ�ײ���ϰ���
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
            {
                Write_Char(i, j, "��");
            }
            else
            {
                Map[i][j] = EMPTYAREA;
            }
        }

    }
    //�����ߵ�ͼ��
    objSnake.Draw_Snake();


    //��ʼ��ʳ��
    objFood.Creat_Food();

    //ui��Ϣ
    Write_Char(35, 25, "��e�浵",15);
    Write_Char(35, 24, "��q��ͣ",15);
    Write_Char(35, 23, "����:",15);
    Write_Char(35, 26, "1p���� ��:w ��:s ��:a ��:d ");
}
//��ʼ����Ϸ
void CArea::Init_Game_DoublePlayer()
{
    //���Ƶ�ͼ�����������д���ϰ�����Ϣ
    //�ϰ�����Ϣ�����ж��Ƿ�ײ���ϰ���
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
            {
                Write_Char(i, j, "��");
            }
            else
            {
                Map[i][j] = EMPTYAREA;
            }
        }

    }
    //�����ߵ�ͼ��
    objSnake.Draw_Snake();
    objSnake.Draw_Enemy_Snake();


    //��ʼ��ʳ��
    objFood.Creat_Food();

    //ui��Ϣ
    Write_Char(35, 25, "��e�浵",15);
    Write_Char(35, 24, "��q��ͣ",15);
    Write_Char(35, 23, "1p����:",15);
    Write_Char(35, 22, "2p����:",15);
    Write_Char(35, 26, "2p���� ��:i ��:k ��:j ��:l");
    Write_Char(35, 27, "1p���� ��:w ��:s ��:a ��:d ");

}
void CArea::Init_Game_Org()
{
    //���Ƶ�ͼ�����������д���ϰ�����Ϣ
   //�ϰ�����Ϣ�����ж��Ƿ�ײ���ϰ���
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
            {
                Map[i][j] = EMPTYAREA;
            }
            else
            {
                Map[i][j] = EMPTYAREA;
            }
        }

    }
    //�����ߵ�ͼ��
    objSnake.Draw_Snake();


    //��ʼ��ʳ��
    objFood.Creat_Food();

    //ui��Ϣ
    Write_Char(35, 25, "��e�浵",15);
    Write_Char(35, 24, "��q��ͣ",15);
    Write_Char(35, 23, "����:",15);
    Write_Char(35, 26, "1p���� ��:w ��:s ��:a ��:d ");
}

//��ȡ��Ϸ���ٳ�ʼ��
void CArea::Load_Init_Game()
{
    //��ͼ��ʼ��
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
            {
                Write_Char(i, j, "��");
            }
            else if (Map[i][j] == PLAYER)
            {
                ;
            }
            else if (Map[i][j] == FOOD)
            {
                Write_Char(i, j, "��");
            }
            else if (Map[i][j] == SPEEDDOWNFOOD)
            {
                Write_Char(i, j, "��");
            }
            else
            {
                Map[i][j] = EMPTYAREA;
            }
        }

    }
    //�����ߵ�ͼ��

    objSnake.Draw_Snake();



    //ui��Ϣ
    Write_Char(35, 25, "��e�浵");
    Write_Char(35, 24, "��q��ͣ");
    Write_Char(35, 23, "����:");
    Write_Char(35, 26, "2p���� ��:i ��:k ��:j ��:l");
    Write_Char(35, 27, "1p���� ��:w ��:s ��:a ��:d ");


}

void CArea::Load_Double_Init_Game()
{
    //��ͼ��ʼ��
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
            {
                Write_Char(i, j, "��");
            }
            else if (Map[i][j] == PLAYER)
            {
                ;
            }
            else if (Map[i][j] == ENEMYPLAYER)
            {
                ;
            }
            else if (Map[i][j] == FOOD)
            {
                Write_Char(i, j, "��");
            }
            else if (Map[i][j] == SPEEDDOWNFOOD)
            {
                Write_Char(i, j, "��");
            }
            else
            {
                Map[i][j] = EMPTYAREA;
            }
        }

    }
    //�����ߵ�ͼ��

    objSnake.Draw_Snake();
    objSnake.Draw_Enemy_Snake();



    //ui��Ϣ
    Write_Char(35, 25, "��e�浵");
    Write_Char(35, 24, "��q��ͣ");
    Write_Char(35, 23, "1p����:");
    Write_Char(35, 22, "2p����:");
    Write_Char(35, 26, "2p���� ��:i ��:k ��:j ��:l");
    Write_Char(35, 27, "1p���� ��:w ��:s ��:a ��:d");





}

//�ؿ���Ϸ
void CArea::Restart_Game()
{
    //��ʳ���״̬�ٴα�Ϊ������
    objFood.Set_Food_Exist(0);
    //���´�������ص�����
    objSnake.RbuildSnake();
}
//�ؿ���Ϸ
void CArea::Restart_DoublePlayer_Game()
{
    //��ʳ���״̬�ٴα�Ϊ������
    objFood.Set_Food_Exist(0);
    //���´�������ص�����
    objSnake.RbuildSnake();
    objSnake.RbuildEnemySnake();
}



//��Ϸ��ʼ
void CArea::Game_Play()
{


    while (1)
    {
        //��ʾ����
        Write_Int(76, 23, objSnake.Get_Score());

        //���մ浵������
        int Select = 0;

        //����ʳ��
        objFood.Creat_Food();

        //�ߵ��ƶ�
        objSnake.Move_Snack();

        //������յ�e��ֱ�Ӵ浵����return������
        Select = objSnake.Get_Oper();
        if (Select == 'e')
        {
            Save_Game();
            return;
        }
        
        //�������ֵ��0��ֱ��return 
        if (objSnake.Get_Game_Life() == 0)
        {

            return;
        }
        //ˢ��ʳ���״��
        if (objSnake.Get_Temp_Count_Food() > objSnake.Get_m_Count_Food())
        {
            objFood.Set_Food_Exist(0);
            objSnake.Set_m_Count_Food(objSnake.Get_Temp_Count_Food());
        }

        //ˢ�·���
        if (objSnake.Get_Temp_Score() > objSnake.Get_Score())
        {
            objSnake.Set_Score(objSnake.Get_Temp_Score());
            Write_Char(38, 23, "                                    ");
            Write_Int(76, 23, objSnake.Get_Score());
        }
    }



}
//˫����Ϸ��ʼ
void CArea::Game_Play_DoublePlayer()
{


    while (1)
    {
        //��ʾ����
        Write_Int(76, 23, objSnake.Get_Score(), F_H_GREEN);
        Write_Int(76, 22, objSnake.Get_Enemy_Score(), F_H_GREEN);

        //���մ浵������
        int Select = 0;

        //����ʳ��
        objFood.Creat_Food();

        //�ߵ��ƶ�
        objSnake.Move_Double_Snake();
        //objSnake.Move_Enemy_Snack();

        //������յ�e��ֱ�Ӵ浵����return������
        Select = objSnake.Get_Oper();
        if (Select == 'e')
        {
            Save_Double_Game();
            return;
        }
        
        //�������ֵ��0��ֱ��return 
        if (objSnake.Get_Game_Life() == 0)
        {
            Write_Char(10,15,"2p���Ӯ");
            Sleep(1500);
            return;
        }
        if (objSnake.Get_Enemy_Game_Life() == 0)
        {
            Write_Char(10, 15, "1p���Ӯ");
            Sleep(1500);
            return;
        }
        //ˢ��ʳ���״��
        if (objSnake.Get_Temp_Count_Food() > objSnake.Get_m_Count_Food())
        {
            objFood.Set_Food_Exist(0);
            objSnake.Set_m_Count_Food(objSnake.Get_Temp_Count_Food());
        }
        if (objSnake.Get_Enemy_Temp_Count_Food() > objSnake.Get_Enemy_m_Count_Food())
        {
            objFood.Set_Food_Exist(0);
            objSnake.Set_Enemy_m_Count_Food(objSnake.Get_Enemy_Temp_Count_Food());
        }
        //ˢ�·���
        if (objSnake.Get_Temp_Score() > objSnake.Get_Score())
        {
            objSnake.Set_Score(objSnake.Get_Temp_Score());
            Write_Char(38, 23, "                                    ");
            Write_Int(76, 23, objSnake.Get_Score(), F_H_GREEN);
        }        
        if (objSnake.Get_Enemy_Temp_Score() > objSnake.Get_Enemy_Score())
        {
            objSnake.Set_Enemy_Score(objSnake.Get_Enemy_Temp_Score());
            Write_Char(38, 22, "                                    ");
            Write_Int(76, 22, objSnake.Get_Enemy_Score(), F_H_GREEN);
        }
    }



}

//�浵
void CArea::Save_Game()
{
    FILE* pFile = NULL;
    int nError = fopen_s(&pFile, PATH, "wb+");
    if (nError != NULL)
    {
        printf("�洢ʧ��!\n");
        system("pause");

        return;
    }
    //1 �洢��ͼ��Ϣ
    for (int i = 0; i < MAP_ROW; i++)
    {
        for (int j = 0; j < MAP_COL; j++)
        {
            if (pFile != 0)
            {
                fwrite(&Map[i][j], 1, sizeof(int), pFile);
            }
        }
    }

    //�洢����Ϣ

    //2.1 ��ȡ�ߵĳ���
    Temp_Snake_Lenth = objSnake.Get_Snake_Lenth();
    fwrite(&Temp_Snake_Lenth, 1, sizeof(int), pFile);
    //2.2 ����õ��ߵ�Ԫ�ط�����ʱ�Ľṹ����
    for (int i = 0; i < Temp_Snake_Lenth; i++)
    {
        Temp_Ele = objSnake.Get_Snake_Ele(i);


        //2.3 ����ʱ��Ԫ��push_back����ʱ�Ľṹ��������
        //Temp_Snake.push_back(Temp_Ele);

         //2.4 ����õ���ʱ�ṹ������д���ļ�
          fwrite(&Temp_Ele, 1, sizeof(COORD), pFile);
      
    }



    //3 �洢����
    Temp_Score = objSnake.Get_Score();
    fwrite(&Temp_Score, 1, sizeof(int), pFile);

    //4 �洢ʳ���״��
    Temp_Food_Exist = objFood.Get_Food_Exist();
    fwrite(&Temp_Food_Exist, 1, sizeof(int), pFile);


    //5 �洢�ٶ�
    Temp_Speed = objSnake.Get_Speed();
    fwrite(&Temp_Speed, 1, sizeof(int), pFile);

    //6 �洢�ߵķ���
    Temp_Dir = objSnake.Get_Dir();
    fwrite(&Temp_Dir, 1, sizeof(int), pFile);

    //7 �洢����
    Temp_Life = objSnake.Get_Game_Life();
    fwrite(&Temp_Life, 1, sizeof(int), pFile);
    fclose(pFile);

}
//����
void CArea::Load_Game()
{
    FILE* pFile = NULL;
    int Error = fopen_s(&pFile, PATH, "rb+");
    if (Error != 0)
    {
        return;
    }
    //1 ��ȡ��ͼ
    for (int i = 0; i < MAP_ROW; i++)
    {
        for (int j = 0; j < MAP_COL; j++)
        {
            if (pFile != 0)
            {
                fread(&Map[i][j], 1, sizeof(int), pFile);
            }
        }
    }

    //2.1 ��ȡ����
    if (pFile != 0)
    {
        fread(&Temp_Snake_Lenth, 1, sizeof(int), pFile);
    }

    //2.2 ��ȡ�ߵ�����

  

    objSnake.Dele_Snake_Ele();
    
    for (int i = 0; i < Temp_Snake_Lenth; i++)
    {
        fread(&Temp_Ele, 1, sizeof(COORD), pFile);
        objSnake.Push_Back_Snake(Temp_Ele);
    }



    //3 ��ȡ����
    fread(&Temp_Score, 1, sizeof(int), pFile);
    objSnake.Set_Score(Temp_Score);

    //4 ��ȡʳ���״��
    fread(&Temp_Food_Exist, 1, sizeof(int), pFile);
    objFood.Set_Food_Exist(Temp_Food_Exist);

    //5 ��ȡ�ٶ�
    fread(&Temp_Speed, 1, sizeof(int), pFile);
    objSnake.Set_Speed(Temp_Speed);

    //6 ��ȡ�ߵķ���
    fread(&Temp_Dir, 1, sizeof(int), pFile);
    objSnake.Set_Dir(Temp_Dir);

    //7 ��ȡ����
    fread(&Temp_Life, 1, sizeof(int), pFile);
    objSnake.Set_Snake_LIfe(Temp_Life);
    fclose(pFile);

}
//�洢˫����Ϸ
void CArea::Save_Double_Game()
{
    FILE* pFile = NULL;
    int nError = fopen_s(&pFile, PATHDouble, "wb+");
    if (nError != NULL)
    {
        return;
    }
    //1 �洢��ͼ��Ϣ
    for (int i = 0; i < MAP_ROW; i++)
    {
        for (int j = 0; j < MAP_COL; j++)
        {
            if (pFile != 0)
            {
                fwrite(&Map[i][j], 1, sizeof(int), pFile);
            }
        }
    }

    //�洢����Ϣ

    //2.1 ��ȡ�ߵĳ���
    Temp_Snake_Lenth = objSnake.Get_Snake_Lenth();
    fwrite(&Temp_Snake_Lenth, 1, sizeof(int), pFile);
    //2.2 ����õ��ߵ�Ԫ�ط�����ʱ�Ľṹ����
    for (int i = 0; i < Temp_Snake_Lenth; i++)
    {
        Temp_Ele = objSnake.Get_Snake_Ele(i);


        //2.3 ����ʱ��Ԫ��push_back����ʱ�Ľṹ��������
        //Temp_Snake.push_back(Temp_Ele);

         //2.4 ����õ���ʱ�ṹ������д���ļ�
        fwrite(&Temp_Ele, 1, sizeof(COORD), pFile);

    }

    //2.1.1 �洢�з��ߵĳ���
    Temp_Snake_Lenth = objSnake.Get_Enemy_Snake_Lenth();
    fwrite(&Temp_Snake_Lenth, 1, sizeof(int), pFile);

    //2.2.1 ����õ��ߵ�Ԫ�ط�����ʱ�Ľṹ����
    for (int i = 0; i < Temp_Snake_Lenth; i++)
    {
        Temp_Ele = objSnake.Get_Enemy_Snake_Ele(i);


         //2.4.1 ����õ���ʱ�ṹ������д���ļ�
        fwrite(&Temp_Ele, 1, sizeof(COORD), pFile);

    }

    //3 �洢����
    Temp_Score = objSnake.Get_Score();
    fwrite(&Temp_Score, 1, sizeof(int), pFile);  


    //3.1 �洢�з�����
    Temp_Score = objSnake.Get_Enemy_Score();
    fwrite(&Temp_Score, 1, sizeof(int), pFile);

    //4 �洢ʳ���״��
    Temp_Food_Exist = objFood.Get_Food_Exist();
    fwrite(&Temp_Food_Exist, 1, sizeof(int), pFile);


    //5 �洢�ٶ�
    Temp_Speed = objSnake.Get_Speed();
    fwrite(&Temp_Speed, 1, sizeof(int), pFile);  
    
    //5.1 �洢�з��ߵ��ٶ�
    Temp_Speed = objSnake.Get_Enemy_Speed();
    fwrite(&Temp_Speed, 1, sizeof(int), pFile);

    //6 �洢�ߵķ���
    Temp_Dir = objSnake.Get_Dir();
    fwrite(&Temp_Dir, 1, sizeof(int), pFile);    
    
    //6.1 �洢�з��ߵķ���
    Temp_Dir = objSnake.Get_Enemy_Dir();
    fwrite(&Temp_Dir, 1, sizeof(int), pFile);

    //7 �洢����
    Temp_Life = objSnake.Get_Game_Life();
    fwrite(&Temp_Life, 1, sizeof(int), pFile);   
    
    //7.1 �洢�з��ߵ�����
    Temp_Life = objSnake.Get_Enemy_Game_Life();
    fwrite(&Temp_Life, 1, sizeof(int), pFile);
    fclose(pFile);


}

//����˫����Ϸ
void CArea::Load_Double_Game()
{
    FILE* pFile = NULL;
    int Error = fopen_s(&pFile, PATHDouble, "rb+");
    if (Error != 0)
    {
        return;
    }
    //1 ��ȡ��ͼ
    for (int i = 0; i < MAP_ROW; i++)
    {
        for (int j = 0; j < MAP_COL; j++)
        {
            if (pFile != 0)
            {
                fread(&Map[i][j], 1, sizeof(int), pFile);
            }
        }
    }

    //2.1 ��ȡ����
    if (pFile != 0)
    {
        fread(&Temp_Snake_Lenth, 1, sizeof(int), pFile);
    }

   
    //2.2 ��ȡ�ߵ�����

    objSnake.Dele_Snake_Ele();

    for (int i = 0; i < Temp_Snake_Lenth; i++)
    {
        fread(&Temp_Ele, 1, sizeof(COORD), pFile);
        objSnake.Push_Back_Snake(Temp_Ele);
    }

    //2.2.1��ȡ�з��ߵĳ���
    fread(&Temp_Snake_Lenth, 1, sizeof(int), pFile);

   

    //2.2.2 ��ȡ�з��ߵ�����

    objSnake.Dele_Enemy_Snake_Ele();

    for (int i = 0; i < Temp_Snake_Lenth; i++)
    {
        fread(&Temp_Ele, 1, sizeof(COORD), pFile);
        objSnake.Push_Back_Enemy_Snake(Temp_Ele);
    }

    //3 ��ȡ����
    fread(&Temp_Score, 1, sizeof(int), pFile);
    objSnake.Set_Score(Temp_Score);    
    
    //3.1 ��ȡ�з��߷���
    fread(&Temp_Score, 1, sizeof(int), pFile);
    objSnake.Set_Enemy_Score(Temp_Score);

    //4 ��ȡʳ���״��
    fread(&Temp_Food_Exist, 1, sizeof(int), pFile);
    objFood.Set_Food_Exist(Temp_Food_Exist);   

    //5 ��ȡ�ٶ�
    fread(&Temp_Speed, 1, sizeof(int), pFile);
    objSnake.Set_Speed(Temp_Speed);    
    //5.1 ��ȡ�з��ٶ�
    fread(&Temp_Speed, 1, sizeof(int), pFile);
    objSnake.Set_Enemy_Speed(Temp_Speed);

    //6 ��ȡ�ߵķ���
    fread(&Temp_Dir, 1, sizeof(int), pFile);
    objSnake.Set_Dir(Temp_Dir); 
    //6.1 ��ȡ�з��ߵķ���
    fread(&Temp_Dir, 1, sizeof(int), pFile);
    objSnake.Set_Enemy_Dir(Temp_Dir);

    //7 ��ȡ����
    fread(&Temp_Life, 1, sizeof(int), pFile);
    objSnake.Set_Snake_LIfe(Temp_Life);    
    //7.1 ��ȡ����
    fread(&Temp_Life, 1, sizeof(int), pFile);
    objSnake.Set_Enemy_Snake_LIfe(Temp_Life);
    fclose(pFile);

}
