#include "CTIME.h"
#include<stdio.h>
#include<stdlib.h>

CTIME::CTIME(int nHour, int nMinute, int nSecond)
{
    m_nHour = nHour;
    m_nMinute = nMinute;
    m_nSecond = nSecond;
}
void CTIME::SetTime()
{
    printf("������Сʱ:>");
    scanf_s("%d", &m_nHour);
    printf("���������:>");
    scanf_s("%d", &m_nMinute);
    printf("��������:>");
    scanf_s("%d", &m_nSecond);

}
void CTIME::GetHour()
{
    printf("��ǰ��:%d��\n", m_nHour);
}

void CTIME::GetMinute()
{
    printf("��ǰ��:%d��\n", m_nMinute);
}
void CTIME::GetSecond()
{
    printf("��ǰ��:%d��\n", m_nSecond);
}