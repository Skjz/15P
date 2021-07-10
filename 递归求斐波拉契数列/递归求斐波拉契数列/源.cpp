#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int Fib(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    else
    {
        return Fib(n - 1) + Fib(n - 2);
    }
}
int main()
{
    int Result = Fib(20);
   


    return 0;
}