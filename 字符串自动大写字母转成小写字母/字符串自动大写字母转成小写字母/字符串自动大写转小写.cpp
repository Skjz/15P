#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char chArr[100] = {'0'};
    printf("ÇëÊäÈë×Ö·û´®:>");
    scanf_s("%s", &chArr, 100);
    for (int i = 0; i < 100; i++)
    {
        if (chArr[i] >= 65 && chArr[i] <= 90)
        {
            chArr[i] += 32;
        }
    }
    printf("×ª»»ºó£º%s", chArr);
    

    return 0;
}