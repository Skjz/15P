#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int nLine = 0;
    printf("������Ҫ��ӡ�������ϰ벿�ֵ�����\n");
    scanf_s("%d", &nLine);

    //�ϰ벿��
    for (int i=0;i<=nLine;i++)     
    {
        for (int j = 0; j < nLine - 1 - i; j++) //��ӡ�ո�
        {
            printf(" ");
        }
        for (int j = 0; j < 2 * i + 1; j++) //��ӡ*
        {
            printf("*");
        }
        printf("\n");
    }

    //�°벿��
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