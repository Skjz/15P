#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define PATH "..\\exteriment.txt"
struct BOOK
{
    char bookName[20];
    char authorName[20];
    float price;
}*PBook;
int main()
{
    BOOK books_input[2] = { {"查理三世","桑特",8.8},{"查拉图斯特拉如是说","尼采",32} };
    int ary_input[10] = { 1,2,3,4,5,6,7,8,9,10 };
    FILE* pFile = NULL;
    int Error = fopen_s(&pFile, PATH, "rb+");
    if (Error != 0)
    {
        system("pause");
    }
    fwrite(books_input, sizeof(BOOK), 1, pFile);
    fread(ary_input, sizeof(int), 10, pFile);
    printf("%s", ary_input);
    fclose(pFile);
    pFile = NULL;


    return 0;
}