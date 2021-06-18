#define _CRT_SECURE_NO_WARNINGS
//#define LENTH 10
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void My_Strcpy(char* Dst, const char* Src)
{
    assert(Src);
    assert(Dst);
    while (*Src != '\0')
    {
        *Dst = *Src;
        Dst++;
        Src++;
    }
}
int main()
{
    //char* c = (char*)"Hello 15PB";
    //char c2[] = "Hello 15PB";
   /* int arr[LENTH] = { 0 };
    for (int i = 0; i < LENTH; i++)
    {
        printf("请输入第%d个元素", i + 1);
        scanf("%d", &arr[i]);
    }
    int* p = arr;
    for (int i = 0; i < LENTH; i++)
    {
        printf("%d ", *(p + i));
    }*/
    //int(*ptoArr)[LENTH] = &arr;
    //for (int i = 0; i < LENTH; i++)
    //{
    //    printf("%d ", *(ptoArr + i));
    //}
    char str1[20] = { 0};
    char str2[20] = { "Hello" };
    My_Strcpy(str1, str2);
    printf("%s", str1);
    return 0;
}