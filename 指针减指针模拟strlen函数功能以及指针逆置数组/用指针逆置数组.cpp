#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
    //int nNum = 0;
    //printf("����������");
    //scanf("%d", &nNum);
    //if (nNum%2==0)
    //{
    //    printf("yes\n");
    //}
    //else
    //{
    //    printf("no\n");
    //}
   /* int nDay = 0;
    int click = 1;
    int ret = 0;
    printf("����������1~7\n");
    while (click)
    {
        scanf("%d", &nDay);
        ret = nDay;
        {
            if (ret > 7 || ret < 0)
            {
                printf("�Ƿ�����");
                click = 1;
            }
            else
            {
                click = 0;
 }
        }
        
    }

    switch (nDay)
    {
        case 1:
            printf("����һ");
            break;
        case 2:
            printf("���ڶ�");
            break;

        case 3:
            printf("������");
            break;

        case 4:
            printf("������");
            break;

        case 5:
            printf("������");
            break;

        case 6:
            printf("������");
            break;

        case 7:
            printf("������");
            break;

        }*/

    //int nNum1 = 0;
    //int nNum2 = 0;
    //printf("��������������:\n");
    //scanf("%d%d", &nNum1,&nNum2);
    //

    //if (nNum1 > nNum2)
    //{
    //    printf("�ϴ�ֵ��%d", nNum1);
    //}
    //else if(nNum1<nNum2)
    //{
    //    printf("�ϴ�ֵ��%d", nNum2);
    //}
    //else
    //{
    //    printf("�������\n");
    //}

    //int a = 10;
    //a + 1;
    //printf("%d", a);

    //int arr[10] = { 0 };
    //for (int i = 0; i < 10; i++)
    //{
    //    printf("������� %d ������:>", i+1);
    //    scanf("%d", &arr[i]);
    //}
    //int sum = 0;
    //int average = 0;
    //int lenth = sizeof(arr) / sizeof(arr[0]);
    //for (int i = 0; i < 10; i++)
    //{
    //    sum += arr[i];
    //}
    //average = sum / lenth;
    //printf("%d", average);

    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int lenth = sizeof(arr) / sizeof(arr[0]);
    int* pBegin = &arr[0];
    int* pEnd = &arr[lenth-1];
    while (pBegin < pEnd)
    {
        int temp = *pBegin;
        (*pBegin) = (*pEnd);
        (*pEnd) = temp;
        pBegin++;
        pEnd--;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }




    
    return 0;
    }
