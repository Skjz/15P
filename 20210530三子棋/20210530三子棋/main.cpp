#define  _CRT_SECURE_NO_WARNINGS

#include"game.h"
void menu()
{
    printf("********************\n");
    printf("*****1.��ʼ��Ϸ*****\n");
    printf("*****0.�˳���Ϸ*****\n");
    printf("********************\n");

}
void game()
{
    char board[ROW][COL] = { 0 };
    Initboard(board, ROW, COL);//��ʼ������
    Displayboard(board, ROW, COL);//��ʾ����
    char ret = 'A';
    while (1)
    {//���ִ��
       
        Playermove(board, ROW, COL);//�������
        Displayboard(board, ROW, COL);
        ret = Iswin(board,ROW,COL);
       if (ret != 'C')
       {
           break;
       }
    //����ִ��
       Computermove(board, ROW, COL);
       Displayboard(board, ROW, COL);
       ret = Iswin(board, ROW, COL);
       if (ret != 'C')
       {
           break;
       }
    }
    if (ret == '*')
    {
        printf("���Ӯ\n");
    }
    else if (ret == '#')
    {
        printf("����Ӯ\n");
    }
    else if (ret == 'Q')
    {
        printf("ƽ��\n");
    }
}
void test()
{
    int select = 0;

    do 
    {
        menu();
        scanf("%d", &select);

        switch (select)
        {
        case 1:game();
            break;
        case 0:
            break;
        default:
            printf("�����������������\n");
            break;
        }
    }        
    while (select);
     
}
int main()
{
    srand((unsigned int)time(NULL));
    test();


    return 0;
}