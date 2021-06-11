#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Reverse(int nArr[], int lenth)
{   
    int i = 0;
    while (&nArr[i] < &nArr[lenth - 1])
    {
        int temp = nArr[i];
        nArr[i] = nArr[lenth - 1];
        nArr[lenth-1] = temp;
        i++;
        lenth--;
    }
}

int main()
{
    int nArr[10] = { 0,1,2,3,4,5,6,7,8,9 };
    int lenth = sizeof(nArr) / sizeof(nArr[0]);
    Reverse(nArr,lenth);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", nArr[i]);
    }
 


    


    return 0;
}