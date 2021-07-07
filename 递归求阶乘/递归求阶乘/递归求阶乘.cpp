#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Fac(int nNum)
{
    if (nNum == 0)
    {
        return 1;
    }
    return nNum *Fac(nNum-1);
   
  

}

int Count_Zero(int Ret)
{
    int nCount = 0;
    int Temp = 0;
    while (Ret != 0)
    {
        Temp =Ret % 10;
        if (Temp == 0)
        {
            nCount++;
        }
        Ret /= 10;
    }
    return nCount;
}

int main()
{

    int Ret = 0;
    Ret = Fac(5);
    printf("%d\n", Ret);
    int nCount = 0;
    nCount =Count_Zero(Ret);
    printf("%d\n", nCount);


    return 0;
}