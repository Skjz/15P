#include "CStudent.h"
#include<stdio.h>
CStudent::CStudent(int nClassCode = 0, int nScore = 0)
{
    m_nClassCode = nClassCode;
    m_nScore = nScore;
}
void CStudent::SetClassCode()
{
    printf("������༶���:>");
    scanf_s("%d", &m_nClassCode);

}
void CStudent::SetScore()
{
    printf("������ѧ������:>");
    scanf_s("%d", &m_nScore);

}

