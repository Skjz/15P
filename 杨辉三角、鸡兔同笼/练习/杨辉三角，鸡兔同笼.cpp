#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    //int nCount = 0;
    //do
    //{
    //    cout << nCount << endl;
    //    nCount++;
    //} while (nCount <= 100);
    // 
    //int arr[5] = { 3,6,5,8,10 };
    //int nChoose = 0;
    //int lenth = sizeof(arr) / sizeof(arr[0]);
    //scanf("%d", &nChoose);
    //int i = 0;
    //for (i = 0; i < lenth; i++)
    //{
    //    if (nChoose == arr[i])
    //    {
    //        printf("�������������%d��λ��", i + 1);
    //        break;
    //    }

    //}
    //if (nChoose != arr[lenth - 1] && i == lenth)
    //{
    //    cout << "no" << endl;
    //}

    

    //for (int i = 1; i <= 9; i++)
    //{
    //    for (int j = 1; j<=i; j++)
    //    {
    //        printf("%d*%d=%-3d ",j,i,j*i);
    //    }
    //    printf("\n");
    //}
  
    
    // ����ͬ��
    //int nCountRabbit = 0;
    //int nCountChicken = 0;
    //for (int nCountRabbit = 40; nCountRabbit >=0 ; nCountRabbit--)
    //{
    //    if (nCountRabbit + nCountChicken <= 40 && nCountRabbit * 4 + nCountChicken * 2 == 110)
    //    {
    //        printf("����%d,����%d", nCountChicken, nCountRabbit);
    //        break;
    //    }
    //    else
    //    {
    //        nCountChicken++;
    //    }
    //}
    //int arr[3][3] = { {1,2,3},
    //                  {4,5,6},
    //                  {7,8,9} };
    //for (int i = 0; i < 3; i++)
    //{
    //    for (int j = 0; j < 3; j++)
    //    {
    //        printf("%d", arr[i][j]);
    //    }
    //    printf("\n");
    // }
    //1
    //11
    //121
    //1331 
    //14641
    // i>1   j>=1 
    // 
    // 
    //ÿһ�е�һ���������һ��������1
    //��һ��ȫ����1
    //�ڶ��У���0��ʼ�Ų�һֱ��9
    //arr[i][j]=arr[i-1][j]+arr[i-1][j-1]
    
    //�������
    int arr[13][13];
    for (int i = 0; i < 13; i++)
    {
        arr[i][0] = 1;
        for (int j = 0; j <= i; j++)
        {
            arr[i][i] = 1;
            if (i > 1 && j >= 1 && i != j)
            {
                arr[i][j] = arr[i - 1][j] + arr[i-1][j - 1];
            }
            
            
        }
    }
    for (int i = 0; i < 13; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}