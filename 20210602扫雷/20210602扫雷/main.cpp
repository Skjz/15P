#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
    printf("*******************\n");
    printf("*****1.开始游戏*****\n");
    printf("*****0.退出游戏*****\n");
    printf("*******************\n");
}
void game()
{
    char mine[ROWS][COLS] = {0};//布置好的雷的信息
    char show[ROWS][COLS] = { 0 };//排查出的雷的信息
    //初始化
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    //打印
    DisplayBoard(show,ROW,COL);
    //布置雷
    SetMine(mine, ROW, COL);
    
    //扫雷
    FindMine(mine,show,ROW,COL);
}
void test()
{
    int input = 0;
    do
    {
        menu();
        printf("请输入选项:>");
        scanf("%d", &input);

        switch (input)
        {
        case 1:game();
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("输入错误，请重新输入!");
            break;
        }
    } while (input);

}

int main()
{
    srand((unsigned int)time(NULL));
    test();

    return 0;
}