#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
    //double nDelta1 = 0;
    //double nDelta2 = 0;
    //double nDelta3 = 0;
    //printf("�����������ε�һ���ߵĳ���:>");
    //scanf("%lf", &nDelta1);
    //printf("�����������εڶ����ߵĳ���:>");
    //scanf("%lf", &nDelta2);
    //printf("�����������ε������ߵĳ���:>");
    //scanf("%lf", &nDelta3);

    //if (nDelta1 == nDelta2 &&nDelta2 ==nDelta3)
    //{
    //    printf("�ǵȱ�������\n");
    //}
    //else if (nDelta1 == nDelta2 || nDelta2 == nDelta3 || nDelta1 == nDelta3)
    //{
    //    printf("�ǵ���������\n");
    //}
    //else
    //{
    //    printf("�ǲ��ȱ�������\n");
    //}
    //char cCh = '0';
    //printf("������һ���ַ�>:");
    //scanf_s("%c", &cCh, 1);
    //if (cCh >= 65 && cCh <= 90)
    //{
    //    printf("��д��ĸ\n");
    //}
    //else if (cCh >= 97 && cCh <= 122)
    //{
    //    printf("Сд��ĸ\n");
    //}
    //else
    //{
    //    printf("�����ַ�\n");
    //}
 /*   int nYear = 0;
    printf("������һ�����>:");
    scanf("%d", &nYear);

    if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
    {
        printf("������\n");
    }
    else
    {
        printf("��ƽ��\n");
    }*/

    //int nNum1 = 0;
    //int nNum2 = 0;
    //int nNum3 = 0;
    //printf("�������һ����>:");
    //scanf("%d", &nNum1);

    //printf("������ڶ�����>:");
    //scanf("%d", &nNum2);

    //printf("�������������>:");
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
    //printf("����������%d", max);
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
    printf("�������һ������:>");
    scanf("%d", &nNum1);
    printf("������ڶ�������:>");
    scanf("%d", &nNum2);
    printf("���������������:>");
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