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
            printf("登录成功\n");
            system("pause");
            break;
        }
        printf("输入错误\n");
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
            printf("请输入选择>:");
           flag = scanf_s("%d", &Select);
            getchar();
            if (flag == 0)
            {
                printf("输入错误\n");
            }
           
        }

        switch (Select)
        {
        case ADD:
        {   
            Add(&p);   
            break;
        }
        case CHANGE:                             //2.修改数据
        {
            Change(p);
            system("pause");
            break;
        }
        case DElE:                               //3.删除数据
        {
            Dele(p);
            system("pause");
            break;
        }
        case SERCH:                              //4.搜索数据
            Search(p);
            break;
        case SEEALL:                             //5.查看全部
        {   
            SeeAll(p);
            system("pause");
            break;
        }
        //case SAVE:                               //6.保存文件
        //    Save(p, Count);
        //    system("pause");
        //    break;
        case EXIT:        
            Incode(p,Count);
            Save(p, Count);
           
       /*     Save(p, Count);*/
            printf("谢谢使用!\n");
            system("pause");
            break;
        default:
            printf("输入错误");
            break;
            /*case 7:
                    printf("是否解密？输入除了0以外任意数字可以解密");
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