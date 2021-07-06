#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main()
{
   //一个数如果是奇数，那么二进制位最后一位是1。
    unsigned int nNum = 11;
    unsigned int Temp = 0;
    Temp = nNum << 31;
    if (Temp == 2147483648)
    {
        printf("奇数");
    }
    else
    {
        printf("偶数");
    }

    return 0;
}