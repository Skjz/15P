#define _CRT_SECURE_NO_WARNINGS
//定义猫科动物Animal类，由其派生出猫类(Cat)和豹类(Leopard)，
//二者都包含虚函数 roar(咆哮)。用Animal类的指针指向子类对象。
//要求根据派生类对象的不同，调用各自重定义后的成员函数。
#include<stdio.h>
#include<stdlib.h>
#include"CAnimal.h"
#include"CCat.h"
#include"CLeopard.h"

int main()
{
    CAnimal* p = NULL;
    CCat c1;
    CLeopard l1;
    int Select = 0;
    scanf_s("%d", &Select);
    if (Select == 0)
    {
        p = &c1;
    }
    else
    {
        p = &l1;
    }

    p->roar();

    return 0;
}