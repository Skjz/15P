#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//void Print_Hello()
//{
//    printf("Hello15PB\n");
//}
//void Get_Address(int nNum)
//{
//    printf("被调函数中的地址:%x", &nNum);
//}
//int Is_Prime(int nNum)
//{
//    int    i = 0;
//    for (i = 2; i <= nNum- 1; i++)
//
//    {
//
//        if (nNum % i == 0)
//
//        {
//
//            break;
//
//        }
//
//    }
//
//    if (i == nNum)
//
//    {
//
//        
//        return 1;
//
//    }
//
//    else
//
//    {
//
//        
//        return 0;
//    }
//
//}
void Exchange(int* nNum1, int* nNum2, int* nNum3)
{
    int* ret = nNum1;
    for (int i = 0; i <= 1; i++)
    {
        for (int j = 0; j <= 1; j++)
        {
            if (*nNum1 > *nNum2)
            {
                int* temp = nNum1;
                nNum1 = nNum2;
                nNum2 = temp;

            }
            else if (*nNum1 > *nNum3)
            {
                int* temp = nNum1;
                nNum1 = nNum3;
                nNum3 = temp;
            }
            if (*nNum2 > *nNum3)
            {
                int* temp = nNum2;
                nNum2 = nNum3;
                nNum3 = temp;
            }


        }


    }



int main()
{
  
    //int i = 0;
    //int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
    //for (i = 0; i <= 12; i++)
    //{
    //    printf("hehe\n");
    //    arr[i] = 0;
    //}
    //system("pause");
    /*void Print_Hello();*/
    
    /*   printf("主调函数中的地址:%x", &nNum);
       Get_Address(nNum);*/
    //int nNum1 = 0;
    //int nNum2 = 0;
    //int nNum3 = 0;
    //int* pNum1 = &nNum1;
    //int* pNum2 = &nNum2;
    //int* pNum3 = &nNum3;
    int arr[3] = { 0 };
    int* pNum1 = &arr[0];
    int* pNum2 = &arr[1];
    int* pNum3 = &arr[2];
    printf("请输入数字1:>");
    scanf("%d", pNum1);
    printf("请输入数字2:>");
    scanf("%d", pNum2);
    printf("请输入数字3:>");
    scanf("%d", pNum3);
    Exchange(pNum1, pNum2, pNum3);
    printf("%d%d%d", *pNum1, *pNum2,*pNum3);
    return 0;
}