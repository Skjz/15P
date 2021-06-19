#define _CRT_SECURE_NO_WARNINGS
#include"mypassword.h"
void Read(struct USERINFO** pp, int* Count)
{
    FILE* pFile = NULL;
    int Error = fopen_s(&pFile, PATH, "rb+");
    if (Error != 0)
    {
        *pp = (USERINFO*)malloc(Maxsize * sizeof(USERINFO));
        Maxsize = 5;
        *Count = 0;
        return;
    }
    int nNum = 0;
    int nSize = 0;
    assert(pFile);
    fread(&nNum, 4, 1, pFile);
    fread(&nSize, 4, 1, pFile);
    *Count = nNum;
    USERINFO *new_p = (USERINFO*)malloc((*Count) * sizeof(USERINFO));
    *pp = new_p;

    /*if (nSize != 0)
    {
        *Maxsize = nSize;
    }
    if (Count >= Maxsize)
    {
        USERINFO* new_p = NULL;
        new_p = (USERINFO*)malloc((*Maxsize) * 2 * sizeof(USERINFO));
        assert(new_p);
        memcpy(new_p, *pp, (*Maxsize) * sizeof(USERINFO));
        free(*pp);
        *pp = new_p;
        (*Maxsize) *= 2;
    }*/
    for (int i = 0; i < *Count; i++)
    {
        fscanf_s(pFile, "%s\n", (*pp)[i].Website,20);
        fscanf_s(pFile, "%s\n", (*pp)[i].Username,20);
        fscanf_s(pFile, "%s\n", (*pp)[i].Password,20);
       /* fscanf_s(pFile, "%s\n", p[i].Password,20);*/
        /* fread(p[i].Website, 1, 20, pFile);
         fread(p[i].Username, 1, 20, pFile);
         fread(p[i].Password, 1, 20, pFile);*/
    }

    fclose(pFile);
}