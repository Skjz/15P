
#include<time.h>
#include "CFood.h"
#include"DrawBase.h"
CFood::CFood():Food_Exist(0),Food_Type(0)
{

}
void CFood::Creat_Food()
{
    //���������
    srand((unsigned int)time(NULL));

    //�ж�ʳ���Ƿ���Ҫ���ɣ����Food_Exist��0����Ӧ������ʳ��
    if (Food_Exist == 0)
    {
        //����ѭ����ֱ���ܹ�����ʳ����˳�
        while(true)
      { 
        //������һ������
        int Food_X = rand() % 28 + 1;
        int Food_Y = rand() % 28 + 1;
        Food_Type = rand() % 70;

        //���ȷ����������ǿյ��������ٵ�ʳ��
        if (Map[Food_X][Food_Y] == EMPTYAREA && Food_Type>=15)
        {
            Write_Char(Food_X, Food_Y, "��");  //��ͼ������ʾʳ��
            Map[Food_X][Food_Y] = FOOD;       //�����λ�õĵ�ͼ��Ϣ�༭Ϊʳ��
            Food_Exist = 1;  
            break;                            //����ѭ��
        }
        //���ȷ����������ǿյ����Ǽ���ʳ��
        else if (Map[Food_X][Food_Y] == EMPTYAREA && Food_Type <15)
        {

            Write_Char(Food_X, Food_Y, "��");
            Map[Food_X][Food_Y] = SPEEDDOWNFOOD;
            Food_Exist = 1;
            break;
        }
      }

    }
}

//����ʳ���Ƿ����
void CFood::Set_Food_Exist(int Is_Exist)
{
    Food_Exist = Is_Exist;

}

//�õ�ʳ���Ƿ����
int CFood::Get_Food_Exist()
{
    return  Food_Exist;
}

//����ʳ���Ƿ����
//void CFood::Set_Food_Exist(int Temp_Food_Exist)
//{
//    Food_Exist = Temp_Food_Exist;
//}
