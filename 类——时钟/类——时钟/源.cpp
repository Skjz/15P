#define _CRT_SECURE_NO_WARNINGS
#include"CTIME.h"
#include<stdio.h>
#include<stdlib.h>

int main()
{
    CTIME timer(3,20,5);
    timer.GetHour();
    timer.GetMinute();
    timer.GetSecond();
    return 0;
}
