#define _CRT_SECURE_NO_WARNINGS
#include"DrawBase.h"
#include"MouseDraw.h"

void MouseDraw()
{
    //1 ��ȡ����̨������
    HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
    //2 ѭ����ȡ����̨������Ϣ
    INPUT_RECORD ir = { 0 };
    DWORD dwRealCourt = 0;
    DWORD dwMode = 0;
    int Return = 0;

    while (true)
    {
        GetConsoleMode(hConsoleInput, &dwMode);
        SetConsoleMode(hConsoleInput, dwMode | ENABLE_MOUSE_INPUT);
        ReadConsoleInput(
            hConsoleInput,//����̨��������
            &ir,          //��ȡ���Ŀ���̨��Ϣ�ʹ�������ṹ����
            3,            //������INPUT_RECORD������
            &dwRealCourt  //��������ȡ��ϵ�ʱ�򣬾�����ȡ�˼����ṹ����Ϣ
        );
        //��һ�������Ϣ
        if (ir.EventType == MOUSE_EVENT)
        {
            //����������Ϣ����ô�����������е�����ֶ�������
            MOUSE_EVENT_RECORD MouseEv = ir.Event.MouseEvent;
            if (MouseEv.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
            {
                //���ϰ���
                if ((EDITOBSTCALES)
                {
                    int x = MOUSEPOS_X;
                    int y = MOUSEPOS_Y;
                    Write_Char(x, y, "��");
                    Map[x][y] = OBSTACLES;
                }
            }
            //�˳��༭ģʽ
            if (MouseEv.dwButtonState == RIGHTMOST_BUTTON_PRESSED)
            {
                return;
            }

            //�����ϰ���
            if (MouseEv.dwButtonState == FROM_LEFT_2ND_BUTTON_PRESSED)
            {
                if (SETEMPTYAREA)
                {
                    int x = MOUSEPOS_X;
                    int y = MOUSEPOS_Y;
                    Write_Char(x, y, "  ");
                    Map[x][y] = EMPTYAREA;
                }
            }

        }

    }
}