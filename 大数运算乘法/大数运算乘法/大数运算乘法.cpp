#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<string.h>
int main()
{
    //����ʹ�������ַ������飬��ֹ���ֱ�������int�����ݵĴ洢��С����
    //�������������1
    char Num1[] = "12345678";
    //�������������2
    char Num2[] = "87654321";


    //�������ÿһ������1����Ԫ�ص����顣
    int TurnNum1[100] = { 0 };
    //�������ÿһ������2����Ԫ�ص����顣
    int TurnNum2[100] = { 0 };

    //������ţ����õģ�������������
    int TurnMul[100] = { 0 };

    
    int nLenth1 = 0;
    int nLenth2 = 0;
    //�������ĳ���
    int nLenth = 16;

    //����1(�ַ�������)�ĳ���
    nLenth1 = strlen(Num1);
    //����2(�ַ�������)�ĳ���
    nLenth2 = strlen(Num2);

    int j = 0;
    for (int i = nLenth1 - 1; i >= 0; i--)
    {
        //������1��ÿһ���ַ�Ԫ�ر�Ϊ���ִ�����������1��(����)
        //֮����������Ϊ�˷������㣬��Ϊ����ʱҲ�Ǵӵ�λ���λ����
        TurnNum1[j] = Num1[i] - '0';
        j++;
    }
    j = 0;
    for (int i = nLenth2 - 1; i >= 0; i--)
    {
        //������2��ÿһ���ַ�Ԫ�ر�Ϊ���ִ�����������2�У����ã�
        TurnNum2[j] = Num2[i] - '0';
        j++;
    }
    for (int i = 0; i < nLenth1; i++)
    {
        for (int j = 0; j < nLenth2; j++)
        {   //�ڳ˷�����ʱ��һ�����ɣ��Ǿ�������1�ĵ�i��Ԫ�غ�����2�ĵ�j��Ԫ����˻�ӵ������i+jλ��
            //Ϊ�˷���д���̣������㣬�ٿ��ǽ�λ
            TurnMul[i + j] = TurnMul[i+j]+TurnNum1[i] * TurnNum2[j];
        }
    }
    for (int i = 0; i < nLenth; i++)
    {
        //���������������һλ����10��������Ҫ��λ
        if (TurnMul[i] >= 10)
        {
            //�൱����һλ������Ӧ�ü�����һλ��Ҫ��λ�����ֵ�10λ�ϵ�����
            TurnMul[i + 1] = TurnMul[i + 1] + TurnMul[i] / 10;
            //Ȼ����һλ��Ҫ��λ�����ֽ����¸�λ��
            TurnMul[i] = TurnMul[i] % 10;
        }
    }

    //��ʱ���ܻ��������ĩβ����0��������Ҫȥ0
    for (int i = 0; i < nLenth; i++)
    {
        if (TurnMul[nLenth] == 0)
        {
            nLenth--;
        }
        else
        {
            break;
        }
    }
    //�������õĽ�����������ӡ
    for (int i = nLenth; i >= 0; i--)
    {
        printf("%d", TurnMul[i]);
    }

    return 0;
}