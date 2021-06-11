#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



int main()
{
   /* printf("1.开始游戏\n");
    printf("2.游戏设置\n");
    printf("3.退出游戏\n");
    int click = 1;
    int select = 0;
    while (click)
    {
        select = 0;
        printf("请输入:>");
        scanf("%d", &select);
        if (select > 3 || select < 0)
        {
            printf("错误输入\n");
        }
        else
        {
            click = 0;
        }
    }
    switch (select)
    {
    case 1:
        printf("1.开始游戏\n");
        break;
    case 2:
        printf("2.游戏设置\n");
        break;
    case 3:
        printf("3.退出游戏\n");
        break;

    }*/

    int nYear = 0;
    int nMonth = 0;
    printf("请输入年份>:");
    scanf("%d", &nYear);
    printf("请输入月份>:");
    scanf("%d", &nMonth);
    if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 100 == 0)
    {
        printf("%d是闰年", nYear);
    }
    else
    {
        printf("%d是平年", nYear);
    }
    if (nMonth >= 3 && nMonth <= 5)
    {
        printf(",是春天");
    }
    else if (nMonth >= 6 && nMonth <= 8)
    {
        printf(",是夏天");
    }
    else if (nMonth >= 9 && nMonth <= 11)
    {
        printf(",是秋天");
    }
    else if (nMonth == 12 || nMonth <= 2)
    {
        printf(",是冬天");
    }
    if (nMonth == 1 || nMonth == 3 || nMonth == 5 || nMonth == 7 || nMonth == 8 || nMonth == 10 || nMonth == 12)//1,3,5,7,8,10,12
    {
        printf(",当月有31天");
    }
    if (nMonth == 4 || nMonth == 6 || nMonth == 9 || nMonth == 11)
    {
        printf(",当月有30天");
    }
    if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 100 == 0)
    {
        if (nMonth == 2)
        {
            printf(",当月有29天");
        }
    }
    else
    {
        if (nMonth == 2)
        {
            printf(",当月有28天");
        }
    }

        //4,6,9,11
    return 0;
}