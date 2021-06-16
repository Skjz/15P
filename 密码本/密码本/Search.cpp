#define _CRT_SECURE_NO_WARNINGS
#include"mypassword.h"
void Search(struct USERINFO* p)
{

    char TagWebsite[20] = { 0 };
    int i = 0;
    int nFound = 0;
    printf("请输入想搜索的站点:>");
    scanf_s("%s", TagWebsite, 20);
    for (; i < Count; i++)
    {
        if (0 == strcmp(TagWebsite, p[i].Website))
        {
            printf("站点:%s\n", p[i].Website);
            printf("用户名:%s\n", p[i].Username);
            printf("密码:%s\n", p[i].Password);
            nFound = 1;
            break;
        }

    }
    if (nFound != 1)
    {
        printf("查无此存储记录\n");
    }
}
