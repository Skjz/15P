#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

char* MyStrcpy(char* dst, const char* src)
{
    while (src != 0)
    {
        *dst = *src;
        src++;
        dst++;
    }
    *dst = 0;

    return dst;
}

int main()
{

    char* (*p)(char*,const  char*) = MyStrcpy;
    char* (*p[4])(char*, const char*) = {MyStrcpy};
    char dst =  '5' ;
    char src = '6';
    MyStrcpy(&dst, &src);



    return 0;
}