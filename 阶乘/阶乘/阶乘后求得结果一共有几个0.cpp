#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
    long long nNum = 0;
    int nCount = 0;
    printf("请输入一个希望进行阶乘的数字:>");
    scanf_s("%d", &nNum);
    long long pow = 1;
    for (int i = 1; i <= nNum; i++)
    {
        pow *= i;
    }
    //末尾有几个0
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

    //全部有几个0
    /* while (pow != 0)
     {
         if (pow % 10 == 0)
         {
             nCount++;
         }
         pow = pow / 10;
     }*/
    printf("有%d个0",nCount);


    return 0;
}