#pragma once
class CFood
{
public:
    CFood();

    //����ʳ��
    void Creat_Food();

    //����ʳ���Ƿ����
    void Set_Food_Exist(int Is_Exist);

    //�õ�ʳ���Ƿ����
    int Get_Food_Exist();

    //����ʳ���Ƿ����
    void Set_Food_Exist();

    //���ʳ�������
    int Get_Food_Type();

    //����ʳ�������
    void Set_Food_Type();

private:
    //�����ж��Ƿ���ʳ��ı���
    int Food_Exist;
    int Food_Type;
};

