#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
    /*  int nNum = 10;
      printf("%d", nNum);*/
    //int nNum = 10;
    //nNum += nNum;
    //printf("%d", nNum);
    int nInput = 0;
    printf("������һ��������:>");
    scanf_s("%d", &nInput);
    if (nInput <10 &&nInput>0 )
    {
        printf("yes");
    }
    else
    {
        printf("no");
    }

 /*   int nInput = 0;
    printf("������һ������:>");
    scanf_s("%d", &nInput);
    if ((nInput % 10 == 7) || (nInput %7 ==0))
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }*/
 /*   int nNum1 = 0;
    int nNum2 = 0;
    printf("����������1������2:>");
    scanf_s("%d%d", &nNum1,&nNum2);
    nNum1 = nNum1 ^ nNum2;
    nNum2 = nNum1 ^ nNum2;
    nNum1 = nNum1 ^ nNum2;
    printf("������: nNum1 =%d,nNum2 =%d", nNum1, nNum2);*/

    system("pause");
    return 0;
}