#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



int main()
{
   /* printf("1.��ʼ��Ϸ\n");
    printf("2.��Ϸ����\n");
    printf("3.�˳���Ϸ\n");
    int click = 1;
    int select = 0;
    while (click)
    {
        select = 0;
        printf("������:>");
        scanf("%d", &select);
        if (select > 3 || select < 0)
        {
            printf("��������\n");
        }
        else
        {
            click = 0;
        }
    }
    switch (select)
    {
    case 1:
        printf("1.��ʼ��Ϸ\n");
        break;
    case 2:
        printf("2.��Ϸ����\n");
        break;
    case 3:
        printf("3.�˳���Ϸ\n");
        break;

    }*/

    int nYear = 0;
    int nMonth = 0;
    printf("���������>:");
    scanf("%d", &nYear);
    printf("�������·�>:");
    scanf("%d", &nMonth);
    if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 100 == 0)
    {
        printf("%d������", nYear);
    }
    else
    {
        printf("%d��ƽ��", nYear);
    }
    if (nMonth >= 3 && nMonth <= 5)
    {
        printf(",�Ǵ���");
    }
    else if (nMonth >= 6 && nMonth <= 8)
    {
        printf(",������");
    }
    else if (nMonth >= 9 && nMonth <= 11)
    {
        printf(",������");
    }
    else if (nMonth == 12 || nMonth <= 2)
    {
        printf(",�Ƕ���");
    }
    if (nMonth == 1 || nMonth == 3 || nMonth == 5 || nMonth == 7 || nMonth == 8 || nMonth == 10 || nMonth == 12)//1,3,5,7,8,10,12
    {
        printf(",������31��");
    }
    if (nMonth == 4 || nMonth == 6 || nMonth == 9 || nMonth == 11)
    {
        printf(",������30��");
    }
    if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 100 == 0)
    {
        if (nMonth == 2)
        {
            printf(",������29��");
        }
    }
    else
    {
        if (nMonth == 2)
        {
            printf(",������28��");
        }
    }

        //4,6,9,11
    return 0;
}