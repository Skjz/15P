#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
    printf("*******************\n");
    printf("*****1.��ʼ��Ϸ*****\n");
    printf("*****0.�˳���Ϸ*****\n");
    printf("*******************\n");
}
void game()
{
    char mine[ROWS][COLS] = {0};//���úõ��׵���Ϣ
    char show[ROWS][COLS] = { 0 };//�Ų�����׵���Ϣ
    //��ʼ��
    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    //��ӡ
    DisplayBoard(show,ROW,COL);
    //������
    SetMine(mine, ROW, COL);
    
    //ɨ��
    FindMine(mine,show,ROW,COL);
}
void test()
{
    int input = 0;
    do
    {
        menu();
        printf("������ѡ��:>");
        scanf("%d", &input);

        switch (input)
        {
        case 1:game();
            break;
        case 0:
            printf("�˳���Ϸ\n");
            break;
        default:
            printf("�����������������!");
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