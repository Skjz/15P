#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct STU
{
    int nScode;
    char szName[20];
    int nScore;

};
int main()
{
    STU S1 = { 0 };
    S1.nScode = 25;
    strcpy_s(S1.szName, 20, "liming");
    S1.nScore = 88;
    printf("ѧ��ѧ��:%d\n", S1.nScode);
    printf("ѧ������:%s\n", S1.szName);
    printf("ѧ������:%d", S1.nScore);

    return 0;
}

