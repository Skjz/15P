//#define _CRT_SECURE_NO_WARNINGS
#include "mypassword.h"

void Uncodepassword(struct USERINFO *p)
{   
    int j = 0;

    for (int i = 0; i < Count; i++)
    {
        while (p[i].Password[j] != 0)
        {
            (p[i].Password)[j] = (p[i].Password)[j] - 1;
            j++;
        }
    }
   


    //for (int i = 0; i < Count; i++)
    //{
    //    while (p[i].IncodePassword[j] != 0&& j<20)
    //    {
    //        (p[i].Password)[j] = (p[i].UncodePassword)[j];
    //        j++;
    //    }
    //}

}