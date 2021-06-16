#define _CRT_SECURE_NO_WARNINGS
#include"mypassword.h"


void Change(struct USERINFO *p)
{

    char TagWebsite[20] = { 0 };
    int i = 0;
    int nFound = 0;
    printf("请输入想搜索的站点:>");
    scanf_s("%s", TagWebsite, 20);
    for (; i < Count; i++)
    {
        if (0 == strcmp(TagWebsite,p[i].Website))
        {
            printf("站点:%s\n", p[i].Website);
            printf("用户名:%s\n", p[i].Username);
            printf("密码:%s\n", p[i].Password);
            nFound = 1;
            break;
        }

    }
    if (nFound == 0)
    {
        printf("查无此存储记录\n");
    }
    else
    {
        printf("请输入站点:>");
        scanf_s("%s", p[i].Website, 20);
        printf("请输入用户名:>");
        scanf_s("%s", p[i].Username, 20);
        printf("请输入密码:>");
        scanf_s("%s", p[i].Password, 20);
    }
}