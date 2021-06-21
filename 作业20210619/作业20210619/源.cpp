#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

//void Change_Stu(struct STU *s)
//{
//    strcpy_s(s->sName, "xiaohong");
//    s->sCode = 18;
//    s->sScore = 100;
//
//}
struct STU
{
    char sName[20];
    int  sCode;
    int sScore;

};
int main()
{

    STU* s = NULL;
    
    s =(STU*) malloc(sizeof(STU) * 20);
    assert(s);
    for (int i = 0; i < 20; i++)
    {
        printf("请输入姓名");
        scanf_s("%s", &s[i].sName,20);
        printf("请输入学号");
        scanf_s("%d", &s[i].sCode);
        printf("请输入分数");
        scanf_s("%d", &s[i].sScore);

    }


    /*  int nSize = 0;
      int sum = 0;
      int* p = NULL;
      printf("输入需要的元素个数:>");
      scanf_s("%d", &nSize);
      p = (int*)malloc(nSize * sizeof(int));
      for (int i = 0; i < nSize; i++)
      {
          scanf_s("%d", (p + i));
      }
      for (int i = 0; i < nSize; i++)
      {
           sum += *(p + i);
      }
      printf("%d", sum);*/

    //STU s = { "xiaoming",15,95 };
    //Change_Stu(&s);
    //printf("%s\n",s.sName);
    //printf("%d\n", s.sCode);
    //printf("%d\n", s.sScore);
    //STU s[10] = { 0 };
    //for (int i = 0; i < 10; i++)
    //{
    //    printf("请输入姓名");
    //    scanf_s("%s", &s[i].sName,20);
    //    printf("请输入学号");
    //    scanf_s("%d", &s[i].sCode);
    //    printf("请输入分数");
    //    scanf_s("%d", &s[i].sScore);


    //}
    ////STU s = { "xiaoming",15,95 };
   /* system("pause");*/
    //for (int i = 0; i < 101; i++)
    //{
    //    if (i % 8 == 2)
    //    {
    //        printf("%d ", i);
    //    }
    //}
  /*  int arr[6] = { 22,54,66,87,98,25 };
    for (int i = 3; i < 5;i++)
    {
        arr[i] = arr[i+1] ;
    }
    arr[5] = 0;
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0]));  i++)
    {
        printf("%d ", arr[i]);
    }*/

    return 0;
}