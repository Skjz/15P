#include "CCircle.h"
#include<stdio.h>

void CCircle::Area()
{
    printf("���ð뾶\n");
    scanf_s("%d", &m_nR);
    m_nArea = m_nR * m_nR * 9.8;
}
//void CCircle::SetR()
//{
//    printf("���ð뾶\n");
//    scanf_s("%d", &m_nR);
//}
void CCircle::GetArea()
{
    printf("%f\n", m_nArea);
}
void CCircle::GetName()
{
    printf("%s\n", m_szName);
}
CCircle::CCircle() :m_szName{ "Բ��" }
{

}
CCircle::~CCircle()
{
  
}

