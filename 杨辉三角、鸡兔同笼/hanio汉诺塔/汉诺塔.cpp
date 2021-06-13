#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
int i = 0;
void move(int n, char from, char to)
{
    printf("第%d步：将%d号盘子%c---->%c\n", i++, n, from, to);
}
void Hanio(int n, char start_pos, char tran_pos, char end_pos)
{
    if (n == 1)
    {
        move(n, start_pos, end_pos);
    }
    else
    {
        Hanio(n - 1, start_pos, end_pos, tran_pos);
        move(n, start_pos, end_pos);
        Hanio(n - 1, tran_pos, start_pos, end_pos);

    }

}

int main()
{
    int n = 4;
    char start_pos = 'a';
    char tran_pos = 'b';
    char end_pos = 'c';

    Hanio(n, start_pos, tran_pos, end_pos);
    

    return 0;
}