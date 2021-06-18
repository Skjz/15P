#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define PATH "..\\test.txt"
int main()
{
    FILE *pFile = NULL;
    int Error = fopen_s(&pFile,PATH,"rb+");
    if (Error != 0)
    {
        system("pause");
    }
    char str[20] = { "hello"};
    assert(pFile);
    fprintf(pFile, "%s\n",str);
    fclose(pFile);
    pFile = NULL;

    Error = fopen_s(&pFile, PATH, "rb+");
    if (Error != 0)
    {
        system("pause");
    }
    char str2[20] = { 0 };
    assert(pFile);
    fscanf_s(pFile, "%s\n", str2, 20);
    printf("%s", str2);
    fclose(pFile);
    pFile = NULL;





    return 0;
}