#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"CRoundTable.h"

int main()
{
    CRoundTable t1;
    double dblArea = 0.0;
    double dblHeight = 0.0;
    dblArea = t1.Count_Area();
    t1.GetColor();
    dblHeight = t1.GetHeight();

    return 0;
}