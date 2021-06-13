#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int My_Strlen(char* str)
{
    if (*(str) != '\0')
    {
        return 1 + My_Strlen(str + 1);
    }
    else
    {
        return 0;
    }

}
int main()
{
    char str[20] = { "Hello World" };
    int ret = 0;
    ret = My_Strlen(str);
    printf("%d", ret);

    return 0;
}