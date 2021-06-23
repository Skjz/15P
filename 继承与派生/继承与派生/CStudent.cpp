#include "CStudent.h"
#include<stdio.h>
#include<string.h>
void CStudent::Test()
{
    printf("øº ‘\n");
}

void CStudent::SetName(char *str)
{
    int lenth = strlen(str)+1;
    m_szName = new char[lenth] {0};
    strcpy_s(m_szName, lenth, str);
}
void CStudent::SetAge(int nAge)
{
    m_nAge = nAge;
}
void CStudent::SetScore(int nScore)
{
    m_nScore = nScore;
}