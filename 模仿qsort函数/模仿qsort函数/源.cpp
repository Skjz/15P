#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Swap(char* buff1, char* buff2,int width)
{
    for (int i = 0; i < width; i++)
    {
        char temp = *buff1;
        *buff1 = *buff2;
        *buff2 = temp;
        buff1++;
        buff2++;
    }
}
void BubbleSort(void* base, int lenth, int width, int(*cmp)(void* e1, void* e2))
{
    for (int i = 0; i < lenth - 1; i++)
    {
        for (int j = 0; j < lenth - 1 - i; j++)
        {
            if (cmp((char*)base+j*width, (char*)base + (j + 1) * width)>0)
            {
                Swap((char*)base+j*width ,(char*)base + (j + 1) * width,width);
            }
        }
    }

}

int Cmp_int( void *e1, void *e2)
{
    return *(int*)e1 - *(int*)e2;
}

int main()
{
    int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
    int lenth = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, lenth, sizeof(arr[0]), Cmp_int);
    for (int i = 0; i < lenth; i++)
    {
        printf("%d ", arr[i]);
    }


    return 0;
}