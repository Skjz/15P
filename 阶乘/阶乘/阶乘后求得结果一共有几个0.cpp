#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
    long long nNum = 0;
    int nCount = 0;
    printf("������һ��ϣ�����н׳˵�����:>");
    scanf_s("%d", &nNum);
    long long pow = 1;
    for (int i = 1; i <= nNum; i++)
    {
        pow *= i;
    }
    //ĩβ�м���0
    while (pow != 0)
    {
        if (pow % 10 == 0)
        {
            nCount++;
        }
        else
        {
            break;
        }
        pow = pow / 10;
    }

    //ȫ���м���0
    /* while (pow != 0)
     {
         if (pow % 10 == 0)
         {
             nCount++;
         }
         pow = pow / 10;
     }*/
    printf("��%d��0",nCount);


    return 0;
}