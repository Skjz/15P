#define _CRT_SECURE_NO_WARNINGS
#include"mypassword.h"
void SeeAll(struct USERINFO* p)
{
    for (int i = 0; i < Count; i++)
    {
        printf("站点：%-1s\n", p[i].Website);
        printf("用户名：%-1s\n", p[i].Username);
        printf("密码：%-1s\n", p[i].Password);
        printf("-----------------------\n");
    }
}