#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
    char nArr[10] = { 0 };
    printf("ÇëÊäÈëÊý×Ö>:");
    scanf_s("%s", nArr, 10);
    for (int i = 0; i < 10; i++)
    {
        if (nArr[i] == '0')
        {
            printf("zero ");
        }
        else if (nArr[i] == '1')
        {
            printf("one ");
        }
        else if (nArr[i] == '2')
        {
            printf("two ");
        }
        else if (nArr[i] == '3')
        {
            printf("three ");
        }
        else if (nArr[i] == '4')
        {
            printf("four ");
        }
        else if (nArr[i] == '5')
        {
            printf("five ");
        }
        else if (nArr[i] == '6')
        {
            printf("six ");
        }
        else if (nArr[i] == '7')
        {
            printf("seven ");
        }
        else if (nArr[i] == '8')
        {
            printf("eight ");
        }
        else if (nArr[i] == '9')
        {
            printf("nine ");
        }
    }
    return 0;
}