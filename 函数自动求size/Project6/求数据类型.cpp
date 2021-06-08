#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int Count_Size(char Arr[])
{
    if (strcmp(Arr, "int")==0)
    {
        return sizeof(int);
    }
    else if (strcmp(Arr,"float")==0)
    {
        return sizeof(float);
    }
    else
    {
        return sizeof(double);
    }
}

int main()
{
    char Arr[][30] = {"int","float","double" };
   /* int nType[3] = { 4,4,8 };*/
    for (int i = 0; i < 3; i++)
    {   
        printf("%s的大小是>:%d\n", Arr[i], Count_Size(Arr[i]));
    }


    return 0;
}