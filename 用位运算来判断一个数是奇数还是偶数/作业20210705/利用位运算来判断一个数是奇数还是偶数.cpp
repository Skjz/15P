#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int main()
{
   //һ�����������������ô������λ���һλ��1��
    unsigned int nNum = 11;
    unsigned int Temp = 0;
    Temp = nNum << 31;
    if (Temp == 2147483648)
    {
        printf("����");
    }
    else
    {
        printf("ż��");
    }

    return 0;
}