#define _CRT_SECURE_NO_WARNINGS
#include"mypassword.h"
void SeeAll(struct USERINFO* p)
{
    for (int i = 0; i < Count; i++)
    {
        printf("վ�㣺%-1s\n", p[i].Website);
        printf("�û�����%-1s\n", p[i].Username);
        printf("���룺%-1s\n", p[i].Password);
        printf("-----------------------\n");
    }
}