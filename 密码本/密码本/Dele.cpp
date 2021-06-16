#define _CRT_SECURE_NO_WARNINGS
#include"mypassword.h"
void Dele(struct USERINFO* p)
{
    char TagWebsite[20] = { 0 };
    int i = 0;
    int nFound = 0;
    printf("请输入想删除的站点:>");
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
    else
    {
        printf("确认删除吗\n");
        system("pause");
        for (; i < Count - 1; i++)
        {
            p[i] = p[i + 1];
        }
        Count--;
        printf("删除成功\n");
    }
}