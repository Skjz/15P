#define _CRT_SECURE_NO_WARNINGS
#include "mypassword.h"
#define ADD 1
#define CHANGE 2
#define DElE 3
#define SERCH 4
#define SEEALL 5
#define SAVE 6
#define EXIT 0
int Count = 0;
int Maxsize = 5;
USERINFO* p = (USERINFO*)malloc(Maxsize * sizeof(USERINFO));
USERINFO* new_p = NULL;

int main()
{
    USERINFO MyAll = { 0 };

    int Select = 1;
    while (Select)
    {
        ShowMenu();
        printf("请输入选择>:");
        scanf_s("%d", &Select);
        switch (Select)
        {
        case ADD:
        {
            if (Count == Maxsize)
            {
                USERINFO* new_p = NULL;
                new_p = (USERINFO*)malloc(Maxsize * 2 * sizeof(USERINFO));
                assert(new_p);
                memcpy(new_p, p, Maxsize * sizeof(USERINFO));
                free(p);
                p = new_p;
                Maxsize *= 2;
            }
           /* Check(p, new_p);*/
            Add(p);
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
        case SAVE:                               //6.保存文件

            break;
        case EXIT:                               //0.退出程序
            printf("谢谢使用!\n");
            break;
        }
        system("cls");
    }





}