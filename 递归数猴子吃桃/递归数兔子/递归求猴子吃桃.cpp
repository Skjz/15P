#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//���ӳ�������:���ӵ�һ��ժ����ǧ�����ӣ���������һ�룬����񫣬�ֶ����һ����
//�ڶ��������ֽ�ʣ�µ����ӳԵ�һ�룬�ֶ����һ�����Ժ�ÿ�����϶�����ǰһ��ʣ�µ�һ����һ����
//����10���������ٳ�ʱ����ֻʣ��һ�������ˡ����һ�칲ժ�˶��١�
int Ret = 0;
int Num = 1;
int Count_Peach(int nDay)
{

    if (nDay == 0)
    {
        return 0;
    }
    else
    {
        Num = (1 + Num) * 2;
        Count_Peach(--nDay);
        return 1;
    }

}



int main()
{
    Count_Peach(10);
    printf("%d", Num);


    return 0;
}