#define _CRT_SECURE_NO_WARNINGS
//����è�ƶ���Animal�࣬����������è��(Cat)�ͱ���(Leopard)��
//���߶������麯�� roar(����)����Animal���ָ��ָ���������
//Ҫ��������������Ĳ�ͬ�����ø����ض����ĳ�Ա������
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