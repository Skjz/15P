#define _CRT_SECURE_NO_WARNINGS
//����һ��shape�����࣬��һ�����麯��Area()��������Rectangle(������)���
//Circle(Բ��)�࣬������������������Area()�����������Լ������ݳ�Ա��ʵ�ּ�������ķ�����
//����һ��ָ��t���飬����10��shape * Ԫ�أ������ָ�����new����Rectangle�������Circle����
//�ڳ�������ͨ������shapeָ�����飬���10��ͼ�ε������������
#include<stdio.h>

#include"CCircle.h"
#include"CShape.h"
#include"CRectangle.h"
#include<stdlib.h>
#include<time.h>


int main()
{   
    srand((unsigned int)time(NULL));
    CShape * pc[10] = { 0 };
    int Select = 0;
    for (int i = 0; i < 10; i++)
    {
        Select = rand() % 2 + 1;
        switch (Select)
        {
            case 1:
                pc[i] = new CCircle;
                break;
            case 2:
                pc[i] = new CRectangle;
                break;
        }
       
    }
   
    for (int i = 0; i < 10; i++)
    {
        pc[i]->Area();
    }

    for (int i = 0; i < 10; i++)
    {
        pc[i]->GetName();
        pc[i]->GetArea();
    }
      for (int i = 0; i < 10; i++)
      {
          delete pc[i];
      }
        
    return 0;
}
