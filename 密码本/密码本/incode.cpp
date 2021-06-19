#define _CRT_SECURE_NO_WARNINGS
#include"mypassword.h"
void Incode(struct USERINFO *p,int Count)
{
    for (int i = 0; i < Count; i++)
    {
        for (int j=0; p[i].Password[j]!=0; j++)
        {
            p[i].Password[j] = p[i].Password[j] + 1;
        }
    }
}