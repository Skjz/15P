#define _CRT_SECURE_NO_WARNINGS
#include"mypassword.h"
void Save(struct USERINFO* p, int Count)
{

    FILE* pFile = NULL;
    int Error = fopen_s(&pFile, PATH, "wb+");
    if (Error != 0)
    {
        printf("–¥»Î ß∞‹");
        system("pause");
        return;
    }

    assert(pFile);
    fwrite(&Count, 4, 1, pFile);
    fwrite(&Maxsize, 4, 1, pFile);
    int i = 0;
    int j = 0;

    for (int i = 0; i < Count; i++)
    {
        fprintf(pFile, "%s\n", p[i].Website);
        fprintf(pFile, "%s\n", p[i].Username);
        fprintf(pFile, "%s\n", p[i].Password);

        /*   fwrite(p[i].Website, Maxsize, sizeof(USERINFO), pFile);
           fwrite(p[i].Password, Maxsize, sizeof(USERINFO), pFile);
           fwrite(p[i].Username, Maxsize, sizeof(USERINFO), pFile);*/
    }

    printf("¥Ê¥¢≥…π¶\n");
    fclose(pFile);

}