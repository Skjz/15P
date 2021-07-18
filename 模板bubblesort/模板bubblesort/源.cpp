#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

template <typename T>
void BubbleSort(T* arr, int nLenth)
{
    for (int i = 0; i < nLenth - 1; i++)
    {
        for (int j = 0; j < nLenth - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

            }

        }
    }

}
int main()
{
    int arr[10] = { 9,8,7,6,5,4,3,2,1 };
    int nLenth = sizeof(arr) / sizeof(arr[0]);
    BubbleSort(arr, nLenth);
    for (int i = 0; i < nLenth; i++)
    {
        printf("%d", arr[i]);
    }

    return 0;
}