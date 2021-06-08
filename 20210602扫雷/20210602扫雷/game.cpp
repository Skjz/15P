#define  _CRT_SECURE_NO_WARNINGS
#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            board[i][j] = set;
        }
    }
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
    int i = 0;
    int j = 0;
    for (i = 0; i <= col; i++)
    {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 1; i <= row; i++)
    {
        printf("%d ", i);
        for (j = 1; j <= col; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
    int count = EASY_COUNT;
    while (count)
    {
        int x = rand() % row + 1;
        int y = rand() % col + 1;
        if (board[x][y] == '0')
        {
            board[x][y] = '1';
            count--;
        }
    }
}
int get_mine_count(char mineboard[][COLS], int  x, int  y)
{return 
    mineboard[x - 1][y]     +
    mineboard[x - 1][y - 1] +
    mineboard[x - 1][y + 1] +
    mineboard[x][y - 1]     +
    mineboard[x][y + 1]     +
    mineboard[x + 1][y]     +
    mineboard[x + 1][y - 1] +
    mineboard[x + 1][y + 1] - 8 * '0';

}
void IsMine(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int x,int y)
{
    //����֪��Χ�˸�û���ף���ѡ���Ǹ��ɿո�
    //�����Χ�˸����Χ�˸��Ƿ����ף����û�����򣬽��Ǹ��Ϊ�ո�
    if (get_mine_count != 0)
    {
        IsMine(mineboard, showboard, x--, y++);
    }
    showboard[x][y] = ' ';
    if (get_mine_count(mineboard, x, y) == 0)
    {
        IsMine(mineboard, showboard, x++, y);
    }
   
}

void FindMine(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int row, int col)
{
    int x = 0;
    int y = 0;
    int win = 0;
    while (win<row*col-EASY_COUNT)
    {
        printf("����������:>");
        scanf("%d%d", &x, &y);
        if (x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if (mineboard[x][y] == '1')
            {
                printf("���ź���Ϸ����\n");
                DisplayBoard(mineboard, row, col);
                break;
            }
            else
            {   
               int count = get_mine_count(mineboard, x, y);//�����Χ�˸������
               
               //����֪��Χ�˸�û���ף���ѡ���Ǹ��ɿո�
               //�����Χ�˸����Χ�˸��Ƿ����ף����û�����򣬽��Ǹ��Ϊ�ո�
             //  IsMine( mineboard, showboard, x,y);
               showboard[x][y] = count + '0';
               DisplayBoard(showboard, row, col);
               win++;
            }
        }
        else
        {
            printf("����Ƿ�������������\n");
        }
    }
    if (win == row * col - EASY_COUNT)
    {
        printf("��ϲ�㣬���׳ɹ�\n");
        DisplayBoard(mineboard, row, col);
    }
}

