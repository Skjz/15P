#pragma once
#include<vector>
#include<windows.h>
#include"DrawBase.h"


using std::vector;
class CSnake
{
public:
    //��ʼ����
    CSnake();

    //��ʾ��
    void Draw_Snake();
    void Draw_Enemy_Snake();

    //�����Ƴ�
    void Remove_Snake();
    void Remove_Enemy_Snake();

    //�ƶ���
    void Move_Snack();
    void Move_Enemy_Snack();
    void Move_Double_Snake();
    void Move_Enemy_Snake_Head(COORD TempEnemy);

    //�ı��ߵķ���
    void Change_Snake_Dir();
    void Change_Enemy_Snake_Dir();

    //�õ��Ե�ʳ����������ʱֵ
    int Get_Temp_Count_Food();
    int Get_Enemy_Temp_Count_Food();

    //�õ��Ե�ʳ��������ֵ
    int Get_m_Count_Food();
    int Get_Enemy_m_Count_Food();

    //���óԵ�ʳ���������ֵ
    void Set_m_Count_Food(int Temp_Count_Food);
    void Set_Enemy_m_Count_Food(int Temp_Enemy_Count_Food);

    //�õ���������ʱֵ
    int Get_Temp_Score();
    int Get_Enemy_Temp_Score();
    //�õ�������ֵ
    int Get_Score();
    int Get_Enemy_Score();

    //���÷�����ֵ
    void Set_Score(int Temp_Score);
    void Set_Enemy_Score(int Temp_Enemy_Score);

    //δ�ر���Ϸʱ�������ߵ�ͼ��
    void Draw_No_Player_Snake();
 
    //�����ߵ�����
    void Set_Snake_LIfe(int Temp_Life);
    void Set_Enemy_Snake_LIfe(int Temp_Enemy_Life);
    

    //�õ���Ϸ����ֵ
    int Get_Game_Life();

    int Get_Enemy_Game_Life();

   
    //��ȡ�ߵĳ���
    int Get_Snake_Lenth();
    int Get_Enemy_Snake_Lenth();
    
    //��ȡ�ߵ�Ԫ��
    COORD Get_Snake_Ele(int nLoc);
    COORD Get_Enemy_Snake_Ele(int nLoc);

    //��ȡ�ļ�push_back
    void Push_Back_Snake(COORD Temp_Snake);
    void Push_Back_Enemy_Snake(COORD Temp_Enemy_Snake);

    //����һ������
    int Get_Oper();
    int Get_Enemy_Oper();

    //���´�����
    void RbuildSnake();
    void RbuildEnemySnake();

    //����ߵ��ٶ�
    int Get_Speed();
    int Get_Enemy_Speed();

    //�����ߵ��ٶ�
    void Set_Speed(int nSpeed);
    void Set_Enemy_Speed(int nEnemySpeed);

    //����ߵķ���
    int Get_Dir();
    int Get_Enemy_Dir();
    //�����ߵķ���
    void Set_Dir(int nDir);
    void Set_Enemy_Dir(int nDir);

    //void ClearVector();
    //ɾ���ߵ�Ԫ��
    void Dele_Snake_Ele();
    void Dele_Enemy_Snake_Ele();

private:
    //Player������
    vector<COORD> m_Snake;
    //player2������
    vector<COORD> m_Enemy_Snake;

    //Player���ƶ�ʱ���
    int m_Move_Lasttime;
    //Player2���ƶ�ʱ���
    int m_Enemy_Move_Lasttime;


    //��Ԫ�ص���ʱ����
    COORD Temp_Snake_Ele;
    COORD Temp_Enemy_Snake_Ele;
    
    //�ߵķ���
    int m_Snake_Dir;
    int m_Enemy_Snake_Dir;

    //�ߵ��ƶ��ٶȣ��Ѷȣ�
    int m_Move_Speed;
    //��2���ƶ��ٶȣ��Ѷȣ�
    int m_Enemy_Move_Speed;

    //�÷�
    int m_Get_Score;
    //�÷֣�player2��
    int m_Enemy_Get_Score;

    //�÷ֵ���ʱֵ
    int m_Get_Temp_Score;
    //�з��ߵ���ʱ�÷�ֵ
    int m_Enemy_Get_Temp_Score;

    //�õ���ʳ����������ʱֵ
    int m_Temp_Count_Food;
    //�з��ߵ�ʳ����������ʱֵ
    int m_Enemy_Temp_Count_Food;

    //ʳ�������
    int m_Count_Food;
    //�з���ʳ�������
    int m_Enemy_Count_Food;
    
    //����ֵ
    int m_Game_Life;
    //�з��ߵ�����ֵ
    int m_Enemy_Game_Life;

    //����
    int Oper;
    //�з�����
    int Enemy_Oper;
   
    
};

