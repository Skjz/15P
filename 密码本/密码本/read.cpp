#define _CRT_SECURE_NO_WARNINGS
#include"mypassword.h"
void Read(struct USERINFO*p, int* Count)
{
    FILE* pFile = NULL;
    int Error = fopen_s(&pFile, PATH, "rb+");
    if (Error != 0)
    {
        p = (USERINFO*)malloc(Maxsize * sizeof(USERINFO));
        Maxsize = 5;
        *Count = 0;
        return;
    }
    int nNum = 0;
    assert(pFile);
    fread(&nNum, 4, 1, pFile);
    p = (USERINFO*)malloc(nNum * sizeof(USERINFO));
    *Count = nNum;

    for (int i = 0; i < *Count; i++)
    {
        fscanf_s(pFile, "%s\n", p[i].Website,20);
        fscanf_s(pFile, "%s\n", p[i].Username,20);
        fscanf_s(pFile, "%s\n", p[i].Password,20);
        /* fread(p[i].Website, 1, 20, pFile);
         fread(p[i].Username, 1, 20, pFile);
         fread(p[i].Password, 1, 20, pFile);*/
    }
  

    fclose(pFile);
}