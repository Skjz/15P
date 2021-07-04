#include "CTable.h"
#include<stdio.h>
#include<string.h>
CTable::CTable(double dblHeight, const char* szColor)
{
    m_dblHeight = dblHeight;
   
    strcpy_s(m_szColor, 20, szColor);
}
double CTable::GetHeight()
{
    return m_dblHeight;
}
void CTable::GetColor()
{
    printf("%s", m_szColor);
}
