#define _CRT_SECURE_NO_WARNINGS
#include"mypassword.h"
void Dele(struct USERINFO* p)
{
    char TagWebsite[20] = { 0 };
    int i = 0;
    int nFound = 0;
    printf("��������ɾ����վ��:>");
    scanf_s("%s", TagWebsite, 20);
    for (; i < Count; i++)
    {
        if (0 == strcmp(TagWebsite, p[i].Website))
        {
            printf("վ��:%s\n", p[i].Website);
            printf("�û���:%s\n", p[i].Username);
            printf("����:%s\n", p[i].Password);
            nFound = 1;
            break;
        }

    }
    if (nFound != 1)
    {
        printf("���޴˴洢��¼\n");
    }
    else
    {
        printf("ȷ��ɾ����\n");
        system("pause");
        for (; i < Count - 1; i++)
        {
            p[i] = p[i + 1];
        }
        Count--;
        printf("ɾ���ɹ�\n");
    }
}