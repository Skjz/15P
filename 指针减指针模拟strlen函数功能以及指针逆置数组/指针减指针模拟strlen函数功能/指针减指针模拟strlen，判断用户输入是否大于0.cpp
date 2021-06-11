#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int My_Strlen(char* str)
{
    char* start = str;
    char* end = str;
    while (*end != '\0')
    {
        end++;
    }
    return end - start;
}
int main()
{
    //char cArr[] = { "Poter" };
    ///*printf("%d",My_Strlen(cArr));*/
    //scanf("%s", cArr);
    //printf("%s", cArr);
    double nNum = 1.0;
    int cilck = 1;
    while (cilck)
    {
        printf("请输入数字:<");
        double ret = 0;

        scanf_s("%lf", &nNum);

        ret = nNum;
        if (ret > 0 && ret < 1.0)
        {
            printf("输入错误，请重新输入！\n");
            cilck = 1;
        }
        else
        {
            cilck = 0;

        }

    }

        if (nNum > 0)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    return 0;
}