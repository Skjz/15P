#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
double Pow(int n, int k)
{
    if (k < 0)
    {
        return (1 / Pow(n, -k));
    }
    else if (k==0)
    {
        return 1;
    }
    else
    {
        return n * Pow(n, k - 1);
    }
}

int main()
{
    int n = 0;
    int k = 0;
    printf("请输入底数:>");
    scanf("%d", &n);
    printf("请输入指数:>");
    scanf("%d", &k);

    double ret = Pow(n, k);
    printf("%lf", ret);


    return 0;
}