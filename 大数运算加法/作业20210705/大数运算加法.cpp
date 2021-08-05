#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//struct Person
//{
//    unsigned int Gender : 1;
//    unsigned int Blood_Type : 4;
//    unsigned int AQ : 8;
//    unsigned int Color : 3;
//};

int main()
{
    int Turn1[100] = { 0 };
    int Turn2[100] = { 0 };
    int TurnSum[100] = { 0 };

    char Num1[10] = "12345678";
    char Num2[10] = "87654321";
    int nLenth1 = 0;
    int nLenth2 = 0;
    int nLenth = 0;
    nLenth1 = strlen(Num1);
    nLenth2 = strlen(Num2);
    int j = 0;
    for (int i = nLenth1-1; i >=0; i--)
    {
        Turn1[j] = Num1[i]-'0';
        j++;

    }
    int k = 0;
    for (int i =nLenth2-1 ; i >=0; i--)
    {
        Turn2[k] = Num2[i] - '0';
        k++;

    }
    if (nLenth1 > nLenth2)
    {
        nLenth = nLenth1;
    }
    else if (nLenth2 > nLenth1)
    {
        nLenth = nLenth2;
    }
    else
    {
        nLenth = nLenth1;
    }
    int m = 0;
    for (int i = 0; i < nLenth; i++)
    {
        TurnSum[i] = (Turn1[i] + Turn2[i] + m) % 10;
        if (Turn1[i] + Turn2[i]+m >= 10)
        {
            m = 1;
        }
        else
        {
            m = 0;
        }
    }
    //int i = nLenth - 1;
    //if (Turn1[i - 1] + Turn2[i - 1] + m >= 10)
    //{
    //    TurnSum[i] = 1;
    //}
    //else
    //{
    //    i = i - 1;
    //}
    for (int i=nLenth-1; i >= 0; i--)
    {
        printf("%d", TurnSum[i]);
    }
    
    //int nNum = 0x3085CDCF;

    //int nNum2 = 0x1B00;
    //int Result = nNum ^ nNum2;
    //printf("%b", Result);
  

    return 0;
}