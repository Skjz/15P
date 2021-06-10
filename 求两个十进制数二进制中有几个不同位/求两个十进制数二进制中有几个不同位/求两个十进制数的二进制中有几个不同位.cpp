#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Count_Bit_One(int temp)
{
    int count = 0;
    while (temp)
    {
        temp = temp & (temp - 1);
        count++;
    }
    return count;
}
int Count_Differ(int a, int b)
{
    int ret = 0;
    int temp = a ^ b;
    ret = Count_Bit_One(temp);
    return ret;

}
int main()
{
    int nNum1 = 0;
    int nNum2 = 0;
    int ret = 0;
    printf("请输入两个数:>");

    scanf("%d%d", &nNum1,&nNum2);
    ret = Count_Differ(nNum1, nNum2);
    printf("两个数二进制位不同位有：%d", ret);
    
   
    return 0;
}