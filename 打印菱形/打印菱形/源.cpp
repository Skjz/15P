#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int nLine = 0;
    printf("请输入要打印的菱形上半部分的行数\n");
    scanf_s("%d", &nLine);

    //上半部分
    for (int i=0;i<=nLine;i++)     
    {
        for (int j = 0; j < nLine - 1 - i; j++) //打印空格
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) //打印*
        {
            printf("*");
        }
        printf("\n");
    }

    //下半部分
    for (int i = 0; i <= nLine - 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * (nLine - 1 - i) - 1; j++)
        {
            printf("*");
        }
        printf("\n");

    }

    return 0;
}