#include "CPerson.h"
#include<stdio.h>
CPerson::CPerson() : m_nCode(0), m_szName{0}
{

}
void CPerson::GetCode()
{
    printf("±àºÅÊÇ:%d", m_nCode);

}
void CPerson::GetName()
{
    printf("ÐÕÃûÊÇ:%s", m_szName);
}
void CPerson::SetCode()
{   
    printf("ÇëÊäÈë±àºÅ:>");
    scanf_s("%d", &m_nCode);
}
void CPerson::SetName()
{
    printf("ÇëÊäÈëÐÕÃû:>");
    scanf_s("%s", m_szName);
}

