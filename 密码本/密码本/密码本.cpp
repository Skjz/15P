#define _CRT_SECURE_NO_WARNINGS
#include "mypassword.h"
//using namespace std;
#define ADD 1
#define CHANGE 2
#define DElE 3
#define SERCH 4
#define SEEALL 5
#define SAVE 6
#define EXIT 0
int Count = 0;
int Maxsize = 5;
char Account[20] = { "lixiang" };
char ThisPassword[20] = { "1234567" };
//Incode* cp = (Incode*)malloc(Maxsize * sizeof(Incode));
USERINFO* p = (USERINFO*)malloc(Maxsize * sizeof(USERINFO));

int main()
   
{
   
    USERINFO MyAll = { 0 };
    int Select = 1;
    Read(&p,&Count);
   
    int ret = 1;
    while (1)
    {
        ret = Login(Account, ThisPassword);
        if (ret == 0)
        {
            printf("��¼�ɹ�\n");
            system("pause");
            break;
        }
        printf("�������\n");
        system("pause");
    }
    system("cls");
    Uncodepassword(p);
    while (Select)
    {   
        ShowMenu();
        int flag = 0;
        while (flag == 0)
        {
            printf("������ѡ��>:");
           flag = scanf_s("%d", &Select);
            getchar();
            if (flag == 0)
            {
                printf("�������\n");
            }
           
        }

        switch (Select)
        {
        case ADD:
        {   
            Add(&p);   
            break;
        }
        case CHANGE:                             //2.�޸�����
        {
            Change(p);
            system("pause");
            break;
        }
        case DElE:                               //3.ɾ������
        {
            Dele(p);
            system("pause");
            break;
        }
        case SERCH:                              //4.��������
            Search(p);
            break;
        case SEEALL:                             //5.�鿴ȫ��
        {   
            SeeAll(p);
            system("pause");
            break;
        }
        //case SAVE:                               //6.�����ļ�
        //    Save(p, Count);
        //    system("pause");
        //    break;
        case EXIT:        
            Incode(p,Count);
            Save(p, Count);
           
       /*     Save(p, Count);*/
            printf("ллʹ��!\n");
            system("pause");
            break;
        default:
            printf("�������");
            break;
            /*case 7:
                    printf("�Ƿ���ܣ��������0�����������ֿ��Խ���");
                    scanf_s("%d", &incodechoose);
                    if (incodechoose != 0)
                    {
                        Uncodepassword(cp);
                        flag = 1;
                    }
                    else
                    {
                        break;
                    }*/

        }
        system("cls");
    }




    return 0;


    /*      if (Count == Maxsize)
      {
          USERINFO* new_p = NULL;
          new_p = (USERINFO*)malloc(Maxsize * 2 * sizeof(USERINFO));
          assert(new_p);
          memcpy(new_p, p, Maxsize * sizeof(USERINFO));
          free(p);
          p = new_p;
          Maxsize *= 2;
      }*/


}