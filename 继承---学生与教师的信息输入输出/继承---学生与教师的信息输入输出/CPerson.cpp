#include "CPerson.h"
#include<stdio.h>
CPerson::CPerson() : m_nCode(0), m_szName{0}
{

}
void CPerson::GetCode()
{
    printf("�����:%d", m_nCode);

}
void CPerson::GetName()
{
    printf("������:%s", m_szName);
}
void CPerson::SetCode()
{   
    printf("��������:>");
    scanf_s("%d", &m_nCode);
}
void CPerson::SetName()
{
    printf("����������:>");
    scanf_s("%s", m_szName);
}

