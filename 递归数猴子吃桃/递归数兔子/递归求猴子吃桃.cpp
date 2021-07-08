#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//猴子吃桃问题:猴子第一天摘下若千个桃子，当即吃了一半，还不瘾，又多吃了一个，
//第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃了前一天剩下的一半零一个。
//到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少。
int Ret = 0;
int Num = 1;
int Count_Peach(int nDay)
{

    if (nDay == 0)
    {
        return 0;
    }
    else
    {
        Num = (1 + Num) * 2;
        Count_Peach(--nDay);
        return 1;
    }

}



int main()
{
    Count_Peach(10);
    printf("%d", Num);


    return 0;
}