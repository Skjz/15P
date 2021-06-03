#define  _CRT_SECURE_NO_WARNINGS

#include"game.h"
void menu()
{
    printf("********************\n");
    printf("*****1.开始游戏*****\n");
    printf("*****0.退出游戏*****\n");
    printf("********************\n");

}
void game()
{
    char board[ROW][COL] = { 0 };
    Initboard(board, ROW, COL);//初始化棋盘
    Displayboard(board, ROW, COL);//显示棋盘
    char ret = 'A';
    while (1)
    {//玩家执棋
       
        Playermove(board, ROW, COL);//玩家落子
        Displayboard(board, ROW, COL);
        ret = Iswin(board,ROW,COL);
       if (ret != 'C')
       {
           break;
       }
    //电脑执棋
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
        printf("玩家赢\n");
    }
    else if (ret == '#')
    {
        printf("电脑赢\n");
    }
    else if (ret == 'Q')
    {
        printf("平局\n");
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
            printf("输入错误，请重新输入\n");
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