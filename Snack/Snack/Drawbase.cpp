#define _CRT_SECURE_NO_WARNINGS
#include"DrawBase.h"

void Write_Char(int x, int y,  const char* str, int Color)
{
    //�������ù����������pos
    COORD pos = { 2*x,y };
    //��ȡ���
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //���ù��λ��
    SetConsoleCursorPosition(hOut,pos);

    //�����ı���ɫ
    SetConsoleTextAttribute(hOut, Color);
    //����ַ�
    printf("%s", str);
}

void Write_Int(int x, int y, int nNum, int Color)
{
    //�������ù����������pos
    COORD pos = { x,y };
    //��ȡ���
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    //���ù��λ��
    SetConsoleCursorPosition(hOut, pos);
    //�����ı���ɫ
    SetConsoleTextAttribute(hOut, Color);
    printf("%d", nNum);
}

//�رչ�꺯��
void ShowCursor(bool isShow)
{
    HANDLE hOUtStd = GetStdHandle(STD_OUTPUT_HANDLE);

    //���ÿ���̨���Ľṹ��
    CONSOLE_CURSOR_INFO cci;
    //���ߴ�
    cci.dwSize = 1;
    //�رչ���򿪹��
    cci.bVisible = isShow;

    //���ÿ���̨����
    SetConsoleCursorInfo(hOUtStd, &cci);
}


int WaitKey()
{
    if (_kbhit())
    {
        return _getch();
    }
    return 0;
}
