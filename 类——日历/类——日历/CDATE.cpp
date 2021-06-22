#include "CDATE.h"
#include<stdio.h>
#include<stdlib.h>
CDATE::CDATE() :
    m_nYear(1998), m_nMonth(1), m_nDay(1),m_nMonth_Day{31,28,31,30,31,30,31,31,30,31,30,31}

{

}
void CDATE::SetDate()
{
    printf("请输入年份:>");
    scanf_s("%d", &m_nYear);
    printf("请输入月份:>");
    scanf_s("%d", &m_nMonth);
    printf("请输入日期:>");
    scanf_s("%d", &m_nDay);
    printf("设置成功\n");
}
void CDATE::Run()
{
    if ((m_nYear % 4 == 0 && m_nYear % 100 != 0) || (m_nYear % 100 == 0))
    {
        if (m_nMonth_Day[1] == 28)
        {
            m_nMonth_Day[1] = m_nMonth_Day[1] + 1;
        }
        if (m_nMonth_Day[m_nMonth - 1] == m_nDay)
        {
            m_nMonth = m_nMonth + 1;
            m_nDay = 1;
        }
        else if (m_nMonth == 12 && m_nDay == 31)
        {
            m_nYear = m_nYear + 1;
            m_nMonth = 1;
            m_nDay = 1;
        }
        else
        {
           m_nDay = m_nDay + 1;
        }
    }
        else
        {
        if (m_nMonth_Day[1] == 29)
        {
            m_nMonth_Day[1] = m_nMonth_Day[1] - 1;
        }

        if (m_nMonth_Day[m_nMonth - 1] == m_nDay)
        {
            m_nMonth = m_nMonth + 1;
            m_nDay = 1;
        }
        else if (m_nMonth == 12 && m_nDay == 31)
        {
            m_nYear = m_nYear + 1;
            m_nMonth = 1;
            m_nDay = 1;
        }
        else
        {
           m_nDay = m_nDay + 1;
        }
        
    }


}
void CDATE::GetDate()
{
    printf("%d/%d/%d \n", m_nDay, m_nMonth, m_nYear);
}
