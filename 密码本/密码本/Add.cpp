#define _CRT_SECURE_NO_WARNINGS
#include"mypassword.h"
void Add(struct USERINFO** p)
{   
    if (Count == Maxsize)
    {
        USERINFO* new_p = (USERINFO*)malloc(Maxsize * 2 * sizeof(USERINFO));
        assert(new_p);
        memcpy(new_p, *p, Maxsize * sizeof(USERINFO));
        free(p);
        *p = new_p;
        Maxsize *= 2;
    }
    printf("������վ��:>");
    assert(p);
    scanf_s("%s", (*p)[Count].Website, 20);
    printf("�������û���:>");
    scanf_s("%s", (*p)[Count].Username, 20);
    printf("����������:>");
    scanf_s("%s", (*p)[Count].Password, 20);
    Count++;
   
        
}