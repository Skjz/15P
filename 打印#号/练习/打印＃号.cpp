#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i = 0;
    int j = 0;  
    int nNum = 0;
   
   
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j <=i+nNum; j++)
        {
            printf("#");
        }
        nNum++;
        printf("\n");
    }

    return 0;
}



