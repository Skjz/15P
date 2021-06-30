#define _CRT_SECURE_NO_WARNINGS
//定义一个shape抽象类，有一个纯虚函数Area()，派生出Rectangle(正方形)类和
//Circle(圆形)类，计算各派生类对象的面积Area()，派生类有自己的数据成员和实现计算面积的方法。
//定义一个指针t数组，包含10个shape * 元素，并随机指向堆中new出的Rectangle对象或者Circle对象。
//在程序的最后通过遍历shape指针数组，输出10个图形的名称与面积。
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
