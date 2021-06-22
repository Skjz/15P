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
    printf("请输入小时:>");
    scanf_s("%d", &m_nHour);
    printf("请输入分钟:>");
    scanf_s("%d", &m_nMinute);
    printf("请输入秒:>");
    scanf_s("%d", &m_nSecond);

}
void CTIME::GetHour()
{
    printf("当前是:%d点\n", m_nHour);
}

void CTIME::GetMinute()
{
    printf("当前是:%d分\n", m_nMinute);
}
void CTIME::GetSecond()
{
    printf("当前是:%d秒\n", m_nSecond);
}