#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void Bubble_Sort(int* arr)
{   
    for (int i = 0; i < 10-1 ; i++)
    {
        for (int j = 0; j < 10-i-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }

        }
    }
}
int main()
{
    int arr[10] = { 5,7,2,4,1,6,8,9,0,3 };
    Bubble_Sort(arr);
    for (int i = 0; i < 10; i++)
    {
        printf("%d", arr[i]);
    }


    return 0;
}