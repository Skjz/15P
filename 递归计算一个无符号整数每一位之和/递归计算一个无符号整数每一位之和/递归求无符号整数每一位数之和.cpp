#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Digit_Sum(int nNum)
{
    //int ret = nNum % 10;
   
    ////while (Digit_Sum(nNum))  //�����ڵݹ麯���Ŀ���·���д��ڵݹ麯���Һ����޷�����
    ////{
    ////    Digit_Sum(nNum / 10);
    ////}
    //
    //
    //return  ret;
    if (nNum > 9)
    {
        return Digit_Sum((nNum / 10) )+nNum% 10;
    }
    else
    {
        return nNum;
    }
}
int main()
{
    unsigned int nNum = 0;
    printf("������һ����>:");
    scanf("%d", &nNum);
    Digit_Sum(nNum);
    int ret = Digit_Sum(nNum);
    printf("%d", ret);

    return 0;
}