#define _CRT_SECURE_NO_WARNINGS
#include"mypassword.h"
void Add(struct USERINFO** pp)
{   
    if (Count == Maxsize)
    {
        USERINFO* new_p = NULL;
        new_p = (USERINFO*)malloc(Maxsize * 2 * sizeof(USERINFO));
        assert(new_p);
        memcpy(new_p, *pp, Maxsize * sizeof(USERINFO));
        free(*pp);
        *pp = new_p;
        Maxsize *= 2;
    }
    printf("请输入站点:>");
    scanf_s("%s", (*pp)[Count].Website, 20);
    printf("请输入用户名:>");
    scanf_s("%s", (*pp)[Count].Username, 20);
    printf("请输入密码:>");
    scanf_s("%s", (*pp)[Count].Password, 20);
    int i = 0;
  
    /*p[Count].IncodePassword[i + 1] = '\0';*/
   /*  if (Count == Maxsize)
     {
         Incode* new_cp = NULL;
         new_cp = (Incode*)malloc(Maxsize * 2 * sizeof(USERINFO));
         assert(new_cp);
         memcpy(new_cp, cp, Maxsize * sizeof(Incode));
         free(cp);
         cp = new_cp;
         Maxsize *= 2;
     }*/

    
    Count++;
   
        
}