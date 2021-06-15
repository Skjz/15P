#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>

void Exchange(int* p1, int* p2, int* p3)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2 - i -1; j++)
        {
            int temp = *p1;
            *p1 = *p2;
            *p2 = temp;
        }

    }
}
int main()
{
    int nNum1 = 0;
    int nNum2 = 0;
    int nNum3 = 0;
    int* pNum1 = &nNum1;
    int* pNum2 = &nNum2;
    int* pNum3 = &nNum3;
    scanf("%d%d%d", pNum1, pNum2, pNum3);
    Exchange(pNum1, pNum2, pNum3);
    printf("%d %d %d", *pNum1, *pNum2, *pNum3);

}




