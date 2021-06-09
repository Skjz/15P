#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
    //double nDelta1 = 0;
    //double nDelta2 = 0;
    //double nDelta3 = 0;
    //printf("请输入三角形第一条边的长度:>");
    //scanf("%lf", &nDelta1);
    //printf("请输入三角形第二条边的长度:>");
    //scanf("%lf", &nDelta2);
    //printf("请输入三角形第三条边的长度:>");
    //scanf("%lf", &nDelta3);

    //if (nDelta1 == nDelta2 &&nDelta2 ==nDelta3)
    //{
    //    printf("是等边三角形\n");
    //}
    //else if (nDelta1 == nDelta2 || nDelta2 == nDelta3 || nDelta1 == nDelta3)
    //{
    //    printf("是等腰三角形\n");
    //}
    //else
    //{
    //    printf("是不等边三角形\n");
    //}
    //char cCh = '0';
    //printf("请输入一个字符>:");
    //scanf_s("%c", &cCh, 1);
    //if (cCh >= 65 && cCh <= 90)
    //{
    //    printf("大写字母\n");
    //}
    //else if (cCh >= 97 && cCh <= 122)
    //{
    //    printf("小写字母\n");
    //}
    //else
    //{
    //    printf("其他字符\n");
    //}
 /*   int nYear = 0;
    printf("请输入一个年份>:");
    scanf("%d", &nYear);

    if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
    {
        printf("是闰年\n");
    }
    else
    {
        printf("是平年\n");
    }*/

    //int nNum1 = 0;
    //int nNum2 = 0;
    //int nNum3 = 0;
    //printf("情输入第一个数>:");
    //scanf("%d", &nNum1);

    //printf("情输入第二个数>:");
    //scanf("%d", &nNum2);

    //printf("情输入第三个数>:");
    //scanf("%d", &nNum3);


    //int max = nNum1;
    //if (nNum2 > nNum1)
    //{
    //    max = nNum2;
    //}
    //if (nNum3 > nNum2)
    //{
    //    max = nNum3;
    //}
    //printf("最大的数字是%d", max);
    //for (int nNum = 1; nNum <= 100; nNum++)
    //{
    //    if (nNum % 9 == 2)
    //    {
    //        printf("%d\n", nNum);
    //    }
    //}
    int nNum1 = 0;
    int nNum2 = 0;
    int nNum3 = 0;
    printf("请输入第一个数字:>");
    scanf("%d", &nNum1);
    printf("请输入第二个数字:>");
    scanf("%d", &nNum2);
    printf("请输入第三个数字:>");
    scanf("%d", &nNum3);
    int min = 0;
    int mid = 0;
    int big = 0;
 
        if (nNum1 - nNum2 > 0 && nNum1 - nNum3 > 0)
        {
            big = nNum1;
        }
        else if (nNum2-nNum1>0 &&nNum2-nNum3>0)
        {
            big = nNum2;
        }
        else
        {
            big = nNum3;
        }
        
        if (nNum1 < big && nNum2 < big)
        {
            if (nNum1 < nNum2)
            {
                min = nNum1;
                mid = nNum2;
            }
            else
            {
                min = nNum2;
                mid = nNum1;
            }
        }
        else if (nNum1 < big && nNum3 < big)
        {
            if (nNum1 < nNum3)
            {
                min = nNum1;
                mid = nNum3;
            }
            else
            {
                min = nNum2;
                mid = nNum1;
            }
        }
        else if (nNum2 < big && nNum3 < big)
        {
            if (nNum2 < nNum3)
            {
                min = nNum2;
                mid = nNum3;
            }
            else
            {
                min = nNum3;
                mid = nNum2;
            }
        }
        printf("%d %d %d", min, mid, big);






    return 0;
}